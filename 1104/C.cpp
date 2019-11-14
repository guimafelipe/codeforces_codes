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
#define PI 3.14159265

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
	int vertical = 0, horizontal = 0;
	string entrada;
	cin >> entrada;
	for(int i = 0; i < sz(entrada); i++){
		char curr = entrada[i];
		if(curr == '0'){
			vertical++;
			cout << "1 " << vertical << "\n";
			vertical = vertical%4;
		} else {
			horizontal+=2;
			cout << "3 " << horizontal-1 << "\n";
			horizontal = horizontal%4;
		}
	}
	return 0;
}