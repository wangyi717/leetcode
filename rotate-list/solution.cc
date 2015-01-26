/**
 * 链表向右翻转k个元素
 * solution.cc
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
    ListNode *rotateList(ListNode *head, int k) {
        ListNode *p = head, *q, *r, *h2, *h3;
        int len = 0;
        while (p != NULL) {
            ++len;
            p = p->next;
        }
        if (len == 1 || len == 0 || k == 0 || k == len) {
            return head;
        }
        k = k % len;
        p = head;
        q = new ListNode(p->val);
        r = q;
        h2 = q;
        p = p->next;
        for (int i = 1; i < len - k; ++i) {
            q = new ListNode(p->val);
            r->next = q;
            r = q;
            p = p->next;
        }
        q = new ListNode(p->val);
        r = q;
        h3 = q;
        p = p->next;
        while (p != NULL) {
            q = new ListNode(p->val);
            r->next = q;
            r = q;
            p = p->next;
        }
        r->next = h2;
        return h3;
    }
};

int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    Solution solution;
    ListNode* p = solution.rotateList(p4, 2);
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
    return 0;
}
