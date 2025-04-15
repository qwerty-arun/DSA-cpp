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

int sumOfNodes(Node* root)
{
	int leftSum, rightSum;
	if(root==nullptr)
		return 0;

	leftSum = sumOfNodes(root->left);
	rightSum = sumOfNodes(root->right);

	return root->data + leftSum + rightSum;
}

int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, 6, -1, -1};
	Node* root = buildTree(preorder);
	int sum = sumOfNodes(root);
	cout<<"Sum of all nodes: "<<sum<<"\n";
	return 0;
}
