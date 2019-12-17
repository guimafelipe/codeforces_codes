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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
	return a / gcd(a,b) * b;
}

ll _sieve_size;
bitset<10000010> bs;
vll primes;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
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
	int r, c;
	scanf("%d %d", &r, &c);
	sieve(10000ll);

	if(r == 1 && c == 1){
		cout << 0 << endl;
		return 0;
	}
	
	bool trans = false;
	if((r < c && r != 1) || c == 1){
		swap(r,c);
		trans = true;
	}
	vvi mat(r, vi(c, 0));

	set<int> pused;

	for(int i = 0; i < c; i++){
		mat[0][i] = i+2;
		pused.insert(mat[0][i]);
	}
	
	int next = 2;
	for(int i = 1; i < r; i++){
		while(pused.count(next)){
			next++;	
		}
		for(int j = 0; j < c; j++){
			mat[i][j] = lcm(next, mat[0][j]);
		}
		next++;
	}

	if(trans){
		for(int j = 0; j < c; j++){
			for(int i = 0; i < r; i++){
				printf("%lld ", mat[i][j]);
			}
			printf("\n");
		}
	} else {
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("%lld ", mat[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
