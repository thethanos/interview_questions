#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

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

Node* cloneGraph(Node* root)
{
    unordered_map<int, Node*> map;

    return cloneGraph(root, map);
}

Node* cloneGraph(Node* node, unordered_map<int, Node*>& map)
{
    if (!node) return nullptr;
    if (map[node->val]) return map[node->val];

    map[node->val] = new Node(node->val);
    for (auto& item : node->neighbors)
        map[node->val]->neighbors.push_back(cloneGraph(item, map));

    return map[node->val];
}