#include <iostream>
#include <vector>
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

void kthLevel(Node *root, int k)
{
	if(root==nullptr)
		return;
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	kthLevel(root->left, k-1);
	kthLevel(root->right, k-1);
}
int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	Node* root = buildTree(preorder);
	kthLevel(root, 3);
	return 0;
}
