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

int n;
string str[100005];

string sanitiz(string s){
	stack<char> pilha;	
	for(int i = 0; i < sz(s); i++){
		char curr = s[i];
		if(curr == '('){
			pilha.push(curr);
		} else if(sz(pilha) != 0){
			char currTop = pilha.top();
			if(currTop == '(') pilha.pop();
			else pilha.push(curr);
		} else {
			pilha.push(curr);
		}
	}
	string result = "";
	while(sz(pilha) > 0){
		char curr = pilha.top();
		pilha.pop();
		result.pb(curr);
	}
	reverse(all(result));
	return result;
}

bool validar(string str){
	bool temAbrindo = false, temFechando = false;
	for(int i = 0; i < sz(str); i++){
		if(str[i] == '(') temAbrindo = true;
		if(str[i] == ')') temFechando = true;
	}
	return !(temFechando && temAbrindo);
}

int definePontos(string str){
	int pontos = 0;
	for(int i = 0; i < sz(str); i++){
		if(str[i] == '(') pontos++;
		if(str[i] == ')') pontos--;
	}
	return pontos;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		string curr, limpa;
		cin >> curr;
		limpa = sanitiz(curr);
		str[i] = limpa;
	}

	map<int, int> hash;

	int paresFeitos = 0;

	for(int i = 0; i < n; i++){
		string curr = str[i];
		if(validar(curr)){
			int pontos = definePontos(curr);
			int target = -pontos;
			if((hash.find(target) != hash.end()) && (hash[target] != 0)){
				hash[target]--;
				paresFeitos++;
			} else {
				if(hash.find(pontos) == hash.end()) hash[pontos] = 0;
				hash[pontos]++;
			}
		}
	}

	cout << paresFeitos << endl;
	return 0;
}