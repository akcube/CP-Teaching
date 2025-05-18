#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, m; cin >> n >> m;
	vector<int> a(n); for(auto &x : a) cin >> x;
	vector<vector<int>> adj(n);
	for(int i=0; i < n-1; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// DFS
	int count = 0;
	function<void(int,int,int)> dfs = [&](int v, int p, int consecutive){
		// Exit condition
		if(consecutive + a[v] > m) return;

		// Am I a leaf?
		count += (adj[v].size() == 1 and p != -1);

		// DFS loop
		for(auto &to : adj[v]) 
			if(to != p) dfs(to, v, (a[v] == 1) ? consecutive + 1 : 0);
	};
	dfs(0, -1, 0);
	cout << count << '\n';
}

signed main(){ 
	solve(); 
}
