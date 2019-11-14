#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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

deque<ll> fin;
set<ll> nbr;
int n;
bool achou = false;

void show_result(){
	while(!fin.empty()){
		cout << fin.front() << " ";
		fin.ppf();
	}
	cout << endl;
}

void tenta_montar(int qnt){
	// cout << "tam = " << qnt << endl;
	// cout << "size = " << fin.size() << endl;
	if(achou) return;
	if(qnt == n){
		achou = true;
		show_result();
	}
	ll fr = fin.front();
	ll bk = fin.back();
	if(!(fr%2) && nbr.find(fr/2) != nbr.end()){
		fin.pf(fr/2);
		nbr.erase(fr/2);
		// cout << "tenta botar " << fr/2 << " na frente\n";
		tenta_montar(qnt+1);
		fin.ppf();
		nbr.insert(fr/2);
	}
	if(nbr.find(fr*3)!=nbr.end()){
		fin.pf(fr*3);
		nbr.erase(fr*3);
		// cout << "tenta botar " << fr*3 << " na frente\n";
		tenta_montar(qnt+1);
		fin.ppf();
		nbr.insert(fr*3);
	}
	if(!(bk%3) && nbr.find(bk/3)!=nbr.end()){
		fin.pb(bk/3);
		nbr.erase(bk/3);
		// cout << "tenta botar " << bk/3 << " atras\n";
		tenta_montar(qnt+1);
		fin.ppb();
		nbr.insert(bk/3);
	}
	// cout << "bk = " << bk << endl;
	// if(bk == 4){
	// 	cout << "bagulho = " << (nbr.find(bk*2)!=nbr.end()) << endl;
	// }
	if(nbr.find(bk*2)!=nbr.end()){
		fin.pb(bk*2);
		nbr.erase(bk*2);
		// cout << "tenta botar " << bk*2 << " atras\n";
		tenta_montar(qnt+1);
		fin.ppb();
		nbr.insert(bk*2);
	}
}

int main(){
	cin >> n;
	for(int i = 0; i<n; i++){
		ll aux;
		cin >> aux;
		nbr.insert(aux);
	}

	fin.pb((*(nbr.begin())));
	tenta_montar(1);
	return 0;
}