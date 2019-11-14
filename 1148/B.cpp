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
	ll n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	if(k >= n || k >= m){
		cout << "-1\n";
		return 0;
	}
	vll atob(n);
	FOR(i, 0, n){
		scanf("%lld", &atob[i]);
		atob[i]+=ta;
	}
	vll btoc(m);
	FOR(i, 0, m){
		scanf("%lld", &btoc[i]);
	}

	int i=0, j = 0;

	vll travelind(n, 0);
	while(i<n){
		while(j < m && atob[i] > btoc[j]){
			j++;
		}
		travelind[i] = j;
		i++;
	}

	ll best = 0;

	for(int i = 0; i <=k; i++){
		int sobra = k - i;
		int j = travelind[i] + sobra;
		if(j >= m){
			cout << "-1\n";
			return 0;
		}
		best = max(best, btoc[j]+tb);
	}
	cout <<  best << endl;

	return 0;
}