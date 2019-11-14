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

vi build(string f){
	int n = sz(f);
	vi ans(30, 0);
	FOR(i, 0, n){
		ans[f[i] - 'a']++;
	}
	return ans;
}

bool check(vi freq){
	FOR(i, 0, 30){
		if(freq[i] > 0){
			return false;
		}
	}
	return true;
}

int solve(string f, string s){
	vi freq = build(f);
	int i = 0;
	while(!check(freq)){
		if(freq[s[i]-'a'] > 0){
			freq[s[i]-'a']--;
		}
		i++;
	}
	return i;
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vvi lettersDist(30, vi());
	FOR(i, 0, n){
		lettersDist[s[i]-'a'].pb(i);
	}
	int m;
	cin >> m;
	FOR(i, 0, m){
		string f;
		cin >> f;
		vi freq = build(f);
		int maxInd = 0;
		FOR(i, 0, 30){
			if(freq[i] <= 0) continue;
			maxInd = max(maxInd, lettersDist[i][freq[i]-1]);
		}
		cout << maxInd+1 << endl;
	}

	return 0;
}