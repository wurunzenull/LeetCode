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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* result = head;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
        if (n <= nodes.size()) {
            ListNode* item = nodes.at(nodes.size() - n);
            if (n == nodes.size())
                result = item->next;
            else {
                ListNode* prev = nodes.at(nodes.size() - n - 1);
                prev->next = item->next;
            }
            delete item;
        }
        return result;
    }
};