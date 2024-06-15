#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
using dbl = long double;
//#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define ff first
#define ss second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define original_name cin.tie(0) -> sync_with_stdio(0)

void solve(){

	int n; cin >> n;
	vector<int> a(n); for(auto &x : a) cin >> x;

	// Calculate prefix & suffix sums
	vector<int> pref(n), suff(n);
	pref[0] = (a[0] >= 0);
	for(int i=1; i < n; i++) 
		pref[i] = pref[i-1] + (a[i] >= 0);
	
	suff[n-1] = (a[n-1] <= 0);
	for(int i=n-2; i >= 0; i--)
		suff[i] = suff[i+1] + (a[i] <= 0);

	// Brute force every index and check which index gives minimum ops
	int ans = INT_MAX;
	for(int i=0; i < n-1; i++)
		ans = min(ans, pref[i] + suff[i+1]);
	cout << ans << '\n';
}

signed main(){ 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve(); 
}