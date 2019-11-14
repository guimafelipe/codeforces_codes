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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<bool> pal2(n,false), pal3(n,false);
	FOR(i,0,n-1){
		if(s[i] == s[i+1]) pal2[i] = true;
	}
	FOR(i,0,n-2){
		if(s[i] == s[i+2]) pal3[i] = true;
	}
	vll fin(n, 0);
	FOR(i,0,n){
		if(pal2[i]){
			if(i==0){
				fin[i+1]++;
			} else{
				fin[i+1] += fin[i-1]+1;
			}
		}
		if(pal3[i]){
			if(i==0){
				fin[i+2]++;
			} else{
				fin[i+2] += fin[i-1]+1;
			}
		}
	}
	ll ans = 0;
	for(ll a : fin){
		// printf("%lld ",a);
		ans+=a;
	}
	// printf("\n");
	cout << ans << endl;
	return 0;
}