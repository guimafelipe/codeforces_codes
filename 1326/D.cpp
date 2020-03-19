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

void print(vector<int> A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

vector<int> LPS(string pat) {
	vector<int> ans(pat.size());

	ans[0] = 0;
	int j = 0;
	int i = 1;

	while (i < pat.size()) {
		if (pat[i] == pat[j])
			ans[i++] = ++j;
		else if (j == 0)
			ans[i++] = 0;
		else
			j = ans[j-1];
	}

	return ans;
}

string getBiggestPal(string ns){
	string nr = ns;
	reverse(all(nr));

	string s = ns;
	s.append(nr);
	string r = nr;
	r.append(ns);

	vi lpss = LPS(s);
	vi lpsr = LPS(r);

	/*
	cout << s << endl;

	print(lpss);

	cout << r << endl;
	print(lpsr);
	*/

	if(lpss.back() > lpsr.back()){
		return s.substr(0, lpss.back());
	} else {
		return r.substr(0, lpsr.back());
	}

}

string solvre(string s){
	int n = sz(s);
	int i = 0, j = n-1;
	while(j > i && s[i] == s[j]){
		i++; j--;
	}
	if(j <= i){
		return s;
	}
	string t = s.substr(i, j+1-i);

	string start = s.substr(0, i);
	string middle = getBiggestPal(t);
	string end = start;
	reverse(all(end));

	string res = "";
	res.append(start);
	res.append(middle);
	res.append(end);

	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << solvre(s) << endl;
	}
	return 0;
}
