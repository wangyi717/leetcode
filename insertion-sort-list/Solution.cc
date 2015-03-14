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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* tail = head;
        ListNode* p = head->next;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        while (p) {
            ListNode* q = newHead->next;
            ListNode* pre = newHead;
            if (p->val >= tail->val) {
                tail = p;
                p = tail->next;
                continue;
            }
            while (q != tail && p->val > q->val) {
                pre = q;
                q = q->next;
            }
            tail->next = p->next;
            p->next = q;
            pre->next = p;
            p = tail->next;
        }
        return newHead->next;
    }
};

int main() {
    Solution solution;
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(6);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    
    ListNode* head = solution.insertionSortList(n1);
    ListNode* p = head;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
