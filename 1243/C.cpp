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
 
ll _sieve_size;
bitset<10001000> bs;
vll primes;
 
void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j <= _sieve_size; j += i){
				bs[j] = 0;
			}
			primes.pb(i);
		}
	}
}
 
vll getPrimeFact(ll n){
	ll i = 0, pf = primes[0];
	vll ans;
	while(pf*pf <= n){
		if(n%pf == 0) ans.pb(pf);
		while(n%pf == 0){
			n/=pf;
		}
		pf = primes[++i];
	}
	if(n!=1) ans.pb(n);
	return ans;
}
 
int main(){
	ll n;
	cin >> n;
	sieve(10000000);
	vll primeFact = getPrimeFact(n);
	if(sz(primeFact) == 1){
		cout << primeFact.front() << endl;
	} else {
		cout << 1 << endl;
	}
	return 0;
}
