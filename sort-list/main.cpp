
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    pair<ListNode*, ListNode*> splitList(ListNode* head) {
        ListNode* left_part = head;
        ListNode* left_tail = head;
        ListNode* right_part = head->next;
        ListNode* right_tail = head->next;
        while (right_tail->next != nullptr && right_tail->next->next != nullptr) {
            left_tail = right_part;
            right_part = right_part->next;
            right_tail = right_tail->next->next;
        }
        left_tail->next = nullptr;
        return {left_part, right_part};
    }
    ListNode* mergeList(ListNode* left_part, ListNode* right_part) {
        if (left_part == nullptr) {
            return right_part;
        } else if (right_part == nullptr) {
            return left_part;
        }
        ListNode* head = left_part;
        if (left_part->val < right_part->val) {
            left_part = left_part->next;
        } else {
            head = right_part;
            right_part = right_part->next;
        }
        ListNode* tail = head;
        while (left_part != nullptr || right_part != nullptr) {
            if (left_part == nullptr) {
                tail->next = right_part;
                right_part = right_part->next;
            } else if (right_part == nullptr) {
                tail->next = left_part;
                left_part = left_part->next;
            } else {
                if (left_part->val < right_part->val) {
                    tail->next = left_part;
                    left_part = left_part->next;
                } else {
                    tail->next = right_part;
                    right_part = right_part->next;
                }
            }
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto [left_part, right_part] = splitList(head);
        left_part = sortList(left_part);
        right_part = sortList(right_part);
        return mergeList(left_part, right_part);
    }
};
