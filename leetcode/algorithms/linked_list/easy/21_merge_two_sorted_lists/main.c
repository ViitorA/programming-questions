/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) {
        return list2;
    } else if (!list2) {
        return list1;
    } else if(!list1 && !list2) {
        return NULL;
    }

    struct ListNode *l1 = list1;
    struct ListNode *l2 = list2;

    struct ListNode *headOr = NULL;
    struct ListNode *head = NULL;
    if(l1->val <= l2->val) {
            headOr = l1;
            l1 = l1->next;
    } else {
            headOr = l2;
            l2 = l2->next;
    }

    head = headOr;

    while(l1 || l2) {
        if(!l1) { // lista 1 acabou -> O resto é a lista 2
            head->next = l2;
            break;
        } else if (!l2) {
            head->next = l1;
            break;
        }

        struct ListNode *aux = NULL;
        if(l1->val <= l2->val) {
            aux = head->next;
            head->next = l1;
            l2 = aux;
        } else {
            aux = head->next;
            head->next = l2;
            l1 = aux;
        }
    }

    return headOr;
}
