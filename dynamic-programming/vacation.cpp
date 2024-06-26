#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){
	// Reading input
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(3));
	for(auto &day : a) for(auto &x : day) cin >> x;

	/**
	 * dp[i][j] => Max points we can get on the i-th day, assuming we do the j-th activity
	 * on the i-th day.
	 */
	vector<vector<int>> dp(n, vector<int>(3));
	// Base state
	for(int j=0; j < 3; j++) dp[0][j] = a[0][j];
	// Recurrence
	for(int i=1; i < n; i++)
		for(int j=0; j < 3; j++) // We want to update dp[i][j]
			for(int k=0; k < 3; k++)
				if(j != k) dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
	cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
}

signed main(){ 
	solve(); 
}
