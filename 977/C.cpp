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
	int n,k;
	vector<int> seq;
	cin >> n >> k;
	seq.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &seq[i]);
	}

	sort(all(seq));

	if(k == 0){
		int resp = seq[0] - 1;
		if(resp < 1) resp = -1;
		cout << resp << endl;
		return 0;
	}

	int resp = seq[k-1];

	if(k < n && seq[k-1] == seq[k]){
		resp = -1;
	}

	// if(resp < 1) resp = -1;

	cout << resp << endl;
	return 0;
}