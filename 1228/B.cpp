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

int mat[1010][1010] = {0};

ll exp2(int a){
	if(a == 0) return 1;
	ll ans = exp2(a/2);
	ans *= ans;
	ans%=MOD;
	if(a%2){
		ans <<= 1;
		ans %=MOD;
	}
	return ans;
}

int main(){
	int h, w;
	cin >> h >> w;
	FOR(i,0,h){
		int r;
		scanf("%d", &r);
		FOR(j,0,r){
			mat[i][j] = 1;
		}
		if(r < w) mat[i][r] = 2;
	}
	FOR(j,0,w){
		int c;
		scanf("%d", &c);
		FOR(i,0,c){
			if(mat[i][j] == 2){
				cout << 0 << endl;
				return 0;
			}
			mat[i][j] = 1;
		}
		if(c < h){
			if(mat[c][j] == 1){
				cout << 0 << endl;
				return 0;
			}
			mat[c][j] = 2;
		}
	}
	int countDisp = 0;
	FOR(i,0,h){
		FOR(j,0,w){
			if(!mat[i][j]) countDisp++;
		}
	}
	ll ans = exp2(countDisp);
	cout << ans << endl;
	return 0;
}