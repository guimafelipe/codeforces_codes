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
typedef pair<ll,ll> pll;

ll n, m, q,g;
ll tn, t_m;

ll getQ(pll a){
	a.nd--;
	if(a.st == 1){
		return a.nd/tn;
	} else {
		return a.nd/t_m;
	}
}

int main(){
	scanf("%lld%lld%lld", &n, &m, &q);
	g = __gcd(n,m);
	tn = n/g, t_m = m/g;
	while(q--){
		ll sx,sy, ex, ey;
		scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
		pll s = mp(sx, sy);
		pll e = mp(ex, ey);
		ll qs = getQ(s), qe = getQ(e);
		if(qs == qe){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}