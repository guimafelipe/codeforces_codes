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

int n,m,k,q;

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	vii tre;
	vi b;
	FOR(i,0,k){
		int x,y;
		scanf("%d%d", &x, &y);
		tre.pb(x,y);
	}
	FOR(i,0,q){
		int x;
		scanf("%d", &x);
		b.pb(x);
	}
	sort(all(b));
	vii ranges(n,mp(INF,0));
	for(ii t: tre){
		if(t.nd < ranges[t.st].st){
			ranges[t.st].st = t.nd;
		}
		if(t.nd < ranges[t.st].nd){
			ranges[t.st].nd = t.nd;
		}
	}

	int col = 1;
	FOR(i, 0, n-1){
		
	}


	return 0;
}