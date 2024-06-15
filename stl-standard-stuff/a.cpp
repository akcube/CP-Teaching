#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void solve(){

	// Read input
	int n, q; cin >> n >> q;
	vector<int> cow(n); for(auto &x : cow) cin >> x;

	// Prefix sums
	vector<vector<int>> pref(4, vector<int>(n, 0));
	for(int type=1; type <= 3; type++){
		pref[type][0] = (cow[0] == type);
		for(int i=1; i < n; i++)
			pref[type][i] = pref[type][i-1] + (cow[i] == type);
	}

	// Queries
	for(int i=0; i < q; i++){
		int l, r; cin >> l >> r; 
		r--, l--;
		for(int type=1; type <= 3; type++){
			if(l == 0) cout << pref[type][r];
			else cout << pref[type][r] - pref[type][l-1];
			if(type != 3) cout << ' ';
		}
	}


}

signed main(){ 
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	solve(); 
}
