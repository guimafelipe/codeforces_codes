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

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi arr;
		for(int i = 0; i <  n; i++){
			int aux;
			cin >> aux;
			arr.pb(aux);
		}
		sort(all(arr));
		reverse(all(arr));
		int minh = INF;
		int ans = 0;
		for(int i = 0; i <  n; i++){
			minh = min(minh, arr[i]);	
			if(minh >= i+1){
				ans = max(ans, min(minh, i+1));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
