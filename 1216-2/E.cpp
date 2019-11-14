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

ll pow10[19];

ll calcCycleTam(ll cycle){
	ll tam = 0;
	ll mult = 1;
	while(cycle > 9LL*pow10[mult-1]){
		tam+=mult*9LL*pow10[mult-1];
		cycle -= 9LL*pow10[mult-1];
		mult++;
	}
	return tam + mult*cycle;
}

int main(){
	pow10[0] = 1;
	FOR(i,1,19){
		pow10[i] = 10LL*pow10[i-1];
	}

	int q;
	cin >> q;
	vi solutions(q);
	vii queries(q);
	FOR(i,0,q){
		int qu;
		scanf("%d", &qu);
		queries.pb(mp(qu, i));
	}
	sort(all(queries));

	ll k = 1, ciclo = 1;
	FOR(i,0,q){
		ii query = queries[i];
		ll nextCycleTam = calcCycleTam(cycle);
		while(query.st > k + nextCycleTam){
			k += nextCycleTam;
			nextCycleTam = calcCycleTam(++cycle);
		}
		for(ll i = 0; )
	}

	return 0;
}