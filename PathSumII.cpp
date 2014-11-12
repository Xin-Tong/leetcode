/**

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]


 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> solution;
        vector<vector<int>> collection;
        if(root != NULL){
            path(root, sum, 0, solution, collection);
        }
        return collection;
    }
    void path(TreeNode *node, int sum, int cal, vector<int>& solution, vector<vector<int>> &collection){  //reference here
        solution.push_back(node->val);
        cal += node->val;
        if(cal == sum && node->left == NULL && node->right == NULL){
            collection.push_back(solution);
        }
        else{
            if(node->left != NULL){
                path(node->left, sum, cal, solution, collection);
            } 
            if(node->right != NULL){
                path(node->right, sum, cal, solution, collection);
            }
        }
        solution.pop_back();
        cal -= node-> val;  
        return;
    }
};