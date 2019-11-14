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
	string command;
	while(cin >> command){
		if(command == "mistake" || command == "end"){
			break;
		}
		char resp;
		int perguntas = 0;

		printf("? 0 1\n");
		perguntas++;
		fflush(stdout);
		scanf(" %c", &resp);
		if(resp == 'e'){
			return 0;
		}
		if(resp == 'x'){
			printf("! 1\n");
			continue;
		}
		int x = 1, y = 2, mid;
		for(int i = 1; i < 60; i++){
			printf("? %d %d\n", x, y);
			perguntas++;
			fflush(stdout);

			scanf(" %c", &resp);
			if(resp == 'e'){
				return 0;
			}
			if(resp == 'y'){
				y <<= 1;	
				x <<= 1;
			} else {
				break;
			}
		}
		int menor = x++;
		y;
		while(x < y){
			mid = (x+y)/2;
			printf("? %d %d\n", menor, mid);
			perguntas++;
			fflush(stdout);

			scanf(" %c", &resp);
			if(resp == 'e'){
				return 0;
			}
			if(resp == 'y'){
				x = mid+1;
			} else {
				y = mid;
			}
		}

		printf("! %d\n", (x+y)/2);
	}
	return 0;
}