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

Node* getInorderSuccessor(Node* root) //left most node in right subtree
{
	while(root!=nullptr && root->left!=nullptr)
	{
		root = root->left;
	}
	return root;
}

Node* delNode(Node* root, int key)
{
	if(root == nullptr)
		return nullptr;

	if(key < root->data)
		root->left = delNode(root->left, key);

	else if(key > root->data)
		root->right = delNode(root->right, key);

	else //delete root = key case
	{
		if(root->left == nullptr)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == nullptr)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			Node* IS = getInorderSuccessor(root->right);
			root->data = IS->data;
			root->right = delNode(root->right, IS->data);
		}
	}
	return root;
}

Node* helper(vector<int> nums, int start, int end)
{
	if(start > end)
		return nullptr;
	int mid = start + (end - start)/2;
	Node* root = new Node(nums[mid]);
	root->left = helper(nums, start, mid-1);
	root->right = helper(nums, mid+1, end);

	return root;
}

Node* sortedArrayToBST(vector<int>& nums)
{
	return helper(nums, 0, nums.size()-1);
}

int main()
{
	vector<int> arr = {3,2,1,5,6,4};
	Node* root = buildBST(arr);
	inorder(root);
	cout<<endl;
	delNode(root, 5);
	inorder(root);
	return 0;
}
