#include <algorithm>
#include <iostream>
#include <climits>
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

class minDiff
{
	Node* prev = nullptr;
	public:
	int minDiffInBST(Node* root)
	{
		if(root==nullptr)
		{
			return INT_MAX;
		}

		int ans = INT_MAX;
		if(root->left != nullptr)
		{
			int leftMin = minDiffInBST(root->left);
			ans = min(ans, leftMin);
		}

		if(prev != nullptr)
		{
			ans = std::min(ans, root->data - prev->data);
		}

		prev = root;

		if(root->right != nullptr)
		{
			int rightMin = minDiffInBST(root->right);
			ans = min(ans, rightMin);
		}
		return ans;
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



int main()
{
	vector<int> arr = {3,2,1,5,6,4};
	Node* root = buildBST(arr);
	minDiff min_diff;
	cout<<"The difference: "<<min_diff.minDiffInBST(root);
	return 0;
}
