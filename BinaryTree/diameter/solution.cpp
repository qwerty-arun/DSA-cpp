//Build a Binary Tree
//Preorder Sequencd: [1,2,-1,-1,3,4,-1,-1,5,-1,-1]
//TC: O(n)

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

static int ans = 0;
int height(Node* root)
{
        int leftHt, rightHt;
        if(root==nullptr)
                return 0;

        leftHt = height(root->left);
        rightHt = height(root->right);

	ans = max(leftHt+rightHt, ans); //Current Diameter of root node, this modification allows for O(n) time complexity

        return max(leftHt, rightHt)+1;
}

int diameter(Node* root) //O(n^2)
{
	if(root == nullptr)
		return 0;
	int leftDiam = diameter(root->left);
	int rightDiam = diameter(root->right);
	int currDiam = height(root->left) + height(root->right);
	return max(leftDiam,max(rightDiam,currDiam));
}


int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	Node* root = buildTree(preorder);

	height(root);
	cout<<"Diameter of the tree: "<<ans;
	return 0;
}
