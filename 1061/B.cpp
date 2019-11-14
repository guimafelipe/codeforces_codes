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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

ll a[1000003];

int main(){
	int n, m;
	cin >> n >> m;
	ll lview = 0, ans = 0;
	ll ini = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		ini += a[i];
		lview = max(lview, a[i]);
	}
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	a[n] = 0;
	sort(a, a+n+1);
	for(int i = n; i > 0; i--){
		// cout << a[i] << " ";
		ans += max(1LL, a[i]-a[i-1]);
		if(a[i] <= a[i-1]){ 
			a[i-1] = max(a[i]-1, 1LL);
		}
	}

	cout << ini - ans << endl;

	return 0;
}