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

int getAlg(char c){
	return (int)(c - '0');
}

char getChar(int x){
	return (char)(x + '0');
}

string soma(string str1, string str2){
	reverse(all(str1));
	reverse(all(str2));
	string ans;
	int i = 0, j = 0, n1 = sz(str1), n2 = sz(str2);
	int c = 0;
	while(i < n1 && j < n2){
		int x = getAlg(str1[i]);
		int y = getAlg(str2[j]);
		int res = (x+y+c)%10;
		ans.pb(getChar(res));
		c = (x+y+c) >= 10 ? 1 : 0; 
		i++; j++;
	}
	while(i < n1){
		int x = getAlg(str1[i]);
		int res = (x+c)%10;
		ans.pb(getChar(res));
		c = (x+c) >= 10 ? 1 : 0; 
		i++;
	}
	while(j < n2){
		int y = getAlg(str2[j]);
		int res = (y+c)%10;
		ans.pb(getChar(res));
		c = (y+c) >= 10 ? 1 : 0; 
		j++;
	}
	if(c == 1){
		ans.pb(getChar(1));
	}
	reverse(all(ans));
	return ans;
}

bool isBigger(string str1, string str2){
	int n = sz(str1);
	if(sz(str1) > sz(str2)){
		return true;
	}
	if(sz(str1) < sz(str2)){
		return false;
	}

	int i = 0;
	// Nao checa igualdade
	while(i < n && str1[i] == str2[i]){
		i++;
	}
	if(i == n) return true;

	return str1[i] > str2[i];

}

int main(){
	int n;
	string str;
	cin >> n;
	cin >> str;

	int mid1 = n/2;
	int mid2 = mid1+1;
	while(str[mid1] == '0'){
		mid1--;
	}
	while(str[mid2] == '0'){
		mid2++;
	}

	string ans1 = soma(str.substr(0, mid1), str.substr(mid1));
	string ans2 = soma(str.substr(0, mid2), str.substr(mid2));

	if(isBigger(ans1, ans2)){
		cout << ans2 << endl;
	} else {
		cout << ans1 << endl;
	}

	return 0;
}