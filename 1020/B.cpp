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

vi students;
vi culpa;

int comeca(int i){
	int culpado = i;
	while(students[culpado] != 1){
		students[culpado] = 1;
		culpado = culpa[culpado];
	}
	return culpado;
}

int main(){
	int n;
	cin >> n;
	culpa.assign(n+2, 0);
	for(int i = 1; i <= n; i++){
		scanf("%d", &culpa[i]);
	}
	for(int i = 1; i <= n; i++){
		students.assign(n+2, 0);
		printf("%d ", comeca(i));
	}
	cout << endl;
	
	return 0;
}