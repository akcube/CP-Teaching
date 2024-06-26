#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	int n; cin >> n;

	vector<int> dp(n+1, -1);
	// function<int(int)> fib = [&](int n){
	// 	// Memoization
	// 	if(dp[n] != -1) return dp[n];
	// 	// Actual function
	// 	if(n == 0) return ll(0);
	// 	if(n == 1) return ll(1);
	// 	return dp[n] = fib(n-1) + fib(n-2);
	// };

	dp[0] = 0;
	dp[1] = 1;
	// DP[i] = i^th fibonacci number <= State of DP
	for(int f=2; f <= n; f++)
		dp[f] = dp[f-1] + dp[f-2];

	cout << dp[n] << '\n';

}

signed main(){ 
	solve(); 
}
