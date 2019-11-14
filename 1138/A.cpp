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

int n;

int tentar(int i, vi &mesa){
	int esq = mesa[i], dir = mesa[i+1];
	int j = i+1;
	int ans = 2;
	i--; j++;
	while(i >= 0 && j < n && mesa[i] == esq && mesa[j] == dir){
		ans += 2;
		i--; j++;
	}
	return ans;
}

int main(){
	cin >> n;
	vi mesa;
	mesa.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &mesa[i]);
	}	

	int ans = 1;
	for(int i = 0; i < n-1; i++){
		if((mesa[i] == 1 && mesa[i+1] == 2)
			||(mesa[i] == 2 && mesa[i+1] == 1)){
			ans = max(ans, tentar(i, mesa));
		}
	}
	cout << ans << endl;
	return 0;
}