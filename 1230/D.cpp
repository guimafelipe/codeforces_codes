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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<short> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int n;
ll a[7000], b[7000];

vi adjList[7000];
vi comps[7000];
ll resp = 0;

ll cval[7000];
int compInd[7000];
bool nes[7000] = {false};
unordered_set<short> cadjList[7000];

bool mIsBetter[7000][7000];

bool isBetter(int i, int j){
	if(a[i] == a[j]) return mIsBetter[i][j] = false;
	if(a[i] - (a[i]&a[j]) != 0) return mIsBetter[i][j] = true;
	return mIsBetter[i][j] = false;
}

int state[7010] = {0};

vector<bool> used;
vector<short> order, component;

void dfs1(int u){
	used[u] = true;
	for(int v : adjList[u]){
		if(!used[v]){
			dfs1(v);
		}
	}
	order.pb(u);
}

int comp = 0;

void dfs2(int u){
	used[u] = true;
	component.pb(u);
	compInd[u] = comp;
	for(int v : adjList[u]){
		if(!used[v]){
			dfs2(v);
		}
	}
}

ll dfsc(int u){
	ll currAns = 0;
	used[u] = true;
	for(int v: cadjList[u]){
		if(!used[v]){
			currAns += dfsc(v);
		}
	}
	currAns += cval[u];
	return currAns;
}

int main(){
	cin >> n;
	FOR(i,0,n){
		ll aux;
		scanf("%lld", &aux);
		a[i] = aux;
	}
	FOR(i,0,n){
		ll aux;
		scanf("%lld", &aux);
		b[i] = aux;
	}

	FOR(i,0,n){
		FOR(j,i+1,n){
			if(!isBetter(i,j)){
				adjList[i].pb(j);
			}
			if(!isBetter(j,i)){
				adjList[j].pb(i);
			}
		}
	}

	used.assign(n, false);

	FOR(i,0,n){
		if(!used[i]){
			dfs1(i);
		}
	}

	FOR(i,0,n){
		adjList[i].clear();
	}

	used.assign(n, false);
	FOR(i,0,n){
		FOR(j,i+1,n){
			if(!mIsBetter[i][j]){
				adjList[j].pb(i);
			}
			if(!mIsBetter[j][i]){
				adjList[i].pb(j);
			}
		}
	}

	FOR(i,0,n){
		int v = order[n-1-i];
		if(!used[v]){
			dfs2(v);
			comps[comp] = component;
			if(sz(component) > 1){
				nes[comp] = true;
			} 
			comp++;
			component.clear();
		}
	}

	FOR(i,0,comp){
		ll val = 0;
		for(int j : comps[i]){
			val+=b[j];
		}
		cval[i] = val;
	}


	FOR(i,0,n){
		for(int j : adjList[i]){
			if(compInd[i] != compInd[j]){
				cadjList[compInd[i]].insert(compInd[j]);
			}
		}
		adjList[i].clear();
	}

	ll ans = 0;

	used.assign(comp, false);
	FOR(i,0,comp){
		if(nes[i]){
			ans += dfsc(i);
		}
	}

	cout << ans << endl;

	return 0;
}