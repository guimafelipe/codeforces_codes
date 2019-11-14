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

int c[102];

int PD[102][10004];

int pd(int i, int tons){
	if(i <= 0){
		return 0;
	}
	int &ans = PD[i][tons];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	if(tons >= i*c[i]){
		ans = max(ans, pd(i-1, tons - i*c[i])+1);
	}
	ans = max(ans, pd(i-1, tons));
	return ans;
}

int main(){
	int n, x;
	FILE* arq, *res;
	arq = fopen("input.txt", "r");
	res = fopen("output.txt", "w");
	fscanf(arq, "%d%d", &n, &x);
	FOR(i, 1, n+1){
		fscanf(arq, "%d", c+i);
	}
	reverse(c+1, c+n+1);
	memset(PD, -1, sizeof PD);
	fprintf(res, "%d\n", pd(n, x));
	fclose(res);
	fclose(arq);

	return 0;
}