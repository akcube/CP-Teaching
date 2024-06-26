#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve(){

	// Reading input
	int n; cin >> n;
	vector<int> a(n); for(auto &x : a) cin >> x;

	// Simulation
	int health = 0, count = 0;
	priority_queue<int, vector<int>, greater<>> pq;
	for(auto &potion : a){
		health += potion;
		count++;
		pq.push(potion);
		if(health < 0){
			int remove = pq.top(); pq.pop();
			count--; health -= remove;
		}
	}
	cout << count << '\n';
}

signed main(){ 
	solve(); 
}
