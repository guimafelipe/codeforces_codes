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
typedef map<ll, int> mlli;


ll x [100100];
vi adjList[100100];

void dfs(int u, int p, mlli gcds){
	for(auto el : gcds){
		
	}
	for(int v: adjList[u]){
		if(v == p) continue;

	}
}

int main(){
	int n;
	cin >> n;
	FOR(i,0,n){
		scanf("%lld", x+i);
	}
	FOR(i,1,n){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;b--;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	dfs(0,-1, mlli() );
	return 0;
}