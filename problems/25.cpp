#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    void PrintList(ListNode* head) {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            length++;
        }
        ListNode* last_tail = NULL;
        ListNode* cur_tail;
        ListNode* cur = head;
        ListNode* next = NULL;
        head = NULL;
        while (length >= k) {
            cur_tail = cur;
            next = cur->next;
            for (int i = 1; i < k; i++) {
                // cout << cur->val << " " << next->val << endl;
                ListNode* tem_next = next->next;
                next->next = cur;
                cur = next;
                next = tem_next;
            }
            if (!head) head = cur;
            if (last_tail) last_tail->next = cur;
            last_tail = cur_tail;
            // cout << cur_tail->val << " " << cur->val << " " << next->val << endl;
            cur = next;
            length -= k;
        }
        last_tail->next = cur;
        // PrintList(head);
        return head;
    }
};