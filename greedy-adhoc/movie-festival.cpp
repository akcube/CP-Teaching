#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Input reading
	int n; cin >> n;
	vector<pair<int, int>> movies(n); for(auto &[a, b] : movies) cin >> a >> b;

	// Sort according to end time
	sort(movies.begin(), movies.end(), [&](auto &x, auto &y){
		return x.second < y.second;
	});

	// Greedily choose movies in order of end time
	int free_from = 0, count = 0;	
	for(auto &[st, en] : movies)
		if(st >= free_from){
			count++;
			free_from = en;
		}
	cout << count << '\n';
}	

signed main(){ 
	solve(); 
}
