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

int A[53][53] = {0};
int B[53][53] = {0};

bool checaQuadrado(int i, int j){
	if(A[i][j] == 0){
		return false;
	}
	if(A[i+1][j] == 0){
		return false;
	}
	if(A[i][j+1] == 0){
		return false;
	}
	if(A[i+1][j+1] == 0){
		return false;
	}
	return true;
}

void pintaB(ii coord){
	int i = coord.st, j = coord.nd;
	B[i][j] = 1;
	B[i+1][j] = 1;
	B[i][j+1] = 1;
	B[i+1][j+1] = 1;

}

int main(){
	int n, m;
	cin >> n >>  m;
	FOR(i, 0, n){
		FOR(j, 0, m){
			scanf("%d", &A[i][j]);
		}
	}
	vii solution;
	FOR(i, 0, n-1){
		FOR(j, 0, m-1){
			if(checaQuadrado(i, j)){
				solution.pb({i, j});
			}
		}
	}
	FOR(i, 0, sz(solution)){
		pintaB(solution[i]);
	}
	// 	printf("\n");
	// FOR(i, 0, n){
	// 	FOR(j, 0, m){
	// 		printf("%d ", A[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// 	printf("\n");
	// FOR(i, 0, n){
	// 	FOR(j, 0, m){
	// 		printf("%d ", B[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// 	printf("\n");
	FOR(i, 0, n){
		FOR(j, 0, m){
			if(A[i][j]!=B[i][j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << sz(solution) << endl;
	FOR(i, 0, sz(solution)){
		printf("%d %d\n", solution[i].st+1, solution[i].nd+1);
	}

	return 0;
}