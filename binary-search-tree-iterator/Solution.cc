/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* p = root;
        while (p != NULL) {
            st.push(p);
            p = p->left;
        }
    }

    bool hasNext() {
        if (st.empty()) return false;
        else return true;
    }

    int next() {
        TreeNode* next = st.top();
        st.pop();
		if (next->right != NULL) {
		    TreeNode* p = next->right;
		    while (p) {
		        st.push(p);
		        p = p->left;
		    }
		}
        return next->val;
    }
};

int main() {
    TreeNode* n1 = new TreeNode(10);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(12);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(6);
    TreeNode* n6 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(8);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->left = n6;
    n5->right = n7;
    BSTIterator iter(n1);
    while (iter.hasNext()) {
        cout << iter.next() << "  ";
    }
	cout << endl;
    return 0;
}
