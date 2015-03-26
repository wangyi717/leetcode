/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* aHead = new ListNode(0);
        fast = slow->next;
        slow->next = NULL;
        while (fast) {
            ListNode* temp = fast->next;
            fast->next = aHead->next;
            aHead->next = fast;
            fast = temp;
        }
        slow = head;
        fast = aHead->next;
        while (fast) {
            ListNode* temp = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = temp;
        }
    }
};
