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
	int n,k;
	cin >> n >> k;
	set<ii > hash;
	vi foram(n+1, 0);
	for(int x = 0; x < k; x++){
		int i;
		scanf("%d", &i);
		foram[i] = 1;
		for(int j = max(i-1,0); j <= min(n, i+1); j++){
			if(foram[j]){
				hash.insert(mp(j,i));
			}
		}
	}

	int ans = (n-2)*3 + 4;
	ans -= hash.size();

	cout << ans << endl;
	
	return 0;
}