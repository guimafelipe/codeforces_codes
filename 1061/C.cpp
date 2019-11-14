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


vi a;

int PD[10002][10002];


int pd(int ind, int curr){
	if(PD[ind][curr] != -1){
		return PD[ind][curr];
	}
	if(curr == sz(a)) return 1;
	int ans = 0;
	if(a[curr] % ind){
		ans += pd(ind, curr+1);
		ans = ans % MOD;
	} else {
		ans += pd(ind, curr+1);
		ans = ans % MOD;
		ans += pd(ind+1, curr+1);
		ans = ans % MOD;
	}
	return PD[ind][curr] = ans;
}

int main(){
	int n;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	memset(PD, -1, sizeof(PD));
	int ans;
	ans = pd(1, 0);
	cout << ans-1 << endl;
	return 0;
}