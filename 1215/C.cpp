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

int main(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	vii swaps;

	vi tipo1;
	vi tipo2;

	FOR(i,0,n){
		if(a[i] == 'a' && b[i] == 'b'){
			tipo1.pb(i+1);
		} else if(a[i] == 'b' && b[i] == 'a'){
			tipo2.pb(i+1);
		}
	}

	vii trocas;

	while(sz(tipo1) > 1){
		int x, y;
		x = tipo1.back();
		tipo1.pop_back();
		y = tipo1.back();
		tipo1.pop_back();
		trocas.pb(mp(x,y));
	}
	while(sz(tipo2) > 1){
		int x, y;
		x = tipo2.back();
		tipo2.pop_back();
		y = tipo2.back();
		tipo2.pop_back();
		trocas.pb(mp(x,y));
	}
	if(sz(tipo1) != sz(tipo2)){
		cout << "-1\n";
		return 0;
	}
	if(sz(tipo1) > 0){
		int x = tipo1.back();
		int y = tipo2.back();
		trocas.pb(mp(x,x));
		trocas.pb(mp(x,y));
	}

	printf("%d\n", sz(trocas));
	for(ii resp : trocas){
		printf("%d %d\n", resp.st, resp.nd);
	}

	return 0;
}