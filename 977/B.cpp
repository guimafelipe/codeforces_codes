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
	
	map<string, int> hash;

	int n; char ant, curr;
	cin >> n;
	scanf(" %c", &ant);
	for(int i = 1; i < n; i++){
		scanf(" %c", &curr);
		string aux;
		aux.append(1u, ant);
		aux.append(1u, curr);
		if(hash.find(aux) == hash.end()){
			hash[aux] = 0;
		}
		hash[aux]++;
		ant = curr;
	}

	map<string, int>::iterator it;

	string sol; int rec = 0;
	for(it = hash.begin(); it!=hash.end(); it++){
		if(it->second > rec){
			rec = it->second;
			sol = it->first;
		}
	}
	cout << sol << endl;
	return 0;
}