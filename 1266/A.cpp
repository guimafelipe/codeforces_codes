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

bool solve(string n){
	bool d2, d3, d10;
	d2 = d3 = d10 = false;
	int sum3 = 0;
	for(char c : n){
		int dig = (int)(c - '0');
		if(dig%2 == 0 && (dig != 0 || d10)){
			d2 = true;
		}
		if(dig == 0){
			d10 = true;
		}
		sum3 += dig;
	}
	if(sum3%3 == 0){
		d3 = true;
	}
	return d2 && d3 && d10;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string n;
		cin >> n;
		if(solve(n)){
			printf("red\n");
		} else {
			printf("cyan\n");
		}
	}
	
	return 0;
}
