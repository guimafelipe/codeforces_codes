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
#define PI 3.14159265

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

#define MAXN 1000005

int n, k;
string seq;
int dmg[MAXN];

ll analisa(){
	// cout << "oi\n";
	ll resp = 0;
	for(int i = 0; i < n; i++){
		// cout << "Começando " << i << endl;
		char curr = seq[i];
		priority_queue<int> pq;
		pq.push(dmg[i]);
		while(i+1 < n && seq[i+1] == curr){
			i++;
			pq.push(dmg[i]);
			// cout << "Adicionando " << i << endl;
		}
		int cnt = 0; 
		ll curr_ans = 0;
		while(cnt < k && !pq.empty()){
			curr_ans += pq.top();
			// cout << "Somando " <<  pq.top()  << " ";
			// cout << "Total " << curr_ans << endl;
			pq.pop();
			cnt++;
		}
		resp += curr_ans;
		// cout << "Resp " << resp << endl;
	}
	return resp;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n ;i++){
		scanf("%d", &dmg[i]);
	}
	cin >> seq;
	ll resp = analisa();
	cout << resp <<  endl;
	return 0;
}