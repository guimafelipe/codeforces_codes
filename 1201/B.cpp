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
	int n;
	cin >> n;
	vi a(n);
	ll sum = 0;
	FOR(i,0,n){
		int aux;
		scanf("%d", &aux);
		a[i] = aux;
		sum += aux;
	}

	sort(all(a));
	int maxi = a.back();
	if(sum%2){
		cout << "NO\n";
		return 0;
	}
	if(sum - maxi < maxi){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}