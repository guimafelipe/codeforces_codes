#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-8
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

int n, m;
vi lift, land;

double simulation(double fuel){
	for(int i = 0; i < n; i++){
		fuel -= (fuel+m)/(double)lift[i];
		fuel -= (fuel+m)/(double)land[(i+1)%n];
		if(fuel < -EPS) break;
	}
	return fuel;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		lift.pb(aux);
	}
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		land.pb(aux);
	}
	double max_fuel = 1000000000.0;
	double min_fuel = 0.0;
	double ans;
	bool achou = false;
	while(max_fuel - min_fuel > EPS){
		double mid = 0.5*min_fuel + 0.5*max_fuel;
		double result = simulation(mid);
		if(result > EPS){
			max_fuel = mid;
		} else if(result < -EPS){
			min_fuel = mid;
		} else {
			ans = mid;
			achou = true;
			break;
		}
	}
	if(achou)
		printf("%.10lf\n",ans);
	else 
		cout << "-1\n";
	// cout << simulation(10.0) << endl;
	
	return 0;
}