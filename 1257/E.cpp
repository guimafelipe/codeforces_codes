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

int PD[200100][3];

int n;

int pd(int i, int estado, vi &dono){
	int &mem = PD[i][estado];
	if(i == n) return 0;
	if(mem != -1) return mem;
	mem = INF;
	if(estado == 0){
		mem = min(mem,pd(i+1, 0, dono));
		mem = min(mem,pd(i+1, 1, dono));
		mem = min(mem,pd(i+1, 2, dono));
		if(dono[i] != 0) mem++;
	}
	if(estado == 1){
		mem = min(mem,pd(i+1, 1, dono));
		mem = min(mem,pd(i+1, 2, dono));
		if(dono[i] != 1) mem++;
	}
	if(estado == 2){
		mem = min(mem,pd(i+1, 2, dono));
		if(dono[i] != 2) mem++;
	}
	return mem;
}

int main(){
	vi k(3);
	n = 0;
	FOR(i,0,3){
		cin >> k[i];
		n += k[i];
	}
	vi dono(n);
	FOR(i,0,3){
		FOR(j,0,k[i]){
			int aux;
			scanf("%d", &aux);
			dono[aux-1] = i;
		}
	}

	int ans = INF;

	memset(PD, -1, sizeof(PD));

	FOR(i,0,3){
		ans = min(ans, pd(0,i,dono));
	}

	cout << ans << endl;

	return 0;
}

