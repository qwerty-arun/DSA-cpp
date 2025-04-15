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

int height(Node* root)
{
	int leftHt, rightHt;
	if(root==nullptr)
		return 0;

	leftHt = height(root->left);
	rightHt = height(root->right);

	return max(leftHt, rightHt)+1;
}

int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, 6, -1, -1};
	Node* root = buildTree(preorder);
	int height_tree = height(root);
	cout<<"Height: "<<height_tree;
	return 0;
}
