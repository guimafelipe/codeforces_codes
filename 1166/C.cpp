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
	int n;
	cin >> n;
	vll valores(n, 0);
	FOR(i, 0, n){
		scanf("%lld", &valores[i]);
	}
	FOR(i, 0, n){
		valores[i]=abs(valores[i]);
	}
	sort(all(valores));
	ll ans = 0;

	FOR(i, 0, n){
		ll curr = valores[i];
		// cout << "buscando para " << curr << endl;
		int l = i, r = n-1, mid;
		while(l < r){
			// cout << "l = " << l << ", r = " << r << endl;
			mid = (l+r)/2;
			if(l == r-1) mid = r;
			ll test = valores[mid];
			// cout << "teste = " << test << endl;
			if(test > 2*curr){
				r = mid-1;
			} else {
				l = mid;
			}
		}
 		ans += max(0, l - i);
	}

	cout << ans << endl;
	return 0;
}