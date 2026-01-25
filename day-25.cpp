#include<iostream>
using namespace std;
 class Node{
    public: 
    int data ;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
 };
 Node* tree(){
    int val;
    cout<<"Enter value: ";
    cin>>val;
    if(val == -1){
        return NULL;
    }

    Node* root = new Node(val);
    root->left = tree();
    root->right = tree();
    
    return root;
 }

 void order(Node* root){
    if(root == NULL){
        return;
    }
    order(root->left);
    cout<<root->data<<" ";
    order(root->right);
 }

 void pre(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);

 }

 void post(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    post(root->left);
    post(root->right);

 }

 int main(){
    Node* root = tree();
    order(root);
    cout<<endl;
     pre(root);
     cout<<endl;
     post(root);
     cout<<endl;
     return 0;
 }