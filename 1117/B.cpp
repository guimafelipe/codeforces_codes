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
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	ll best = -1, secondBest = -1;
	vll a(n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		if(a[i] > best) best = a[i];
	}
	bool bestFound = false;
	for(int i = 0; i < n; i++){
		if(!bestFound && a[i] == best){
			bestFound = true;
			continue;
		}
		if(a[i] > secondBest) secondBest = a[i];
	}
	ll step = k*best + secondBest, result = 0LL;
	result += step*(m/(k+1));
	result += best*(m%(k+1));
	cout << result << endl;
	return 0;
}