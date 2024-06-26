#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){
	// Reading input
	int n, m; cin >> n >> m;
	vector<int> deg(n);
	for(int i=0; i < m; i++){
		int u, v; cin >> u >> v; u--, v--;
		deg[u]++; deg[v]++;
	}

	array<int, 3> freq{};
	for(auto &v : deg)
		if(v <= 2) freq[v]++;
	int max_deg = *max_element(deg.begin(), deg.end());

	if(freq[2] == n) cout << "ring topology\n";
	else if(freq[2] == n-2 and freq[1] == 2) cout << "bus topology\n";
	else if(freq[1] == n-1 and max_deg == n-1) cout << "star topology\n";
	else cout << "unknown topology\n";


}

signed main(){ 
	solve(); 
}
