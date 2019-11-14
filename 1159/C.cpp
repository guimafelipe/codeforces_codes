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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int main(){
	int n, m;
	cin >> n >> m;
	vi bs(n, 0);
	vi gs(m, 0);
	for(int i = 0; i < n; i++){
		scanf("%lld", &bs[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%lld", &gs[i]);
	}
	sort(all(bs), greater<int>());
	sort(all(gs), greater<int>());
	
	for(int i = 0; i < m; i++){
		if(bs[0] > gs[i]){
			cout << -1 << endl;
			return 0;
		}
	}

	bool usar2 = false;
	if(bs[0] < gs[m-1]) usar2 = true;

	ll ans = 0;
	for(int i = 0; i < m; i++){
		ans+= gs[i];
	}

	if(!usar2){
		for(int i = 1; i < n; i++){
			ans += bs[i]*m;
		}
	} else {
		ans += bs[0];
		if(n == 1){
			cout << -1 << endl;
			return 0;
		}
		ans += (m-1)*bs[1];
		for(int i = 2; i < n; i++){
			ans += bs[i]*m;
		}
	}

	cout << ans << endl;

	return 0;
}