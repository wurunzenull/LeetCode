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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (l1 || l2) {
            ListNode* node;
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    node = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    node = new ListNode(l2->val);
                    l2 = l2->next;
                }
            } else if (l1) {
                node = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                node = new ListNode(l2->val);
                l2 = l2->next;
            }
            if (!head) {
                head = node;
                tail = head;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }
        return head;
    }
};
