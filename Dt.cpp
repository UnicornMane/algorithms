﻿#include <cstdlib>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;
constexpr int INF = numeric_limits<int> :: infinity();
struct node {
	int key, priority;
	node* left, * right;
	int size;

	node(int n_key = 0) {
		left = nullptr;
		right = nullptr;
		key = n_key;
		priority = ((rand() << 15) | rand());
		size = 1;
	}
};

int size(node* root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		return root->size;
	}
}

void update(node* root) {
	if (root == nullptr) {
		return;
	}
	else {
		root->size = size(root->left) + size(root->right) + 1;
	}
}

node* merge(node* root1, node* root2) {
	if (root1 == nullptr) {
		return root2;
	}
	if (root2 == nullptr) {
		return root1;
	}
	if (root1->priority < root2->priority) {
		root1->right = merge(root1->right, root2);
		update(root1);
		return root1;
	}
	else {
		root2->left = merge(root1, root2->left);
		update(root2);
		return root2;
	}
}

pair<node*, node* > split(node* root, int k) {
	if (root == nullptr) {
		return { nullptr, nullptr };
	}
	if (root->key < k) {
		auto p = split(root->right, k);
		root->right = p.first;
		update(root);
		return { root, p.second };
	}
	else {
		auto p = split(root->left, k);
		root->left = p.second;
		update(root);
		return { p.first, root };
	}
}

pair <node*, node* > split_size(node* root, int k) {
	if (root == nullptr) {
		return { nullptr, nullptr };
	}
	else {
		if (size(root->left) >= k) {
			auto p = split_size(root->left, k);
			root->left = p.second;
			update(root);
			return { p.first, root };
		}
		else {
			auto p = split_size(root->right, k - size(root->left) - 1);
			root->right = p.first;
			update(root);
			return { root, p.second };
		}
	}
}

node* insert(node* root, node* v) {
	if (root == nullptr) {
		return v;
	}
	if (v == nullptr) {
		return root;
	}
	if (root->priority > v->priority) {
		auto p = split(root, v->key);
		v->left = p.first;
		v->right = p.second;
		update(v);
		return v;
	}
	else {
		if (v->key < root->key) {
			root->left = insert(root->left, v);
		}
		else {
			root->right = insert(root->right, v);
		}
		update(root);
		return root;
	}
}

bool find(node* root, int key) {
	if (root == nullptr) {
		return false;
	}
	if (root->key == key) {
		return true;
	}
	if (key < root->key) {
		return find(root->left, key);
	}
	else {
		return find(root->right, key);
	}
}

int find_kth(node* root, int id) {
	if (root == nullptr) {
		return -INF;
	}
	if (size(root) < id) {
		return -1;
	}
	if (size(root->left) == id) {
		return root->key;
	}
	else {
		if (size(root->left) > id) {
			return find_kth(root->left, id);
		}
		else {
			return find_kth(root->right, id - size(root->left) - 1);
		}
	}
}

node* erase(node* root, int key) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->key == key) {
		return merge(root->left, root->right);
	}
	if (key < root->key) {
		root->left = erase(root->left, key);
	}
	else {
		root->right = erase(root->right, key);
	}
	update(root);
	return root;
}

int find_number(node* root, int key) {
	if (root == nullptr) {
		return 0;
	}
	else {
		if (root->key == key) {
			return -1;
		}
		if (root->key > key) {
			return find_number(root->left, key);
		}
		else {
			return find_number(root->right, key) + size(root->left) + 1;
		}
	}
}

int find_prev(node* root, int key) {
	if (root == nullptr) {
		return 0;
	}
	else {
		if (root->key == key) {
			return -1;
		}
		if (root->key <= key) {
			return find_number(root->left, key);
		}
		else {
			return find_number(root->right, key) + size(root->left) + 1;
		}
	}
}

void write(node* root) {
	if (root == nullptr) {
		return;
	}
	else {
		write(root->left);
		cout << root->key << ' ';
		write(root->right);
	}
}

node* root = nullptr;

auto main() -> signed
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin)
	{
		string t;
		int n;
		cin >> t >> n;
		if (t == "insert")
		{
			if (!find(root, n))
			{
				node* v = new node(n);
				root = insert(root, v);
			}
		}
		else if (t == "exists")
		{
			if (find(root, n))
			{
				cout << "true" << '\n';
			}
			else
			{
				cout << "false" << '\n';
			}
		}
		else
		{
			root = erase(root, n);
		}
	}

}
