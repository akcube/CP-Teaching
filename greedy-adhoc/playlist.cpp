#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Input reading
	int n; cin >> n;
	vector<int> songs(n); for(auto &x : songs) cin >> x;

	// Binary search
	map<int, int> m;
	int l=0, r=-1, ans=0;
	for(int l=0; l < n; l++){
		while(r < n-1 and m.find(songs[r+1]) == m.end()) m[songs[++r]]++;
		ans = max(ans, r - l + 1);
		m[songs[l]]--;
		if(m[songs[l]] == 0) m.erase(songs[l]);
	}
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
