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
        vector<ListNode*> list1, list2;
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        ListNode* temp = l1;
        while (temp) {
            list1.push_back(temp);
            temp = temp->next;
        }
        temp = l2;
        while (temp) {
            list2.push_back(temp);
            temp = temp->next;
        }
        int add = 0;
        int idx1 = list1.size() - 1, idx2 = list2.size() - 1;
        ListNode* head = nullptr;
        while (idx1 >= 0 || idx2 >= 0) {
            int sum = add;
            if (idx1 >= 0) {
                sum += list1[idx1]->val;
                idx1--;
            }
            if (idx2 >= 0) {
                sum += list2[idx2]->val;
                idx2--;
            }
            add = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        if (add) {
            ListNode* node = new ListNode(add);
            node->next = head;
            head = node;
        }
        return head;
    }
};