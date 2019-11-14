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
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	vvi mat(h, vi(w,0));

	FOR(i,0,h){
		FOR(j,i,i+a){
			mat[i][j%w] = 1;
		}
	}
	int count1;
	bool deuruim = false;
	FOR(j,0,w){
		count1 = 0;
		FOR(i,0,h){
			if(mat[i][j] == 1){
				count1++;
			}
		}
		if(count1 != b && h - count1 != b){
			deuruim = true;
		}
	}
	if(!deuruim){
		FOR(i,0,h){
			FOR(j,0,w){
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
		return 0;
	}

	FOR(i,0,h){
		FOR(j,0,w){
			mat[i][j] = 0;
		}
	}

	FOR(j,0,w){
		FOR(i, j, j+b){
			mat[i%h][j] = 1;
		}
	}

	deuruim = false;
	FOR(i,0,h){
		count1 = 0;
		FOR(j,0,w){
			if(mat[i][j] == 1){
				count1++;
			}
		}
		if(count1 != a && w - count1 != a){
			// cout << count1 << endl;
			deuruim = true;
		}
	}
	if(!deuruim){
		FOR(i,0,h){
			FOR(j,0,w){
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
		return 0;
	}

	printf("-1\n");
	return 0;
}