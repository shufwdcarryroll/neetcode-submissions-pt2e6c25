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
private:
    vector<int> rightSideNode;
    
    void helper(TreeNode* root, int level) {
        if (!root) return;
        
        // If this is the first node we're visiting at this level
        if (level == rightSideNode.size()) {
            rightSideNode.push_back(root->val);
        }
        
        // Recurse right first, then left
        helper(root->right, level + 1);
        helper(root->left, level + 1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return rightSideNode;
    }
};

