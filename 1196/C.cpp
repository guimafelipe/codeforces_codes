#include <bits/stdc++.h>

using namespace std;

#define INF 100000
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

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
	int q;
	cin >> q;
	while(q--){
		int n;
		scanf("%d", &n);
		int maxx = INF, maxy = INF, minx = -INF, miny = -INF;
		int x, y;
		FOR(j,0,n){
			scanf("%d%d", &x, &y);
			FOR(i,0,4){
				int f;
				scanf("%d", &f);
				if(f == 0){
					if(i == 0){
						minx = max(x,minx);
					}
					if(i == 1){
						maxy = min(y, maxy);
					}
					if(i == 2){
						maxx = min(x, maxx);
					}
					if(i == 3){
						miny = max(y, miny);
					}
				}
			}
		}
		if(minx > maxx || miny > maxy){
			cout << "0\n";
		} else {
			printf("1 %d %d\n", maxx, maxy);
		}
	}
	return 0;
}