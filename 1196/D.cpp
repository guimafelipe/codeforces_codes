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

string pat = "RGB";

int getSum(int a, vi &pre){
	if(a < 0) return 0;
	return pre[a];
}

int getRange(int a, int b, vi& pre){
	return getSum(b, pre) - getSum(a-1, pre);
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		scanf("%d%d", &n, &k);
		string s;
		cin >> s;
		int minChanges = INF;
		FOR(j,0,3){
			vi pre(n, 0);
			if(s[0] == pat[j]){
				pre[0] = 0;
			} else {
				pre[0] = 1;
			}
			FOR(i,1,n){
				if(s[i] != pat[(j+i)%3]){
					pre[i] = pre[i-1] + 1;
				} else {
					pre[i] = pre[i-1];
				}
			}
			FOR(i, 0, n-k+1){
				minChanges = min(minChanges, getRange(i, i+k-1, pre));
			}
		}
		printf("%d\n", minChanges);
	}
	return 0;
}