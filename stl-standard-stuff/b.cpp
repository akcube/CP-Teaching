#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n, m; cin >> n >> m;
	vector<int> ticket(n); for(auto &x : ticket) cin >> x;
	vector<int> customer(m); for(auto &x : customer) cin >> x;

	// Solve
	multiset<int> ticket_set(ticket.begin(), ticket.end());
	for(auto &c : customer){
		// Find his ticket
		// We want first element <= x
		auto it = ticket_set.upper_bound(c);
		if(ticket_set.empty() or it == ticket_set.begin())
			cout << -1 << '\n';
		else{
			cout << *prev(it) << '\n';
			ticket_set.erase(prev(it));
		}
	}

}

signed main(){ 
	solve(); 
}
