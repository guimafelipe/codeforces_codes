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
	int n, m, r;
	cin >> n >> m >> r;
	int bestMorning = 100000, bestEvening = 0;
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		bestMorning = min(bestMorning, aux);
	}
	for(int i = 0; i < m; i++){
		int aux;
		scanf("%d", &aux);
		bestEvening = max(bestEvening, aux);
	}

	if(bestMorning > bestEvening){
		cout << r;
	} else {
		int compradas = r/bestMorning;
		r = r%bestMorning;
		r+= compradas*bestEvening;
		cout << r;
	}
	cout << endl;
	
	return 0;
}