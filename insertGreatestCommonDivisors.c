int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    struct ListNode* current = head;    
    while (current && current->next) {
        int gcdValue = gcd(current->val, current->next->val);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = gcdValue;
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }
    return head;
}
