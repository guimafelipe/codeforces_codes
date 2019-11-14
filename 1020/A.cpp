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
	int n, h;
	int a, b;
	int k;
	cin >> n >> h >> a >> b >> k;
	for(int i = 0; i < k; i++){
		int ta, fa, tb, fb;
		scanf("%d %d %d %d", &ta, &fa, &tb, &fb);
		int ans = 0;
		if(ta == tb){
			cout << abs(fa - fb) << endl;
			continue;
		}
		ans += abs(ta - tb);
		if(fa < a){
			ans += a-fa;
			fa = a;
		} else if(fa > b){
			ans += fa-b;
			fa = b;
		}
		if(fb < a){
			ans += a-fb;
			fb = a;
		} else  if(fb  > b){
			ans += fb-b;
			fb = b;
		}
		ans+=abs(fa - fb);
		cout << ans << endl;
	}
	
	return 0;
}