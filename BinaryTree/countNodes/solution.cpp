#include <ios>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		left = right = nullptr;
	}
};

static int idx = -1;
Node* buildTree(std::vector<int> preorder)
{
	idx++;

	if(preorder[idx] == -1)
		return nullptr;

	Node* root = new Node(preorder[idx]);
	root->left = buildTree(preorder); //LEFT
	root->right= buildTree(preorder); //RIGHT

	return root;
}

int count(Node* root)
{
	int leftcount, rightcount;
	if(root==nullptr)
		return 0;

	leftcount = count(root->left);
	rightcount = count(root->right);

	return leftcount + rightcount +1;
}

int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, 6, -1, -1};
	Node* root = buildTree(preorder);
	int noNodes = count(root);
	cout<<"No. of nodes: "<<noNodes<<"\n";
	return 0;
}
