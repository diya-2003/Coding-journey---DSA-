struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    bool exists[100001] = {false};

    for (int i = 0; i < numsSize; i++) 
        exists[nums[i]] = true;
  
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;
    while (current->next != NULL) {
        if (exists[current->next->val]) {
            struct ListNode* toDelete = current->next;
            current->next = current->next->next;
            free(toDelete); 
        }
        else
            current = current->next;
    }
    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}
