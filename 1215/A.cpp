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
typedef pair<ll,ll> pll;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int getMax(int a1, int a2, int k1, int k2, int n){
	int exp1, exp2;
	int ans = 0;
	if(k1 < k2){
		while(a1 > 0 && n >= k1){
			ans++;
			n-=k1;
			a1--;
		}
		while(a2 > 0 && n >= k2){
			ans++;
			n-=k2;
			a2--;
		}
	} else {
		while(a2 > 0 && n >= k2){
			ans++;
			n-=k2;
			a2--;
		}
		while(a1 > 0 && n >= k1){
			ans++;
			n-=k1;
			a1--;
		}
	}
	return ans;
}

int getMin(int a1, int a2, int k1, int k2, int n){
	int maxCard = a1*(k1-1) + a2*(k2-1);
	n -= maxCard;
	return max(0, n);
}

int main(){
	int a1, a2, k1, k2, n;
	scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2,&n);

	printf("%d %d\n", getMin(a1,a2,k1,k2,n), getMax(a1,a2,k1,k2,n));

	return 0;
}