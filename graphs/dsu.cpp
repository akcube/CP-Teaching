#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

struct DSU{
	int num_components;
	vector<int> dsu, size;

	DSU(int n) : dsu(n), size(n), num_components(n) { iota(dsu.begin(), dsu.end(), 0); }

	int find_parent(int a){
		if(dsu[a] == a) return a;
		return dsu[a] = find_parent(dsu[a]);
	}

	void merge(int a, int b){
		a = find_parent(a), b = find_parent(b);
		if(a == b) return;
		if(size[a] < size[b]) swap(a, b);
		num_components--;
		dsu[b] = a;
		size[a] += size[b];
	}
};

struct Edge {
	int u, v, c;
};

signed main(void){

	// Reading input
	int n, m; cin >> n >> m;
	vector<Edge> edges(m);
	for(auto &[u, v, c] : edges) cin >> u >> v >> c, u--, v--;

	// Kruskals
	int cost = 0;
	sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b){ return a.c < b.c; });
	DSU dsu(n);
	for(auto &[u, v, c] : edges){
		if(dsu.find_parent(u) == dsu.find_parent(v)) continue;
		cost += c;
		dsu.merge(u, v);
	}

	if(dsu.num_components == 1) cout << cost << '\n';
	else cout << "IMPOSSIBLE\n";
}