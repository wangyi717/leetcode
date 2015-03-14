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
    ListNode *sortList(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* p = head;
        ListNode* q = head;
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = NULL;
        ListNode* l = sortList(head);
        ListNode* r = sortList(q);
        ListNode* newHead = new ListNode(0);
        p = newHead;
        while (l && r) {
            if (l->val < r->val) {
                p->next = l;
                l = l->next;
            } else {
                p->next = r;
                r = r->next;
            }
            p = p->next;
        }
        if (l) p->next = l;
        if (r) p->next = r;
        return newHead->next;
    }
};

int main() {
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(6);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(8);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    Solution solution;
    ListNode* p = solution.sortList(n1);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
