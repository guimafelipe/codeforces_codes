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
	while(t--){
		string s;
		cin >> s;
		vi uns;
		uns.pb(-1);
		FOR(i,0,sz(s)){
			if(s[i] == '1') uns.pb(i);
		}
		ll ans = 0;
		printf("\n");
		for(ll i = 0; i < sz(s); i++){
			ll sum = 0;
			ll j = lower_bound(all(uns), i) - uns.begin();
			if(j >= sz(uns) || uns[j] > i) j--;
			for(bool sair = false; !sair && sum < 500010;j--){
				ll ind = uns[j];
				if(ind == -1 || (i-ind)>20){
					sair = true;
				}
				if((i-ind) >= sum && sum!=0){
					ans++;
				}
				if(!sair){
					sum += 1LL << (i-ind);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}