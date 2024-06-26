#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Input
	int r, c; cin >> r >> c;
	vector<string> grid(r); for(auto &s : grid) cin >> s;

	// Case 0 / Mortal
	vector<string> ALLA(r, string(c, 'A')), ALLP(r, string(c, 'P'));
	if(grid == ALLA) return void(cout << "0\n");
	if(grid == ALLP) return void(cout << "MORTAL\n");

	// Case 1
	for(auto &ri : {0, r-1}){
		bool edge_a = true;
		for(int i=0; i < c; i++) edge_a &= (grid[ri][i] == 'A');
		if(edge_a) return void(cout << "1\n");
	}
	for(auto &ci : {0, c-1}){
		bool edge_a = true;
		for(int i=0; i < r; i++) edge_a &= (grid[i][ci] == 'A');
		if(edge_a) return void(cout << "1\n");
	}

	// Case 2
	if(grid[0][0] == 'A' or grid[r-1][c-1] == 'A' or grid[0][c-1] == 'A' or grid[r-1][0] == 'A')
		return void(cout << "2\n");
	for(int ri=0; ri < r; ri++){
		bool edge_a = true;
		for(int i=0; i < c; i++) edge_a &= (grid[ri][i] == 'A');
		if(edge_a) return void(cout << "2\n");
	}
	for(int ci=0; ci < c; ci++){
		bool edge_a = true;
		for(int i=0; i < r; i++) edge_a &= (grid[i][ci] == 'A');
		if(edge_a) return void(cout << "2\n");
	}	

	// Case 3
	for(auto &ri : {0, r-1}){
		bool edge_a = false;
		for(int i=0; i < c; i++) edge_a |= (grid[ri][i] == 'A');
		if(edge_a) return void(cout << "3\n");
	}
	for(auto &ci : {0, c-1}){
		bool edge_a = false;
		for(int i=0; i < r; i++) edge_a |= (grid[i][ci] == 'A');
		if(edge_a) return void(cout << "3\n");
	}

	// Case 4
	cout << 4 << '\n';
}

signed main(){ 
	int t; cin >> t;
	while(t--) solve(); 
}
