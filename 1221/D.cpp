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

#define MAXN 300100

int n;
int a[MAXN], b[MAXN];
ll PD[MAXN][3];

ll pd(int i, int incBef){
	if(i == n){
		return 0;
	}
	int ant = 0;
	if(i > 0){
		ant = incBef+a[i-1];
	}

	ll &mem = PD[i][incBef];
	if(mem != -1){
		return mem;
	}

	mem = INFLL;

	for(ll toadd = 0; toadd < 3; toadd++){
		if(a[i]+toadd != ant){
			mem = min(mem, pd(i+1, toadd) + toadd*b[i]);
		}
	}
	return mem;
}

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		FOR(i,0,n){
			scanf("%d %d", a+i, b+i);			
		}
		FOR(i,0,n){
			FOR(j,0,3){
				PD[i][j] = -1;
			}
		}
		printf("%lld\n", pd(0,0));
	}
	return 0;
}