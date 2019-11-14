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

typedef unsigned int ui;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

bool checkCorrectness(int x){
	ui aux = 1;
	for(ui i = 1; i <= 32; i++){
		if(!(((aux << i)-1)^x)){
			return true;
		}
	}
	return false;
}

int main(){
	ui x;
	cin >> x;
	if(checkCorrectness(x)){
		cout << "0\n";
		return 0;
	}
	ui i, n;
	ui aux = 1<<31;
	n = 31;
	vi ns;
	ui times = 0;
	while(!(aux&x)){
		aux >>= 1;
		n--;
		// cout << aux << endl;
	}
	while(n){
		while(aux&x){
			aux >>= 1;
			n--;
		}
		// cout << n+1<<endl;
		ns.pb(n+1);
		x ^= (1<<(n+1))-1;
		times++;
		// cout << "x: " << x << endl;
		if(checkCorrectness(x)) break;
		x++; times++;
		// cout << "x: " << x << endl;
		if(checkCorrectness(x)) break;
	}

	cout << times << endl;
	for(int i = 0; i < sz(ns);i++){
		printf("%d ", ns[i]);
	}
	cout << endl;

	return 0;
}