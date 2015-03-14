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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        ListNode* p = head;
        ListNode* q;
        ListNode* bTail = before;
        ListNode* aTail = after;
        while (p) {
            q = p->next;
            if (p->val < x) {
                bTail->next = p;
                bTail = bTail->next;
                bTail->next = NULL;
            } else {
                aTail->next = p;
                aTail = aTail->next;
                aTail->next = NULL;
            }
            p = q;
        }
        bTail->next = after->next;
        return before->next;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(2);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(2);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    Solution solution;
    ListNode* p = solution.partition(n1, 3);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
