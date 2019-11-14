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

bool intersect(ii seg1, ii seg2){
	if(seg1.st <= seg2.st){
		if(seg1.nd >= seg2.nd){
			return true;
		}
		if(seg1.nd >= seg2.st){
			return true;
		}
	}
	if(seg1.st >= seg2.st){
		if(seg1.nd <= seg2.nd){
			return true;
		}
		if(seg1.st <= seg2.nd){ 
			return true;
		}
	}
	return false;
}

ii unify(ii seg1, ii seg2){
	return mp(min(seg1.st, seg2.st), max(seg1.nd, seg2.nd));
}

bool comp1(iii a, iii b){
	return a.nd < b.nd;
}

int main(){
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n;
		vector<iii> pares;
		vector<int> flag;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			pares.pb(mp(i, mp(x,y)));
			flag.pb(0);
		}
		sort(all(pares), &comp1);
		ii grupo = pares[0].nd;
		flag[pares[0].st] = 1;
		int  i = 1;
		while(i < n && intersect(pares[i].nd, grupo)){
			grupo = unify(grupo, pares[i].nd);
			flag[pares[i].st] = 1;
			i++;
		}
		if(i == n){
			cout << "-1";
		} else {
			for(int i = 0; i < n; i++){
				cout << flag[i]+1 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}