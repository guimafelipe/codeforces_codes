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
	int n, m;
	cin >> n >> m;
	vi levels;
	levels.resize(m, 0);
	for(int i = 0; i < m; i++){
		scanf("%d", &levels[i]);
	}
	map<int, int> hash;
	for(int i = 0; i < m; i++){
		bool can_do = false;
		int lvl = levels[i];
		if(hash.find(lvl) == hash.end()){
			hash[lvl] = 0;
		}
		hash[lvl]++;
		if(hash.size() == n){
			can_do = true;
			map<int, int>::iterator it;
			for(it =  hash.begin(); it!=hash.end(); it++){
				it->nd--;
			}
			vi zerados;
			for(it =  hash.begin(); it!=hash.end(); it++){
				if(it->nd == 0){
					zerados.pb(it->st);
				}	
			}
			for(int i = 0; i < zerados.size(); i++){
				hash.erase(zerados[i]);
			}
		}
		cout << (can_do ? '1' : '0' );
	}
	cout << endl;
	return 0;
}