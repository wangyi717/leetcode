/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    unordered_map<int, UndirectedGraphNode*> map;
    UndirectedGraphNode* dfs(UndirectedGraphNode* node) {
        UndirectedGraphNode* cnode;
        auto it = map.find(node->label);
        if (it != map.end()) {
            cnode = it->second;
            return cnode;
        }
        cnode = new UndirectedGraphNode(node->label);
        vector<UndirectedGraphNode*> cneighbors;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (node->label == node->neighbors[i]->label) {
                cneighbors.push_back(cnode);
            } else {
                cneighbors.push_back(dfs(node->neighbors[i]));
            }
        }
        cnode->neighbors = cneighbors;
        map[node->label] = cnode;
        return cnode;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        return dfs(node);
    }
};

void traverse(UndirectedGraphNode* node) {
    cout << node->label << endl;
    for (int i = 0; i < node->neighbors.size(); ++i) {
        traverse(node->neighbors[i]);
    }
}

int main() {
    Solution solution;
    UndirectedGraphNode* node = new UndirectedGraphNode(0);
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
    vector<UndirectedGraphNode*> vec;
    vec.push_back(node1);
    vec.push_back(node2);
    node->neighbors = vec;
    traverse(node);
    return 0;
}
