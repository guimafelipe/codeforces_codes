#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000
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
typedef pair<ll,ll> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int main(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	FOR(i,0,n){
		int aux;
		scanf("%d", &aux);
		a[i]=aux;
	}
	sort(all(a));
	vii c;
	c.pb(mp(a[n/2],1));
	FOR(i, n/2+1, n){
		if(a[i] == c.back().st){
			c.back().nd++;
		} else {
			c.pb(mp(a[i],1));
		}
	}
	c.pb(mp(INF,1));

	int i = 0;
	while(true){
		ii curr = c[i];
		ll val = curr.st, qnt = curr.nd;
		ll lim = c[i+1].st;
		ll delta = (lim-val)*qnt;
		if(delta <= k){
			c[i+1].nd += qnt;
			k-=delta;
			i++;
		} else {
			int res = val;
			res += (k/qnt);
			cout << res << endl;
			return 0;
		}
	}

	return 0;
}