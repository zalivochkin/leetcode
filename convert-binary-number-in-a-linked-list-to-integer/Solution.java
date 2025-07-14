
class Solution {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public int getDecimalValue(ListNode head) {
        if (head == null) {
            return 0;
        }
        int res = 0;
        while (head != null) {
            res *= 2;
            if (head.val != 0) {
                res |= head.val;
            }
            head = head.next;
        }
        return res;
    }
}
