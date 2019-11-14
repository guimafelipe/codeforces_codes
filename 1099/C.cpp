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

char str[205], result[205], curr[305];
int n;
int m;

int PD[205][205] = {0};

void pd(int i, char* curr){
	int j = strlen(curr);

	// printf("i = %d, curr = %s\n", i, curr);
	if(PD[i][j] != 0) return;

	if(i == m && j == n){
		strcpy(result, curr);
		return;
	}
	if(i >= m) return;
	if(j >= n + 10) return;
	char curchar = str[i];
	// cout << curchar << endl;
	if(curchar == '?'){
		pd(i+1, curr);

		char last = curr[j-1];
		curr[j-1] = '\0';
		pd(i+1, curr);
		curr[j-1] = last;
	}
	else if(curchar == '*'){
		pd(i+1, curr);

		char last = curr[j-1];
		curr[j-1] = '\0';
		pd(i+1, curr);
		curr[j-1] = last;

		curr[j] = last;
		curr[j+1] = '\0';
		pd(i, curr);
		curr[j] = '\0';
	} else {
		curr[j] = str[i];
		curr[j+1] = '\0';
		pd(i+1, curr);
		curr[j] = '\0';
	}

	PD[i][j] = 1;
}

int main(){
	scanf(" %s", str);
	cin >> n;
	m = strlen(str);
	curr[0] = '\0';

	pd(0, curr);
	if(result[0] == '\0'){
		strcpy(result, "Impossible");
	}
	printf("%s\n", result);
	return 0;
}