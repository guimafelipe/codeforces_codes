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
	vll swords;
	FOR(i,0,n){
		ll aux;
		scanf("%lld", &aux);
		swords.pb(aux);
	}

	sort(all(swords));

	ll mini = swords.front();

	FOR(i,0,n){
		swords[i] -= mini;
	}

	ll z = swords.back();

	if(z == 0){
		cout << "0 0\n";
		return 0;
	}

	FOR(i,0,n){
		z = __gcd(z, swords[i]);
	}

	FOR(i,0,n){
		swords[i]/=z;
	}

	ll maxi = swords.back();

	ll y = 0;
	FOR(i,0,n){
		y += maxi - swords[i];
	}


	cout << y << " " << z << endl;

	return 0;
}