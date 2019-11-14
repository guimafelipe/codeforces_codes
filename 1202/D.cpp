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

ll sqrtll(ll n){
	ll tent = sqrt(n);
	if(tent*tent == n) return tent;
	tent++;
	if(tent*tent == n) return tent;
	tent-=2;
	if(tent*tent == n) return tent;
	return -1;
}

void print1(ll n){
	printf("133");
	FOR(i,0,n){
		printf("7");
	}
	printf("\n");
}

int main(){
	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		ll x = 0;
		while(x*(x+1)/2 <= n){
			x++;
		}
		ll dec = n-(x*(x-1))/2;
		printf("133");
		FOR(i,0,dec){
			printf("7");
		}
		FOR(i,2,x){
			printf("3");
		}
		printf("7\n");
	}
	return 0;
}