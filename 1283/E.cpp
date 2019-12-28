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
	int arr[200100];
	int casas[200100] = {0};
	int casas2[200100] = {0};
	FOR(i,0,n){
		scanf("%d", arr+i);
		casas[arr[i]]++;
		casas2[arr[i]]=1;
	}

	sort(arr, arr+n);

	bool mrc[200100] = {false};
	int maxi = 0;
	for(int i = 0; i < n; i++){
		int x = arr[i];	
		if(!mrc[x-1]){
			maxi++;
			mrc[x-1] = true;
		} else if(!mrc[x]){
			maxi++;
			mrc[x] = true;
		} else if(!mrc[x+1]){
			maxi++;
			mrc[x+1] = true;
		}
	}

	bool marc[200100] = {false};
	int mini = 0;
	for(int i = 1; i <= n; i++){
		if(casas2[i] > 0){
			if(!marc[i-1] && !marc[i] && !marc[i+1]){
				mini++;
				marc[i+1] = true;
			}
		}
	}

	printf("%d %d\n", mini, maxi);

	return 0;
}
