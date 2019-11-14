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

ll mat[1003][1003];

ll gsqrt(ll x){
	ll r = sqrt(x);
	if(r*r == x){
		return r;
	}
	r++;
	if(r*r == x){
		return r;
	}
	r-=2;
	if(r*r == x){
		return r;
	}
	return r;
}

int main(){
	int n;
	cin >> n;
	FOR(i,0,n){
		FOR(j,0,n){
			scanf("%lld", &mat[i][j]);
		}
	}

	ll a0 = mat[0][1]*mat[0][2]/mat[1][2];

	a0 = gsqrt(a0);
	vll as(n,0);
	as[0] = a0;

	FOR(i,1,n){
		as[i] = mat[0][i]/a0;
	}

	FOR(i,0,n){
		printf("%lld ", as[i]);
	}

	printf("\n");

	return 0;
}