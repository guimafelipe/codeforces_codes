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

ll sizeOfInt(ll a, ll b, ll x, ll y){
	ll start = max(a, x);
	ll end = min(b, y);
	return max(0LL, end-start + 1LL);
}

int main(){
	int n;
	cin >> n;
	ll draws = 1;
	ll a = 0, b = 0;
	for(int i = 0; i < n; i++){
		ll newA, newB;
		scanf("%lld %lld", &newA, &newB);
		draws += sizeOfInt(a, newA, b, newB);
		if(a == b) draws--;
		a = newA;
		b = newB;
	}
	cout << draws << endl;
	return 0;
}