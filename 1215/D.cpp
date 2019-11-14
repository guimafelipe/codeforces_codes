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
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;

	ll sum1 = 0, sum2 = 0;
	int pos1 = 0, pos2 = 0;
	FOR(i,0,n/2){
		if(s[i] == '?'){
			pos1++;
		} else {
			sum1+= (int)(s[i]-'0');
		}
	}
	FOR(i,n/2,n){
		if(s[i] == '?'){
			pos2++;
		} else {
			sum2+= (int)(s[i]-'0');
		}
	}

	if(sum1 < sum2){
		swap(sum1,sum2);
		swap(pos1,pos2);
	}

	if(pos1 > pos2){
		cout << "Monocarp\n";
		return 0;
	}
	pos2 -= pos1;
	sum2 += (pos2/2)*9;
	if(sum2 == sum1){
		cout << "Bicarp\n";
	} else {
		cout << "Monocarp\n";
	}
	return 0;

	return 0;
}