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
	int q;
	cin >> q;
	for(int Q = 0; Q < q;  Q++){
		int n;
		cin >> n;
		if(n == 2){
			char a, b;
			scanf(" %c%c", &a, &b);
			if(a < b){
				cout << "YES\n";
				printf("2\n%c %c\n", a, b);
			}  else {
				printf("NO\n");
			}
		} else {
			char str[305];
			scanf("%s", str);
			printf("YES\n2\n");
			printf("%c %s\n", str[0], str+1);
		}
	}
	return 0;
}