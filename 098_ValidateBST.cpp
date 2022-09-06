// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Performs in-order traversal; if any numbers are out of order then BST is invalid
    bool isValidHelper(TreeNode* root, TreeNode*& prev) {
        if (root == nullptr) return true;
        if (!isValidHelper(root->left, prev)) return false;
        if (prev != nullptr && prev->val >= root->val) return false;
        prev = root;
        return isValidHelper(root->right, prev);
    }
    
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidHelper(root, prev);
    }
};
