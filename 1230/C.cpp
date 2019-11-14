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

int mark[8];

int ligacoes[8][8];

vi adjList[8];

void dfs(int u){
	if(mark[u] == -1){

	}
}

int main(){
	int n, m;
	cin  >> n >> m;

	FOR(i,0,m){
		int a, b;
		scanf("%d%d", &a, &b);
		adjList[a].pb(b);
		adjList[b].pb(a);
	}

	if(n < 7){
		cout << m << endl;
		return 0;
	}

	int ans = 0;
	FOR(i,1,8){
		FOR(j,i+1,8){
			int quebro = 0;
			for(int u : adjList[i]){
				for(int v : adjList[j]){
					if(u == v) quebro++;
				}
			}
			ans = max(ans, m-quebro);
		}
	}

	cout << ans << endl;

	return 0;
}