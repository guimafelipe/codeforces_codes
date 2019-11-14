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

#define MAXN 100009

//dados da arvore
int par[MAXN], size[MAXN]; 
vi adjList[MAXN]; //um para cada noh
int root, N, up[MAXN], fson[MAXN];

//dados das cadeias
vi chain[MAXN];
int nchains, nchain[MAXN], id[MAXN], depth[MAXN];

int sizedfs(int u, int p){
	size[u] = 1; fson[u] = -1; par[u] = p;
	int msz = 0; // marca qual filho seguir
	for(int i = 0; i < sz(adjList[u]); i++){
		int v = adjList[u][i];
		if(v == p) continue;
		size[u] += sizedfs(v, u);
		if(size[v] > msz){
			fson[u] = v; msz = size[v];
		}
	}
	return size[u];
}

void build(int u, int ch, int h){
	nchain[u] = ch;
	id[u] = sz(chain[ch]);
	chain[ch].pb(u);
	for(int i = 0; i < sz(adjList[u]); i++){
		int v = adjList[u][i];
		if(v == par[u]) continue;
		if(v == fson[u]) build(v, ch, h+1);
		else {
			up[nchains] = u;
			depth[nchains] = h;
			chain[nchains].clear();
			build(v, nchains++, h+1);
		}
	}
}

void hld(int _root){
	root = _root;
	sizedfs(root, -1);
	nchains = 0;
	chain[0].clear();
	up[nchains] = -1;
	depth[nchains] = 0;
	build(root, nchains++, 1);	
}

int LCA(int u, int v){
	int cu = nchain[u], cv = nchain[v];
	while(cu!=cv){
		if(depth[cu] > depth[cv]) u = up[cu];
		else v = up[cv];
		cu = nchain[u]; cv = nchain[v];
	}
	if(id[u] < id[v]) return u;
	else return v;
}

int value[MAXN];

int main(){
	cin >> N;	
	for(int i = 0; i < N; i++){
		scanf("%d", &value[i]);
	}
	for(int i = 0;  i < N-1;  i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	hld(0);
	return 0;
}