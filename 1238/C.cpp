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
		int h, n;
		scanf("%d%d", &h, &n);
		vector<bool> plats(h,0);
		FOR(i,0,n){
			int p;
			scanf("%d", &p);
			plats[p-1] = true;
		}
		reverse(all(plats));
		int i = 0;
		int cris = 0;
		while(i < h){
			if(i == h-1 || i == h-2) break;
			if(!plats[i+1]){
				i++;
			} else if(plats[i+2]){
				i+=2;
			} else{
				i+=2;
				cris++;
			}
		}
		printf("%d\n", cris);
	}
	return 0;
}