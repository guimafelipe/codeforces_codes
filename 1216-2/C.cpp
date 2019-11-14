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

struct Rect{
	ll x1, x2, y1, y2;
	ll area(){
		return max(0LL, x2-x1)*max(0LL, y2-y1);
	}
	void print(){
		printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
	}
};



int main(){

	Rect r[3];
	FOR(i,0,3){
		ll x1, x2, y1, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		Rect rec;
		rec.x1 = x1; rec.x2 = x2; rec.y1 = y1; rec.y2 = y2;
		r[i] = rec;
	}

	FOR(i,1,3){
		Rect rec = r[i];
		Rect ori = r[0];
		r[i].x1 = max(ori.x1, rec.x1);
		r[i].y1 = max(ori.y1, rec.y1);
		r[i].x2 = min(ori.x2, rec.x2);
		r[i].y2 = min(ori.y2, rec.y2);
	}

	ll area0 = r[0].area();
	ll area1 = r[1].area();
	ll area2 = r[2].area();
	Rect interc;
	interc.x1 = max(r[2].x1, r[1].x1);
	interc.y1 = max(r[2].y1, r[1].y1);
	interc.x2 = min(r[2].x2, r[1].x2);
	interc.y2 = min(r[2].y2, r[1].y2);
	ll areaInt = interc.area();

	// printf("\n");
	// r[0].print();
	// r[1].print();
	// r[2].print();
	// interc.print();

	// cout << area0 << endl;
	// cout << area1 << endl;
	// cout << area2 << endl;
	// cout << areaInt << endl;

	if(area1 + area2 - areaInt == area0){
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}

	return 0;
}