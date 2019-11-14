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

#define MAXN 100005

vi adjList[MAXN];

int s[MAXN];
int a[MAXN];
int par[MAXN];
bool deuRuim = false;

void busca(int u){
	if(s[u] == -1){
		if(sz(adjList[u]) == 0){
			s[u] = s[par[u]];
		} else {
			s[u] = s[adjList[u][0]];
			for(int i = 1; i < sz(adjList[u]); i++){
				s[u] = min(s[adjList[u][i]], s[u]);
			}
		}
	}
	for(int i = 0; i < sz(adjList[u]); i++){
		int v = adjList[u][i];
		busca(v);
	}
}

void busca2(int u){
	for(int i = 0; i < sz(adjList[u]); i++){
		int v = adjList[u][i];
		a[v] = s[v] - s[u];
		busca2(v);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i < n; i++){
		int p;
		scanf("%d", &p);
		par[i] = p-1;
		adjList[p-1].pb(i);
	}
	for(int i = 0; i < n; i++){
		int _s;
		scanf("%d", &_s);
		s[i] = _s;
	}
	a[0] = s[0];
	busca(0);
	busca2(0);
	ll result = 0;
	// for(int i = 0; i < n; i++){
	// 	printf("%d ", i);
	// }
	// cout << endl;
	// for(int i = 0; i < n; i++){
	// 	printf("%d ", s[i]);
	// }
	// cout << endl;
	// for(int i = 0; i < n; i++){
	// 	printf("%d ", par[i]);
	// }
	// cout << endl;
	for(int i = 0; i < n; i++){
		result += a[i];
		// printf("%d ", a[i]);
		if(a[i] < 0) deuRuim = true;
	}
	// cout << endl;
	if(deuRuim) result = -1;
	cout << result << endl;
	return 0;
}