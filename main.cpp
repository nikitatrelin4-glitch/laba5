#include <iostream>
#include "BinaryTree.h"
#include "tests.h"

void printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    runTests();

    std::cout << "=== Лабораторная работа: Бинарные деревья ===\n\n";

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    std::cout << "--- Обязательная часть: Обходы дерева ---\n";
    
    std::cout << "Прямой обход (Preorder): ";
    printVector(preorder(root));

    std::cout << "Симметричный обход (Inorder): ";
    printVector(inorder(root));

    std::cout << "Обратный обход (Postorder): ";
    printVector(postorder(root));

    std::cout << "Обход в ширину (Level-order):\n";
    auto levels = level_order(root);
    for (size_t i = 0; i < levels.size(); ++i) {
        std::cout << "  Уровень " << i << ": ";
        printVector(levels[i]);
    }

    std::cout << "\n--- Вариативная часть (Вариант 4) ---\n";
    std::cout << "Количество путей от корня до листьев: " << countPathsToLeaves(root) << "\n";

    freeTree(root);
    return 0;
}
