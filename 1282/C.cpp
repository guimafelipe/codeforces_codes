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

void solve(){
	int n, t;
	ll a, b;
	scanf("%d %d %lld %lld", &n, &t, &a, &b);

	vii problems(n);

	int rf = 0, rd = 0;
	FOR(i,0,n){
		int aux;
		scanf("%d", &aux);
		problems[i].nd = aux;
		aux == 0 ? rf++ : rd++;
	}

	FOR(i,0,n){
		int aux;
		scanf("%d", &aux);
		problems[i].st = aux;
	}

	sort(all(problems));
	
	n++;
	problems.pb(mp(t+1, 0));

	int ans = 0;
	ll tempoAcumulado = 0;
	for(int i = 0; i < n; i++){
		ll tempo = problems[i].st - 1;
		tempo -= tempoAcumulado;

		if(tempo >= 0){
			int currAns = i;
			if(tempo >= rf*a){
				tempo -= rf*a;
				currAns += rf;

				if(tempo >= rd*b){
					currAns += rd;
				} else {
					currAns += tempo/b;
				}
			} else {
				currAns += tempo/a;
			}
			ans = max(ans, currAns);
		}

		if(problems[i].nd == 0){
			tempoAcumulado += a;
			rf--;
		} else {
			tempoAcumulado += b;
			rd--;
		}
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
