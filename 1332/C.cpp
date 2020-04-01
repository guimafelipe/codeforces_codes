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

void dfs(int u, int curr_color, vi &color, int n, int k){
	if(u >= 0 && u < n && color[u] == 0){
		color[u] = curr_color;
		dfs(n-u-1, curr_color, color, n, k); // palindromo
		dfs(u + k, curr_color, color, n, k); 
		dfs(u - k, curr_color, color, n, k);
	}
}

int solvre(int n, int k, string s){
	int ans = 0;

	vector<int> color(n, 0);
	int curr_color = 1;
	for(int i = 0; i < n; i++){
		if(color[i] == 0){
			dfs(i, curr_color, color, n, k);
			curr_color++;
		}
	}

	map<int, vector<char> > freq;
	for(int i = 0; i < n; i++){
		freq[color[i]].pb(s[i]);
	}

	for(auto inst : freq){
		map<char, int> freq2;
		vector<char> arr = inst.nd;
		for(char c : arr){
			freq2[c]++;
		}
		int maxi = 0;
		int tot = 0;
		for(auto el : freq2){
			maxi = max(maxi, el.nd);
			tot += el.nd;
		}
		ans += (tot - maxi);
	}

	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		scanf("%d %d", &n, &k);
		string s;
		cin >> s;
		cout << solvre(n, k, s) << endl;
	}
	return 0;
}
