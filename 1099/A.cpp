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
	int w, h, u1, d1, u2, d2;
	cin >> w >> h;
	cin >> u1 >> d1;
	cin >> u2 >> d2;

	for(int i = h; i>0; i--){
		w+=i;
		if(i == d1) w-=u1; 
		if(i == d2) w-=u2; 
		if(w < 0) w = 0;
	}

	cout << w << endl;

	return 0;
}