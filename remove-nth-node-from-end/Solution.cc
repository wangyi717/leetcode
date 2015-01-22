/**
 * 去掉链表中导数第n个节点
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
    ListNode *removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode* p = head;
        ListNode* q = p;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
		if (q == NULL) return head->next;
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }
};

int main() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    Solution solution;
    solution.removeNthFromEnd(p1, 2);
    ListNode *p = p1;
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
    return 0;
}
