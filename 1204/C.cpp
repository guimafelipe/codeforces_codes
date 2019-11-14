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

vi shortPaths[100][100];

vi bfs(vvi &adjList, int ori, int des){
	queue<ii> fila;
	vi ans;
	vi parents(sz(adjList), -1);
	vector<bool> visited(sz(adjList), false);
	fila.push(mp(ori, -1));
	while(!fila.empty()){
		ii curr = fila.front();
		int u = curr.st;
		int par = curr.nd;
		// cout << "u = " << u << endl;
		fila.pop();
		parents[u] = par;
		visited[u] = true;
		if(u == des) break;
		FOR(k, 0, sz(adjList[u])){
			int v = adjList[u][k];
			if(visited[v]) continue;
			fila.push(mp(v,u));
			visited[v] = true;
		}
	}
	int u = des;
	while(u!=-1){
		ans.pb(u);
		u = parents[u];
	}
	reverse(all(ans));
	// cout << "Ans de " << ori << " ate " << des << " eh: ";
	// FOR(i, 0, sz(ans)){
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;
	return ans;

}

void getShortPaths(int n, vvi &adjList){
	FOR(i, 0, n){
		FOR(j, 0, n){
			if(i == j) continue;
			// cout << "i = " << i << ", j = " << j << endl;
			shortPaths[i][j] = bfs(adjList, i, j);
		}
	}
}

int main(){
	int n;
	cin >> n;
	string line;

	vvi adjList(n, vi());

	FOR(i, 0, n){
		cin >> line;
		FOR(j, 0, n){
			char c = line[j];
			if(c == '1'){
				adjList[i].pb(j);
			}
		}
	}

	int m;
	cin >> m;
	vi path;
	FOR(i, 0, m){
		int aux;
		scanf("%d", &aux);
		path.pb(--aux);
	}

	getShortPaths(n, adjList);

	vi ans;
	ans.pb(path[0]);
	FOR(i, 0, m-1){
		// cout << "analisando i = " << i << endl;
		int currNode = path[i];
		int nextNodeInd = -1;
		FOR(j, i+1, m){
			int next = path[j];
			if(next == currNode){
				break;
			}
			// cout << "	j = " << j<< endl;
			// cout <<"	tam path = " << sz(shortPaths[currNode][next]) << " e diff=  " << (j-i)+1 << endl;
			if(sz(shortPaths[currNode][next]) == (j-i) + 1) {
				nextNodeInd = j;
			} else {
				// cout << "break\n";
				break;
			}
		}
		if(nextNodeInd != -1){
			// cout << "entrou aqui\n";
			ans.pb(path[nextNodeInd]);
		} else {
			// cout << "BREAK\n";
			break;
		}
		i=nextNodeInd-1;
		// cout << "i = " << i << endl;
	}

	if(ans.back() != path.back()){
		ans.pb(path.back());
	}

	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)){
		printf("%d ", 1+ans[i]);
	}
	printf("\n");

	return 0;
}