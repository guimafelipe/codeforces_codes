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
	ll n;
	vi a;
	scanf("%lld", &n);
	a.reserve(n);
	FOR(i,0,n){
		int aux;
		scanf("%d", &aux);
		if(aux < 0){
			aux = 1;
		} else {
			aux = 0;
		}
		a.pb(aux);
	}

	vi pre;
	pre.pb(a[0]);
	FOR(i,1,n){
		pre.pb(a[i]+pre[i-1]);
	}

	ll negs = 0, pos = 1;
	FOR(i,0,n){
		if(pre[i]%2){
			negs++;
		} else {
			pos++;
		}
	}
	printf("%lld %lld\n", negs*pos, (n*(n-1))/2 + n - negs*pos);

	return 0;
}