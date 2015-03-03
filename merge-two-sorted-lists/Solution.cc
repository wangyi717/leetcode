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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* p = new ListNode(0);
        ListNode* h = p;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else  {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return h->next;
    }
};

int main() {
    ListNode* l1_1 = new ListNode(1);
    ListNode* l1_2 = new ListNode(5);
    ListNode* l1_3 = new ListNode(8);
    ListNode* l1_4 = new ListNode(9);
    ListNode* l2_1 = new ListNode(2);
    ListNode* l2_2 = new ListNode(3);
    ListNode* l2_3 = new ListNode(4);
    ListNode* l2_4 = new ListNode(6);
    ListNode* l2_5 = new ListNode(9);
    l1_1->next = l1_2;
    l1_2->next = l1_3;
    l1_3->next = l1_4;
    l2_1->next = l2_2;
    l2_2->next = l2_3;
    l2_3->next = l2_4;
    l2_4->next = l2_5;
    Solution solution;
    ListNode *p = solution.mergeTwoLists(l1_1, l2_1);
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    return 0;
}
