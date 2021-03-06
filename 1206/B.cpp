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
	ll changes = 0;
	int countNeg = 0, count0 = 0;
	FOR(i, 0, n){
		int curr;
		scanf("%d", &curr);
		if(curr > 0){
			changes += (curr - 1);
		} else if (curr < 0){
			curr = -curr;
			changes += (curr - 1);
			countNeg++;
		} else {
			count0++;
		}
	}
	if(count0){
		changes += count0;
	} else if(countNeg%2){
		changes += 2;
	}
	cout << changes << endl;
	return 0;
}