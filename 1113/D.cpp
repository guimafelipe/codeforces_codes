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
bool checkImpossible(string str){
	int strSize = str.size();
	char primeiro = str[0];
	int equalsCounter = 0;
	for(int i = 0; i < strSize; i++){
		if(str[i] == primeiro){
			equalsCounter++;
		}
	}
	if(equalsCounter < strSize - 1){
		return false;
	} else {
		return true;
	}
}

bool isPalindrome(string str){
	int n = str.size();
	for(int i = 0; i < n/2; i++){
		if(str[i] != str[n-1-i]) return false;
	}
	return true;
}

bool checkCyclic(string str){
	int n = str.size();
	for(int i = 1; i < n; i++){
		string testStr;
		for(int j = i; j < n; j++) testStr.pb(str[j]);
		for(int j = 0; j < i; j++) testStr.pb(str[j]);
		if(testStr != str && isPalindrome(testStr)) return true;
	}
	return false;
}

int main(){
	cin >> str;

	if(checkImpossible(str)){
		cout << "Impossible\n";
		return 0;
	}

	if(checkCyclic(str)){
		cout << "1\n";
		return 0;
	}

	cout << "2\n";
	return 0;
}