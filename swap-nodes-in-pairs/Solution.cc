/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *ans = q;
        ListNode *pre = new ListNode(0);
        while (p != NULL && q != NULL) {
            pre->next = q;
            p->next = q->next;
            q->next = p;
            pre = p;
            p = p->next;
            if (p != NULL)
                q = p->next;
        }
        return ans;
    }
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Solution solution;
    ListNode *result = solution.swapPairs(n1);
    ListNode *p = result;
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
