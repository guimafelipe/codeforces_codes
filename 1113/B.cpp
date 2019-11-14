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
	int n, answer = 0, soma = 0;
	cin >> n;
	vi machines(n);
	for(int i = 0; i < n; i++) scanf("%d", &machines[i]);
	for(int i = 0; i < n; i++) soma += machines[i];
	sort(all(machines));
	int menor = machines[0];
	answer = soma;
	for(int i = n-1; i > 0; i--){
		int curr = machines[i];
		for(int div = curr-1; div >= 2; div--){
			if(curr%div == 0){
				int newAnswer = soma - menor - curr
				+ menor*div + curr/div;
				if(newAnswer > 0) answer = min(answer, newAnswer);
			}
		}
	}

	cout << answer << endl;
	return 0;
}