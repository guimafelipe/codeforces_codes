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

int n;
char mat[110][110];
bool vis[110][110] = {false};

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, bool type){
	mat[x][y] = (type ? 'W' : 'B');
	vis[x][y] = true;
	FOR(i,0,8){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n){
			continue;
		}
		if(vis[nx][ny]) continue;
		dfs(nx, ny, !type);
	}
}

int main(){
	cin >> n;
	FOR(i,0,n){
		FOR(j,0,n){
			if(!vis[i][j]){
				dfs(i,j,false);
			}
		}
	}
	FOR(i,0,n){
		FOR(j,0,n){
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}