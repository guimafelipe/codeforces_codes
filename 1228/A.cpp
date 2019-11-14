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

bool check(int ans){
	vi countDig(10,0);
	while(ans > 0){
		countDig[ans%10]++;
		ans/=10;
	}
	for(int i : countDig){
		if(i > 1) return false;
	}
	return true;
}

int main(){
	int l, r, ans;
	bool achou = false;
	cin >> l >> r;
	for(ans = l; ans <= r; ans++){
		if(check(ans)){
			achou = true;
			break;
		}
	}
	if(achou){
		cout << ans << endl;
	} else {
		cout << "-1\n";
	}
	return 0;
}