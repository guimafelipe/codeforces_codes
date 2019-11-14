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

int n, k;
string spots;

int main(){
	cin >> n >> k;
	cin >> spots;
	vll pre;
	pre.pb(0);
	FOR(i,1, n+1){
		pre.pb(pre.back()+(spots[i-1]=='1' ? 1 : 0));
	}

	// FOR(i,0,n+1){
	// 	cout << pre[i] << " ";
	// }
	// cout << endl;

	int cover = -1;	
	FOR(i,0,n){
		if(spots[i] == '0') continue;
		if(i > cover){
			spots[i]  = '2';
			cover = i+k;
		} else if(i+k >= n-1){
			spots[i] = '2';
			break;
		} else if(pre[i+1] == pre[cover+1]){
			spots[i] = '2';
			cover = i+k;
		}
		if(cover >= n-1) break;
	}

	// cout << spots << endl;

	int last3 = -1;
	FOR(i,0,n){
		if(spots[i] == '2'){
			for(int j = max(last3+1, i-k); j <= min(n-1, i+k); j++){
				if(i == j) continue;
				if(spots[j] == '2') continue;
				spots[j] = '3';
			}
			last3 = min(n-1, i+k);
		}
	}

	cout << spots << endl;

	ll cost = 0;
	FOR(i,0,n){
		if(spots[i]!='3'){
			cost+=(i+1);
		}
	}

	cout << cost << endl;

	return 0;
}