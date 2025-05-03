
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	string data;
	Node* left;
	Node* right;

	Node(int val) {
		data = to_string(val);
		left = right = nullptr;
	}
};

static int idx = -1;

Node* buildTree(vector<int>& preorder) {
	idx++;
	if (preorder[idx] == -1)
		return nullptr;

	Node* root = new Node(preorder[idx]);
	root->left = buildTree(preorder);
	root->right = buildTree(preorder);

	return root;
}

void allPaths(Node* root, string path, vector<string>& ans) {
	if (root->left == nullptr && root->right == nullptr) {
		ans.push_back(path);
		return;
	}
	if (root->left) {
		allPaths(root->left, path + "->" + root->left->data, ans);
	}
	if (root->right) {
		allPaths(root->right, path + "->" + root->right->data, ans);
	}
}

vector<string> binaryTreePaths(Node* root) {
	vector<string> ans;
	if (root == nullptr)
		return ans;
	string path = root->data;
	allPaths(root, path, ans);
	return ans;
}

void preOrder(Node* root) {
	if (root == nullptr)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	Node* root = buildTree(preorder);

	cout << "Preorder: ";
	preOrder(root);
	cout << "\n";

	vector<string> ans = binaryTreePaths(root);
	cout << "Paths:\n";
	for (string path : ans)
		cout << path << "\n";

	return 0;
}
