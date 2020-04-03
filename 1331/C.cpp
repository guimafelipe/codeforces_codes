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
	int x;
	cin >> x;
	// And they lived happily ever after
	// And after happily lived ever tehy
	//  5 4 3 2 1 0
	//  5 0 2 3 1 4
			
	int original[6];
	int depois[6];
	
	for(int i = 0; i < 6; i++){
		original[i] = x%2;
		x/=2;
	}
	
	depois[0] = original[4];
	depois[1] = original[1];
	depois[2] = original[3];
	depois[3] = original[2];
	depois[4] = original[0];
	depois[5] = original[5];

	int ans = 0;
	
	for(int i = 0; i < 6; i++){
		ans += depois[i]*(1<<i);
	}

	cout << ans << endl;

	return 0;
}
