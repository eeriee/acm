/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        maxLen = 0;
        if(root != NULL){
            ++maxLen;
            findConsecutivePath(root, 1);
        }
        return maxLen;
    }
    void findConsecutivePath(TreeNode* node, int len){
        int pVal = node->val;
        if(node->left != NULL){
            int lVal = node->left->val;
            if(lVal == pVal+1){
                maxLen = max(1+len, maxLen);
                findConsecutivePath(node->left, 1+len);
            }else{
                findConsecutivePath(node->left, 1);
            }
        }
        if(node->right != NULL){
            int rVal = node->right->val;
            if(rVal == pVal+1){
                maxLen = max(1+len, maxLen);
                findConsecutivePath(node->right, 1+len);
            }else{
                findConsecutivePath(node->right, 1);
            }
        }
    }
    int maxLen;
};
