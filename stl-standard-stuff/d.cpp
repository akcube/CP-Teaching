#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
#define int ll

void solve(){

	// Reading input
	int n, x; cin >> n >> x;
	vector<int> a(n); for(auto &x : a) cin >> x;

	// Prefix sums
	vector<int> p(n); p[0] = a[0];
	for(int i=1; i < n; i++) p[i] = p[i-1] + a[i];

	// Solve
	map<int, int> freq;
	/**
	 * At each iteration of this loop, I want to count ALL the subarrays
	 * that end in r with sum [l, r] = x. 
	 */
	freq[0]++;
	int answer = 0;
	for(int r=0; r < n; r++){
		answer += freq[p[r] - x];
		freq[p[r]]++;
	}
	cout << answer << '\n';
}

signed main(){ 
	solve(); 
}
