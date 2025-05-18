#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	string s; cin >> s;
	string t; cin >> t;
	int n = s.size(), m = t.size();

	// DP
	tuple<int,int,int> mx = {-1, -1, -1};
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	for(int i=1; i <= n; i++){
		for(int j=1; j <= m; j++){
			if(s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
			mx = max(mx, {dp[i][j], i, j});
		}
	}

	string ans;
	for(int len=0, i=get<1>(mx)-1, j=get<2>(mx)-1; len < get<0>(mx); len++, i--, j--)
		ans += s[i];
	reverse(ans.begin(), ans.end());
	
	cout << get<0>(mx) << '\n';
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
