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

int n;
int tab[55][55];

bool checkFreeCell(int i, int j){
	if(i < 0 || i >= n) return false;
	if(j < 0 || j >= n) return false;
	if(tab[i][j] == 1) return false;
	return true;
}

bool tentaCompletar(int i, int j){
	if(!checkFreeCell(i+1, j)) return false;
	if(!checkFreeCell(i+2, j)) return false;
	if(!checkFreeCell(i+1, j-1)) return false;
	if(!checkFreeCell(i+1, j+1)) return false;
	return true;
}

void paint(int i, int j){
	tab[i][j] = 1;
	tab[i+1][j] = 1;
	tab[i+2][j] = 1;
	tab[i+1][j-1] = 1;
	tab[i+1][j+1] = 1;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			scanf(" %c", &c);
			if(c == '.') tab[i][j] = 0;
			else tab[i][j] = 1;
		}
	}

	int deuRuim = false;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(tab[i][j] == 0){
				if(!tentaCompletar(i, j)){
					cout << "NO\n";
					return 0;
				}
				paint(i, j);
			}
		}
	}
	cout << "YES\n";
	
	return 0;
}