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

int n, m;

void orderPair(ii &par){
	if(par.st >  par.nd){
		int aux = par.st;
		par.st = par.nd;
		par.nd = aux;
	}
}

bool tentar(int delta, vii segments, set<ii> &gabarito){
	for(int i = 0; i < sz(segments); i++){
		// cout << "Pegando par: (" << segments[i].st << ", " << segments[i].nd << ")\n";
		segments[i].st += delta;
		segments[i].st = segments[i].st%n;
		segments[i].nd += delta;
		segments[i].nd = segments[i].nd%n;
		orderPair(segments[i]);
		// cout << "Gerando par: (" << segments[i].st << ", " << segments[i].nd << ")\n";
		if(!gabarito.count(segments[i])){
			// cout << "Par acima bateu\n";
			return false;
		}
	}
	return true;
}

int main(){
	cin >> n >> m;
	vii segments;
	for(int k = 0; k < m; k++){
		int x, y;
		scanf("%d %d", &x, &y);
		segments.pb(mp(x-1,y-1));
	}

	set<ii> gabarito;

	for(int i = 0; i < sz(segments); i++){
		orderPair(segments[i]);
		gabarito.insert({segments[i]});
	}

	ii pivot = segments[0];

	bool deuBom = false;

	for(int i = 1; i < n; i++){
		if(n%i) continue;
		deuBom |= tentar(i, segments, gabarito);
	}

	if(deuBom){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	
	return 0;
}