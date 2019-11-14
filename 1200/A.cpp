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

int h[10];

bool isDigit(char c){
	return c!='L' && c!='R';
}

void tira(int x){
	h[x]=0;
}

void entra(char c){
	if(c == 'L'){
		FOR(i,0,10){
			if(!h[i]){
				h[i]=1;
				break;
			}
		}
	}else {
		RFOR(i,9,0){
			if(!h[i]){
				h[i]=1;
				break;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	FOR(i,0,n){
		char c;
		scanf(" %c", &c);
		if(isDigit(c)){
			tira(c-'0');
		}
		else{
			entra(c);
		}
	}
	FOR(i,0,10){
		printf("%d", h[i]);
	}
	printf("\n");
	return 0;
}