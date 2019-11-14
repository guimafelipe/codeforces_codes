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

int n, m;

char pano[1002][1002];

int getTam(int x, int y){
	int ans = 0;
	int curr = pano[x][y];
	int i = x;
	while(pano[i][y] == curr){
		i++; ans++;
	}
	return ans;
}

string getFaixa(int x, int y, int tam){
	string faixa;
	FOR(i, x-tam, x+2*tam){
		faixa.pb(pano[i][y]);
	}
	return faixa;
}

int testaMeio(int x, int y, int tam){ // retorna largura da bandeira
	// printf("Testando coords %d, %d. Tam = %d.\n", x, y, tam);
	int ans = 0;
	char meio = pano[x][y];
	if(x+2*tam > n) return 0;
	if(x-tam < 0) return 0;
	FOR(i, x, x+tam){
		if(pano[i][y]!=meio) return 0;
	}
	char acima = pano[x-tam][y];
	if(acima == meio) return 0;
	FOR(i, x-tam, x){
		if(pano[i][y]!=acima) return 0;
	}
	char abaixo = pano[x+tam][y];
	if(abaixo == meio) return 0;
	FOR(i, x+tam, x+2*tam){
		if(pano[i][y]!=abaixo) return 0;
	}
	string faixa;
	FOR(i, x-tam, x+2*tam){
		faixa.pb(pano[i][y]);
	}
	// cout << "Faixa = "<< faixa << endl;

	int j = y;
	while(j < m && getFaixa(x, j, tam) == faixa){
		ans++;
		j++;
	}
	return ans;
}

int main(){
	cin >> n >> m;
	FOR(i, 0, n){
		FOR(j, 0, m){
			scanf(" %c", &pano[i][j]);
		}
	}
	ll ans = 0;
	FOR(i, 0, n){
		FOR(j, 0, m){
			int tam = getTam(i, j);
			int curr = testaMeio(i, j, tam);
			if(curr == 1) ans++;
			else if(curr > 1){
				ans+= (curr*(curr+1))/2;
				j+= (curr - 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}