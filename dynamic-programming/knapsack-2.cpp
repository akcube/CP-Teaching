#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	// Reading input
	int n, W; cin >> n >> W;
	vector<pair<int,int>> item(n); for(auto &[w, v] :  item) cin >> w >> v;

	// DP
	const int MXV = 1e5+10;
	vector<vector<int>> dp(n+1, vector<int>(MXV+1, 1e15));
	dp[0][0] = 0;
	for(int i=1; i <= n; i++){
		auto [weight, value] = item[i-1];
		for(int j=0; j <= MXV; j++){
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			if(j - value >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j - value] + weight);
			// cout << dp[i][j] << ' ';
		}
		// cout << '\n';
	}

	int ans = 0;
	for(int j=0; j <= MXV; j++)
		if(dp[n][j] <= W) ans = j;
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
