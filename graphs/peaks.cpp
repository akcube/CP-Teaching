#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, m; cin >> n >> m;
	vector<int> h(n); for(auto &x : h) cin >> x;
	vector<vector<int>> adj(n);
	for(int i=0; i < m; i++){
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Solve
	int count = 0;
	for(int v=0; v < n; v++){
		bool is_good = true;
		for(auto &to : adj[v])
			is_good &= (h[to] < h[v]);
		count += is_good;
	}
	cout << count << '\n';
}

signed main(){ 
	solve(); 
}
