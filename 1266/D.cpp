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
typedef vector<set<int>> vsi;

void removeLig(int ind, vsi &xfirst, vsi &xsecond, viii &ligacoes){
	int u = ligacoes[ind].nd.st;
	int v = ligacoes[ind].nd.nd;
	xfirst[u].erase(ind);
	xsecond[v].erase(ind);
}

void criaLig(int d, int ind1, int ind2, vsi &xfirst, vsi &xsecond, viii &ligacoes){
	int u = ligacoes[ind1].nd.nd;
	int v = ligacoes[ind2].nd.st;
	ligacoes.pb(mp(d, mp(v,u)));
	int ind = sz(ligacoes) -1;
	xfirst[v].insert(ind);
	xsecond[u].insert(ind);
}

int main(){
	int n, m;
	cin >> n >> m;
	vsi xfirst(n, set<int>());
	vsi xsecond(n, set<int>());
	viii ligacoes;
	for(int i = 0; i < m; i++){
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);
		u--; v--;
		ligacoes.pb(mp(d, mp(u,v)));
		int ind = sz(ligacoes) -1;
		xfirst[u].insert(ind);
		xsecond[v].insert(ind);
	}
	for(int i = 0; i < n; i++){
		//cout << "set first[" << i << "]: ";
		for(int j : xfirst[i]){
		//	cout << j << " ";
		}
		//cout << endl;
	}
	for(int i = 0; i < n; i++){
		//cout << "set second[" << i << "]: ";
		for(int j : xsecond[i]){
		//	cout << j << " ";
		}
		//cout << endl;
	}
	for(int i = 0; i < n; i++){
		while(sz(xfirst[i]) > 0 && sz(xsecond[i]) > 0){
			int ind1 = *(xfirst[i].begin());
			int ind2 = *(xsecond[i].begin());
			int val1 = ligacoes[ind1].st;
			int val2 = ligacoes[ind2].st;
			//printf("Analisando ligacoes %d e %d\n", ind1, ind2);
			if(val1 == val2){
				//printf("excuinndo ambas\n");
				removeLig(ind1, xfirst, xsecond, ligacoes);
				removeLig(ind2, xfirst, xsecond, ligacoes);
				criaLig(val1, ind1, ind2, xfirst, xsecond, ligacoes);
			} else if(val1 > val2){
				//printf("excluindo a segunda\n");
				removeLig(ind2, xfirst, xsecond, ligacoes);
				ligacoes[ind1].st -= val2;
				criaLig(val2, ind1, ind2, xfirst, xsecond, ligacoes);
			} else {
				//printf("excluindo a primeira\n");
				removeLig(ind1, xfirst, xsecond, ligacoes);
				ligacoes[ind2].st -= val1;
				criaLig(val1, ind1, ind2, xfirst, xsecond, ligacoes);
			}
		}
	}
	for(int i = 0; i < n; i++){
		//cout << "set first[" << i << "]: ";
		for(int j : xfirst[i]){
		//	cout << j << " ";
		}
		//cout << endl;
	}
	for(int i = 0; i < n; i++){
		//cout << "set second[" << i << "]: ";
		for(int j : xsecond[i]){
			//cout << j << " ";
		}
		//cout << endl;
	}
	int cnt = 0;
	viii ans;
	for(int i = 0; i < n; i++){
		for(int ind : xfirst[i]){
			ans.pb(ligacoes[ind]);	
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for(iii lig: ans){
		printf("%d %d %d\n", lig.nd.st+1, lig.nd.nd+1, lig.st);
	}
	return 0;
}
