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

bool stages[29] = {0};

int n, k;

int main(){
	cin >> n >> k;
	char c;
	for(int i = 0; i < n; i++){
		scanf(" %c", &c);
		stages[c-'a'] = true;
	}

	int counter = 0, peso = 0;
	int i = 0;

	for(i = 0; i < 27; i++){
		if(stages[i]){
			// cout << "add "<< (char)(i + 'a') << endl;
			counter++;
			peso+=(i+1);
			i++;
		}
		if(counter == k){
			break;
		}
	}

	if(counter == k) cout << peso << endl;
	else cout << "-1\n";
	
	return 0;
}