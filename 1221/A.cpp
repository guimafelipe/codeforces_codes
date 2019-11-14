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
		int n;
		cin >> n;
		vll a;
		FOR(i,0,n){
			ll aux;
			scanf("%lld", &aux);
			a.pb(aux);
		}
		sort(all(a));
		vi pre;
		pre.pb(0);
		FOR(i,0,n){
			pre.pb(a[i]+pre.back());
		}
		bool deubom = false;
		FOR(i,1,n+1){
			FOR(j,i,n+1){
				if(pre[j]-pre[i-1] == 2048){
					deubom = true;
				}
			}
		}
		if(deubom){
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}
	}
	return 0;
}