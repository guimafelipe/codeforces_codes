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
	string resps[n];
	FOR(i,0,n){
		string a;
		cin >> a;
		resps[i] = a;
	}
	vi points;
	FOR(i,0,m){
		int aux;
		scanf("%d", &aux);
		points.pb(aux);
	}
	ll ans = 0;
	FOR(i,0,m){
		vi count(5,0);
		FOR(j,0,n){
			count[resps[j][i]-'A']++;
		}
		int maxi = 0;
		FOR(j,0,5){
			if(count[j]>maxi) maxi = count[j];
		}
		ans += maxi*points[i];
	}
	cout << ans << endl;
	return 0;
}