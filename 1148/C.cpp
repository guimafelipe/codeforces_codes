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

int n;

void fazTroca(int i, int j, vi &perm, vi &ind, vii &movs){
	swap(perm[i], perm[j]);
	ind[perm[i]] = i;
	ind[perm[j]] = j;
	if(abs(j-i) >= n/2){
		movs.pb(mp(i,j));
	} else if(i < n/2 && j < n/2){
		movs.pb(mp(i,n-1));
		movs.pb(mp(j,n-1));
		movs.pb(mp(i,n-1));
	} else if(i >= n/2 && j >= n/2){
		movs.pb(mp(i,0));
		movs.pb(mp(j,0));
		movs.pb(mp(i,0));
	} else if(i < n/2 && j >= n/2){
		movs.pb(mp(i, n-1));
		movs.pb(mp(j, 0));
		movs.pb(mp(0, n-1));
		movs.pb(mp(i, n-1));
		movs.pb(mp(j, 0));
	} else if(j < n/2  && i >= n/2){
		movs.pb(mp(j, n-1));
		movs.pb(mp(i, 0));
		movs.pb(mp(0, n-1));
		movs.pb(mp(j, n-1));
		movs.pb(mp(i, 0));
	}
}

int main(){
	cin >> n;
	vi perm(n);
	vi inds(n);
	int curr;
	FOR(i, 0, n){
		scanf("%d",&curr );
		perm[i] = curr-1;
		inds[curr-1] = i;
	}

	vii movs;
	for(int i = 0; i < n; i++){
		int dono = inds[i];
		if(dono == i) continue;
		fazTroca(dono, i, perm, inds, movs);
	}
	cout << sz(movs) <<  endl;
	FOR(i, 0, sz(movs)){
		printf("%d %d\n", movs[i].st+1, movs[i].nd+1);
	}

	return 0;
}