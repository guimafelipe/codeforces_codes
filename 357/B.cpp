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

int color[100100];

vi adj[100100];
int mask[100100] = {0};

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--; c--;
		vi dance;
		dance.pb(a);
		dance.pb(b);
		dance.pb(c);
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(i == j) continue;
				adj[dance[i]].pb(dance[j]);
				adj[dance[j]].pb(dance[i]);
			}
		}
	}
	for(int d = 0; d < n; d++){
		int i = 0;
		while((1<<i)&mask[d]) i++;
		color[d] = i;
		for(int v : adj[d]){
			mask[v] |= (1<<i);
		}
	}
	for(int i = 0; i < n; i++){
		int c = color[i]+1;
		printf("%d ", c);
	}
	printf("\n");
	return 0;
}

