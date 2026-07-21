/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 :*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode aux = {
        .val = 0,
        .next = head
    };

    struct ListNode *slow = &aux;
    struct ListNode *fast = &aux;

    for(int i = 0; i <= n; i++)
        fast = fast->next;

    while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    struct ListNode *rem = slow->next;
    slow->next = rem->next;
    free(rem);
    return aux.next;
}
