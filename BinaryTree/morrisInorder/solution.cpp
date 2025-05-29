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

vector<int> MorrisInOrder(Node* root)
{
	vector<int> ans;
	Node* curr = root;
	while(curr!=nullptr)
	{
		if(curr->left == nullptr)
		{
			ans.push_back(root->val);
		}
		else
		{
			Node* IP = curr->left;
			while(IP->right !=nullptr && IP->right !=curr)
			{
				IP = IP->right;
			}
			if(IP->right == nullptr){
				IP->right = curr; //create
				curr=curr->left;
			}
			else
			{
				IP->right = nullptr; //destrooy
				ans.push_back(curr->val);
				curr = curr->right;
			}
		}
	}

	return ans;
}

int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	Node* root = buildTree(preorder);
	std::vector<int> ans = MorrisInOrder(root);
	return 0;
}
