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
	}

	// Toposort
	auto get_topo = [&](){
		vector<int> ord, vis(n);
		function<void(int)> dfs = [&](int v){
			if(vis[v]) return;
			vis[v] = true;
			for(auto &to : adj[v]) dfs(to);
			ord.push_back(v);
		};
		for(int v=0; v < n; v++)
			if(!vis[v]) dfs(v);
		reverse(ord.begin(), ord.end());
		return ord;
	};

	auto ord = get_topo();

	vector<int> dp(n, 1);
	for(auto &v : ord)
		for(auto &to : adj[v])
			dp[to] = max(dp[to], dp[v] + 1);

	cout << *max_element(dp.begin(), dp.end()) - 1 << '\n';
}

signed main(){ 
	solve(); 
}
