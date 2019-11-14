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

int n, m;	
int city[1000][1000];

int getPosition(vector<int> &a, int target){
	int tam = sz(a);

	int l = 0, r = tam-1;
	while(l < r){
		int mid = (l+r)/2;
		if(a[mid] < target){
			l = mid+1;
		} else if(a[mid] > target){
			r = mid-1;
		} else if(a[mid] == target){
			return mid;
		}
	}
	return l;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j  < m; j++){
			scanf("%d", &city[i][j]);
		}
	}

	vector<vector<int> > lines;
	vector<vector<int> > columns;

	lines.resize(n, vector<int>());
	columns.resize(m, vector<int>());

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			lines[i].pb(city[i][j]);
			columns[j].pb(city[i][j]);
		}
	}


	for(int i = 0; i < n; i++){
		sort(all(lines[i]));
	}

	for(int j = 0; j < m; j++){
		sort(all(columns[j]));
	}

	for(int i = 0; i < n; i++){
		vector<int> newLine;
		newLine.pb(lines[i][0]);
		for(int k = 1; k < sz(lines[i]); k++){
			if(lines[i][k] != newLine.back()){
				newLine.pb(lines[i][k]);
			}
		}
		lines[i] = newLine;
	}

	for(int j = 0; j < m; j++){
		vector<int> newColumn;
		newColumn.pb(columns[j][0]);
		for(int k = 1; k < sz(columns[j]); k++){
			if(columns[j][k] != newColumn.back()){
				newColumn.pb(columns[j][k]);
			}
		}
		columns[j] = newColumn;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int curr = city[i][j];
			int positionLines, positionColumns;
			int afterLines, afterColumns;
			int result = 1;
			positionLines = getPosition(lines[i], curr);
			positionColumns = getPosition(columns[j], curr);
			afterLines = sz(lines[i])-positionLines-1;
			afterColumns = sz(columns[j])-positionColumns-1;
			result += max(positionColumns, positionLines);
			result += max(afterColumns, afterLines);
			printf("%d ", result);
		}
		printf("\n");
	}

	return 0;
}