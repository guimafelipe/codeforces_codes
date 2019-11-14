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

char tab[51][51];
int n;

int cost(int x1, int y1, int x2, int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	return dx*dx + dy*dy;
}

void bfs(int x, int y, char color){
	if(x <= 0 || x > n) return; 
	if(y <= 0 || y > n) return; 
	if(tab[x][y] != '0') return;
	tab[x][y] = color;
	bfs(x+1, y, color);
	bfs(x-1, y, color);
	bfs(x, y+1, color);
	bfs(x, y-1, color);
}

int main(){
	int x1, x2, y1, y2;
	scanf("%d %d %d %d %d ", &n, &x1, &y1, &x2, &y2);
	for(int i = 1;  i <= n; i++){
		for(int j = 1; j <= n; j++){
			char aux;
			scanf(" %c", &aux);
			tab[i][j] = aux;
		}
	}

	bfs(x1, y1, '2');

	if(tab[x2][y2] == '2'){
		cout << 0 << endl;
		return 0;
	}

	bfs(x2, y2, '3');

	vii firstLand;
	vii secondLand;

	for(int i = 1;  i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(tab[i][j] == '2'){
				firstLand.pb(mp(i,j));
			}
			if(tab[i][j] == '3'){
				secondLand.pb(mp(i,j));
			}
		}
	}

	int ans = 2*50*50 + 100;

	for(int i = 0; i < sz(firstLand); i++){
		for(int j = 0; j < sz(secondLand); j++){
			ii x = firstLand[i];
			ii y = secondLand[j];
			ans = min(ans, cost(x.st, x.nd, y.st, y.nd));
		}
	}

	cout << ans << endl;

	return 0;
}