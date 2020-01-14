#include <iostream>
#include <string>
#include <algorithm>


#define speed ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


using namespace std;

struct Node
{
	int flag;
	Node* ch[10];
	Node()
	{
		flag = 0;
		for (int i = 0; i < 10; i++)
		{
			ch[i] = nullptr;
		}
	}
};

Node* root = new Node();

void add(Node* root, const string& s, int pos)
{
	if (pos == s.size())
	{
		root->flag++;
		return;
	}

	int c = s[pos] - '0';
	if (root->ch[c] == nullptr)
	{
		root->ch[c] = new Node();
	}
	add(root->ch[c], s, pos + 1);
}

void del(Node* root, const string& s, int pos)
{
	if (pos == s.size())
	{
		root->flag = max(root->flag - 1, 0);
		return;
	}

	int c = s[pos] - '0';
	if (root->ch[c] == nullptr)
	{
		return;
	}
	add(root->ch[c], s, pos + 1);
}

bool find(Node* root, const string& s, int pos)
{
	if (pos == s.size())
	{
		return root->flag > 0;
	}

	int c = s[pos] - '0';
	if (root->ch[c] == nullptr)
	{
		return false;
	}
	find(root->ch[c], s, pos + 1);
}

int main()
{
	speed

	
}
