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
	if(!(n%2)){
		cout << "NO\n";
		return 0;
	}
	vi resp(2*n, 0);
	int p = n-1, q = 2*n-1;
	bool rod1 = true;
	for(int i = 1; i <= n*2; i+=2){
		if(rod1){
			resp[p] = i;
			resp[q] = i+1;
			rod1 = false;
		} else {
			resp[p] = i+1;
			resp[q] = i;
			rod1 = true;
		}
		p--; q--;
	}
	printf("YES\n");

	FOR(i, 0, 2*n){
		printf("%d ", resp[i]);
	}
	cout << endl;

	return 0;
}