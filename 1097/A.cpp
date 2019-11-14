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
	string mesa;
	string mao[5];
	cin >> mesa;
	for(int i = 0; i < 5; i++){
		cin >> mao[i];
	}
	bool deuBom = false;
	for(int i = 0; i < 5; i++){
		if(mesa[0] == mao[i][0]) deuBom = true;
		if(mesa[1] == mao[i][1]) deuBom = true;
	}
	cout << (deuBom ? "YES" : "NO"); 
	cout << endl;
	return 0;
}