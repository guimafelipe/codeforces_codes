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

bool c[5005];
bool a[5005];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		char aux;
		scanf(" %c", &aux);
		if(aux == '1'){
			c[i] = true;
		} else if(aux == '0'){
			c[i] == false;
		}
	}
	for(int i = 0; i < n; i++){
		char aux;
		scanf(" %c", &aux);
		if(aux == '1'){
			a[i] = true;
		} else if(aux == '0'){
			a[i] == false;
		}
	}

	int na, nb, nc, nd;
	na = nb = nc = nd = 0;

	for(int i = 0; i < n; i++){
		if(a[i] == 0 && c[i] == 0) na++;
		if(a[i] == 1 && c[i] == 0) nb++;
		if(a[i] == 0 && c[i] == 1) nc++;
		if(a[i] == 1 && c[i] == 1) nd++;
	}

	// a + b + c + d == n/2;
	// c + d == nb - b + nd -d
	// c + b + 2d = nb + nd

	for(int d = 0; d <= nd; d++){
		for(int b = 0; b <= nb; b++){
			int C = nb + nd - (2*d + b);
			int A = n/2 - (b + C + d);
			if(A >= 0 && A <= na && C >= 0 && C <= nc){
				for(int i = 0; i < n; i++){
					if(a[i] == 0 && c[i] == 0 && A > 0){
						printf("%d ", i+1);
						A--;
					}
					if(a[i] == 1 && c[i] == 0 && b > 0){ 
						printf("%d ", i+1);
						b--;
					}
					if(a[i] == 0 && c[i] == 1 && C > 0){
						printf("%d ", i+1);
						C--;
					}
					if(a[i] == 1 && c[i] == 1 && d >  0){
						printf("%d ", i+1);
						d--;
					}
				}
				printf("\n");
				return 0;
			}
		}
	}

	printf("-1\n");


	
	return 0;
}