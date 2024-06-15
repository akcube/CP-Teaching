#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	// Input
	int n, k; cin >> n >> k;
	vector<int> a(n); for(auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	// Binary search
	int l=0, r=2e9+100, ans=-1;
	while(l <= r){
		auto ok = [&](int m){
			int req = 0;
			for(int i=n/2; i < n; i++) req += max(0LL, m - a[i]);
			return req <= k;
		};
		int mid = l + (r - l) / 2;
		if(ok(mid)){
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
