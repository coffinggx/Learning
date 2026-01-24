#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

class Node {
public:
  int data;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  explicit Node(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
public:
  class TreeInfo {
  public:
    int Height{};
    int Diameter{};
    TreeInfo(int h, int d) : Height{h}, Diameter{d} {}
  };
  std::unique_ptr<Node> buildBinaryTree(const std::vector<int> &nodes, int &idx) {
    idx += 1;
    if (idx >= nodes.size() || nodes[idx] == -1) {
      return nullptr;
    }
    auto node = std::make_unique<Node>(Node(nodes[idx]));
    node->left = buildBinaryTree(nodes, idx);
    node->right = buildBinaryTree(nodes, idx);
    return node;
  }
  void preOrderTraverse(const Node *root) {
    if (root == nullptr) {
      return;
    }
    std::cout << root->data;
    preOrderTraverse(root->left.get());
    preOrderTraverse(root->right.get());
  }
  void inOrderTraverse(const Node *root) {
    if (root == nullptr) {
      return;
    }
    inOrderTraverse(root->left.get());
    std::cout << root->data;
    inOrderTraverse(root->right.get());
  }
  void postOrderTraverse(const Node *root) {
    if (root == nullptr) {
      return;
    }
    postOrderTraverse(root->left.get());
    postOrderTraverse(root->right.get());
    std::cout << root->data;
  }
  void levelOrderTraverse(Node *root) {
    std::queue<Node *> q;
    if (root != nullptr) {
      q.push(root);
      q.push(nullptr);
    }
    while (!q.empty()) {
      Node *tmp = q.front();
      if (tmp == nullptr) {
        std::cout << '\n';
        q.pop();
        if (q.empty()) {
          break;
        } else {
          q.push(nullptr);
        }
      } else {
        std::cout << tmp->data;
        q.pop();
        if (tmp->left != nullptr)
          q.push(tmp->left.get());
        if (tmp->right != nullptr)
          q.push(tmp->right.get());
      }
    }
  }
  int countOfNodes(const Node *root) {
    if (root == nullptr)
      return 0;
    int lCount = countOfNodes(root->left.get());
    int rCount = countOfNodes(root->right.get());
    return lCount + rCount + 1;
  }
  int sumOfNodes(const Node *root) {
    if (root == nullptr)
      return 0;
    int lSum = sumOfNodes(root->left.get());
    int rSum = sumOfNodes(root->right.get());
    return lSum + rSum + root->data;
  }
  int height(const Node *root) {
    if (root == nullptr)
      return 0;
    int lHeight = height(root->left.get());
    int rHeight = height(root->right.get());
    return std::max(lHeight, rHeight) + 1;
  }
  TreeInfo diameter(Node *root) {
    if (root == nullptr) {
      TreeInfo ti = TreeInfo(0, 0);
      return ti;
    }
    TreeInfo til = diameter(root->left.get());
    TreeInfo tir = diameter(root->right.get());

    int h1 = til.Height;
    int h2 = tir.Height;
    int rh = std::max(h1, h2) + 1;
    int d1 = til.Diameter;
    int d2 = tir.Diameter;
    int d3 = h1 + h2 + 1;
    int rd = std::max(d3, std::max(d1, d2));
    TreeInfo ti = TreeInfo(rh, rd);
    return ti;
  }
};

int main() {
  BinaryTree bt;
  std::vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

  int idx = -1;
  auto root = bt.buildBinaryTree(nodes, idx);

  bt.preOrderTraverse(root.get());
  std::cout << "\nHeight: " << bt.height(root.get());
  std::cout << "\nNodes: " << bt.countOfNodes(root.get());
  std::cout << "\nSum: " << bt.sumOfNodes(root.get());

  auto info = bt.diameter(root.get());
  std::cout << "\nDiameter: " << info.Diameter << std::endl;
}
