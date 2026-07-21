/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null) return null;

        ListNode aux = new ListNode(0,head); 
        ListNode fast = new ListNode(0,aux);
        ListNode slow = new ListNode(0,aux);

        for(int i = 0; i <= n; i++) 
            fast = fast.next;

        while(fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        ListNode rem = slow.next;
        slow.next = rem.next;

        return aux.next;
    }
}
