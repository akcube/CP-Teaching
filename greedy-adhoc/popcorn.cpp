#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, m; cin >> n >> m;
	vector<int> stand(n);
	for(auto &x : stand){
		string s; cin >> s;
		for(int i=0; i < m; i++)
			if(s[i] == 'o') x |= (1 << i);
	}

	// Brute-force across all possible combinations of stands
	int ans = INT_MAX;
	for(int msk=0; msk < (1<<n); msk++){
		int union_mask = 0;
		for(int i=0; i < n; i++)
			if(msk & (1 << i)) union_mask |= stand[i];
		if(union_mask == (1<<m)-1)
			ans = min(ans, __builtin_popcount(msk));
	}
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
