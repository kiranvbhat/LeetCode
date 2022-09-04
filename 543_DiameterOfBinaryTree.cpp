// https://leetcode.com/problems/diameter-of-binary-tree/

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
    // returns height of tree and updates diameter when needed
    int findDiameter(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        
        if (leftHeight + rightHeight > diameter) {
            diameter = leftHeight + rightHeight;
        }
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDiameter(root, diameter);
        return diameter;
    }
};
