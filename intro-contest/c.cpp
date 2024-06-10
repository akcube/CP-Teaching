#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
using dbl = long double;
//#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;
using vll = vector<ll>;

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

	auto is_pal = [&](vector<int> &a){
		for(int i=0; i < a.size()/2; i++)
			if(a[i] != a[a.size() - i - 1]) return false;
		return true;
	};

	auto rem = [&](vector<int> &a, int r){
		vector<int> tmp;
		for(auto &x : a) if(x != r) tmp.push_back(x);
		return tmp;
	};

	if(is_pal(a)) return void(cout << "YES\n");
	for(int i=0; i < a.size(); i++)
		if(a[i] != a[n - i - 1]){
			auto option_1 = rem(a, a[i]), option_2 = rem(a, a[n - i - 1]);
			if(is_pal(option_1) or is_pal(option_2)) return void(cout << "YES\n");
			return void(cout << "NO\n");
		}
}

signed main(){ 
	original_name;
	int t; cin >> t;
	while(t--) solve(); 
}