#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
#define int ll

void solve(){

	// Read input
	int n, t; cin >> n >> t;
	vector<int> a(n); for(auto &x : a) cin >> x;

	// Prefix sums
	vector<int> p(n); p[0] = a[0];
	for(int i=1; i < n; i++) p[i] = p[i-1] + a[i];

	// Solve
	int answer = 0;
	map<int, int> m;

	for(int l=n-1; l >= 0; l--){
		m[p[l]] = l;
		auto it = m.upper_bound(t + (l == 0 ? 0 : p[l-1]));
		if(it != m.begin()){
			it = prev(it);
			answer = max(answer, it->second - l + 1);
		}
	}
	cout << answer << '\n';
}

signed main(){ 
	solve(); 
}
