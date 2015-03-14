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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* p = head;
        while (p) {
            while (p->next && p->val == p->next->val) {
                p->next = p->next->next;
            }
            p = p->next;
        }
        return head;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Solution solution;
    ListNode* p = solution.deleteDuplicates(n1);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
