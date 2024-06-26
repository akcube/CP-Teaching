#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n; cin >> n;
	string s; cin >> s;
	string t; cin >> t;

	// Two-pointer esque solution
	auto diff = [&](char a, char b) { return a ^ b; };
	int ans = 0;
	for(int i=0; i < n; ){
		int st = i;
		while(i < n and diff(t[i], s[i]) == diff(t[st], s[st]))
			i++;
		if(diff(t[st], s[st])) ans++;
	}
	cout << ans << '\n';
}

signed main(){ 
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	solve(); 
}
