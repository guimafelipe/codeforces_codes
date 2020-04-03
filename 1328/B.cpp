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

ll sumn(ll n){
	return (n*(n+1))/2;
}

string solvre(ll n, ll k){
	ll lim = 0;
	while(k > sumn(lim)){
		lim++;
	}
	ll r = sumn(lim) - k;

	/*
	cout << "lim = " << lim <<  endl;
	cout << "r   = " << r <<  endl;
	*/

	ll pos1 = n - lim - 1;
	ll pos2 = pos1 + r + 1;

	/*
	cout << "p1  = " << pos1 <<  endl;
	cout << "p2  = " << pos2 <<  endl;
	*/

	string ans = "";
	FOR(i,0,n){
		ans.pb('a');
	}
	ans[pos1] = 'b';
	ans[pos2] = 'b';
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		scanf("%lld %lld", &n, &k);
		cout << solvre(n, k) << endl;
	}
	return 0;
}
