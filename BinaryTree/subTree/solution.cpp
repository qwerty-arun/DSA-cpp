
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Modified buildTree to take index by reference
Node* buildTree(const vector<int>& preorder, int& idx) {
    idx++;

    // Base case
    if (idx >= preorder.size() || preorder[idx] == -1)
        return nullptr;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);  // LEFT
    root->right = buildTree(preorder, idx); // RIGHT

    return root;
}

// Function to compare two binary trees
bool isSameTree(Node* p, Node* q) {
    if (p == nullptr || q == nullptr)
        return p == q;

    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);

    return isLeftSame && isRightSame && p->data == q->data;
}

bool isSubTree(Node *root, Node *subRoot)
{
    if(root== nullptr || subRoot == nullptr)
        return root==subRoot;

    if(root->data == subRoot->data && isSameTree(root, subRoot))
        return true;

    return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

int main() {
    vector<int> p_preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, 6, -1, -1};
    int idx1 = -1;
    Node* p = buildTree(p_preorder, idx1);

    vector<int> q_preorder = {3, 4, -1, -1, 5, -1, 6, -1, -1};
    int idx2 = -1;
    Node* q = buildTree(q_preorder, idx2);

    if (isSubTree(p, q)) {
        cout << "Yes, the second tree is the subtree of the first!\n";
    } else {
        cout << "Noooo!\n";
    }
    return 0;
}
