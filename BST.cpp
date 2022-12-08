#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode *parent;
    struct TreeNode *left;
    struct TreeNode *right;
};

TreeNode *search(TreeNode *l, int x){
    if (l == NULL)
        return NULL;
    if (l->data == x)
        return l;
    
    if (x < l->data){
        return search(l->left, x);
    }
    else{
        return search(l->right, x);
    }
}

void insert(TreeNode **l, int x, TreeNode *parent){
    if (*l == NULL){
         struct TreeNode* newNode = new TreeNode;
         newNode->data = x;
         newNode->left = newNode->right = NULL;
         newNode->parent = parent;
        //  if (parent != 0){
        //     cout << x << " " << parent->data << endl;
        //  }
         *l = newNode;
         return;
    }
    if (x < (*l)->data){
        return insert(&((*l)->left), x, *l);
    }
    else{
        return insert(&((*l)->right), x, *l);
    }
}

void traverse(TreeNode *l){
    if (l != NULL){
        traverse(l->left);
        cout << l->data <<endl;
        traverse(l->right);
    }
}

int successor(TreeNode * root) {
  root = root -> right;
  while (root -> left != NULL) root = root -> left;
  return root -> data;
}
int predecessor(TreeNode * root) {
  root = root -> left;
  while (root -> right != NULL) root = root -> right;
  return root -> data;
}

TreeNode * remove(TreeNode * root, int x){
    if (root == NULL) return NULL;
    if (x > root->data) 
        root->right = remove(root->right, x);
    else if (x < root->data){
        root->left = remove(root->left, x);
    }
    else {
        if (root->left == NULL && root->right == NULL) 
            root = NULL;
        else if (root->right != NULL) {
            root->data = successor(root);
            root->right = remove(root->right, root->data);
        } else {
            root->data = predecessor(root);
            root->left = remove(root->left, root->data);
        } 
    }
    return root;
}

int main(){
    struct TreeNode* head = NULL; 
    insert(&head, 20, NULL); 
    insert(&head, 30, NULL); 
    insert(&head, 10, NULL); 
    insert(&head, 9, NULL); 
    insert(&head, 40, NULL); 
    insert(&head, 21, NULL); 
    // insert(&head, 10, NULL); 
    // insert(&head, 40, NULL); 
    // traverse(head);
    traverse(head);
    head = remove(head, 20);
    cout <<"after removed"<<endl;
    traverse(head);
    return 0;
}