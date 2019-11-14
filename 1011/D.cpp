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

int n, m;
bool ehmentira[30] = {0};
int main(){
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		cout << 1 << endl;
		fflush(stdout);
		int ans;
		cin >> ans;
		fflush(stdout);
		if(ans == 0) exit(0);
		if(ans == -1) ehmentira[i] = true;
		if(ans == 1) ehmentira[i] = false;
	}
	int maxi = m+1;
	int mini = 0;
	int counter = 0;
	int ans;
	while(mini < maxi){
		int mid = (mini + maxi)/2;
		cout << mid << endl;
		fflush(stdout);
		cin >> ans;
		fflush(stdout);
		if(ans == 0 || ans == -2) exit(0);
		if(ans == -1){
			if(ehmentira[counter%n])
				mini = mid;
			else maxi = mid +1;
		}
		if(ans == 1){
			if(ehmentira[counter%n])
				maxi = mid+1;
			else mini = mid;
		}	
		counter++;
	}
	
	return 0;
}