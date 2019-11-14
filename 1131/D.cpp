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


struct Node {
	int value;
	Node(int i){
		value = i;
		next = NULL;
	}
	Node* next;
};

int getLeader(vi &leader, int ind){
	if(leader[ind] == ind) return ind;
	return getLeader(leader, leader[ind]);
}

void appendArr(Node* a, Node* b, int ia, int ib, vector<Node*> &ultimo, vi &sizes){
	ultimo[ia]->next = b;
	ultimo[ia] = ultimo[ib];
	sizes[ia]+= sizes[ib];
}

int main(){
	int n;
	scanf("%d", &n);
	vii queries;
	vi leader(n+1);
	vector<Node*> listas(n+1, NULL);
	vector<Node*> ultimo(n+1, NULL);
	vi sizes(n+1);
	for(int i = 1; i <= n; i++){
		leader[i] = i;
		listas[i] = new Node(i);
		ultimo[i] = listas[i];
		sizes[i] = 1;
	}
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		queries.pb(mp(a,b));
	}

	int liderFinal = 1;
	for(int i = 0; i < n-1; i++){
		int a, b;	
		a = queries[i].st;
		b = queries[i].nd;
		int la, lb;
		la = getLeader(leader, a);
		lb = getLeader(leader, b);
		if(sizes[la] > sizes[lb]){
			int aux = la;
			la = lb;
			lb = aux;
		}
		appendArr(listas[lb], listas[la], lb, la, ultimo, sizes);
		leader[la] = lb;
		liderFinal = lb;
	}

	Node* ordemFinal = listas[liderFinal];
	while(ordemFinal != NULL){
		printf("%d ", ordemFinal->value);
		ordemFinal = ordemFinal->next;
	}
	cout << endl;

	return 0;
}