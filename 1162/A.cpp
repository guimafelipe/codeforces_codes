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

int main(){
	int n, h, m;
	cin >> n >> h >> m;
	vi houses(n, h);
	for(int i = 0; i <  m; i++){
		int l, r, mh;
		cin >> l >> r >> mh;
		for(int j = l; j <= r; j++){
			houses[j-1] = min(houses[j-1], mh);
		}
	}
	ll ans = 0LL;
	for(int i = 0; i < n; i++){
		ans+= houses[i]*houses[i];
	}
	cout << ans << endl;
	return 0;
}