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

string result;

vi prefix(string s){
	vi b(sz(s)+1, -1);
	int m = sz(s);
	for(int i = 0, j=-1; i<m;){
		while(j >= 0 && s[i] != s[j]){
			j = b[j];
		}
		b[++i] = ++j;
	}
	return b;
}

void merge(string s){
	string cat = s;
	cat.pb('#');
	cat.append(result.substr(max(0,sz(result)-sz(s))));
	vi z = prefix(cat);
	int tam = z.back();
	for(int i = tam; i < sz(s); i++){
		result.pb(s[i]);
	}
}

int main(){
	int n;
	cin >> n;
	cin >> result;
	FOR(i,1,n){
		string s;
		cin >> s;
		merge(s);
	}
	cout << result << endl;
	return 0;
}