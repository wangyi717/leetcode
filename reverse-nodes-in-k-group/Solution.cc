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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 0) return head;
        if (head == NULL) return NULL;
        ListNode* p = head;
        ListNode* h = new ListNode(0);
        ListNode* pre = h;
        h->next = p;
        while (p) {
            ListNode* q = p;
            for (int i = 0; i < k; ++i) {
                if (q == NULL)
                    return h->next;
                q = q->next;
            }
            pre->next = q;
            ListNode* nextPre = p;
            while (p != q) {
                ListNode* t = p->next;
                p->next = pre->next;
                pre->next = p;
                p = t;
            }
            pre = nextPre;
            p = q;
        }
        return h->next;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Solution solution;
    ListNode* head = solution.reverseKGroup(n1, 0);
    ListNode* p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
