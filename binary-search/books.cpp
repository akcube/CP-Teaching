#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, t; cin >> n >> t;
	vector<int> a(n); for(auto &x : a) cin >> x;

	// Binary search
	int l=0, r=n, ans=-1;
	while(l <= r){

		auto ok = [&](int x){
			// Sliding window init
			int wsum = 0;
			for(int i=0; i < x; i++) wsum += a[i];
			if(wsum <= t) return true;
			// Slide the window
			for(int i=x; i < n; i++){
				wsum += a[i];
				wsum -= a[i-x];
				if(wsum <= t) return true;
			}
			return false;
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
