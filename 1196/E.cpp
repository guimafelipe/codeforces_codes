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
	int q;
	cin >> q;
	while(q--){
		int b, w;
		bool troca = false;
		scanf("%d%d", &b, &w);
		if(b < w){
			swap(b,w);
			troca = true;
		}
		if(b > 3*w + 1){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vii ws, bs, resp;
		FOR(i,1,w+1){
			ws.pb(mp(1, i+2));
			bs.pb(mp(1, i+1));
			b--;
		}
		if(b){
			bs.pb(mp())
		}
		for(ii r : resp){
			if(!troca){
				printf("%d %d\n", r.st, r.nd);
			} else {
				printf("%d %d\n", r.st+1, r.nd);
			}
		}
	}
	return 0;
}