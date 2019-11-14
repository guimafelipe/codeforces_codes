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

int main(){
	int n;
	cin >> n;
	vvi bolos(n+1, vi());
	for(int i = 0; i < 2*n; i++){
		int aux;	
		scanf("%d", &aux);
		bolos[aux].pb(i);
	}
	ll d1 = bolos[1][0], d2 = bolos[1][1];
	int p1 = d1, p2 = d2;
	for(int i = 2; i <= n; i++){
		// cout << p1 << " " << p2 << endl;
		int n1 = bolos[i][0], n2 = bolos[i][1];
		if(abs(p1-n1)+abs(p2-n2) < abs(p1-n2) + abs(p2-n1)){
			d1 += abs(p1-n1);
			d2 += abs(p2-n2);
			p1 = n1;
			p2 = n2;
		} else {
			d1 += abs(p1-n2);
			d2 += abs(p2-n1);
			p1 = n2;
			p2 = n1;
		}
	}
	ll ans = d1 + d2;
	cout << ans << endl;
	return 0;
}