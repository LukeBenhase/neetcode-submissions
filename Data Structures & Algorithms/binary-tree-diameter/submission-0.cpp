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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxval = 0;
        dfs(root, maxval);

        return maxval;
    }
    int dfs(TreeNode* node, int& val){

        int left = 0;
        int right = 0;
        if (node->left){
            left = dfs(node->left, val);
        }
        if (node->right) {
            right = dfs(node->right, val);
        }
        val = max(right + left, val);
        return max(left, right) +1;
    }

    int max(int l, int r){
        if (l > r) return l;
        return r;
    }
};

    
