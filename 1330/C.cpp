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
	ll n, m;
	scanf("%lld %lld", &n, &m);
	vi l;
	FOR(i,0,m){
		int aux;
		scanf("%d", &aux);
		l.pb(aux);
	}
	
	vi sol;
	ll limInf = 0;
	ll sum = 0;
	for(ll i = 0; i < m; i++){
		ll curr = l[i];
		sum += curr;
		if(curr + limInf > n){
			cout << -1 << endl;
			return 0;
		}
		sol.pb(limInf++);
	}

	if(sum < n){
		cout << -1 << endl;
		return 0;
	}

	if(sol[m-1] + l[m-1] < n){
		sol[m-1] = n - l[m-1];
	}

	for(int i = m-2; i >= 0; i--){
		if(sol[i] + l[i] < sol[i+1]){
			sol[i] = sol[i+1] - l[i];
		} else {
			break;
		}
	}

	for(int i = 0; i < m; i++){
		printf("%d ", sol[i] + 1);
	}
	printf("\n");

	return 0;
}

