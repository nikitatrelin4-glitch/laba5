#include "BinaryTree.h"
#include <queue>

Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

void preorderImpl(Node* node, std::vector<int>& result) {
    if (!node) return;
    result.push_back(node->value);
    preorderImpl(node->left, result);
    preorderImpl(node->right, result);
}

std::vector<int> preorder(Node* root) {
    std::vector<int> result;
    preorderImpl(root, result);
    return result;
}

void inorderImpl(Node* node, std::vector<int>& result) {
    if (!node) return;
    inorderImpl(node->left, result);
    result.push_back(node->value);
    inorderImpl(node->right, result);
}

std::vector<int> inorder(Node* root) {
    std::vector<int> result;
    inorderImpl(root, result);
    return result;
}

void postorderImpl(Node* node, std::vector<int>& result) {
    if (!node) return;
    postorderImpl(node->left, result);
    postorderImpl(node->right, result);
    result.push_back(node->value);
}

std::vector<int> postorder(Node* root) {
    std::vector<int> result;
    postorderImpl(root, result);
    return result;
}

std::vector<std::vector<int>> level_order(Node* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            currentLevel.push_back(current->value);

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        result.push_back(currentLevel);
    }
    return result;
}

int countPathsToLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countPathsToLeaves(root->left) + countPathsToLeaves(root->right);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
