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

ll gcd(ll a, ll b){
	return a == 0 ? b : gcd(b%a, a);
}

ll _sieve_size;
bitset<1000100> bs;
vll primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j <= _sieve_size; j+=i){
				bs[j] = 0;
			}
			primes.pb(i);
		}
	}
}

int main(){
	int t;
	cin >> t;
	sieve(1010);
	while(t--){
		int n;
		scanf("%d", &n);
		vll nums;
		for(int i = 0; i < n; i++){
			int aux;
			scanf("%d", &aux);
			nums.pb(aux);
		}
		int color = 1;
		vi ans(n, 0);
		
		for(ll p : primes){
			bool marcou = false;
			for(int i = 0; i < n; i++){
				int curr = nums[i];
				if(ans[i] != 0) continue;
				if(curr%p == 0){
					ans[i] = color;
					marcou = true;
				}
			}
			if(marcou) color++;
		}

		printf("%d\n", color-1);
		for(int c : ans){
			printf("%d ", c);
		}
		printf("\n");

	}
	return 0;
}
