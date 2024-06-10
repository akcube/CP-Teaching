#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
using dbl = long double;
#define int ll

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

	/**
	 * int x; cin >> x;
	 * cout << "x = " << x << '\n';
	 * O(1)
	 */

	/**
	 * int n; cin >> n;
	 * for(int i=0; i < 2*n; i++) 
	 * 		cout << 42 << '\n';
	 * O(n)
	 */

	/**
	 * int n; cin >> n;
	 * for(int i=0; i < 2*n; i++) 
	 * 		for(int j=0; j < 3*n; j++)
	 * 			cout << 42 << '\n';
	 * O(n^2)
	 */

	/**
	 * int x; cin >> x;
	 * cout << "x = " << x << '\n';
	 * cout << "x = " << x << '\n';
	 * cout << "x = " << x << '\n';
	 * cout << "x = " << x << '\n';
	 * O(1)
	 */

	/**
	 * int n; cin >> n;
	 * for(int i=0; i < 2*n; i++) 
	 * 		for(int j=0; j < 3*n; j++)
	 * 			cout << 42 << '\n';
	 * O(n^2)
	 */

	/**
	 * int n; cin >> n;
	 * for(int i=0; i < n; i++)
	 * 		cout << 42 << '\n';
	 * O(n)
	 * for(int i=0; i < 2*n; i++) 
	 * 		for(int j=0; j < 3*n; j++)
	 * 			cout << 42 << '\n';
	 * O(n^2)
	 * O(n^2 + n)
	 * O(n^2)
	 */

	// int l=0, r=n;
	// while(l <= r){
	// 	int mid = l + (r - l) / 2;
	// 	if(ok(mid)){
	// 		l = mid + 1;
	// 	}
	// 	else r = mid - 1;
	// }
	// O(log(n))

	// int a, b; cin >> a >> b;
	// while(min(a, b) > 1){
	// 	tie(a, b) = minimax(a, b); // After this, a = min(a, b) & b = max(a, b)
	// 	b %= a;
	// }
	// O(max(logA, logB))

	// int n; cin >> n;
	// vector<int> factors;

	// for(int i=1; i*i <= n; i++){
	// 	if(n % i != 0) continue;
	// 	int f1 = i;
	// 	int f2 = n / i;
	// 	factors.push_back(f1);
	// 	if(f1 != f2) factors.push_back(f2);
	// }
	// O(sqrt(n))

	// for(int i=1; i <= n; i++){
	// 	vector<int> factors_of_i = get_factors(i);
	// 	// do some computation with it
	// }
	// O(n * sqrt(n))

	// Can we do better than O(n*sqrt(n))?
	// Sieve, yes
	// How?
	// vector<vector<int>> fac(n+1);
	// for(int i=1; i <= n; i++)
	// 	for(int j=i; j <= n; j += i) 
	// 		fac[j].push_back(i);

}

signed main(){ 
	original_name; 
	solve(); 
}