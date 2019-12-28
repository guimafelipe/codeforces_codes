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

void solve(){
	ll n, m;
	cin >> n >> m;
	vll a(n);
	vector<bool> vis(n+1, false);

	FOR(i,0,n){
		cin >> a[i];	
	}

	ll i = 0, res = 0, jaforam = 0;
	while(m--){
		ll b;
		cin >> b;
		if(vis[b]){
			res++;
			jaforam++;
			continue;
		}
		while(a[i] != b){
			vis[a[i++]] = true;
		}
		res += 1 + 2*(i - jaforam++);
	}
	cout << res << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
