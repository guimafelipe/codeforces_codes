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

int m, n;

bool rec(int ant, int ind, int k, vi &arr){
	if(ind == n) return true;
	int curr = arr[ind];

	// cout << "ant = " << ant << ", ind = " << ind << endl;
	if(curr == ant){
		return rec(ant, ind+1, k, arr);
	}
	if(curr > ant){
		if(ant + (m-curr) <= k){
			return rec(ant, ind+1, k, arr);
		} else {
			return rec(curr, ind+1, k, arr);
		}
	} else {
		if(ant-curr <= k){
			return rec(ant, ind+1, k, arr);
		} else {
			return false;
		}
	}
}

int main(){
	vi arr;
	cin >> n >> m;
	FOR(i,0,n){
		int curr;
		scanf("%d", &curr);
		arr.pb(curr);
	}

	int l = 0, r = m-1;

	while(l < r){
		int mid = (l+r)/2;
		bool res = rec(0, 0, mid, arr);
		if(res){
			r = mid;
		} else {
			l = mid+1;
		}
	}

	cout << (l+r)/2 << endl;

	return 0;
}