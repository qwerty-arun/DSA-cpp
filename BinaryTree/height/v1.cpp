#include <iostream>
#include <vector>
#include <queue>
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

int height(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(nullptr);
	int height=1;

	while(q.size()>0)
	{
		Node* curr = q.front();
		q.pop();

		if(curr==nullptr) //Either full traversal is over or a level is done
		{
			if(!q.empty())
			{
				q.push(nullptr);
				height++;
				continue;
			}
			else
				break;
		}
		if(curr->left!=nullptr)
			q.push(curr->left);

		if(curr->right!=nullptr)
			q.push(curr->right);
	}
	return height;
}

int main()
{
	std::vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, 6, -1, -1};
	Node* root = buildTree(preorder);
	int height_tree = height(root);
	cout<<"Height: "<<height_tree;
	return 0;
}
