#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

#define MAXN 100004

vii adjList[MAXN];
int estado[MAXN];

bool dfs1(int u, int tar){
	estado[u] = 1;
	for(int i = 0; i < sz(adjList[u]); i++){
		ii curr = adjList[u][i];
		int v = curr.st;
		int c = curr.nd;
		if(c <= tar) continue;
		if(estado[v] == 2) continue;
		if(estado[v] == 1){
			return true;
		}
		if(dfs1(v, tar)) return true;
	}
	estado[u] = 2;
	return false;
}

bool hasCicle(int tar, int n){
	memset(estado, 0, sizeof estado);
	for(int i = 1; i <= n; i++){
		if(estado[i] == 0){
			if(dfs1(i, tar)){
				return true;
			}
		}
	}
	return false;
}


void dfs2(int u, int tar, vi &resp){
	estado[u] = 1;
	for(int i = 0; i < sz(adjList[u]); i++){
		ii curr = adjList[u][i];
		int v = curr.st;
		int c = curr.nd;
		if(c <= tar) continue;
		if(estado[v] == 2) continue;
		dfs2(v, tar, resp);
	}
	estado[u] = 2;
	resp.pb(u);
}

vi topologic(int tar, int n){
	vi resp;
	memset(estado, 0, sizeof estado);
	for(int i = 1; i <= n; i++){
		if(estado[i] == 0){
			dfs2(i, tar, resp);
		}
	}
	return resp;
}

int main(){
	int n, m;
	cin >> n >> m;
	viii roads;
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adjList[a].pb(mp(b,c));
		roads.pb(mp(c,mp(a,b)));
	}
	int lo = 0, hi = 1000000001, mid;
	while(lo < hi){
		mid = (lo + hi)/2;
		if(hasCicle(mid, n)){
			lo = mid+1;
		} else {
			hi = mid;
		}
	}
	mid = (lo + hi)/2;

	vi top = topologic(mid, n);

	map<int, int> ordem;
	for(int i = 0; i < sz(top); i++){
		ordem[top[i]] = i;
	}

	vi resp;

	for(int i = 0; i < m; i++){
		if(roads[i].st <= mid){
			ii curr = roads[i].nd;
			int a = curr.st, b = curr.nd;
			if(ordem[a] < ordem[b]){
				resp.pb(i);
			}
		}
	}

	printf("%d %d\n", mid, sz(resp));

	for(int i = 0; i < sz(resp); i++){
		printf("%d ", resp[i]+1);
	}
	cout << endl;

	return 0;
}