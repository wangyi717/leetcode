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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow = head;
        ListNode *fast = head->next;
        bool isExisted = false;
        while (fast && fast->next) {
            if (fast == slow) {
                isExisted = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if (isExisted) {
            int len = 1;
            fast = fast->next;
            while (fast != slow) {
                ++len;
                fast = fast->next;
            }
            fast = head;
            while (len--)
                fast = fast->next;
            ListNode* p = head;
            while (p != fast) {
                p = p->next;
                fast = fast->next;
            }
            return p;
        }
        return NULL;
    }
};
