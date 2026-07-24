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
    int DFS(TreeNode* node, int max){
        if (node == nullptr) return 0;
        
        if (node->val >= max){ // check if it's a good node
            sum+=1;
            max = node->val;
        }

        DFS(node->left, max);
        
        DFS(node->right, max);
        
        return sum;
    }

    int goodNodes(TreeNode* root) {
        // root is always considered 'good'?
        // "Use DFS to traverse the tree, and constantly keep track of the current path maximum"
        // go left until nothing is left, go right, else go up
        
        return DFS(root, -1000000);
    }

    // global var    
    int sum = 0;
};