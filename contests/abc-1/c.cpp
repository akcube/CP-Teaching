#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, k; cin >> n >> k;
	vector<int> a(n); for(auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	// Solve
	int ans = INT_MAX;
	for(int plen=0, suff=n-k-1; plen <= k; plen++, suff++)
		ans = min(ans, a[suff] - a[plen]);
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
