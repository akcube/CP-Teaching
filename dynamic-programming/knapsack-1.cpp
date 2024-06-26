#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	// Reading input
	int n, W; cin >> n >> W;
	vector<pair<int,int>> item(n); for(auto &[w, v] : item) cin >> w >> v;

	// Knapsack DP
	/**
	 * dp[i][j] => Represents the maximum value I can obtain, considering ONLY the 
	 * first i items, using up capacity at most j.
	 * 
	 * dp[i][j] <= We are trying to include item i, in at most j space. So the first 
	 * i-1 elements, can only use at most j-w[i] space.
	 * 
	 * dp[i][j] = max(value[i] + dp[i-1][j - w[i]], dp[i-1][j])
	 */
	vector<vector<int>> dp(n+1, vector<int>(W+1));
	for(int i=1; i <= n; i++){
		auto [weight, value] = item[i-1];
		for(int j=1; j <= W; j++){
			if(j - weight >= 0) dp[i][j] = max(dp[i][j], value + dp[i-1][j - weight]);
			dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
		}
	}
	cout << dp[n][W] << '\n';
}

signed main(){ 
	solve(); 
}
