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

int solve1(int n, int p, int k, vi& a){
	sort(all(a));
	int r1 = 0, r2 = 0;
	int c = 0, i = 0;
	while(i < n && (i%2 == 0 || c + a[i] <= p)){
		if(i%2 != 0){
			c += a[i];
			r1+=2;
		}
		i++;
	}
	c = 0, i = 0;
	while(i < n && (i%2 != 0 || c + a[i] <= p)){
		if(i%2 == 0){
			c += a[i];
			if(i == 0){
				r2++;
			} else {
				r2+=2;
			}
		}
		i++;
	}
	return max(r1, r2);
}

int solve2(int n, int p, int k, vi& a){
	sort(all(a));
	int pref = 0, ans= 0;
	for(int i = 0; i <= k; i++){
		int sum = pref, cnt = i;
		if(sum > p) break;
		for(int j = i + k - 1; j < n; j += k){
			if(sum + a[j] <= p){
				cnt += k;
				sum += a[j];
			} else {
				break;
			}
		}
		pref += a[i];
		ans = max(ans, cnt);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, p, k;
		scanf("%d %d %d", &n, &p, &k);
		vi a;
		FOR(i,0,n){
			int aux;
			scanf("%d", &aux);
			a.pb(aux);
		}
		//cout << solve1(n,p,k,a) << endl;
		cout << solve2(n,p,k,a) << endl;
	}
	return 0;
}
