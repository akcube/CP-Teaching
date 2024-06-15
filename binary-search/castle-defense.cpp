#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	// Input
	int n, R, k; cin >> n >> R >> k;
	vector<int> a(n); for(auto &x : a) cin >> x;

	// Binary search
	int l=0, r=2e18, ans=-1;	
	while(l <= r){

		auto ok = [&](int x){ // <= Is a reliability of at least "x" achieveable?
			int l=0, r=-1, window_sum=0, archers_left=k;
			vector<int> acpy(a);
			auto add = [&](int pos, int num_archers){
				window_sum += num_archers;
				acpy[pos] += num_archers;
				archers_left -= num_archers;
			};
			for(int i=0; i < n; i++){
				while(l < n and i-R > l) window_sum -= acpy[l++];
				while(r < n-1 and i+R > r) window_sum += acpy[++r];
				if(window_sum >= x) continue; // I don't need to modify anyone
				// Not sufficient. Add archers to i+R
				add(min(i+R, n-1), x - window_sum);
				if(archers_left < 0) return false;
			}
			return archers_left >= 0;
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
