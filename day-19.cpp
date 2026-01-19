#include <iostream>
#include <string>
using namespace std;

// Linked list node
struct Node {
    int data;
    Node* next;
};

// Insert node at end
Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node{data, NULL};

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Convert linked list to string
string listToString(Node* head) {
    string num = "";
    while (head != NULL) {
        num += to_string(head->data);
        head = head->next;
    }
    return num;
}

// Add 1 to string number
string addOneToString(string num) {
    int i = num.length() - 1;

    while (i >= 0 && num[i] == '9') {
        num[i] = '0';
        i--;
    }

    if (i < 0)
        num = '1' + num;
    else
        num[i]++;

    return num;
}

// Update linked list values
Node* updateList(Node* head, string num) {
    Node* curr = head;
    int index = 0;

    while (curr != NULL) {
        int len = to_string(curr->data).length();
        curr->data = stoi(num.substr(index, len));
        index += len;
        curr = curr->next;
    }
    return head;
}

// Main logic function
Node* addOne(Node* head) {
    string num = listToString(head);
    num = addOneToString(num);
    return updateList(head, num);
}

// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, val;
    Node* head = NULL;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertEnd(head, val);
    }

    head = addOne(head);

    cout << "Modified linked list:\n";
    printList(head);

    return 0;
}
