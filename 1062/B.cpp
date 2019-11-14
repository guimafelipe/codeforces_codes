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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	} 
}

bool isPrime(ll N) { // a good enough deterministic prime tester
	if (N <= _sieve_size) return bs[N]; // O(1) for small primes
	for (int i = 0; i < (int)primes.size(); i++)
	if (N % primes[i] == 0) return false;
	return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2
//------------------------------------------

vi getPrimeFact(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx];
	vi ans;
	while (PF * PF <= N) {
		while (N % PF == 0) { N /= PF; ans.pb(PF); }
		PF = primes[++PF_idx];
	}
	if (N != 1) ans.pb(N);
	return ans;
}

int main(){
	ll n;
	cin >> n;
	vi fact;
	sieve(1000000);
	fact = getPrimeFact(n);
	// for(int i = 0; i < sz(fact); i++){
	// 	cout << fact[i] << endl;
	// }
	vi expoents;
	int cnt = 0, ant = 0;
	ll ans = 1;
	for(int i = 0; i < sz(fact); i++){
		if(fact[i] == ant){
			expoents[sz(expoents)-1]++;
		} else {
			expoents.pb(1);
			ans *= fact[i];
		}
		ant = fact[i];
	}
	int ops = 0;
	for(int i = 0; i < sz(expoents); i++){
		// cout << expoents[i] << " ";
		ops = max(ops, expoents[i]);
	}
	// cout << endl;
	int base = 1, counter = 0;
	while(base < ops){
		counter++;
		base = 1 << counter;
	}

	bool temMult = false;
	for(int i = 0; i < sz(expoents); i++){
		if(expoents[i] != base){
			temMult = true;
		}
	}

	if(temMult){
		counter++;
	}

	cout << ans << " " << counter << endl;
	return 0;
}