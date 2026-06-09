#pragma once
#include "BinaryTree.h"
#include <cassert>
#include <iostream>

inline void runTests() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::vector<int> expectedPreorder = {1, 2, 4, 5, 3};
    assert(preorder(root) == expectedPreorder);

    std::vector<int> expectedInorder = {4, 2, 5, 1, 3};
    assert(inorder(root) == expectedInorder);

    std::vector<int> expectedPostorder = {4, 5, 2, 3, 1};
    assert(postorder(root) == expectedPostorder);

    std::vector<std::vector<int>> expectedLevelOrder = {{1}, {2, 3}, {4, 5}};
    assert(level_order(root) == expectedLevelOrder);

    assert(countPathsToLeaves(root) == 3);

    freeTree(root);

    Node* emptyRoot = nullptr;
    assert(countPathsToLeaves(emptyRoot) == 0);
    assert(preorder(emptyRoot).empty());

    Node* singleNode = new Node(42);
    assert(countPathsToLeaves(singleNode) == 1);
    freeTree(singleNode);

    std::cout << "[SUCCESS] Все автоматические тесты успешно пройдены!\n\n";
}
