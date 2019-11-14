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

int n, m, p;
int s[10];
char grid[1002][1002];
int dist[1002][1002][9];
bool visited[1002][1002];

bool teste(int i, int j){
	if(i < 0  ||  j < 0 || i >=n || j >= m) return false;
	return grid[i][j] == '.';
}

void bfs(int a, int b, int pl){
	queue<ii> fila;
	fila.push(mp(a,b));
	while(!fila.empty()){
		ii curr = fila.front();
		fila.pop();
		int i = curr.st, j = curr.nd;
		if(teste(i+1, j) && dist[i+1][j][pl] > dist[i][j][pl]+1){
			dist[i+1][j][pl] = dist[i][j][pl]+1;
			fila.push(mp(i+1, j));
		}
		if(teste(i, j+1) && dist[i][j+1][pl] > dist[i][j][pl]+1){
			dist[i][j+1][pl] = dist[i][j][pl]+1;
			fila.push(mp(i, j+1));
		}
		if(teste(i-1, j) && dist[i-1][j][pl] > dist[i][j][pl]+1){
			dist[i-1][j][pl] = dist[i][j][pl]+1;
			fila.push(mp(i-1, j));
		}
		if(teste(i, j-1) && dist[i][j-1][pl] > dist[i][j][pl]+1){
			dist[i][j-1][pl] = dist[i][j][pl]+1;
			fila.push(mp(i, j-1));
		}
	}
}

void busca(int pl){
	memset(visited, 0, sizeof visited);
	for(int i = 0; i<n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] - '1' == pl){
				dist[i][j][pl] = 0;
				bfs(i, j, pl);
			}
		}
	}

}

int main(){
	cin >> n >> m >> p;
	for(int i = 0; i < p; i++){
		scanf("%d", &s[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &grid[i][j]);
			for(int pl = 0; pl < p; pl++){
				dist[i][j][pl] = INF;
			}
		}
	}


	for(int pl = 0; pl < p; pl++){
		busca(pl);
	}

	// for(int pl = 0; pl < p; pl++){
	// 	for(int i = 0; i < n; i++){
	// 		for(int j = 0; j < m; j++){
	// 			cout << dist[i][j][pl] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!teste(i, j)) continue;
			for(int pl = 0; pl < p; pl++){
				int oldDist = dist[i][j][pl];
				int newDist = oldDist/s[pl];
				if(oldDist%s[pl] != 0) newDist++;
				dist[i][j][pl] = newDist;
			}
		}
	}

	int counter[10] = {0};

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char curr =  grid[i][j];
			if(curr - '1' < 9 && curr-'1' >= 0){
				counter[curr-'1']++;
				continue;
			}
			int bestPl = -1;
			int currMin = INF;
			for(int pl = 0; pl < p; pl++){
				if(!teste(i, j)) continue;
				int currDist = dist[i][j][pl];
				if(currDist < currMin){
					bestPl = pl;
					currMin = currDist;
				}

			}
			if(bestPl != -1){
				counter[bestPl]++;
			}
		}
	}

	for(int i = 0; i < p; i++){
		cout << counter[i] << " ";
	}
	cout << endl;

	return 0;
}