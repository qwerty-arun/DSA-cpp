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

void inorder(Node* root)
{
	if(root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main()
{
	vector<int> arr = {3,2,1,5,6,4};
	Node* root = buildBST(arr);
	inorder(root);
	return 0;
}
