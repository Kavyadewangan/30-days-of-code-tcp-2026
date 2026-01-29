#include<iostream>
#include<climits>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
Node* buildTree(int arr[], int &i, int n){
    if(i>=n||arr[i] == -1){
        i++;
        return NULL;
    }
   
    Node* root = new Node(arr[i++]);
    root->left = buildTree(arr, i, n);
    root->right = buildTree(arr,i, n);
    return root;
}
int maxPathSumUtil(Node* root, int &ans){
    if(root == NULL)
    return 0;
    int left = max(0, maxPathSumUtil(root->left, ans));
    int right = max(0, maxPathSumUtil(root->right, ans));

    ans = max(ans, root->data + left + right);
    return root -> data + max(left, right);
}
int maxPathSum(Node*root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}
int main(){
    int n;
    cout<<"enter the size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements(-1 for NULL): ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int index = 0;
    Node* root = buildTree(arr, index, n);
    cout<<"Maximum Path Sum: "<<maxPathSum(root);

    return 0;
}