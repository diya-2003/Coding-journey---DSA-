## Intuition
The task is to reverse a singly linked list. The intuition behind this solution is to traverse the original list, and for each node, insert it at the beginning of a new list. This way, the order of the nodes in the new list will be the reverse of the order in the original list.

## Approach
1. **Create a New ListNode:** Implement a helper function `createNode` that initializes a new node with a given value.
2. **Insert at Beginning:** Use the `insertAtBeginning` function to insert nodes at the beginning of the new list. This function will set the new node's `next` pointer to the current head of the new list and update the head to this new node.
3. **Reverse the List:** In the `reverseList` function, traverse the original list. For each node, use the `insertAtBeginning` function to insert it at the beginning of the new list.

## Complexity
- **Time complexity:** $$O(n)$$
  - We traverse the list once, inserting each node into the new list, making this operation linear in terms of the number of nodes in the original list.
- **Space complexity:** $$O(n)$$
  - We create a new list of the same size as the original list, so the additional space used is proportional to the number of nodes.

## Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* createNode(int val) 
 {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
struct ListNode* insertAtBeginning(struct ListNode* head, int val) 
{
    struct ListNode* node = createNode(val);
    node->next = head;
    return node;
}
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* newhead = NULL;
    struct ListNode* ptr = head;
    
    while (ptr != NULL) 
    {
       newhead=insertAtBeginning(newhead, ptr->val);
        ptr = ptr->next;
    }
    return newhead;
}
```