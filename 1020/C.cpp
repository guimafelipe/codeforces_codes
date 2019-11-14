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

#define MAXN 3004

int partidos[MAXN];
priority_queue<ii> voters;

int n, m;

int get_curr_max(){
	int resp = -1;
	for(int i = 2; i <= m; i++){
		resp = max(resp, partidos[i]);
	}
	return resp;
}

int main(){
	memset(partidos, 0, sizeof partidos);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int party, price;
		scanf("%d %d", &party, &price);
		if(party != 1){
			voters.push(mp(-price, party));
		}
		partidos[party]++;
	}

	int maxi = get_curr_max(), gasto = 0;
	while(partidos[1] <= maxi){
		ii front = voters.top();
		voters.pop();
		gasto -= front.st;
		partidos[front.nd]--;
		partidos[1]++;
		maxi = get_curr_max();
	}

	
	return 0;
}