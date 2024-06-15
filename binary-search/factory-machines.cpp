#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

signed main(void){
	// Input reading
	int n, k; cin >> n >> k;
	vector<int> machine(n); for(auto &x : machine) cin >> x;

	// Binary search
	int l=0, r=1e18+100, ans=-1;
	while(l <= r){
		auto ok = [&](int t){
			__int128_t sum = 0;
			for(auto &k_i : machine) sum += t / k_i;
			return sum >= k;
		};
		int mid = l + (r - l) / 2;
		if(ok(mid)){
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << ans << '\n';
}