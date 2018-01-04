#include <cstdio>
using namespace std;

struct Node{
  int lheight;
  int rheight;
  Node *left;
  Node *right;
  int Data;
  Node(int Data, int lheight = 0, int rheight = 0,
   Node *left = nullptr, Node *right = nullptr) :
   Data(Data), lheight(lheight), rheight(rheight),
   left(left), right(right) {}
};

class AVL{
public:
  AVL():root(nullptr){}

  ~AVL(){
    clearAll();
  }

  void clearAll() {
    root = nullptr;
  }

  int insert(Node* &root, const int& data) {
    if (root == nullptr) {
      root = new Node(data);
      return 1;
    }

    if (data > root->Data) {
      root->rheight = insert(root->right, data);
      if (root->rheight - root->lheight >= 2) {
        rebalance(root, false);
      }
      return root->rheight + 1;
    }
    else {
      root->lheight = insert(root->left, data);
      if (root->rheight - root->lheight <= -2) {
        rebalance(root, true);
      }
      return root->lheight + 1;
    }
  }

  void insertToRoot(const int& data) {
    insert(root, data);
  }

  void rebalance(Node* &root, bool leftHiger) {
    if (leftHiger) {
      Node* child = root->left;
      if (child->lheight < child->rheight) {
        Node* grandChild = child->right;
        child->rheight = grandChild->lheight;
        grandChild->lheight = ((child->lheight > child->rheight) ? child->lheight : child->rheight) + 1;
        child->right = grandChild->left;
        grandChild->left = child;
        root->left = child = grandChild;
      }
      root->lheight = child->rheight;
      child->rheight = ((root->lheight > root->rheight) ? root->lheight : root->rheight) + 1;
      root->left = child->right;
      child->right = root;
      root = child;
    }
    else {
      Node* child = root->right;
      if (child->rheight < child->lheight) {
        Node* grandChild = child->left;
        child->lheight = grandChild->rheight;
        grandChild->rheight = ((child->lheight > child->rheight) ? child->lheight : child->rheight) + 1;
        child->left = grandChild->right;
        grandChild->right = child;
        root->right = child = grandChild;
      }
      root->rheight  = child->lheight;
      child->lheight = ((root->lheight > root->rheight) ? root->lheight : root->rheight) + 1;
      root->right = child->left;
      child->left = root;
      root = child;
    }
  }

  void printAll() {
    print(root);
    printf("\n");
  }

  void print(Node *root) {
    if (root == nullptr)
      return;
    printf("%d ", root->Data);
    print(root->left);
    print(root->right);
  }
  
  private:
    Node *root;
};

int num;
int size;
int data;
AVL tree;

int main() {
  scanf("%d", &num);
  for (int i = 0; i < num; ++i) {
    tree.clearAll();
    scanf("%d", &size);
    for (int t = 0; t < size; ++t) {
      scanf("%d", &data);
      tree.insertToRoot(data);
    }
    tree.printAll();
  }
  return 0;
}