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
typedef vector<bool> vb;

void solvre(int n, vi &arr){
	set<int> esq, dir;
	vi pos(n, 0);
	set<int>::iterator it;
	for(int i = 0; i < n-1; i++){
		int curr = arr[i];
		if(esq.count(curr)) break;
		esq.insert(curr);
		it = esq.end();
		it--;
		if(*it == esq.size()){
			pos[i]++;
		}
	}
	for(int i = n-1; i > 0; i--){
		int curr = arr[i];
		if(dir.count(curr)) break;
		dir.insert(curr);
		it = dir.end();
		it--;
		if(*it == dir.size()){
			pos[i-1]++;
		}
	}
	vii sol;
	for(int i = 0; i < sz(pos); i++){
		if(pos[i] == 2){
			sol.pb(mp(i+1, n - (i+1)));
		}
	}
	printf("%d\n", sz(sol));
	for(ii el : sol){
		printf("%d %d\n", el.st, el.nd);
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		scanf("%d", &n);
		vi arr;
		FOR(i,0,n){
			int aux;
			scanf("%d", &aux);
			arr.pb(aux);
		}
		solvre(n, arr);
	}
	return 0;
}
