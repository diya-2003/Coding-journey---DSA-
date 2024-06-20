## Intuition
This code seems to be targeting the removal of duplicate elements from a singly-linked list. It iterates through the list and removes any duplicate elements it encounters.

## Approach
The approach is simple: iterate through the list and whenever a duplicate element is encountered, remove it by adjusting the `next` pointers appropriately.

## Complexity
- Time complexity: \( O(n) \), where \( n \) is the number of nodes in the linked list. The algorithm iterates through the list once.
- Space complexity: \( O(1) \), because the algorithm only uses a constant amount of extra space regardless of the input size.

# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    if(head==NULL)
    {
        return head;
    }
    struct ListNode *ptr=head;
    
    while (ptr->next!=NULL) 
    {
        if (ptr->val==ptr->next->val) 
        {
            struct ListNode *temp=ptr->next;
            ptr->next=ptr->next->next;
            free(temp);
        } 
        else
        {
            ptr = ptr->next;
        }
    }
    return head;
}
```