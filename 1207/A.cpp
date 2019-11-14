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
	int t;
	cin >> t;
	FOR(i, 0, t){
		int b, p, f;
		cin >> b >> p >> f;
		int h , c;
		cin >> h >> c;
		ll ans = 0;
		if(h > c){
			while(p > 0 && b > 1){
				p--;
				b-=2;
				ans+=h;
			}
			while(f > 0 && b > 1){
				p--;
				f--;
				b-=2;
				ans+=c;
			}
		} else {
			while(f > 0 && b > 1){
				f--;
				b-=2;
				ans+=c;
			}
			while(p > 0 && b > 1){
				p--;
				b-=2;
				ans+=h;
			}
		}
		cout << ans << endl;
	}
	return 0;
}