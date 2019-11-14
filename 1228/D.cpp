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

int n, m;
unordered_set<int> adjList[100100];
unordered_set<int> grupo[3];
vi grupos;
vii edges;

void confere(){
	FOR(i,0,n){
		if(grupos[i] == -1){
			cout << "-1\n";
			return;
		}
	}
	for(ii edge: edges){
		int x = edge.st, y = edge.nd;
		if(grupos[x] == grupos[y]){
			cout << "-1\n";
			return;
		}
	}
	ll s1,s2,s0;
	s0 = sz(grupo[0]);
	s1 = sz(grupo[1]);
	s2 = sz(grupo[2]);
	if(s0 == 0 || s1 == 0 || s2 == 0){
		cout << "-1\n";
		return;
	}
	ll nArestas = s0*s1 + s1*s2 + s2*s0; 
	if(nArestas != m){
		cout << "-1\n";
		return;
	}
	FOR(i,0,n){
		printf("%d ", grupos[i]+1);
	}
	printf("\n");
}

int main(){
	cin >>n >> m;
	FOR(i,0,m){
		int x,y;
		scanf("%d%d", &x, &y);
		x--; y--;
		adjList[x].insert(y);
		adjList[y].insert(x);
		edges.pb(mp(x,y));
	}
	grupos.resize(n, -1);
	grupo[0].insert(0);
	grupos[0] = 0;
	FOR(i,1,n){
		if(!adjList[0].count(i)){
			grupo[0].insert(i);
			grupos[i] = 0;
		}
	}
	int next = -1;
	FOR(i,0,n){
		if(grupos[i]==-1){
			next = i;
			break;
		}
	}
	if(next == -1){
		confere();
		return 0;
	}
	grupo[1].insert(next);
	grupos[next] = 1;
	FOR(i,0,n){
		if(grupos[i] != -1)  continue;
		if(!adjList[next].count(i)){
			grupo[1].insert(i);
			grupos[i] = 1;
		}
	}
	next = -1;
	FOR(i,0,n){
		if(grupos[i]==-1){
			next = i;
			break;
		}
	}
	if(next == -1){
		confere();
		return 0;
	}
	grupo[2].insert(next);
	grupos[next] = 2;
	FOR(i,0,n){
		if(grupos[i] != -1)  continue;
		if(!adjList[next].count(i)){
			grupo[2].insert(i);
			grupos[i] = 2;
		}
	}
	confere();
	return 0;
}