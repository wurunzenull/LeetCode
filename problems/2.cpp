/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        int flag = 0;
        while (l1 || l2) {
            int add = flag;
            if (l1) add += l1->val;
            if (l2) add += l2->val;
            flag = add / 10;
            if (result == nullptr) {
                result = new ListNode(add % 10);
                tail = result;
            } else {
                tail->next = new ListNode(add % 10);
                tail = tail->next;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (result == nullptr) {
            result = new ListNode(0);
        }
        if (flag) {
            tail->next = new ListNode(flag);
        }
        ListNode* head = result;
        return result;
    }
};