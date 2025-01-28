
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* tmp_start = dummy;
        int cnt = right - left + 1;
        while (left > 1) {
            tmp_start = tmp_start->next;
            --left;
        }
        ListNode *start = tmp_start;
        ListNode *end = tmp_start->next;
        ListNode* tmp_end = end;
        while (cnt > 0) {
            ListNode* tmp_next = tmp_end->next;
            tmp_end->next = tmp_start;
            tmp_start = tmp_end;
            tmp_end = tmp_next;
            --cnt;
        }
        start->next = tmp_start;
        end->next = tmp_end;
        return dummy->next;
    }
};

int main() {
    Solution sol;
    return EXIT_SUCCESS;
}

/*
Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/
