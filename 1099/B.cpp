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

int conta(int n){
	int side = ceil(sqrt(n));
	int ans = 2*side;
	int minSquare = (side-1)*(side-1);
	int resto = n - minSquare;
	if(resto < side) ans--;
	return ans;
}

int main(){
	int n;
	cin >> n;
	cout << conta(n) << endl;
	return 0;
}