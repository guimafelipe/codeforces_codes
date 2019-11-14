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

struct Knight {
	ll ind, f, c;	
};

bool comp(Knight a, Knight b){
	return a.f < b.f;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<Knight> knights(n);
	FOR(i, 0, n){
		ll aux;
		scanf("%lld", &aux);
		knights[i].ind = (ll)i;
		knights[i].f = aux;
	}
	FOR(i, 0, n){
		ll aux;
		scanf("%lld", &aux);
		knights[i].c = aux;
	}

	sort(all(knights), comp);

	int i = 0, j = 0;
	ll ans = 0;
	vll sol(n);

	priority_queue<ll> coins;

	while(j < n){
		if(j - i > k){
			ll menor = -coins.top();
			coins.pop();
			ans -= menor;
			i++;
		}
		ans += knights[j].c;
		coins.push(-knights[j].c);
		sol[knights[j].ind] = ans;
		j++;
	}

	FOR(i, 0, n){
		printf("%lld ", sol[i]);
	}
	printf("\n");

	return 0;
}