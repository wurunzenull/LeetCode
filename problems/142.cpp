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
    ListNode* detectCycle(ListNode* head) {
        ListNode* result = nullptr;
        ListNode* one_step = head;
        ListNode* two_step = head;
        bool meet = false;
        while (one_step && two_step && two_step->next) {
            one_step = one_step->next;
            two_step = two_step->next->next;
            if (one_step == two_step) {
                meet = true;
                break;
            }
        }
        if (meet) {
            two_step = head;
            while (one_step && two_step) {
                if (one_step == two_step) {
                    result = one_step;
                    break;
                }
                one_step = one_step->next;
                two_step = two_step->next;
            }
        }
        return result;
    }
};