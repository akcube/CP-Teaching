#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using dbl = double;
//#define int ll

void solve(){

	// Reading input
	int n; cin >> n;
	vector<dbl> p(n); for(auto &x : p) cin >> x;

	/**
	 * State:
	 * dp[i][j] => Using the first i-flips, what is the probability I have
	 * at least j heads.
	 * 
	 * Recurrence:
	 * We reach the 'i' flips state from the 'i-1' flips state. We're basically simulating all
	 * possibilities of the 'i'th flip.
	 * Now, in one flip I can get either a heads or a tails. 
	 * So to reach j heads, I must have had j heads on the previous flip and then gotten tails on
	 * the current flip, or I must have had j-1 heads on the previous flip and then gotten heads
	 * on the current flip. So,
	 * dp[i][j] = dp[i-1][j] * probability_tails + dp[i-1][j-1] * probability_heads
	 */
	vector<vector<dbl>> dp(n+1, vector<dbl>(n+1, 0));
	dp[0][0] = 1;

	for(int i=1; i <= n; i++)
		for(int j=0; j <= n; j++)
			dp[i][j] = dp[i-1][j] * (1 - p[i-1]) + ((j == 0 ? 0 : dp[i-1][j-1]) * p[i-1]);

	// dp[n][i] => After n flips, probability I have i heads
	dbl ans = 0;
	for(int i=n/2+1; i <= n; i++) ans += dp[n][i];

	cout << fixed << setprecision(15) << ans << '\n';

}

signed main(){ 
	solve(); 
}
