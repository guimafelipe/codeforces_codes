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
	int t;
	cin >> t;
	while(t--){
		int a, b, c, d;
		int x, y, x1, y1, x2 ,y2;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);
		int dx = b - a;
		int dy = d - c;
		if(x1 == x2 && (a != 0 || b != 0)){
			cout << "No\n";
			continue;
		}
		if(y1 == y2 && (c != 0 || d != 0)){
			cout << "No\n";
			continue;
		}
		if(x + dx < x1 || x + dx > x2){
			cout << "No\n";
			continue;
		}
		if(y + dy < y1 || y + dy > y2){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}
	return 0;
}
