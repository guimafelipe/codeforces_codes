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
	vi tabs;
	tabs.resize(n, 0);
	int or_e = 0, or_s = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &tabs[i]);
		tabs[i] == 1 ? or_e++ : or_s++;
	}
	vii counter;
	counter.resize(k, mp(0,0));
	for(int i = 0; i < n; i++){
		if(tabs[i] == 1)
			counter[i%k].st++;
		else
			counter[i%k].nd++;
	}
	int resp = 0;
	for(int i = 0; i < k; i++){
		resp = max(resp, abs((or_e - counter[i].st) - 
			(or_s - counter[i].nd)));
	}
	cout << resp << endl;
	return 0;
}