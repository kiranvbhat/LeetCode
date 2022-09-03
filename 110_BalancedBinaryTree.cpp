// https://leetcode.com/problems/balanced-binary-tree/

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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = height(root->left);
        int right_height = height(root->right);
        
        // if there is currently, or has been at any point, a height imbalance of >1, return -1
        if (abs(left_height - right_height) > 1 || left_height == -1 || right_height == -1) {
            return -1;
        }
        
        int max_height = max(left_height, right_height);
        return 1 + max_height;
    }
    
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        return h != -1;
    }
};
