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
#define FOR(I, A, B) for(int I = A; I < B; I++)
#define RFOR(I, A, B) for(int I = A; I >= B; I--)

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

bool visited[65] = {0};
bool closed[65] = {0};
int level[65] = {0};

void dfs(int u, int p, int tam, int &best, ll numUsado, ll pai, vvll &adjList){
	// cout << "To no uu = " << u << ", num usado = " << numUsado <<  ", pai = "<< pai <<", tam = " << tam  << endl;
	visited[u] = true;
	level[u] = tam;
	for(int i = 0; i <  sz(adjList[u]); i++){
		ll vnum = adjList[u][i];
		if(vnum == numUsado) continue;
		if(vnum == pai) continue;
		// cout << "Vnum = " << vnum << endl;
		FOR(j, 0, 64){
			ll bit = (1LL << j);
			if(vnum&bit){
				int v=j;
				// if(v == p) continue;
				if(v == u) continue;
				if(closed[v]) continue;
				if(visited[v]){
					if(tam >= 2){
						// cout << "atualizando o best pra "<< tam+1 << " - " << level[v] << endl;
						if(best >= 3){
							best = min(best, tam+1 - level[v]);
						} else {
							best = tam+1;
						}
					}
					continue;
				}
				dfs(v, u, tam+1, best, vnum, numUsado, adjList);
			}
		}
	}
	closed[u] = true;
}

int main(){
	int n;
	cin >> n;
	vvll lig(64, vll());
	vvll adjList(64, vll());
	vll arr;

	FOR(i, 0, n){
		ll aux;
		scanf("%lld", &aux);
		if(aux == 0) continue;
		arr.pb(aux);
		FOR(j, 0, 64){
			ll bit = (1LL << j);
			if(aux&bit){
				lig[j].pb(aux);
			}
		}
	}

	// sort(all(arr));
	// FOR(i, 0, sz(arr)){
	// 	cout <<  arr[i] << " ";
	// }
	// cout << endl;


	FOR(i, 0, 64){
		if(sz(lig[i]) >= 3){
			cout << "3\n";
			return 0;
		}
	}


	int best = 0;

	FOR(i, 0, 64){
		int candBest = 0;
		memset(visited, 0, sizeof visited);
		memset(closed, 0, sizeof closed);
		dfs(i, -1, 0, candBest, 0LL, 0LL, lig);
		if(candBest >= 3 && best == 0){
			best = candBest;
		} else if(candBest >= 3 && best >= 3){
			best = min(candBest, best);
		}
	}

	if(best >= 3){
		cout << best << endl;
		return 0;
	}

	cout << "-1\n";
	return 0;
}