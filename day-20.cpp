#include <iostream>
using namespace std;

// Definition of singly linked list node
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int x) {
        data = x;
        next = NULL;
    }
};

// Function to rearrange odd and even indexed nodes
ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    // Connect odd list with even list
    odd->next = evenHead;

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty";
        return 0;
    }

    int value;
    cout << "Enter node values:\n";
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> value;
        temp->next = new ListNode(value);
        temp = temp->next;
    }

    cout << "Original List: ";
    printList(head);

    head = oddEvenList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
