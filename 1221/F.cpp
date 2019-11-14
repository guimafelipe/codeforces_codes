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

struct range{
	int x, y, c;
}

int main(){
	int n;
	scanf("%d", &n);

	vector<range> ranges(n);

	FOR(i,0,n){
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		if(y < x){
			swap(x,y);
		}
		range r; r.x = x; r.y = y; r.c = c;
		ranges[i] = r;
	}

	return 0;
}