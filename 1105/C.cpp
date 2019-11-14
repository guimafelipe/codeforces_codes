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
#define PI 3.14159265

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int n, l, r;
int nr[3];
ll PD[200006][3];
ll result = 0LL;

ll pd(int i, int resto){
	if(i == n){
		if(resto == 0) return 1;
		return 0;
	}

	ll &mem = PD[i][resto];
	if(mem != -1) return mem;

	ll resp = 0LL;
	resp += (pd(i+1, resto)*nr[0])%MOD;
	resp += (pd(i+1, (resto + 1)%3)*nr[1])%MOD;
	resp = resp%MOD;
	resp += (pd(i+1, (resto + 2)%3)*nr[2])%MOD;
	resp = resp%MOD;
	return mem = resp;
}

int main(){
	cin >> n >> l >> r;
	int qnt = (r+1-l);
	int q = qnt/3;
	nr[0] = nr[1] = nr[2] = q;
	if(qnt % 3 >= 1){
		int restPrim = (l%3);
		nr[restPrim]++;
	}
	if(l < r && (qnt % 3) >= 2){
		int restSec = ((l+1)%3);
		nr[restSec]++;
	}

	memset(PD, -1, sizeof PD);
	cout << pd(0, 0)  << endl;

	return 0;
}