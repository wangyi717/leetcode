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
        ListNode* p = head;
        ListNode* newHead = new ListNode(0);
        newHead->next = p;
        ListNode* pre = newHead;
        bool isDuplicate = false;
        while (p && p->next) {
            while (p->next && p->next->val == p->val) {
                isDuplicate = true;
                p->next = p->next->next;
            }
            if (isDuplicate) {
                pre->next = p->next;
				isDuplicate = false;
            } else {
                pre = p;
            }
            p = p->next;
        }
        return newHead->next;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Solution solution;
    ListNode* p = solution.deleteDuplicates(n1);
    while (p) {
        cout << p->val << "  ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
