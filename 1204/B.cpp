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
	ll n, l, r;
	cin >> n >> l >> r;
	ll maxSum = 0, minSum = 0;
	int diffNums = 1;
	ll currNum = 1;
	FOR(i, 0, n){
		maxSum += currNum;
		if(diffNums < r) {
			currNum<<=1;
			diffNums++;
		}
	}
	currNum = 1;
	diffNums = 1;
	FOR(i, 0, n){
		minSum += currNum;
		if(n - i <= l){
			currNum<<=1;
		}
	}
	cout << minSum << " " << maxSum << endl;
	return 0;
}