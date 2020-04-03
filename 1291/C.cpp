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

int solvre(int n, int m, int k, vi& arr){
	int ans = -INF;
	for(int x = 0; x <= k; x++){
		int cans = INF;
		for(int y = 0; y <= (m-1)-k; y++){
			cans = min(cans, max(arr[x+y],
					arr[(n-1)-(k-x)-(((m-1)-k)-y)]));
		}
		ans = max(cans, ans);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		vi arr;
		k = min(k, m-1);
		FOR(i,0,n){
			int aux;
			scanf("%d", &aux);
			arr.pb(aux);
		}
		cout << solvre(n, m, k, arr) << endl;
	}
	return 0;
}
