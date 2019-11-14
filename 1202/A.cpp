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
	int T;
	cin >> T;
	while(T--){
		string s, r;
		cin >> s >> r;
		int q = sz(r)-1;
		// cout << "q:\n";
		while(r[q]=='0'){
			// printf("	%d\n", q);
			q--;
		}
		// cout << "q final; " << q << endl;
		int p = max(0, (sz(s) - 1) - (sz(r)-1-q));
		int counter = 0;
		// cout << "p inicial: " << p << endl;
		while(p > 0 && s[p]=='0'){
			p--;
			// printf("	%d\n", p);
			counter++;
		}
		cout << counter << endl;
	}
	return 0;
}