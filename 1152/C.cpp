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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main(){
	ll a, b;
	cin >> a >> b;
	ll dif = abs(a-b);
	vi divisors;

	for(int i = 1; i <= sqrt(dif); i++){
		if(!(dif%i)){
			divisors.pb(i);
			divisors.pb(dif/i);
		}
	}

	ll bestAns = LONG_LONG_MAX;
	ll bestK = 0;
	for(int i = 0; i < sz(divisors); i++){
		ll k;
		ll q = divisors[i];
		if(!(a%q)){
			k = 0;
		} else {
			k = ((q-a)%q + q)%q;
		}
		ll currAns = lcm(a+k, b+k);  
		if(currAns < bestAns){
			bestK = k;
			bestAns = currAns;
		}
	}

	cout << bestK << endl;
	
	return 0;
}