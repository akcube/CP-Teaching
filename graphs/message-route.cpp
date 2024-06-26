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

	// BFS
	const int inf = 1e8;
	queue<int> q; q.push(0);
	vector<int> d(n, inf); d[0] = 0;
	vector<int> par(n, -1); 
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(auto &to : adj[v])
			if(d[v] + 1 < d[to]) { // Can also do d[to] == inf
				q.push(to);
				d[to] = d[v] + 1;
				par[to] = v;
			}
	}

	if(d[n-1] == inf) return void(cout << "IMPOSSIBLE\n");

	// Reconstruct
	vector<int> path;
	for(int v=n-1; v != -1; v=par[v]) path.push_back(v);
	reverse(path.begin(), path.end());
	
	// Output
	cout << path.size() << '\n';
	for(auto &v : path) cout << v + 1 << ' ';

}

signed main(){ 
	solve(); 
}
