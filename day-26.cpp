#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* tree() {
    int value;
    cin >> value;

    if (value == -1) {
        return NULL;
    }

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int valueLeft, valueRight;
        cin >> valueLeft >> valueRight;

        if (valueLeft != -1) {
            curr->left = new Node(valueLeft);
            q.push(curr->left);
        }
        if (valueRight != -1) {
            curr->right = new Node(valueRight);
            q.push(curr->right);
        }
    }
    return root;
}

void orderLevel(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // 🔹 IMPORTANT

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        } else {
            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

int main() {
    Node* root = tree();
    orderLevel(root);
}
