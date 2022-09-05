// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraphHelper(Node* node, unordered_map<Node*, Node*>& visited) {
        Node* nodeCopy = new Node(node->val);
        visited[node] = nodeCopy;
        for (Node* neighbor : node->neighbors) {
            if (visited.count(neighbor) == 0) {
                nodeCopy->neighbors.push_back(cloneGraphHelper(neighbor, visited));
            } else {
                nodeCopy->neighbors.push_back(visited[neighbor]);
            }
        }
        return nodeCopy;
    }
    
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> visited;
        return cloneGraphHelper(node, visited);
    }
};
