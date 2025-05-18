#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, m; cin >> n >> m;
	vector<int> blocked(n);
	for(int i=0; i < m; i++){
		int u, v; cin >> u >> v; u--, v--;
		blocked[u] = blocked[v] = 1;
	}

	// Solve
	int center = -1;
	for(int v=0; v < n; v++)
		if(!blocked[v]) center = v;

	cout << n-1 << '\n';
	for(int v=0; v < n; v++)
		if(v != center) cout << v+1 << ' ' << center << '\n';

}

signed main(){ 
	solve(); 
}
