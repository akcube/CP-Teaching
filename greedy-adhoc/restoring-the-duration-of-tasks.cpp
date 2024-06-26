#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	// Input reading
	int n; cin >> n;
	vector<int> start(n); for(auto &x : start) cin >> x;
	vector<int> end(n); for(auto &x : end) cin >> x;

	// Simulation
	for(int i=0; i < n; i++){
		if(i > 0) start[i] = max(start[i], end[i-1]);
		cout << end[i] - start[i] << ' ';
	}
	cout << '\n';
}

signed main(){ 
	int t; cin >> t;
	while(t--) solve(); 
}
