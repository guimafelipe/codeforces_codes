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

#define N 500002
#define SQ 709

int a[N];
int freq[SQ];

int mod(int x, int y){
	return ((x%y)+y)%y;
}

int tab2[SQ][SQ];

int main(){
	int q;
	cin >> q;
	FOR(Q, 0, q){
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		if(type == 1){
			int old = a[x];
			a[x]+=y;
			int novo = a[x];
			FOR(i, 1, SQ){
				tab2[i][mod(x,i)]-=old;
				tab2[i][mod(x,i)]+=novo;
			}
		} else {
			if(x < SQ){
				cout << tab2[x][mod(y,x)] << endl;
			} else {
				ll ans = 0;
				for(int cx = y; cx < N; cx += x){
					ans += a[cx];
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}