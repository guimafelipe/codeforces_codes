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
	ll h1, h2, w1, w2;
	scanf("%lld %lld %lld %lld", &w1, &h1, &w2, &h2);
	ll resp;
	resp = 2*(h1 + h2 + 2);
	resp += w1 + w2;
	resp += w1 - w2;
	cout << resp << endl;
	return 0;
}