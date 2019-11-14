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

vi pSum;
int n, q;
string cake;

int main(){
	cin >> n >> q;	
	cin >> cake;	
	// cout << cake;
	pSum.resize(sz(cake)+1); //1 indexed
	pSum[0] = 0;
	for(int i = 1; i <= sz(cake); i++){
		pSum[i] = pSum[i-1] + cake[i-1] - '0';	
	}

	// for(int i = 0; i < sz(pSum); i++){
	// 	cout << pSum[i] << " ";
	// }
	// cout << endl;

	int l, r;
	int tot, nUns;
	for(int i = 0; i < q; i++){
		scanf("%d %d", &l, &r);
		tot = r-l+1;
		nUns = pSum[r] - pSum[l-1];
		int nZeros = tot - nUns;
		int ans = 0;
		int currAns = 1;
		for(int j = 0; j < nUns; j++){
			currAns = currAns << 1;
			currAns = currAns % MOD;
		}
		ans = currAns;
		ans--;
		ans += MOD;
		ans = ans % MOD;
		currAns = 1;
		for(int j = 0; j < nZeros; j++){
			currAns = currAns << 1;
			currAns = currAns % MOD;
		}
		currAns--;
		currAns += MOD;
		currAns = currAns % MOD;
		ans += ans*currAns;
		ans = ans % MOD;
		// printf("nzeros = %d, nuns = %d\n", nZeros, nUns);
		printf("%d\n", ans);
	}
	return 0;
}

/*
	1 + 2 + 4 + 8 + 16 = 2^(nUns) - 1
	ans + 2*ans + 4*ans + ... = ans * (2^(nZeros) - 1) 

*/