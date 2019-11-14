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
	string s;
	cin >> s;
	if(sz(s) == 1 && s[0] == '0'){
		cout << 0 << endl;
		return 0;
	}
	int count1 = 0;
	int ans = 0;
	for(int i = sz(s) - 1; i>=0; i--){
		if(s[i]=='1') count1++;
		int bit = (sz(s)-1)-i;
		if(!(bit%2)){
			ans++;
		}
	}
	if(sz(s)%2 && count1 == 1) ans--;
	cout << ans << endl;
	return 0;
}