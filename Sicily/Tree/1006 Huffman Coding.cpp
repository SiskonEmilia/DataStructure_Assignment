#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
using std::string;
using std::stack;
using std::priority_queue;

int chs[26];
int length;
char temp;
struct Node{
  char ch;
  int times;
  string code;

  Node *left;
  Node *right;
  void clear() {
    if (left)
      delete left;
    if (right)
      delete right;
  }
  Node (char ch, int times, Node* left = nullptr, Node* right = nullptr):
  ch(ch), times(times), left(left), right(right), code("") {}
  ~Node () {
    clear();
  }
  bool operator< (const Node& node) const {
    return times > node.times;
  }
};

priority_queue<Node> huffman;
stack<Node*> output;

void getCode(Node* root, string code) {
  if (root == nullptr)
    return;
  root->code = code;
  getCode(root->left, code + "1");
  getCode(root->right, code + "0");
}

int main() {
  for (int i = 0; i < 26; ++i)
    chs[i] = 0;
  scanf("%d", &length);
  for (int i = 0; i < length; ++i) {
    scanf("%c", &temp);
    ++chs[temp - 'A'];
  }

  for (int i = 0; i < 26; ++i) {
    if (chs[i] != 0) {
      huffman.push(Node(i + 'A', chs[i]));
    }
  }

  if (huffman.size() == 1) {
    printf("%c %d %d", huffman.top().ch, huffman.top().times, 1);
  }
  else {
    while(huffman.size() != 1) {
      Node *left = new Node(huffman.top());
      if (left->ch != 0) 
        output.push(left);
      huffman.pop();
      Node *right = new Node(huffman.top());
      if (right->ch != 0) 
        output.push(right);
      huffman.pop();
      huffman.push(Node(0, left->times + right->times, left, right));
    }


  }
}