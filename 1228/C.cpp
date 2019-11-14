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

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

ll exp1(ll n, ll a){
	if(!a) return 1LL;
	ll ans = exp1(n, a/2LL);
	ans *= ans;
	ans %= MOD;
	if(a%2LL){
		ans *= n;
		ans %= MOD;
	}
	return ans;
}

vll getFact(ll n){
	vll fact;
	for(ll d = 2LL; d*d <= n; d++){
		if(n%d == 0LL){
			fact.pb(d);
			while(n%d == 0LL){
				n/=d;
			}
		}
	}
	if(n > 1LL){
		fact.pb(n);
	}
	return fact;
}

int main(){
	ll x, n;
	cin >> x >> n;
	vll primes = getFact(x);

	ll ans = 1LL;
	for(ll primo : primes){
		ll p = primo;
		// cout << "primo: " << primo << endl;
		ll totCont = 0LL;
		while(true){
			ll cont = n/p;
			// cout << "p: " << p << ", cont: " << cont << endl;
			totCont += cont;
			// cout << ans << endl;
			p*=primo;
			if(cont <= 1LL) break;
		}
		ans *= exp1(primo, totCont);
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}