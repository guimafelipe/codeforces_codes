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
	// set<int> posCounter;
	// set<int> negCounter;
	int pCounter = 0;
	int nCounter = 0;
	for(int i = 0; i < n; i++){
		int curr;
		scanf("%d", &curr);
		// if(curr > 0) posCounter.insert(curr);
		// else if (curr < 0) negCounter.insert(curr);
		if(curr > 0) pCounter++;
		if(curr < 0) nCounter++;
	}
	int ans;
	// if(posCounter.size() >= (n+1)/2){
	if(pCounter >= (n+1)/2){
		ans = 1;
	// } else if(negCounter.size() >= (n+1)/2){
	} else if(nCounter >= (n+1)/2){
		ans = -1;
	} else {
		ans = 0;
	}

	cout << ans << endl;
	
	return 0;
}