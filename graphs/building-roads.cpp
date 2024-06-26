#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i=0; i < m; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Doing the DFS
	vector<int> vis(n);
	function<void(int)> dfs = [&](int v){
		if(vis[v]) return;
		vis[v] = true;
		for(auto &to : adj[v]) dfs(to);
	};
	
	vector<int> root;
	for(int v=0; v < n; v++){
		if(vis[v]) continue;
		root.push_back(v);
		dfs(v);
	}
	cout << root.size() - 1 << '\n';
	for(int i=1; i < root.size(); i++)
		cout << root[0]+1 << ' ' << root[i]+1 << '\n';
}

signed main(){ 
	solve(); 
}
