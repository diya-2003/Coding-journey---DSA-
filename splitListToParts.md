# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem asks us to divide a linked list into `k` parts such that the parts are as equal in size as possible, with any extra nodes distributed to the earlier parts. We need to handle cases where the linked list has fewer nodes than `k`, resulting in some empty parts.

My first thought was to traverse the list to calculate its total length, then use this information to divide the nodes across the `k` parts as evenly as possible. This ensures the problem constraints are met.

# Approach
<!-- Describe your approach to solving the problem. -->
1. **Find the length of the linked list**: We first traverse the list to determine the total number of nodes (`n`).
2. **Calculate base size and extra nodes**: Divide `n` by `k` to get the base size of each part. Any remainder (`n % k`) represents the extra nodes that will be distributed to the first `extra` parts.
3. **Split the list**: Traverse the list again to create the `k` parts. For each part, assign `baseSize` nodes, and give an extra node to the first `extra` parts.
4. **Handle shorter lists**: If the list has fewer than `k` nodes, ensure some parts are empty (`NULL`).
5. **Break the list**: After each part, set the `next` pointer to `NULL` to detach it from the rest of the list.

# Complexity
- **Time complexity**:  
   $$O(n)$$  
   We traverse the list twice — once to calculate its length and once to split it — resulting in linear time complexity where `n` is the number of nodes in the list.

- **Space complexity**:  
   $$O(k)$$  
   We use an array to store the `k` parts, so the space complexity depends on `k`.

# Code
```c
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
/*
  Author   : Pankaj Mondal
	Date     : Sunday, September 8, 2024, 9:52 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
```

This implementation should now be complete with the correct approach and complexity analysis.
