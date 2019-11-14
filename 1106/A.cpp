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

int m;

char mat[500][500];

int main(){
	cin >> m;
	for(int i  = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &mat[i][j]);
		}
	}

	int crosses = 0;

	for(int i = 1; i < m-1; i++){
		for(int j = 1; j < m-1; j++){
			char c = mat[i][j];
			if(c!='X') continue;
			if(c == mat[i+1][j+1] &&
				c == mat[i-1][j+1] &&
				c == mat[i+1][j-1] &&
				c == mat[i-1][j-1]) {
				crosses++;
			}

		}
	}
	cout << crosses << endl;
	
	return 0;
}