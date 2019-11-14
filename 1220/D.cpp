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

int main(){
	int n;
	cin >> n;
	vll b;
	b.reserve(n);
	map<ll, ll> counter;
	FOR(i,0,n){
		ll a;
		scanf("%lld", &a);
		b.pb(a);
		ll g = (a&-a);
		if(counter.find(g) == counter.end()){
			counter[g]=0;
		}
		counter[g]++;
	}

	map<ll, ll>::iterator it;

	ll bestg = 1, bestcount = 0;

	for(it = counter.begin(); it != counter.end(); it++){
		if(it->nd >= bestcount){
			bestg = it->st;
			bestcount = it->nd;
		}
	}
	
	cout << n - bestcount << endl;
	FOR(i,0,n){
		ll a = b[i];
		ll g = (a&-a);
		if(g!=bestg){
			printf("%lld ", a);
		}
	}
	printf("\n");

	return 0;
}