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

short mat[5200][5200];

bool teste(int r){
	int side = r;
	for(int i = 0; i < n; i+= side){
		for(int j = 0; j < n; j+=side){
			int flag = mat[i][j];
			for(int a = i; a < i+side; a++){
				for(int b = j; b < j+side; b++){
					if(mat[a][b]!=flag){
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n/4; j++){
			char dig;
			int chunk;
			scanf(" %c", &dig);
			if(dig >= '0' && dig <= '9'){
				chunk = dig -'0';
			} else {
				chunk = dig - 'A' + 10;
			}
			// cout << chunk << endl;
			for(int k = 4*j;  k < 4*j + 4; k++){
				int _k =  k - 4*j;
				mat[i][k] = ((1<<(3-_k))&chunk) ? 1 : 0;
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		printf("%d",  mat[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int resp = 1;

	for(int r = 2; r <= n; r++){
		if(n%r) continue;
		if(teste(r)) resp = r;
	}

	cout << resp << endl;
	return 0;
}