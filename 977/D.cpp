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
typedef vector<unsigned ll> vull;

int main(){
	int n;
	vll nbr;
	vvi ind;
	vector<bool> visited;
	scanf("%d", &n);
	nbr.resize(n);
	ind.resize(n);
	visited.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &nbr[i]);
		ind[i].resize(0);
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!(nbr[i]%3) && nbr[i]/3 == nbr[j]){
				ind[i].pb(j);
			}
			if(nbr[i]*2=nbr[j]){
				ind[i].pb(j);
			}
		}
	}
	stack<ll> topol;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			
		}
	}



	return 0;
}