#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

void solve(){

	// Reading input
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	s += "..";
	t += "..";

	// Solve
	/**
	 * 101 => 2^0 + 2^2
	 * 012 => 3^1 + 2*3^2
	 * .bw => 3^1 + 2*3^2
	 */
	auto convert = [&](string &s){
		int pow = 1, hash = 0;
		for(auto &c : s){
			if(c == '.') hash += 0;
			if(c == 'B') hash += pow;
			if(c == 'W') hash += 2*pow;
			pow *= 3;
		}
		return hash;
	};

	// BFS
	const int MXN = 43046721, INF = 1e8;
	vector<int> dis(MXN, INF);
	queue<string> q; 
	q.push(s);
	dis[convert(s)] = 0;

	while(!q.empty()){
		auto node = q.front(); q.pop();
		int node_id = convert(node);

		// Find dot index
		int dot_index = -1;
		for(int i=0; i < node.size(); i++) if(node[i] == '.') { dot_index = i; break; }

		// Find all possible strings I can transform into
		for(int i=0; i < node.size()-1; i++){
			if(abs(i - dot_index) <= 1) continue;
			string to(node);
			swap(to[i], to[dot_index]); swap(to[i+1], to[dot_index+1]);
			int to_id = convert(to);
			if(dis[node_id] + 1 < dis[to_id]){
				q.push(to);
				dis[to_id] = dis[node_id] + 1;
			}
		}
	}

	if(dis[convert(t)] == INF) cout << -1 << '\n';
	else cout << dis[convert(t)] << '\n';

}

signed main(){ 
	solve(); 
}
