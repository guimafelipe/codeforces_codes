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

void solvre(int n, string s){
	string r1, r2;
	bool flag = false;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			r1.pb('0');
			r2.pb('0');
		} else if (s[i] == '1'){
			if(!flag){
				r1.pb('1');
				r2.pb('0');
				flag = true;
			} else {
				r1.pb('0');
				r2.pb('1');
			}
		} else if(s[i] == '2'){
			if(!flag){
				r1.pb('1');
				r2.pb('1');
			} else {
				r1.pb('0');
				r2.pb('2');
			}
		}
	}
	cout << r1 << endl;
	cout << r2 << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		scanf("%d", &n);
		cin >> s;
		solvre(n, s);
	}
	return 0;
}
