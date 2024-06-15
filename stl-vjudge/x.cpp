#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define ff first
#define ss second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define original_name cin.tie(0) -> sync_with_stdio(0)

void solve(){

	int n, a, b; cin >> n >> a >> b;
	vi A(n); for(auto &x : A) cin >> x;

	vi p(n); p[0] = A[0];
	for(int i=1; i < n; i++) p[i] = p[i-1] + A[i];

	multiset<int> ms;
	for(int i=a-1; i < b; i++) ms.insert(p[i]);

	int ans = *ms.rbegin();
	for(int i=b; i < n; i++){
		ms.insert(p[i]);
		ms.erase(ms.find(p[i-b]));
		ans = max(ans, *ms.rbegin() - p[i-b]);
	}
	cout << ans << '\n';
}

signed main(){ 
	original_name; 
	solve(); 
}
