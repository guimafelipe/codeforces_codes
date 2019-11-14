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
	int n, m;
	cin >> n >> m;
	vii ois;
	vii bis;
	vector<bool> marked(n, false);
	FOR(i, 0, m){
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1){
			ois.pb(mp(l-1, r-1));
		} else {
			bis.pb(mp(l-1, r-1));
		}
	}

	FOR(i, 0, sz(ois)){
		ii curr = ois[i];
		FOR(j, curr.st+1, curr.nd+1){
			marked[j] = true;
		}
	}

	FOR(i, 0, sz(bis)){
		ii curr = bis[i];
		bool foi = false;
		FOR(j, curr.st+1, curr.nd+1){
			if(!marked[j]){
				foi = true;
				break;
			}
		}
		if(!foi){
			cout << "NO\n";
			return 0;
		}
	}

	int currVal = 50000;
	cout << "YES \n";

	FOR(i, 0, n){
		if(!marked[i]){
			currVal--;
		}
		printf("%d ", currVal);
	}
	printf("\n");

	return 0;
}