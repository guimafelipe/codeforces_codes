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
#define PI 3.14159265

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

#define MAXA  1<<20

ll xorCounter[MAXA][2] = {0};

int main(){
	int n;
	cin >> n;
	vll a(n+1);
	ll currXor = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);

	}
	a[0] = 0;
	for(int i = 0; i <= n; i++){
		currXor ^= a[i];
		xorCounter[currXor][i%2]++;
	}
	ll ans = 0;
	for(int i = 0; i < MAXA; i++){
		ans += (xorCounter[i][0]*(xorCounter[i][0]-1))/2;
		ans += (xorCounter[i][1]*(xorCounter[i][1]-1))/2;
	}
	cout << ans << endl;
	return 0;
}
