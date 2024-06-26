#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Input reading
	int n, m; cin >> n >> m;
	vector<vector<int>> dance(m, vector<int>(3));
	for(auto &vec : dance) for(auto &x : vec) cin >> x, x--;

	// Assignment
	vector<int> color(n); // {0, 0, 0, 0, 0, 0, 0}
	for(auto &vec : dance){
		set<int> to_assign = {1, 2, 3};
		for(auto &dancer : vec) to_assign.erase(color[dancer]);
		for(auto &dancer : vec){
			if(color[dancer]) continue;
			color[dancer] = *to_assign.begin();
			to_assign.erase(to_assign.begin());
		}
	}

	for(auto &dancer : color) cout << dancer << ' ';
	cout << '\n';
}

signed main(){ 
	solve(); 
}
