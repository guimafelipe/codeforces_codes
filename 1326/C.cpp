#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 998244353
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
	int n, k;
	scanf("%d %d", &n, &k);

	vll p;
	FOR(i,0,n){
		ll aux;
		scanf("%lld", &aux);
		p.pb(aux);
	}

	ll soma = 0;
	vll mark;

	FOR(i,0,n){
		if(p[i] > n - k){
			soma += p[i];
			mark.pb((ll)i);
		}
	}

	ll qnt = 1;

	for(int i = 0; i < sz(mark) - 1; i++){
		qnt *= (mark[i+1] - mark[i]);
		qnt %= MOD;
	}

	printf("%lld %lld\n", soma, qnt);

	return 0;
}
