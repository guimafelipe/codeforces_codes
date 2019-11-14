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

int n, k;
int packages[102] = {0};
int npserson[102] = {0};

int main(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		int aux;
		scanf("%d", &aux);
		packages[aux]++;
	}

	int maxdias = k;

	for(int i = 0; i < n; i++){
		int currmax = -1;
		int currmaxind = 0;
		for(int j = 1; j <= 100; j++){
			if(packages[j] == 0) continue;
			if(packages[j]/(npserson[j]+1) > currmax){
				currmax = packages[j]/(npserson[j]+1);
				currmaxind = j;
			}
		}
		npserson[currmaxind]++;
	}
	for(int i = 1; i <= 100; i++){
		if(packages[i] != 0 && npserson[i] != 0)
			maxdias = min(maxdias, packages[i]/npserson[i]);
	}

	cout << maxdias << endl;
	
	return 0;
}