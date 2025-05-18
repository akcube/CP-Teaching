#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int ll

struct Trie {
	struct Node { array<Node*, 27> ptr{}; } *root;
	Trie(){ root = new Node(); }

	int id(char c) { return c - 'a'; }
	void insert(const string &s){
		Node *current = root;
		for(auto &c : s){
			if(current->ptr[id(c)] == nullptr) 
				current->ptr[id(c)] = new Node();
			current = current->ptr[id(c)];
		}
		if(current->ptr[26] == nullptr) current->ptr[26] = new Node();
	}
	bool find(const string &s){
		Node *current = root;
		for(auto &c : s){
			if(current->ptr[id(c)] == nullptr) return false;
			current = current->ptr[id(c)];
		}
		return (current->ptr[26] != nullptr);
	}
};


void solve(){

}

signed main(){ 
	solve(); 
}
