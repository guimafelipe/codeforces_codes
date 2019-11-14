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

	int n;
	cin >> n;
	vi ar(n, 0);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}

	int k = INF;
	for(int i = 0; i < n; i++){
		int curr = ar[i];
		int d = max(abs(i-0), abs((n-1)-i));
		k = min(k, curr/d);
		// for(int j = i+1; j < n; j++){
		// 	int q = min(ar[i], ar[j]);
		// 	int d = abs(i-j);
		// 	k = min(k, q/d);
		// }
	}
	
	cout << k << endl;
	return 0;
}