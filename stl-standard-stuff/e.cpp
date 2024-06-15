#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
#define int ll

void solve(){

	// Read input
	int n, a, b; cin >> n >> a >> b;
	vector<int> A(n); for(auto &x : A) cin >> x;

	// Prefix sums
	vector<int> p(n); p[0] = A[0];
	for(int i=1; i < n; i++) p[i] += p[i-1] + A[i];

	int answer = LLONG_MIN;
	// Build the first window
	multiset<int> ms;
	for(int i=a-1; i < b; i++) ms.insert(p[i]);
	answer = max(answer, *ms.rbegin());
	
	// Slide the window
	for(int i=a; i < n; i++){
		ms.erase(ms.find(p[i-1]));
		if(i + b - a < n)
			ms.insert(p[i + b - a]);
		answer = max(answer, *ms.rbegin() - p[i - a]);
	}
	cout << answer << '\n';
}

signed main(){ 
	solve(); 
}
