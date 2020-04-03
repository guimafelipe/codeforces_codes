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

void print(vi arr){
	for(int i : arr){
		printf("%d ", i);
	}
	printf("\n");
}

void normalize(vi &car){
	map<int, int> transf;
	int curr = 1;
	for(int i = 0; i < sz(car); i++){
		if(transf.find(car[i]) == transf.end()){
			transf[car[i]] = curr++;
		}
	}
	for(int i = 0; i < sz(car); i++){
		car[i] = transf[car[i]];
	}
}

void solvre(int n, vi &car){
	normalize(car);

	// print(car);

	vi res(n);

	res[0] = 1;

	int used = 1;
	bool temrep = false;

	for(int i = 1; i < n; i++){
		if(car[i] == car[i-1]){
			res[i] = res[i-1];
			temrep = true;
		} else {
			if(res[i-1] == 1){
				res[i] = 2;
				used = 2;
			} else {
				res[i] = 1;
			}
		}
	}


	if(1 != car[n-1] && 1 == res[n-1]){
		if(car[n-2] == car[n-1]){
			res[n-1] = 2;
		} else if(temrep){
			int i = 1;
			res[0] = 2;
			while(car[i] != car[i-1]){
				if(res[i] == 1){
					res[i] = 2;
				} else {
					res[i] = 1;
				}
				i++;
			}
		} else {
			res[n-1] = 3;
			used = 3;
		}
	}

	printf("%d\n", used);	
	print(res);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		vi car;
		scanf("%d", &n);
		FOR(i,0,n){
			int aux;
			scanf("%d", &aux);
			car.pb(aux);
		}

		solvre(n, car);
	}
	return 0;
}
