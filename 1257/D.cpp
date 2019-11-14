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

int solve(vi &monstros, vii &heroes){
	int k = 0; //proximo monstro a ser derrotado	
	int n = sz(monstros);
	int m = sz(heroes);
	int ans = 0;
	while(k < n){
		int currMax = monstros[k];
		int bk = k;
		int mortos = 0;
		for(ii h : heroes){
			int p = h.st, s = h.nd;
			s -= mortos;
			while(p >= currMax && s > 0){
				bk++;
				if(bk >= n) return ++ans;
				currMax = max(currMax, monstros[bk]);
				mortos++;
				s--;
			}
		}
		if(bk == k) return -1;
		k = bk;
		ans++;
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		scanf("%d", &n);
		vi monstros;
		FOR(i,0,n){
			int aux;
			scanf("%d", &aux);
			monstros.pb(aux);
		}
		vii heroes;
		int m;
		scanf("%d", &m);
		FOR(i,0,m){
			int a,b;
			scanf("%d %d", &a, &b);
			heroes.pb(mp(a,b));
		}
		cout << solve(monstros, heroes) << endl;
	}
	return 0;
}
