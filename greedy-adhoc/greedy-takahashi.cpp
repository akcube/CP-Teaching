#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	int a, b, k; cin >> a >> b >> k;
	int eaten = min(a, k);
	a -= eaten, k -= eaten;
	eaten = min(b, k);
	b -= eaten;
	cout << a << " " << b << '\n';
}

signed main(){ 
	solve(); 
}
