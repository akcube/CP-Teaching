#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){
	int n; cin >> n;
	vector<int> a(n); for(auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	vector<int> pref(n), suff(n);
	pref[0] = a[0];
	for(int i=1; i < n; i++) pref[i] = pref[i-1] + a[i];
	suff[n-1] = a[n-1];
	for(int i=n-2; i >= 0; i--) suff[i] = suff[i+1] + a[i];

	pair<int,int> ans = {1e18, -1};
	for(int i=0; i < n; i++){
		int lsum = i * a[i] - (i == 0 ? 0 : pref[i-1]);
		int rsum = (i == n-1 ? 0 : suff[i+1]) - (n - i - 1) * a[i];
		ans = min(ans, make_pair(lsum + rsum, a[i]));
	}
	cout << ans.second << '\n';
}

signed main(){ 
	solve(); 
}
