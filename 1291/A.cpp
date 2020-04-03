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

string ebne(string s){
	int n = sz(s);
	int impar1 = 0, impar2 = 0;
	for(int i = 0; i < sz(s); i++){
		int val = s[i] - '0';
		if(val%2){
			if(impar1 == 0){
				impar1 = val;
			}
			else {
				impar2 = val;
				break;
			}
		}
	}
	if(impar1 && impar2){
		string ans;
		ans.pb(impar1+'0');
		ans.pb(impar2+'0');
		return ans;
	}
	return "-1";
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n;
		cin >> s;
		cout << ebne(s) << endl;
	}
	return 0;
}
