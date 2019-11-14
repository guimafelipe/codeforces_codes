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

#define MAXN 200005

int n, q;
int arr[MAXN];
ii queries[MAXN];

const int neutral = INF;
int comp (int a, int b){
	return min(a,b);
}

class SegmentTree {
	vi a;
	int n;
public:
	SegmentTree(int* st, int *en){
		int sz = int(en-st);
		for(n = 0; n < sz; n <<=1){a.assign(n << 1, neutral);}
		for(int i = 0; i < sz; i++) a[i+n] = st[i];
		for(int i = n+sz-1; i > 1;i--) a[i>>1] = comp(a[i>>1], a[i]);
	}
	void update(int i, int x){
		a[i+n] = x;
		for(i += n, i >>=1; i; i >>=1){
			a[i] = comp(a[i<<1], a[i+(i<<1)]);
		}
	}
	int query(int l, int r){
		int ans = neutral;
		for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
			if(l&1)ans = comp(ans, a[l++]);
			if(r&1)ans = comp(ans, a[--r]);
		}
		return ans;
	}
};

bool analisa(){
	int ant = 1;
	int curr = 0, maxi = 0;
	for(int i = 0; i < n; i++){
		curr = arr[i];
		if(curr == 0) {
			curr = ant;
			arr[i] = curr;
		}
		if(queries[curr].st == -1)
			queries[curr].st = i;
		queries[curr].nd = i;
	}
}

int main(){
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		scanf("%d", arr + i);
	}
	for(int i = 0; i <= q; i++){
		queries[i] = mp(-1, -1);
	}

	analisa();

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	SegmentTree* segt = new SegmentTree(arr, arr+n);

	for(int i = 0; i < q; i++){
		if(segt->query(queries[i].st, queries[i].nd) < i+1){
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	cout << endl;



	return 0;
}