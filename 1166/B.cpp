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
	int k;
	cin >> k;
	int div1, div2 = -1;
	char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
	for(div1 = 5; div1*div1 <=k; div1++){
		if(k%div1 == 0){
			div2 = k/div1;
			break;
		}
	}

	if(div2 < 5){
		cout << -1 << endl;
		return 0;
	}

	// cout << div1 << " " << div2 << endl;

	FOR(i, 0, div1){
		FOR(j, 0, div2){
			printf("%c", vowels[(i+j)%5]);
		}
		// printf("\n");
	}
	printf("\n");
	return 0;
}