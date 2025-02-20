
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int lists_size = lists.size();
        if (lists_size == 0) {
            return nullptr;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < lists_size; ++i) {
            if (lists[i] != nullptr) {
                pq.emplace(lists[i]->val,i);
            }
        }
        if (pq.empty()) {
            return nullptr;
        }
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        while (true) {
            auto it = pq.top();
            pq.pop();
            temp->val = it.first;
            if (lists[it.second]->next != nullptr) {
                lists[it.second] = lists[it.second]->next;
                pq.emplace(lists[it.second]->val,it.second);
            }
            if (!pq.empty()) {
                temp->next = new ListNode();
                temp = temp->next;
            } else {
                break;
            }
        }
        return head;
    }
};
