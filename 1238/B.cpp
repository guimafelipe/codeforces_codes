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
	int q;
	cin >> q;
	while(q--){
		int n, r;
		scanf("%d%d", &n, &r);
		vi xs;
		set<int> lidos;
		FOR(i,0,n){
			int x;
			scanf("%d", &x);
			if(lidos.count(x)) continue;
			lidos.insert(x);
			xs.pb(x);
		}
		sort(all(xs));
		n = sz(xs);
		vi rx(n);
		FOR(i,0,n){
			rx[i] = xs[i]/r;
			if(xs[i]%r) rx[i]++;
		}
		int tiros = 0;
		for(int i = n-1; i >=0; i--){
			if(rx[i] <= tiros) break;
			tiros++;
		}
		printf("%d\n", tiros);
	}
	return 0;
}