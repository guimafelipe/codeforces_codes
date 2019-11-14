#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 10000000000000000
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

string road;
ll n, a, b;
ll PD[200005][2];

ll pd(int i, int isUp){
	int h = road[i] == '1'? 1 : 0;
	ll &ans = PD[i][isUp];
	if(ans != -1){
		return ans;
	}
	ans = INFLL;
	if(i == sz(road)-1){
		if(isUp){
			return ans = 2*a + b;
		} else {
			return ans = a+b;
		}
	}
	if(h == 0){
		if(isUp){
			ans = min(ans, pd(i+1, 1) + a + 2*b);
			ans = min(ans, pd(i+1, 0) + 2*a + b);
		}  else {
			ans = min(ans, pd(i+1, 1) + 2*a + 2*b);
			ans = min(ans, pd(i+1, 0) + a + b);
		}
	} else {
		if(!isUp){
			ans = INFLL;
		} else {
			ans = min(ans, pd(i+1, 1) + a + 2*b);
		}
	}
	return ans;
}

int main(){
	int T;
	cin >> T;
	FOR(t, 0, T){
		scanf("%lld %lld %lld", &n, &a, &b);
		cin >> road;
		memset(PD, -1, sizeof(PD));
		printf("%lld\n", pd(0, 0) + b);
	}
	return 0;
}