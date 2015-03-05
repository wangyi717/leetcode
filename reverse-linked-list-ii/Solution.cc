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
    ListNode *reserveBetween(ListNode *head, int m, int n) {
        if (head == NULL || m == n) return head;
        ListNode* p = head;
        ListNode* pre = NULL;
        ListNode* next = p->next;
        ListNode* rBegin = NULL;
        ListNode* rPre = NULL;
        for (int i = 0; i < m; ++i) {
            if (i == m - 1) {
                rBegin = p;
                rPre = pre;
            }
            pre = p;
            p = next;
            next = p->next;
        }
        for (int i = m; i < n; ++i) {
            p->next = pre;
            pre = p;
            p = next;
            if (p) next = p->next;
        } 
        rBegin->next = p;
        if (rPre) {
            rPre->next = pre;
            return head;
        } else {
            return pre;
        }
    }
};

int main() {
    Solution solution;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode* head = solution.reserveBetween(n1, 2, 5);
    ListNode* p = head;
    while (p) {
        cout << p->val << "  ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
