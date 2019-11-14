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

int rotations[17];
int n;

int bruteforce(int i, int currsum){

	// CONDICAO DE PARADA
	if(i == n){
		if(currsum % 360 == 0) return true;
		return false;
	}






	return bruteforce(i+1, currsum + rotations[i]) || bruteforce(i+1, currsum - rotations[i]);
}

int main(){
	cin  >> n;
	for(int i = 0; i < n; i++) {
		cin >> rotations[i];
	}
	int ans = bruteforce(0, 0);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}