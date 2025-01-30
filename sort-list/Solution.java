
import java.util.*;

class Solution {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode leftPartTail = head;
        ListNode tail = head.next;
        while (tail != null && tail.next != null) {
            leftPartTail = leftPartTail.next;
            tail = tail.next.next;
        }
        ListNode rightPart = leftPartTail.next;
        leftPartTail.next = null;
        ListNode leftPart = sortList(head);
        rightPart = sortList(rightPart);
        ListNode dummy = new ListNode();
        head = dummy;
        while (leftPart != null && rightPart != null) {
            if (leftPart.val <= rightPart.val) {
                head.next = leftPart;
                leftPart = leftPart.next;
            } else {
                head.next = rightPart;
                rightPart = rightPart.next;
            }
            head = head.next;
        }
        if (leftPart != null) {
            head.next = leftPart;
        } else {
            head.next = rightPart;
        }
        return dummy.next;
    }
}
