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

int n;
int a[1005];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int bestCusto = INF;
	int bestT = 0;
	for(int t = 1; t <= 100; t++){
		int currCusto = 0;
		for(int i = 0; i < n; i++){
			int newA = a[i], currA = a[i];
			if(currA < t) newA = t-1;
			else if(currA > t) newA = t+1;
			currCusto += abs(currA - newA);
		}
		if(currCusto < bestCusto){
			bestCusto = currCusto;
			bestT = t;
		}
	}
	cout << bestT << " " << bestCusto << endl;
	return 0;
}