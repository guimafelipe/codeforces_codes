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

int vowel(char c){
	if(c == 'A'){
		return 1;
	}
	if(c == 'E'){
		return 1;
	}
	if(c == 'I'){
		return 1;
	}
	if(c == 'O'){
		return 1;
	}
	if(c == 'U'){
		return 1;
	}
	if(c == 'Y'){
		return 1;
	}
	return 0;
}


int part(int i, vi &prep){
	if(i < 0){
		return 0;
	}
	return prep[i];
}

int vowels(int i, int j, vi &prep){
	return part(j, prep) - part(i-1, prep);
}

int main(){
	string s;
	cin >> s;
	int n = sz(s);
	vi arr(n, 0);
	FOR(i, 0, n){
		if(vowel(s[i])){
			arr[i] = 1;
		}
	}

	double ans = 0.0;

	vi pre, pre2;
	pre[0] = arr[0];
	FOR(i, 1, n){
		pre[i] = pre[i-1]+arr[i];
	}

	pre2[0] = pre[0];
	FOR(i, 1, n){
		pre2[i] = pre2[i-1]+pre[i];
	}

	printf("%.10lf\n", ans);

	return 0;
}