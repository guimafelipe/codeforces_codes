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

int A[50][50], B[50][50];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &A[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &B[i][j]);
		}
	}

	for(int i = 0;  i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] > B[i][j]){
				int aux = B[i][j];
				B[i][j] = A[i][j];
				A[i][j] = aux;
			}
		}
	}
	bool deuRuim = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m-1; j++){
			if(A[i][j] >= A[i][j+1]) deuRuim=true;
			if(B[i][j] >= B[i][j+1]) deuRuim=true;
		}
	}
	
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] >= A[i+1][j]) deuRuim=true;
			if(B[i][j] >= B[i+1][j]) deuRuim=true;
		}
	}

	if(deuRuim){
		cout << "Impossible\n";
	} else {
		cout << "Possible\n";
	}
	
	return 0;
}