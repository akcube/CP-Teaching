#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

template<int NX = int(1e6 + 5e5)>
struct Trie {
	int root{}, lastocc{};
	array<array<int, 27>, NX> mem;
	int id(char c) { return c - 'a'; }
	void insert(string s, int wid){
		// Convert it to cipher form first
		for(auto &c : s) c = tolower(c);
		reverse(s.begin(), s.end());
		// Insert
		int current = root;
		for(auto &c : s){
			if(mem[current][id(c)] == 0) 
				mem[current][id(c)] = ++lastocc;
			current = mem[current][id(c)];
		}
		if(mem[current][26] == 0) mem[current][26] = wid+1;
	}
	void find(const string &cipher, int start, vector<int> &dp){
		int current = root;
		for(int i=start; i < cipher.size(); i++){
			if(mem[current][id(cipher[i])] == 0) return;
			current = mem[current][id(cipher[i])];
			if(mem[current][26] != 0) dp[i] = mem[current][26];
		}
	}
};

void solve(){

	// Reading input
	int n; cin >> n;
	string s; cin >> s;
	int m; cin >> m;
	vector<string> words(m); for(auto &x : words) cin >> x;

	// Solving
	Trie t;
	for(int i=0; i < words.size(); i++) t.insert(words[i], i);
	vector<int> dp(n, -1);
	for(int i=0; i < n; i++){
		if(i != 0 and dp[i-1] == -1) continue;
		t.find(s, i, dp);
	}

	// Backtracking
	vector<string> ans;
	for(int ptr=n-1; ptr >= 0; ){
		int wlen = words[dp[ptr]-1].size();
		ans.push_back(words[dp[ptr]-1]);
		ptr -= wlen;
	}
	reverse(ans.begin(), ans.end());
	for(auto &x : ans) cout << x << ' ';
	cout << '\n';
}

signed main(){ 
	solve(); 
}
