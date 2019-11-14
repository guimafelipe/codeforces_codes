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

struct Query{
	int t, i, x;
};

int main(){
	int n;
	cin >> n;
	vi a;
	FOR(i,0,n){
		int aux;
		scanf("%d", &aux);
		a.pb(aux);
	}
	int q;
	cin >> q;
	vector<Query> queries;
	while(q--){
		int t;
		int i, x;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d", &i, &x);
			i--;
		} else {
			scanf("%d", &x);
		}
		Query query;
		query.t = t; query.x = x; query.i = i;
		queries.pb(query);
	}
	reverse(all(queries));
	vector<bool> marcados(n, false);
	vi valorFinal(n, 0);

	q = sz(queries);
	int currMin = 0;
	FOR(_q,0,q){
		Query curr = queries[_q];
		if(curr.t == 1 && !marcados[curr.i]){
			valorFinal[curr.i] = max(currMin, curr.x);
			marcados[curr.i] = true;
		} else if(curr.t == 2){
			currMin = max(currMin, curr.x);
		}
	}
	FOR(i,0,n){
		if(marcados[i]) continue;
		valorFinal[i] = max(a[i], currMin);
	}

	FOR(i,0,n){
		printf("%d ", valorFinal[i]);
	}
	printf("\n");

	return 0;
}