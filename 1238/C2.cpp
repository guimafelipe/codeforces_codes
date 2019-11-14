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

int main(){
	int q;
	cin >> q;
	while(q--){
		int h, n;
		scanf("%d%d", &h, &n);
		vi plats;
		FOR(i,0,n){
			int p;
			scanf("%d", &p);
			plats.pb(p);
		}
		plats.pb(0);
		n++;
		vi ilhas;
		ilhas.pb(1);
		FOR(i,1,n){
			if(plats[i] == plats[i-1] - 1){
				ilhas.back()++;
			}else{
				ilhas.pb(1);
			}
		}
		// printf("Ilhas: ");
		// FOR(i,0,sz(ilhas)){
		// 	printf("%d ", ilhas[i]);
		// }
		// printf("\n");

		int cris = 0;
		
		if(ilhas.front()%2 == 0){
			cris++;
		}
		FOR(i,1,sz(ilhas)-1){
			if(ilhas[i]%2 != 0){
				cris++;
			}
		}
		if(sz(ilhas)==1){
			printf("0\n");
		} else {
			printf("%d\n", cris);
		}
	}
	return 0;
}