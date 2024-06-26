#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// #define int ll

void solve(){

	// Input reading
	int n, k; cin >> n >> k;
	vector<int> h(n); for(auto &x : h) cin >> x;

	/**
	 * dp[i] => Represents the minimum cost it takes, to reach the
	 * i^th stone from the 0th stone. 
	 * To reach the i^th stone, I must have jumped either from the 
	 * (i-1)^th stone, or the (i-2)^th stone. 
	 * So, if we compute dp in order from 0 to n, notice that when
	 * computing dp[i], dp[i-1] & dp[i-2] have already been computed.
	 *
	 * Therefore, it has optimal substructure. 
	 * Because, if I know the value of dp[i-1] & dp[i-2] I can 
	 * optimally compute dp[i]. 
	 */

	// Tell me the minimum cost to reach ith stone.
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for(int i=0; i < n; i++)
		for(int j=1; j <= k; j++)
			if(i+j < n)
				dp[i+j] = min(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
	cout << dp[n-1] << '\n';
}

signed main(){ 
	solve(); 
}
