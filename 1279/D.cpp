#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

#define MOD 998244353

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invMod(ll a){
	ll x, y;
	ll g = gcd(a, MOD, x, y);
	x = (x % MOD + MOD) % MOD;
	return x;
}

pair<ll, ll> calcProb(vll &denos){
	ll g = 1;
	for(ll d : denos){
		g = __lcm(g, d);
	}
	ll num = 0, den = g;
	for(ll d : denos){
		num += g/d;
	}
	ll fing = __gcd(num, den);
	return mp(num/fing, den/fing);
}

int main(){
	ll n;
	cin >> n;
	vvi dens(1001000, vi());
	map<ll,ll> presfreq;
	FOR(_n, 0, n){
		ll k;
		scanf("%d", &k);
		FOR(_k,0,k){
			ll item;
			scanf("%d", &item);
			dens[item].pb(n*k);
			presfreq[item]++;
		}
	}
	
	map<ll, pair<ll, ll>> itemProb;
	for(int item = 0; item < sz(dens); item++){
		if(sz(dens[item]) > 0){
			itemProb[item] = calcProb(dens[item]);
		}
	}

	ll num = 0, den = totPres*n;
	for(auto ent : presfreq){
		ll item = ent.st, freq = ent.nd;
	}
	cout << num << " " << den << endl;
	ll ans = (num*invMod(den))%MOD;
	cout << ans << endl;
	return 0;
}
