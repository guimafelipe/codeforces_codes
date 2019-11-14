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
int n;

int countCurrMax(){
	int actualMax = 1, currMax = 1;
	char ant = str[0];
	for(int i = 1; i < n; i++){
		if(str[i] != ant){
			currMax++;
		} else {
			actualMax = max(actualMax, currMax);
			currMax = 1;
		}
		ant = str[i];
	}
	actualMax = max(actualMax, currMax);
	return actualMax;
}

int main(){
	cin >> str;
	str += str;
	n = str.size();
	cout << min(n/2, countCurrMax()) << endl;
	return 0;
}