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
	ll n, m, q;
	cin >> n >> m >> q;
	vi cities(m, 0);
	FOR(i, 0, n){
		int a;
		scanf("%d", &a);
		cities[a-1]++;
	}
	vii queries;
	FOR(i, 0, q){
		int querieVal;
		scanf("%d", &querieVal);
		queries.pb(mp(querieVal, i));
	}
	vii citiesVals;
	FOR(i, 0, m){
		citiesVals.pb(mp(cities[i], i));
	}
	sort(all(queries));
	sort(all(citiesVals));

	int empatadas = 1;
	int proxima;
	FOR(i, 1, m){
		if(citiesVals[i].st == citiesVals[0].st) empatadas++;
		else{
			proxima = citiesVals[i].st;
			break;
		}
	}

	int currYear = n;
	FOR(currQ, 0, q){
		ii nextQpair = queries[currQ];
		int nextQ = nextQpair.st;
		int deltaYears = nextQ - currYear;
		FOR(i, 0, )
	}
	return 0;
}