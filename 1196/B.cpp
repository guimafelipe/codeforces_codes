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

void prsp(bool res){
	if(res){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		scanf("%d%d", &n, &k);
		vii arr;
		arr.reserve(n);
		FOR(i,0,n){
			int aux;
			scanf("%d",&aux);
			if(aux%2) arr.pb(mp(aux, i+1));
		}
		int on = n;
		n = sz(arr);
		if(n < k){
			prsp(false);
		} else {
			if((n-k)%2){
				prsp(false);
			} else {
				prsp(true);
				FOR(i,0,k){
					printf("%d ", (i == k-1 ? on : arr[i].nd ));
				}
				printf("\n");
			}
		}
	}
	return 0;
}