#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll
const int MOD = int(1e9) + 7;

void solve(){

	// Reading input
	int h, w; cin >> h >> w;
	vector<string> grid(h); for(auto &row : grid) cin >> row;

	// DP
	vector<vector<int>> dp(h, vector<int>(w, 0));
	dp[0][0] = 1;
	
	auto val = [&](int i, int j){
		if(i < 0 or j < 0) return 0;
		return (grid[i][j] == '#' ? 0 : dp[i][j]);
	};

	for(int i=0; i < h; i++)
		for(int j=0; j < w; j++)
			if(not(i == 0 and j == 0))
				dp[i][j] = (val(i-1, j) + val(i, j-1)) % MOD;

	cout << dp[h-1][w-1] << '\n';

}

signed main(){ 
	solve(); 
}
