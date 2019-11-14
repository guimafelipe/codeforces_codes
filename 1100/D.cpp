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

#define MAXN 100003

vii adjList[MAXN];
int estado[MAXN] = {0};
map<ii, int> crossRoads;

void dfs(int u){
	estado[u] = 1;
	for(int i = 0; i < sz(adjList[u]); i++){
		int v = adjList[u][i].st;
		int c = adjList[u][i].nd;
		int stt = estado[v];
		if(stt == 0){
			dfs(v);
		} else if(stt == 1){
			printf("ciclo fechendo em %d->%d\n", u, v);
		}
	}
	estado[u] = 2;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m ; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adjList[a].pb(mp(b,c));
		crossRoads[mp(a,b)] = i;
	}

	dfs(1);

	return 0;
}