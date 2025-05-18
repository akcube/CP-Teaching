#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	using Point = array<int, 3>;
	Point a, b, c, d; 
	auto read_point = [&](Point &a) { for(auto &x : a) cin >> x; };
	read_point(a), read_point(b), read_point(c), read_point(d);

	// Solve
	if(max(a[0], c[0]) >= min(b[0], d[0])) return void(cout << "No\n");
	if(max(a[1], c[1]) >= min(b[1], d[1])) return void(cout << "No\n");
	if(max(a[2], c[2]) >= min(b[2], d[2])) return void(cout << "No\n");
	cout << "Yes\n";
}

signed main(){ 
	solve(); 
}
