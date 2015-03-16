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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = 0, lenB = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA) {
            ++lenA;
            pA = pA->next;
        }
        while (pB) {
            ++lenB;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            int sub = lenA - lenB;
            while (sub--) {
                pA = pA->next;
            }
        }
        if (lenA < lenB) {
            int sub = lenB - lenA;
            while (sub--) {
                pB = pB->next;
            }
        }
        while (pA && pB) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};
