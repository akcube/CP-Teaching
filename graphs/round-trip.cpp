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

	// We want to detect all back-edges in our dfs
	vector<int> vis(n), cycle, path;

	function<void(int, int)> dfs = [&](int v, int p){
		if(vis[v]) return;
		vis[v] = true;
		path.push_back(v);
		for(auto &to : adj[v]) {
			if(vis[to] and to != p and cycle.empty()) {
				while(path.back() != to){
					cycle.push_back(path.back()); 
					path.pop_back();
				}
				cycle.push_back(to);
				cycle.push_back(v);
			}
			dfs(to, v);
		}
		if(!path.empty() and path.back() == v) path.pop_back();
	};

	for(int v=0; v < n; v++)
		if(!vis[v]) dfs(v, -1);

	if(!cycle.empty()){
		cout << cycle.size() << '\n';
		for(auto &v : cycle)
			cout << v+1 << ' ';
		cout << '\n';
	}
	else cout << "IMPOSSIBLE\n";
}

signed main(){ 
	solve(); 
}
