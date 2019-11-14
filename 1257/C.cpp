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

int solve(vi &arr){
	int n = sz(arr);
	if(n < 2) return -1;
	vvi pos(n, vi());
	FOR(i,0,n){
		pos[arr[i]].pb(i);
	}
	int ans = -1;
	FOR(i,0,n){
		int np = sz(pos[i]);
		if(np <= 1) continue;
		vi cpos = pos[i];
		FOR(j, 1, np){
			if(ans == -1){
				ans = 1 + cpos[j] - cpos[j-1];
			} else {
				ans = min(ans, 1 + cpos[j] - cpos[j-1]);
			}
		}
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		scanf("%d", &n);
		vi arr;
		FOR(i,0,n){
			int aux;
			scanf("%d", &aux);
			arr.pb(aux-1);
		}
		cout << solve(arr) << endl;
	}
	return 0;
}
