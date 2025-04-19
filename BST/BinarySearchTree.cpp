#include <iostream>
#include <memory>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdexcept> // For std::invalid_argument

template <typename T>
class BinarySearchTree {
private:
    int nodeCount = 0;
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node(T elem) : data(elem), left(nullptr), right(nullptr) {}
    };
    std::unique_ptr<Node> root;

    // Private method to recursively add a value in the binary tree
    std::unique_ptr<Node> add(std::unique_ptr<Node> node, const T& elem) {
        // Base case: found a leaf node
        if (node == nullptr) {
            return std::make_unique<Node>(elem);
        } else {
            // Pick a subtree to insert element
            if (elem < node->data) {
                node->left = add(std::move(node->left), elem);
            } else if (elem > node->data) {
                node->right = add(std::move(node->right), elem);
            }
            // If the element is equal, we do nothing (as per the Java code's comment)
            return node;
        }
    }

    // Private method to recursively remove a value in the binary tree
    std::unique_ptr<Node> remove(std::unique_ptr<Node> node, const T& elem) {
        if (node == nullptr) return nullptr;
        int cmp = 0;
        if (elem < node->data) cmp = -1;
        else if (elem > node->data) cmp = 1;

        // Dig into left subtree, the value we're looking for is smaller than the current value
        if (cmp < 0) {
            node->left = remove(std::move(node->left), elem);
        }
        // Dig into right subtree, the value we're looking for is greater than the current value
        else if (cmp > 0) {
            node->right = remove(std::move(node->right), elem);
        }
        // Found the node we wish to remove
        else {
            // This is the case with only a right subtree or no subtree at all.
            // In this situation just swap the node we wish to remove with its right child.
            if (node->left == nullptr) {
                return std::move(node->right);
            }
            // This is the case with only a left subtree or no subtree at all.
            // In this situation just swap the node we wish to remove with its left child.
            else if (node->right == nullptr) {
                return std::move(node->left);
            }
            // When removing a node from a binary tree with two links the
            // successor of the node being removed can either be the largest
            // value in the left subtree or the smallest value in the right
            // subtree. In this implementation I have decided to find the
            // smallest value in the right subtree which can be found by
            // traversing as far left as possible in the right subtree.
            else {
                Node* tmp = findMin(node->right.get());
                node->data = tmp->data;
                node->right = remove(std::move(node->right), tmp->data);
                // If instead we wanted to find the largest node in the left
                // subtree as opposed to smallest node in the right subtree
                // here is what we would do:
                // Node* tmp = findMax(node->left.get());
                // node->data = tmp->data;
                // node->left = remove(std::move(node->left), tmp->data);
            }
        }
        return node;
    }

    // Helper method to find the leftmost node (which has the smallest value)
    Node* findMin(Node* node) const {
        while (node->left != nullptr) node = node->left.get();
        return node;
    }

    // Helper method to find the rightmost node (which has the largest value)
    Node* findMax(Node* node) const {
        while (node->right != nullptr) node = node->right.get();
        return node;
    }

    // Private recursive method to find an element in the tree
    bool contains(const Node* node, const T& elem) const {
        // Base case: reached bottom, value not found
        if (node == nullptr) return false;
        if (elem < node->data) return contains(node->left.get(), elem);
        else if (elem > node->data) return contains(node->right.get(), elem);
        // We found the value we were looking for
        else return true;
    }

    // Recursive helper method to compute the height of the tree
    int height(const Node* node) const {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->left.get()), height(node->right.get()));
    }

    // Helper methods for tree traversals returning vectors
    void preOrderTraversalHelper(const Node* node, std::vector<T>& result) const {
        if (node != nullptr) {
            result.push_back(node->data);
            preOrderTraversalHelper(node->left.get(), result);
            preOrderTraversalHelper(node->right.get(), result);
        }
    }

    void inOrderTraversalHelper(const Node* node, std::vector<T>& result) const {
        if (node != nullptr) {
            inOrderTraversalHelper(node->left.get(), result);
            result.push_back(node->data);
            inOrderTraversalHelper(node->right.get(), result);
        }
    }

    void postOrderTraversalHelper(const Node* node, std::vector<T>& result) const {
        if (node != nullptr) {
            postOrderTraversalHelper(node->left.get(), result);
            postOrderTraversalHelper(node->right.get(), result);
            result.push_back(node->data);
        }
    }

    std::vector<T> levelOrderTraversalHelper() const {
        std::vector<T> result;
        if (root == nullptr) return result;
        std::queue<Node*> queue;
        queue.push(root.get());
        while (!queue.empty()) {
            Node* node = queue.front();
            queue.pop();
            result.push_back(node->data);
            if (node->left != nullptr) queue.push(node->left.get());
            if (node->right != nullptr) queue.push(node->right.get());
        }
        return result;
    }

public:
    // Check if this binary tree is empty
    bool isEmpty() const {
        return size() == 0;
    }

    // Get the number of nodes in this binary tree
    int size() const {
        return nodeCount;
    }

    // Add an element to this binary tree. Returns true
    // if we successfully perform an insertion
    bool add(const T& elem) {
        // Check if the value already exists in this
        // binary tree, if it does ignore adding it
        if (contains(elem)) {
            return false;
            // Otherwise add this element to the binary tree
        } else {
            root = add(std::move(root), elem);
            nodeCount++;
            return true;
        }
    }

    // Remove a value from this binary tree if it exists, O(n)
    bool remove(const T& elem) {
        // Make sure the node we want to remove
        // actually exists before we remove it
        if (contains(elem)) {
            root = remove(std::move(root), elem);
            nodeCount--;
            return true;
        }
        return false;
    }

    // returns true is the element exists in the tree
    bool contains(const T& elem) const {
        return contains(root.get(), elem);
    }

    // Computes the height of the tree, O(n)
    int height() const {
        return height(root.get());
    }

    // Enum for tree traversal order (C++ doesn't directly map the Java enum here)
    enum class TraversalOrder {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER,
        LEVEL_ORDER
    };

    // This method returns a vector for a given TraversalOrder.
    // The ways in which you can traverse the tree are in four different ways:
    // preorder, inorder, postorder and levelorder.
    std::vector<T> traverse(TraversalOrder order) const {
        std::vector<T> result;
        switch (order) {
            case TraversalOrder::PRE_ORDER:
                preOrderTraversalHelper(root.get(), result);
                break;
            case TraversalOrder::IN_ORDER:
                inOrderTraversalHelper(root.get(), result);
                break;
            case TraversalOrder::POST_ORDER:
                postOrderTraversalHelper(root.get(), result);
                break;
            case TraversalOrder::LEVEL_ORDER:
                result = levelOrderTraversalHelper();
                break;
            default:
                break;
        }
        return result;
    }
};

int main() {
    BinarySearchTree<int> bst;
    std::cout << "Is BST empty? " << bst.isEmpty() << std::endl;

    bst.add(5);
    bst.add(3);
    bst.add(7);
    bst.add(2);
    bst.add(4);
    bst.add(6);
    bst.add(8);

    std::cout << "Size of BST: " << bst.size() << std::endl;
    std::cout << "Contains 4? " << bst.contains(4) << std::endl;
    std::cout << "Contains 9? " << bst.contains(9) << std::endl;

    std::cout << "Pre-order traversal: ";
    for (int val : bst.traverse(BinarySearchTree<int>::TraversalOrder::PRE_ORDER)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    for (int val : bst.traverse(BinarySearchTree<int>::TraversalOrder::IN_ORDER)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    for (int val : bst.traverse(BinarySearchTree<int>::TraversalOrder::POST_ORDER)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    for (int val : bst.traverse(BinarySearchTree<int>::TraversalOrder::LEVEL_ORDER)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Height of BST: " << bst.height() << std::endl;

    bst.remove(3);
    std::cout << "Size of BST after removing 3: " << bst.size() << std::endl;
    std::cout << "In-order traversal after removal: ";
    for (int val : bst.traverse(BinarySearchTree<int>::TraversalOrder::IN_ORDER)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
