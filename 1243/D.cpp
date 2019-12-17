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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int p[100100];
int tam[100100] = {0};

int find(int x){
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void join(int x, int y){
	tam[find(y)] += tam[find(x)];
	p[find(x)] = find(y);
}

int main(){
	int n, m;
	cin >> n >> m;
	vii are;
	while(m--){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		are.pb(mp(--a,--b));
	}
	m = sz(are);
	sort(all(are));
	for(int i = n-1; i >= 0; i--){
		p[i] = i;	
	}

	vvi adj(n, vi());

	for(ii ar : are){
		adj[ar.st].pb(ar.nd);
	}

	for(int i = n-1; i >= 0; i--){
		p[i] = i;	
		tam[i] = 1;
	}

	unordered_set<int> parents;

	for(int i = n-1; i >= 0; i--){
		vi conta(n,0);
		for(int j : adj[i]){
			conta[find(j)]++;
		}
		unordered_set<int> parToErase;
		for(int par : parents){
			if(conta[par] < tam[par]){
				join(i, par);
				parToErase.insert(par);
			}
		}
		for(int par : parToErase){
			parents.erase(par);
		}
		parents.insert(find(i));
	}
	cout << sz(parents) - 1 << endl;
	return 0;
}
