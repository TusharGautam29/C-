#include <iostream>
using namespace std;
class node{
    public:
        int val;
        node* left;
        node* right;
        int h;
        node(int val) : val(val),left(nullptr),right(nullptr);
}
node* leftrotate(node* x){
    node* y=x->right;
    node* z=y->left;
    y->left=x;
    x->right=z;
    x->h=1+max(x-left->h,x->right->h);
    y->h=1+max(y-right->h,y->left->h);
    return y;
}
node* rightrotate(node* x){
    node* y = x->left;
    node* z = x->right;
    y->right=x;
    x->left=z;
    x->h=1+max(x-left->h,x->right->h);
    y->h=1+max(y-right->h,y->left->h);
    return y;
}
int height(node* x){
    if(x==nullptr) return 0;
    return x->h;
}
int balance(node* x){
    if(x==nullptr) return 0;
    return heigth(x->left) - height(x->right);
}
node* insert(node* x,int k){
    if(x==nullptr) return new node(k);
    if(k<x->left->val) x->left=insert(x->left,k);
    else if(k>x->right->val) x->right=insert(x->right,k);
    else return x;
    x->h=1+max(x->right->h,x->left->h);
    int balance=height(x);
    if(balance>1 && k<x->left->val) return rightrotate(x,k);
    else if(balance<1 && k>x->right->val) return leftrotate(x,k);
    else if(balance<1 && k<x->left->val){
        x->right=rightrotate(x,k);
        return leftrotate(x,k);
    }
    else if(balance>1 && k>x->left->val){
        x->left=left(x,k);
        return rightrotate(x,k);
    }
    return x;
}
int main() {
  cout << endl << endl;
  return 0;
}