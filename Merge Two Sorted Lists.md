# Intuition
To merge two sorted linked lists into a single sorted linked list, we can use a two-pointer approach where we traverse both lists simultaneously, comparing the values at each step and attaching the smaller value node to our result list.

# Approach
1. Create a helper function `newnode` to allocate and initialize a new node with a given value.
2. Initialize a dummy node to act as the starting point of the merged list and a current pointer to build the merged list.
3. Traverse through both lists (`list1` and `list2`):
   - Compare the current nodes of both lists.
   - Attach the smaller node to the current node of the merged list and move the corresponding list's pointer forward.
4. If one of the lists is exhausted, attach the remaining part of the other list to the merged list.
5. Return the merged list, starting from the node next to the dummy node.

# Complexity
- Time complexity: \(O(n + m)\), where \(n\) and \(m\) are the lengths of the two lists.
- Space complexity: \(O(1)\) (excluding the space required for the output list).

# Code
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* newnode(int value)
 {
    struct ListNode* ptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val=value;
    ptr->next=NULL;
    return ptr;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode* head=NULL;
    struct ListNode* current=NULL;
    struct ListNode* ptr;
    if (list1==NULL)
    {
        return list2;
    }
    if (list2==NULL) 
    {
        return list1;
    }
    while (list1!=NULL && list2!=NULL) 
    {
        if (list1->val <= list2->val) 
        {
            ptr=newnode(list1->val);
            list1=list1->next;
        } 
        else 
        {
            ptr=newnode(list2->val);
            list2 = list2->next;
        }
        if (head==NULL) 
        {
            head=ptr;
            current=head;
        } 
        else 
        {
            current->next=ptr;
            current=ptr;
        }
    }
    while (list1!=NULL) 
    {
        ptr=newnode(list1->val);
        current->next=ptr;
        current=ptr;
        list1=list1->next;
    }

    while (list2!=NULL) 
    {
        ptr=newnode(list2->val);
        current->next=ptr;
        current=ptr;
        list2=list2->next;
    }
    return head;
}
```