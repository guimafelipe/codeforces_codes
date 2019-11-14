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
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;


vpll pares;
vi mmcs;

int gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}
int lcm(ll a, ll b){return a*(b/gcd(a,b));}

ll _sieve_size;
bitset<1000000010> bs;
vll primes;
set<ll> primosAdicionados;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	// cout << _sieve_size << endl;;
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++) if(bs[i]){
		for(ll j = i*i; j <= _sieve_size; j+=i) bs[j] = 0;
		primes.pb(i);
	}
}

bool divides_pair(ll m, pll par){
	if(par.st % m == 0) return true;
	if(par.nd % m == 0) return true;
	return false;
}

bool isPrime(ll N){
	if(N <= _sieve_size) return bs[N];
	if(primosAdicionados.count(N) != 0) return true;
	for(int i = 0; i < (int)primes.size(); i++){
		if(N % primes[i] == 0) return false;
	}
	primes.pb(N);
	primosAdicionados.insert(N);
	return true;
}

int main(){
	int n;
	cin >> n;
	ll maxi = 0;
	sieve(50000LL);
	for(int i = 0; i < n; i++){
		ll aux1, aux2;
		cin >> aux1 >> aux2;
		isPrime(aux1);
		isPrime(aux2);
		pares.pb(mp(aux1, aux2));
		maxi = max(maxi, max(aux1, aux2));
	}

	if(n == 1){
		cout << maxi << endl;
		return 0;
	}

	for(int i = 0; i < primes.size(); i++){
		bool deu = true;
		for(int j = 0; j < n; j++){
			if(!divides_pair(primes[i], pares[j])){
				deu = false; 
				break;
			}
		}
		if(deu){
			cout << primes[i] << endl;
			return 0;
		}
	}

	cout << "-1\n";

	return 0;
}