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

ll  _sieve_size;
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

int main(){
	int n;
	cin >> n;
	int count1 = 0,  count2 = 0;

	sieve(n);

	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		if(aux == 1) count1++;
		else count2++;
	}

	vi resp;
	int currSum = 0, currPrime = 0;

	for(int i = 0; i < n; i++){
		int nextPrime = primes[currPrime];

		if(count1 && nextPrime - currSum == 1){
			currSum++;
			resp.pb(1);
			count1--;
			currPrime++;
		} else if(count2 && nextPrime - currSum == 2){
			currSum+=2;
			resp.pb(2);
			count2--;
			currPrime++;
		} else {
			if(count2){
				currSum+=2;
				resp.pb(2);
				count2--;
			} else if(count1){
				currSum++;
				resp.pb(1);
				count1--;
			}
		}
	}

	for(int i = 0; i < n; i++){
		printf("%d ", resp[i]);
	}
	cout <<  endl;


	
	return 0;
}