
import java.util.*;

class Solution {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head.next == null || left == right) {
            return head;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode tmp_start = dummy;
        int cnt = right - left + 1;
        while (left > 1) {
            tmp_start = tmp_start.next;
            --left;
        }
        ListNode start = tmp_start;
        ListNode end = tmp_start.next;
        ListNode tmp_end = end;
        while (cnt > 0) {
            ListNode tmp_next = tmp_end.next;
            tmp_end.next = tmp_start;
            tmp_start = tmp_end;
            tmp_end = tmp_next;
            --cnt;
        }
        start.next = tmp_start;
        end.next = tmp_end;
        return dummy.next;
    }
}
