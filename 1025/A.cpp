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

int A[27] = {0};

int main(){
	int n;
	cin >> n;
	bool ok = false;
	if(n == 1) ok = true;
	for(int i = 0; i < n; i++){
		char aux;
		scanf(" %c", &aux);
		if(A[aux - 'a'] == 0){
			A[aux-'a'] = 1;
		} else {
			ok = true;
		}
	}

	cout << (ok?"Yes":"No") << endl;
	
	return 0;
}