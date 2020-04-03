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

bool solvre(int n, vi arr){
	bool cre = true;
	int i = 0;
	for(i = 0; i < n; i++){
		if(arr[i] >= i){
			arr[i] = i; 
		} else {
			break;
		}
	}
	for(; i < n; i++){
		if(arr[i] >= arr[i-1]){
			arr[i] = arr[i-1]-1;
		}
		if(arr[i] < 0) return false;
	}
	return true;
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
		vi rarr = arr;
		reverse(all(arr));
		if(solvre(n, arr) || solvre(n, rarr)){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}
