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
	int n, ant = 0;
	cin >> n;
	int ans = 0, cnt = 1;
	int atual;
	for(int i = 0; i < n; i++){
		scanf("%d", &atual);
		if(atual == ant+1){
			cnt++;
		} else {
			cnt = 1;
		}
		ans = max(ans, cnt);
		ant = atual;
	}
	if(ant == 1000){
		cnt++;
		ans = max(ans, cnt);
	}
	printf("%d\n", ans-2);
	return 0;
}