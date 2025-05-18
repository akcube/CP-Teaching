#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll
const int MOD = int(1e9) + 7;

void solve(){
	// Reading input
	int n; cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for(auto &row : mat) for(auto &cell : row) cin >> cell;

	// DP
	vector<int> dp(1<<n); dp[0] = 1;
	for(int msk=0; msk < (1 << n); msk++){
		for(int w=0; w < n; w++){
			if((msk & (1 << w)) or not mat[__builtin_popcount(msk)][w]) continue;
			dp[msk | (1 << w)] = (dp[msk | (1 << w)] + dp[msk]) % MOD;
		}
	}
	cout << dp[(1 << n)-1] << '\n';
}

signed main(){ 
	solve(); 
}
