#include <iostream>
using namespace std;

// Node class representing a single element in the linked list
class Node {
public:
    int value;
    Node* next;
    
    Node(int val) {
        value = val;
        next = NULL;
    }
};

// Function to find the middle element using the Tortoise and Hare Algorithm
int findMiddle(Node* head) {
    // Edge case: If the list is empty, return -1
    if (!head) return -1;  

    Node* slow = head;  // Moves one step at a time (Tortoise)
    Node* fast = head;  // Moves two steps at a time (Hare)

    // Loop until the fast pointer reaches the end
    while (fast && fast->next) {  
        slow = slow->next;        // Move slow by 1 step
        fast = fast->next->next;  // Move fast by 2 steps
    }

    // When fast reaches the end, slow is at the middle
    return slow->value;  
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find and print the middle element
    cout << "Middle Element: " << findMiddle(head) << endl;

    return 0;

//     📌 Explanation of the Algorithm:

// 🚀 Tortoise and Hare (Floyd’s Algorithm for Finding Middle of a Linked List)
// The algorithm uses two pointers, slow and fast:
// slow moves one step at a time (🐢).
// fast moves two steps at a time (🐇).

// When fast reaches the end (NULL), slow will be at the middle of the list.

// 🛠 Intuition / Analogy

// Imagine a race where:

// The slow pointer (Tortoise) moves one step at a time.
// The fast pointer (Hare) moves two steps at a time.

// By the time the Hare reaches the finish line, the Tortoise is halfway through, which gives us the middle element.

// 📊 Time & Space Complexity
// Time Complexity: O(N) → Each node is traversed once.
// Space Complexity: O(1) → No extra space is used.
}
