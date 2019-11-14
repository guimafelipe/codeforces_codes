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


ll _sieve_size;

bitset<1000000010> bs;
// vi primos;
ll minn, maxn;
ll raizMaxn, raizMinn, raizDiff;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;

	raizDiff = max(2LL, raizDiff + 1);
	ll lower = max(maxn - raizDiff, minn);
	ll upper = min(raizMaxn + 1, minn);
	// cout << upper << endl;
	// cout << _sieve_size << endl;
	// cout << lower << endl;
	// cout << _sieve_size - lower << endl;
	for(ll i = 2; i <= upper; i++){
		// cout << i << endl;
		for(ll j = lower + (i - (lower%i)); j <= _sieve_size; j+=i){
			// cout << "   " << j << endl;
			bs[j] = 0;
		}
		// primos.pb((int)i);
	}
}

bool isPrime(ll N){
	if(N <= _sieve_size){
		return bs[N];
	}
	// for(int i = 0; i < sz(primos); i++){
	// 	if(N % primos[i] == 0) return false;
	// }
	// return true;
}

int main(){
	cin >> minn >> maxn;
	raizMaxn = (int)sqrt(maxn);
	raizMinn = (int)sqrt(minn);
	raizDiff = raizMaxn;
	// cout << raizMaxn << endl;
	sieve(maxn);
	// cout << "fez o crivo\n";
	int resp = maxn;

	while(!isPrime(resp) && resp > minn){
		resp--;
	}

	if(resp == minn) cout << "-1\n";
	else cout << resp << endl;
	
	return 0;
}