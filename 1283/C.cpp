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

int main(){
	int n;
	scanf("%d", &n);
	int f[200100];
	bool rec[200100], vis[200100];
	FOR(i,1,n+1){
		scanf("%d", &f[i]);
		rec[f[i]] = true;
	}

	int nextToVis = 1, ant = -1;
	for(int i = 1; i <= n ; i++){
		if(!vis[i]){
			int curr = i;
			while(!vis[curr]){
				if(f[curr] == 0){
					while(rec[nextToVis]){
						nextToVis++;
					}
					if(nextToVis != curr){
						f[curr] = nextToVis;
						rec[nextToVis] = true;
					} else if(ant != -1){
						f[curr] = nextToVis;
						rec[nextToVis] = true;
						swap(f[curr], f[ant]);
					} else {
						int bnext = nextToVis+1;
						while(rec[bnext]){
							bnext++;
						}
						f[curr] = bnext;
						rec[bnext] = true;
					}
					ant = curr;
				}
				vis[curr] = true;
				curr = f[curr];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", f[i]);
	}
	printf("\n");

	return 0;
}
