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
    TreeNode* invertTree(TreeNode* root) {
        // loop through the tree 
        if (root != nullptr) dfs(root);
        return root;
    }

    void dfs(TreeNode* node){
        if (node->left != nullptr) dfs(node->left);
        if (node->right != nullptr) dfs(node->right);
        TreeNode* temp = nullptr;
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
