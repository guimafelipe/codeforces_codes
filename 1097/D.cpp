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

#define ymsg "YES\n"
#define nmsg "NO\n"

int main(){
	int n;
	cin >> n;
	int x = 0, y = 0;
	for(int i = 0; i < n;  i++){
		char op;
		scanf(" %c", &op);
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b){
			swap(a, b);
		}
		if(op == '+'){
			x = max(x, a);
			y = max(y, b);
		} else if(op == '?'){
			if(x > a || y > b) cout << nmsg;
			else cout << ymsg;
		}
	}
	return 0;
}