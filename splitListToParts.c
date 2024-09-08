#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    // Initialize returnSize with the value of k
    *returnSize = k;
    
    // Create an array of struct ListNode* to store the results
    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    
    // Initialize all elements in the result to NULL
    for (int i = 0; i < k; i++) {
        result[i] = NULL;
    }
    
    // Find the total length of the linked list
    int n = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    
    // Calculate the base size of each part and how many parts will have an extra node
    int baseSize = n / k;
    int extra = n % k;
    
    // Reset temp to head for splitting
    temp = head;
    
    // Split the linked list
    for (int i = 0; i < k; i++) {
        if (temp == NULL) {
            result[i] = NULL;  // If there are not enough nodes, the remaining parts are NULL
        } else {
            result[i] = temp;  // Start of the current part
            int partSize = baseSize + (extra > 0 ? 1 : 0);  // Determine the size of the current part
            extra--;  // Decrease the count of extra nodes
            
            // Move temp to the end of the current part
            for (int j = 1; j < partSize; j++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }
            
            // Break the link to the rest of the list, but only if temp is not NULL
            if (temp != NULL) {
                struct ListNode* nextPart = temp->next;
                temp->next = NULL;
                temp = nextPart;
            }
        }
    }
    
    return result;
}
