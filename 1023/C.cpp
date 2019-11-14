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
typedef pair<char, int> ci;

int n, k;
string bracks;

stack<ci> pilha;

vi retirados;

void analisa(){
	int i = 0;
	int counter = 0;
	int m = bracks.size();
	for(int i = 0; i < m and counter < (n-k); i++){
		if(pilha.empty()){
			pilha.push(mp(bracks[i], i));
			continue;
		}
		if(bracks[i] == ')'){
			ci front = pilha.top();
			pilha.pop();
			char brak = front.st;
			int ind = front.nd;
			retirados[ind] = 1;
			retirados[i] = 1;
			counter += 2;
		} else {
			pilha.push(mp(bracks[i], i));
		}
	}
}

int main(){
	cin >> n >> k;
	cin >> bracks;

	vi ret (bracks.size(), 0);

	retirados = ret;

	if(n == k){
		cout << bracks << endl;
		return 0;
	}

	analisa();

	for(int i = 0; i < bracks.size(); i++){
		if(retirados[i] == 1) continue;
		cout << bracks[i];
	}
	cout << endl;
	
	return 0;
}