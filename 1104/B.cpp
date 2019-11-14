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
	stack<char> pilha;
	string str;
	cin >> str;
	int plays = 0;
	for(int i = 0; i < sz(str); i++){
		char curr = str[i];
		if(sz(pilha) != 0){
			if(pilha.top() == curr){
				pilha.pop();
				plays++;
			} else {
				pilha.push(curr);
			}
		} else {
			pilha.push(curr);
		}
	}

	int resto = plays%2;

	cout << (resto ? "Yes" : "No") << endl;

	return 0;
}