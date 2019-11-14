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
	int t;
	cin >>t;
	while(t--){
		ll n,m,k;
		cin >> n >> m >> k;
		vll h;
		FOR(i,0,n){
			ll aux;
			scanf("%lld", &aux);
			h.pb(aux);
		}
		FOR(i,0,n){
			if(i == n-1){
				cout << "YES\n";
				break;
			}
			if(h[i+1]>h[i]+k){
				m-=(h[i+1]-(h[i]+k));
			}else if(h[i+1]<h[i]+k){
				m+=(min(h[i], h[i]+k-h[i+1]));
			}
			// cout << "i: " << i << ", m:" << m << endl;
			if(m<0){
				cout << "NO\n";
				break;
			}
		}
	}
	return 0;
}