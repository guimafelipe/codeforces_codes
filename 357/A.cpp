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
	int m;
	vll c;
	scanf("%d", &m);
	ll sum = 0;
	FOR(i,0,m){
		ll aux;
		scanf("%lld", &aux);	
		c.pb(aux);
		sum+=aux;
	}
	ll x, y;
	cin >> x >> y;
	ll curr = 0;
	FOR(i,0,m){
		curr+=c[i];
		if(curr >= x && curr <= y &&
			sum-curr >= x && sum-curr <= y){
			cout << i+2 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
