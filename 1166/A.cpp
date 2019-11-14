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
	vi letras(26, 0);
	string str;
	FOR(i, 0, n){
		cin >> str;
		letras[str[0]-'a']++;
	}
	ll ans = 0;
	FOR(i, 0, 26){
		int curr = letras[i];
		int half = curr/2;
		int half2 = half;
		if(curr%2) half2++;
		ans += (half*(half-1))/2;
		ans += (half2*(half2-1))/2;
	}
	cout << ans << endl;
	return 0;
}