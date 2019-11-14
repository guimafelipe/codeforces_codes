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
#define PI 3.14159265

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
	vi kids(n), ans;
	deque<int> dek;
	for(int i = 0; i<n; i++) {scanf("%d", &kids[i]);}
	sort(all(kids));

	for(int i = 0; i < n; i++){
		if(i%2){
			dek.push_front(kids[i]);
		} else {
			dek.push_back(kids[i]);
		}
	}

	for(int i = 0; i < n; i++){
		int curr = dek.front();
		dek.pop_front();
		ans.pb(curr);
	}

	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}
