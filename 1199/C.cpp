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
#define sz(v) ll(v.size())
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
typedef vector<ii> vpll;

ll pow2(ll k){
	if(k > 61){
		return INFLL;
	}
	return 1LL << k;
}

ll get(int i, vll &pre){
	if(i < 0) return 0;
	return pre[i];
}

ll getRange(int i, int j, vll &pre){
	return get(j-1, pre) - get(i-1, pre);
}

int main(){
	ll n, I;
	cin >> n >> I;
	vll a; a.reserve(n);
	FOR(i,0,n){
		ll aux;
		scanf("%lld", &aux);
		a.pb(aux);
	}
	ll maxDist = pow2((8LL*I)/n);
	sort(all(a));
	vpll b;
	b.pb(mp(a[0],1));
	FOR(i,1,n){
		if(b.back().st == a[i]){
			b.back().nd++;
		} else {
			b.pb(mp(a[i], 1));
		}
	}

	ll toChange = sz(b) - maxDist;
	// cout << "toChange: "  << toChange << endl;

	int p = 0, q = sz(b)-1;
	ll ans = INFLL;
	// FOR(i,0,sz(b)){
	// 	cout << b[i].nd << " ";
	// }
	// cout << endl;

	vll pre;
	pre.pb(b[0].nd);

	FOR(i,1,sz(b)){
		pre.pb(b[i].nd+pre.back());
	}

	// FOR(i,0,sz(b)){
	// 	cout << pre[i] << " ";
	// }
	// cout << endl;

	if(toChange < 0){
		cout << 0 << endl;
		return 0;
	}
	FOR(k,0, toChange+1){
		ans = min(ans, getRange(0,k,pre) + getRange(sz(pre)-(toChange - k), sz(pre), pre));
	}

	printf("%lld\n", ans);

	return 0;
}