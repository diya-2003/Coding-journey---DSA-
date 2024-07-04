# Intuition
The problem is to merge nodes of a linked list between zeros, where each segment's nodes are summed, and only the sum is retained in the resultant list. Zeros serve as delimiters for these segments.

# Approach
1. Traverse the linked list starting from the node after the head (since the head node is guaranteed to be zero).
2. Use a pointer `ptr1` to traverse the list, and accumulate values in a `sum` variable until a zero is encountered.
3. On encountering a zero, check if the `sum` is non-zero, then create a new node with this sum and link it to the resultant list.
4. Reset the `sum` to zero and continue until the end of the list.
5. Return the head of the resultant list.

# Complexity
- Time complexity: \(O(n)\) where \(n\) is the number of nodes in the input list. We traverse each node once.
- Space complexity: \(O(1)\) excluding the space required for the output list. The space used is constant as we're only using a few pointers and integer variables.

# Code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* newnode(int value)
{
    struct ListNode *ptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val=value;
    ptr->next=NULL;
    return ptr;
}
struct ListNode* mergeNodes(struct ListNode* head) 
{
    struct ListNode *ptr1,*ptr2=NULL,*ptr3=NULL;
    int sum=0;
    ptr1=head->next;
    while(ptr1!=NULL) 
    {
        if(ptr1->val==0)
        {
            if (sum!=0) 
            {
                if(ptr2==NULL) 
                {
                    ptr2=newnode(sum);
                    ptr3=ptr2;
                } 
                else 
                {
                    ptr3->next=newnode(sum);
                    ptr3=ptr3->next;
                }
                sum=0;
            }
        }
        else
        {
            sum+=ptr1->val;
        }
        ptr1=ptr1->next;
    }
    return ptr2;
}
```