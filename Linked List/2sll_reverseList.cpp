/*
Problem Statement:
Implement a singly linked list with the following functionalities:
1. Create a linked list from user input.
2. Reverse the linked list using:
   a) Iterative method
   b) Recursive method
3. Print the linked list.

Example:
Input:
5
10 20 30 40 50

Output:
Original List: 10 20 30 40 50
Reversed (Iterative): 50 40 30 20 10
Reversed (Recursive): 10 20 30 40 50
*/

#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a linked list from a vector of integers
Node* createList(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node{arr[0], NULL};
    Node* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node{arr[i], NULL};
        curr = curr->next;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the linked list (Iterative approach)
Node* reverseIterative(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next; // store next
        curr->next = prev;     // reverse pointer
        prev = curr;           // move prev forward
        curr = nextNode;       // move curr forward
    }

    return prev; // new head after reversal
}

// Function to reverse the linked list (Recursive approach)
Node* reverseRecursive(Node* head) {
    // Base case: empty list or single node
    if (head == NULL || head->next == NULL)
        return head;

    // Reverse the rest of the list
    Node* newHead = reverseRecursive(head->next);

    // Fix current node’s next pointer
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Driver function
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = createList(arr);
    cout << "Original List: ";
    printList(head);

    // Reverse Iteratively
    head = reverseIterative(head);
    cout << "Reversed (Iterative): ";
    printList(head);

    // Reverse Recursively (back to original)
    head = reverseRecursive(head);
    cout << "Reversed (Recursive): ";
    printList(head);

    return 0;
}
