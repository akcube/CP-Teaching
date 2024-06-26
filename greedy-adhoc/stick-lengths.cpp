#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){
	int n; cin >> n;
	vector<int> p(n); for(auto &x : p) cin >> x;

	sort(p.begin(), p.end());
	int median = p[p.size() / 2];

	int ans = 0;
	for(auto &x : p) ans += abs(x - median);
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
