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

int n, m;
string A, B;

bool processa(){
	int i = 0, j = 0;
	while(A[i] == B[j]){
		i++; j++;
		// cout << i << ' ' << j << endl;
	}
	if(A[i] != '*') return false;
	int ast = i, k = m-1;
	i = n-1;
	while(A[i] == B[k]){
		k--; i--;
	}
	if(i != ast) return false;
	if(k < j-1) return false;
	return true;

}

int main(){
	cin >> n >> m;
	cin >> A >> B;
	if(A == B) {cout << "YES\n"; return 0;}

	cout << (processa() ? "YES\n" : "NO\n");
	
	return 0;
}