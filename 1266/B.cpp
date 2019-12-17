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

bool solve(ll n){
	if(n/14ll == 0ll){
		return false;
	}
	ll resto = n%14ll;			
	if(resto < 7ll && resto > 0ll){
		return true;
	} else {
		return false;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		scanf("%lld", &n);
		if(solve(n)){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
