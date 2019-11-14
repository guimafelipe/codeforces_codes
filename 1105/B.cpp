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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int i = 0, j = 0;
	int countLetras[30] = {0};
	while(i < n){
		char currLetra = s[i];
		int count = 1;
		// printf("%c %d\n", s[i], count);
		while(i < n-1 && s[i+1] == currLetra && count < k){
			count++;
			i++;
			// printf("%c %d\n", s[i], count);
		}
		if(count == k){
			countLetras[currLetra - 'a']++;
		}
		i++;
	}
	int resp = 0;
	for(int i = 0; i < 28; i++){
		resp = max(resp, countLetras[i]);
	}
	cout << resp << endl;
	return 0;
}