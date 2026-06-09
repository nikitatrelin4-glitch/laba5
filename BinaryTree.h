#pragma once
#include <vector>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val);
};

std::vector<int> preorder(Node* root);
std::vector<int> inorder(Node* root);
std::vector<int> postorder(Node* root);
std::vector<std::vector<int>> level_order(Node* root);
int countPathsToLeaves(Node* root);
void freeTree(Node* root);
