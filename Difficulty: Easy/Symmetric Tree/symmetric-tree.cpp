/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool anil(Node *a,Node* b){
        if(a==nullptr || b==nullptr) return a==b;
        return (a->data==b->data)&&anil(a->left,b->right)&&anil(a->right,b->left);
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(root==nullptr){
            return false;
        }
        return anil(root->left,root->right);
    }
};