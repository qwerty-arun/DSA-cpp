//Build a Binary Tree
//Preorder Sequencd: [1,2,-1,-1,3,4,-1,-1,5,-1,-1]
//TC: O(n)

#include <iostream>
#include <numeric>
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

void inOrder(Node* root)
{
	if(root==nullptr)
		return;
	else
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	Node* root = buildTree(preorder);
	cout<<root->data<<endl;
	inOrder(root);
	return 0;
}
