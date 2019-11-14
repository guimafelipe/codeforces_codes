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

#define yes "YES"
#define no "NO"

int main(){
	int k, n;	
	cin >> n >> k;
	bool deuruim = false;
	map<int, int> hash;
	vector<int> cores;
	cores.resize(n);
	int ncolors = 0;
	for(int i = 0; i < n; i++){
		int c;
		scanf(" %d", &c);
		cores[i] = c;
		if(hash.find(c) == hash.end()){
			hash[c] = 0;
			ncolors++;
		} 
		hash[c]++;
		if(hash[c] > k) deuruim = true;
	}

	cout << (deuruim ? no : yes) << endl;

	if(!deuruim){
		int currColor = 0;
		map<int, int> inicial;
		map<int, int>::iterator it;
		for(it = hash.begin(); it != hash.end(); it++){
			inicial[it->st] = currColor;
			currColor += it->nd;
			currColor = (currColor%k);
		}

		for(int i = 0; i < n; i++){
			int cor = cores[i];
			int newcolor = inicial[cor];
			printf("%d ", newcolor + 1);
			inicial[cor]++;
			inicial[cor] = inicial[cor] % k;
		}

		cout << endl;
	}

	return 0;
}