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

bool contem(ii par, int x){
	return par.st == x || par.nd == x;
}

bool executa2(int y, vii& pares, vector<bool> &firstRound){
	int m = sz(pares);
	int marcados = 0;
	FOR(i, 0, m){
		if(firstRound[i]) marcados++;
	}
	FOR(i, 0, m){ 
		if(!firstRound[i]){
			if(contem(pares[i], y)){
				marcados++;
			}
		}
	}
	return marcados == m;
}

bool executa(int x, vii &pares){
	vector<bool> firstRound(sz(pares), false);
	int m = sz(pares);
	FOR(i, 0, m){
		if(contem(pares[i], x)){
			firstRound[i] = true;
		}
	}
	int countMarcadosFirstRound = 0;
	FOR(i, 0 , m){
		if(firstRound[i]) countMarcadosFirstRound++;
	}
	if(countMarcadosFirstRound == m) return true;
	bool ans = false;
	FOR(i, 0, m){
		if(!firstRound[i]){
			ans |= executa2(pares[i].st, pares, firstRound);
			ans |= executa2(pares[i].nd, pares, firstRound);
			break;
		}
	}
	return ans;
}

int main(){
	int n, m;
	cin >> n >> m;
	vii pares;
	FOR(i, 0, m){
		int a, b;
		scanf("%d %d", &a, &b);
		pares.pb(mp(a, b));
	}
	bool firstRound[300005] = {false};

	bool deubom = false;

	deubom |= executa(pares[0].st, pares);
	deubom |= executa(pares[0].nd, pares);

	if(deubom){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}