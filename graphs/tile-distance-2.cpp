#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
#define int ll

void solve(){

	int sx, sy; cin >> sx >> sy;
	int tx, ty; cin >> tx >> ty;

	int ans = abs(sy - ty);

	sx = sx - (abs(sy - sx) & 1);
	tx = tx - (abs(ty - tx) & 1);

	int hx = abs(tx - sx), hy = abs(ty - sy);
	ans += max(0LL, (hx - hy) / 2);
	cout << ans << '\n';
}

signed main(){ 
	solve(); 
}
