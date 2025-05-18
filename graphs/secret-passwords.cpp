#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n; cin >> n;
	vector<string> password(n); for(auto &x : password) cin >> x;

	// Build graph
	vector<vector<int>> adj(n + 26);
	auto ldex = [&](int i) { return i; };
	auto rdex = [&](int i) { return 26 + i; };

	for(int i=0; i < n; i++){
		sort(password[i].begin(), password[i].end());
		password[i].resize(unique(password[i].begin(), password[i].end()) - password[i].begin());
		for(auto &c : password[i]){
			adj[ldex(c - 'a')].push_back(rdex(i));
			adj[rdex(i)].push_back(ldex(c - 'a'));
		}
	}

	// connected components
	vector<int> vis(n + 26);
	int connected_components = 0;

	function<void(int)> dfs = [&](int v){
		if(vis[v]) return;
		vis[v] = true;
		for(auto &to : adj[v]) dfs(to);
	};

	for(int v=26; v < n + 26; v++)
		if(!vis[v]) {
			dfs(v);
			connected_components++;
		}
	cout << connected_components << '\n';
}

signed main(){ 
	solve(); 
}
