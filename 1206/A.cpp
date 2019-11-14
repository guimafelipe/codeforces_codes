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

int main(){
	int n,m;
	cin >> n;
	vi ar1, ar2;

	set<int> set1, set2;
	FOR(i, 0, n){
		int aux;
		scanf("%d", &aux);
		ar1.pb(aux);
		set1.insert(aux);
	}

	cin >> m;
	FOR(i, 0, m){
		int aux;
		scanf("%d", &aux);
		ar2.pb(aux);
		set2.insert(aux);
	}

	FOR(i, 0, n){
		FOR(j, 0, m){
			int a = ar1[i], b = ar2[j];
			int soma = a+b;
			if((!set1.count(soma)) && (!set2.count(soma))){
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}

	return 0;
}