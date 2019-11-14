#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MAXN 2010
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


int n,k;
int tab[MAXN][MAXN];
int tab2[MAXN][MAXN];

int prel[MAXN][MAXN], prec[MAXN][MAXN];

set<int> fullLines, fullCols;

int sumL(int k,int i){
	if(i == -1)return 0;
	return prel[k][i];
}

int getRangeL(int k ,int i, int j){
	return sumL(k,j) - sumL(k, i-1);
}

vvi alg(bool inv){
	FOR(i,0,n){
		prel[i][0] = tab[i][0];
		FOR(j, 1, n){
			prel[i][j] = prel[i][j-1]+tab[i][j];
		}
	}

	vvi linhas(n,vi(n-k+1,0));
	FOR(i,0,n){
		FOR(j, 0, n-k+1){
			int r = getRangeL(i, j, j+k-1);
			if(r == getRangeL(i,0,n-1)){
				linhas[i][j] = 1;
			}
		}
	}

	// FOR(i,0,n){
	// 	FOR(j,0,n-k+1){
	// 		cout << linhas[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	vvi bestL(n-k+1, vi(n-k+1,0));

	FOR(i,0,n-k+1){
		int sum = 0;
		FOR(j, 0, k){
			sum+=linhas[j][i];
		}
		int j = 0;
		while(j < n-k+1){
			bestL[i][j] = sum;
			sum-=linhas[j][i];
			if(j+k < n) sum+=linhas[j+k][i];
			j++;
		}
	}

	// FOR(i,0,n-k+1){
	// 	FOR(j,0,n-k+1){
	// 		cout <<  bestL[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	return bestL;
}

int getSum(int i, vi &pre){
	if(i < 0) return 0;
	return pre[i];
}

int getRange(int i, int j, vi& pre){
	return getSum(j, pre)-getSum(i-1,pre);
}

int main(){
	scanf("%d%d", &n, &k);
	char c;
	FOR(i,0,n){
		FOR(j,0,n){
			scanf(" %c", &c);
			if(c == 'B'){
				tab[i][j]=1;
			}
		}
	}

	vvi lin, col;
	lin = alg(false);


	vi fullLines(n,0);
	FOR(i,0,n){
		FOR(j,0,n+1){
			if(j == n){
				fullLines[i]++;
			}
			if(tab[i][j] == 1){
				break;
			}
		}
	}

	FOR(i,0,n){
		FOR(j,0,n){
			tab2[i][j] = tab[j][i];
		}
	}

	FOR(i,0,n){
		FOR(j,0,n){
			tab[i][j] = tab2[i][j];
		}
	}

	vi fullCols(n,0);
	FOR(i,0,n){
		FOR(j,0,n+1){
			if(j == n){
				fullCols[i]++;
			}
			if(tab[i][j] == 1){
				break;
			}
		}
	}

	vi fullLinesPre(n,0);
	fullLinesPre[0] = fullLines[0];
	FOR(i,1,n){
		fullLinesPre[i] = fullLines[i]+fullLinesPre[i-1];
	}

	vi fullColsPre(n,0);
	fullColsPre[0] = fullCols[0];
	FOR(i,1,n){
		fullColsPre[i] = fullCols[i]+fullColsPre[i-1];
	}

	col = alg(true);

	// FOR(i,0,n){
	// 	cout << fullLines[i] << " ";
	// }
	// cout << endl;
	// FOR(i,0,n){
	// 	cout << fullLinesPre[i] << " ";
	// }
	// cout << endl;

	// FOR(i,0,n){
	// 	cout << fullCols[i] << " ";
	// }
	// cout << endl;
	// FOR(i,0,n){
	// 	cout << fullColsPre[i] << " ";
	// }
	// cout << endl;

	int bestSum = 0;
	FOR(i,0,n-k+1){
		FOR(j,0,n-k+1){
			int sum = lin[i][j]+col[j][i];
			sum += getRange(0,i-1,fullLinesPre);
			sum += getRange(i+k,n-1,fullLinesPre);
			sum += getRange(0,j-1,fullColsPre);
			sum += getRange(j+k,n-1,fullColsPre);
			bestSum = max(sum, bestSum);
		}
	}
	cout << bestSum << endl;
	return 0;
}