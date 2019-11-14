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
	ll counter[3] = {0};
	ll n;
	cin >>n;
	ll target = n/3;
	string word;
	cin >> word;
	for(ll i = 0; i < n; i++){
		counter[word[i] - '0']++;
	}

	for(ll i = 0; i < n; i++){
		if(counter[0] < target && word[i] != '0' && counter[word[i] - '0'] > target){
			counter[word[i]-'0']--;	
			word[i] = '0';
			counter[0]++;
		}
	}

	for(ll i = n-1; i >= 0; i--){
		if(counter[2] < target && word[i] != '2' && counter[word[i] - '0'] > target){
			counter[word[i]-'0']--;	
			word[i] = '2';
			counter[2]++;
		}
	}

	if(counter[1] < target){
		if(counter[2] > target){
			for(ll i = 0; i < n; i++){
				if(word[i] == '2' && counter[1] < target && counter[2] > target){
					word[i] = '1';
					counter[1]++;	
					counter[2]--;
				}
			}
		}
		if(counter[0] > target){
			for(ll i = n-1; i >= 0; i--){
				if(word[i] == '0' && counter[1] < target && counter[0] > target){
					word[i] = '1';
					counter[1]++;	
					counter[0]--;
				}
			}
		}
	}

	cout << word << endl;

	return 0;
}