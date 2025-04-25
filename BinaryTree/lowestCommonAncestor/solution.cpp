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

Node* LCA(Node* root, Node*p, Node* q)
{
	if(root==nullptr)
		return nullptr;

	if(root->data== p->data|| root->data== q->data)
		return root;

	Node* lLCA = LCA(root->left, p, q);
	Node* rLCA = LCA(root->right, p, q);

	if(lLCA && rLCA)
		return root;
	else if(lLCA!=nullptr)
		return lLCA;
	else
		return rLCA;
}
int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	Node* root = buildTree(preorder);
	Node* p = root->left; //2
	Node* q = root->right->right; //5
	std::cout<<"The LCA is: "<<LCA(root, p, q)->data;
	return 0;
}
