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
	int n, m; cin >> n >> m;
	vector<int> cities(n); for(auto &x : cities) cin >> x;
	vector<int> tower(m); for(auto &x : tower) cin >> x;

	sort(cities.begin(), cities.end());
	sort(tower.begin(), tower.end());

	int answer = 0;
	for(auto &city : cities){
		int min_distance = 1e16;
		// Right hand side closest tower
		auto it = lower_bound(tower.begin(), tower.end(), city);
		if(it != tower.end())
			min_distance = min(min_distance, abs(*it - city));
		// Left hand side closest tower
		if(it != tower.begin())
			min_distance = min(min_distance, abs(*prev(it) - city));
		answer = max(answer, min_distance);
	}
	cout << answer << '\n';
}

signed main(){ 
	original_name; 
	solve(); 
}