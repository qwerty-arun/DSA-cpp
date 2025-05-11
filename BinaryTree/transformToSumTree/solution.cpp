#include <ios>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
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

int TransformToSumTree(Node* root)
{
	if(root==nullptr)
		return 0;

	int leftSum = TransformToSumTree(root->left);
	int rightSum = TransformToSumTree(root->right);

	root->data += leftSum + rightSum;

	return root->data;
}

void preOrder(Node* root)
{
	if(root==nullptr)
		return;
	preOrder(root->left);
	cout<<root->data<<" ";
	preOrder(root->right);
}

int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	Node* root = buildTree(preorder);
	preOrder(root);
	cout<<"\nSum of the entire tree: "<<TransformToSumTree(root)<<"\n";
	preOrder(root);
	return 0;
}
