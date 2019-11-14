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
	int n;
	cin >> n;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < sz(s); i+=2){
		char a1, a2;
		a1 = s[i]; a2 = s[i+1];
		if(a1 == a2){
			ans++;
			if(a1 ==  'a'){
				s[i+1] = 'b';
			}else{
				s[i+1] = 'a';
			}
		}
	}
	cout << ans << endl;
	cout << s << endl;
	return 0;
}