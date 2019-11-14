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

string str;
int PD[500005][6];
const int ruim = -1000000;


int pd(int i, int estado){
	int &mem = PD[i][estado];
	if(mem != -1) return mem;
	if(i == str.size()) return ruim;

	int resp = ruim;

	if(estado == 0 && str[i] == '['){
		resp = max(resp, 1 + pd(i+1, 1));
	}
	if(estado == 1 && str[i] == ':'){
		resp = max(resp, 1 + pd(i+1, 2));
	}
	if(estado == 2){
		if(str[i] == '|'){
			resp = max(resp, 1 + pd(i+1, 2));
		}
		if(str[i] == ':'){
			resp = max(resp, 1 + pd(i+1, 3));
		}
	}
	if(estado == 3 && str[i] == ']'){
		resp = 1;
	}
	resp = max(resp, pd(i+1, estado));
	// printf("pos %d, estado %d, resp %d\n", i, estado, resp);
	return mem = resp;
}

int main(){
	cin >> str;
	memset(PD, -1, sizeof PD);
	int resp = pd(0,0);
	if(resp < 0) resp = -1;
	cout << resp << endl;
	return 0;
}