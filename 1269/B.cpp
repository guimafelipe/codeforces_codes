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
	int n, m;
	cin >> n >> m;

	vi a(n, 0), b(n, 0);

	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		a[i]=aux;
	}

	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		b[i]=aux;
	}

	sort(all(a));
	sort(all(b));

	int ans = INF;

	for(int i = 0; i < n; i++){
		int x = b[0] - a[i];
		x = (x + m)%m;
		
		

		bool deuruim = false;
		for(int d = 0; d < n; d++){
			int j = (i + d)%n;
			if((a[j] + x)%m != b[d]){
				deuruim = true;
				break;
			}
		}

		if(!deuruim){
			ans = min(ans, x);
		}
	}

	printf("%d\n", ans);

	return 0;
}
