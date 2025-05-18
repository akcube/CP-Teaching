#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){
	// Reading input
	int n, k, x; cin >> n >> k >> x;
	vector<int> a(n); for(auto &x : a) cin >> x;

	// The non-C++ way
	// for(int i=0; i < k; i++) cout << a[i] << ' ';
	// cout << x << ' ';
	// for(int i=k; i < n; i++) cout << a[i] << ' ';

	// More C++-ish way
	a.insert(a.begin()+k, x);
	for(auto &x : a) cout << x << ' ';
}

signed main(){ 
	solve(); 
}
