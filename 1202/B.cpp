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

string s;
int PD[10][10][10][10];

int calcula(int x, int y){
	if(x > y) swap(x,y);
	int r = 0;
	int ans = 0;
	FOR(i, 1, sz(s)){
		int nr = s[i]-'0';
		int &nans = PD[r][nr][x][y];
		if(nans == INF){
			return -1;
		} else if(nans != -2){
			ans+=nans;
			r = nr;
			continue;
		}

		nans = INF;
		for(int a = 0; a < 10; a++){
			for(int b = 0; b < 10; b++){
				if(a == 0 && b == 0) continue;
				if((r + a*x + b*y)%10 == nr){
					nans = min(nans, (a+b)-1);
				}
			}
		}	
		if(nans == INF) return -1;
		ans += nans;
		r = nr;
	}
	return ans;
}

int main(){
	cin >> s;
	FOR(i,0,10){
		FOR(j,0,10){
			FOR(k,0,10){
				FOR(l,0,10){
					PD[i][j][k][l] = -2;
				}
			}
		}
	}
	FOR(i, 0, 10){
		FOR(j,0,10){
			printf("%d ", calcula(i, j));
		}
		printf("\n");
	}
	return 0;
}