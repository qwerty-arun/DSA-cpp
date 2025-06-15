#include <algorithm>
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

Node* insert(Node* root, int value)
{
	if(root == nullptr)
		return new Node(value);
		
	if(value < root->data)
		root->left = insert(root->left, value);

	else
		root->right = insert(root->right, value);

	return root;
}

Node* buildBST(vector<int> arr)
{
	Node* root = nullptr;

	for(int val : arr)
	{
		root = insert(root, val);
	}

	return root;
}

bool isBST(Node* root, Node* min, Node* max)
{
	if (root == nullptr)
	{
		return true;
	}

	if(min != nullptr && root->data <= min->data){
		return false;
	}

	if(max!= nullptr && root->data >= max->data){
		return false;
	}

return isBST(root->left, min, root) && isBST(root->right, root, max);
}

int main()
{
	vector<int> arr = {3,2,1,5,6,4};
	Node* root = buildBST(arr);
	if(isBST(root, nullptr, nullptr))
		cout<<"The binary tree is a BST!\n";
	else
		cout<<"The binary tree isn't a BST!\n";
	return 0;
}
