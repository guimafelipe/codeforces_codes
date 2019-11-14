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
}

ll numDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
	while (PF * PF <= N) {
		ll power = 0; // count the power
		while (N % PF == 0) { N /= PF; power++; }
		ans *= (power + 1); // according to the formula
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
	return ans;
}

unordered_map<ll,ll> divs;
unordered_map<ll,ll> nums;
ll max_gcd;

void fill_divs(){
	unordered_map<ll,ll>::iterator it;
	for(it = nums.begin(); it != nums.end(); it++){
		ll N = it->st;
		ll mult = it->nd;
		for(ll i = 1; i*i <= N; N%2?i+=2:i++){
			if(N%i == 0){
				if(i > max_gcd){
					if(divs.find(i) == divs.end()) divs[i] = 0;
					divs[i]+=mult;
				}
				if(N/i != i && ((N/i) > max_gcd)){
					if(divs.find(N/i) == divs.end()) divs[N/i] = 0;
					divs[N/i]+=mult;
				}
			}
		}
	}
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(){
	int n;
	cin >> n;
	max_gcd = 0LL;
	for(int i = 0; i < n; i++){
		ll aux;
		scanf("%lld", &aux);
		if(nums.find(aux) == nums.end()) nums[aux] = 0;
		nums[aux]++;
		max_gcd = gcd(max_gcd, aux);
	}

	fill_divs();

	int curr_max = 0, curr_ind;

	unordered_map<ll,ll>::iterator it;
	for(it = divs.begin(); it != divs.end(); it++){
		if(it->nd > curr_max) curr_max = it->nd;
	}

	if(curr_max == 0) curr_max = n+1;
	cout << n-curr_max << endl; 

	return 0;
}