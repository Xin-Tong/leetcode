//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

/**
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
    bool hasPathSum(TreeNode *root, int sum) {
        vector<int> solution;
        vector<vector<int>> collection;
        if(root != NULL){
            path(root, sum, 0, solution, collection);
        }
        if(collection.empty()){
            return false;
        }
        else return true;
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
        //solution.pop_back();
        //cal -= node-> val;  no need to back-tracking
        return;
    }
};

//and this is the no back-tracking version
/**
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
    bool hasPathSum(TreeNode *root, int sum) {
        vector<int> solution;
        if(root != NULL){
            return path(root, sum, 0, solution);
        }
        else return false;
    }
    bool path(TreeNode *node, int sum, int cal, vector<int>& solution){  //reference here
        solution.push_back(node->val);
        bool right = false;
        bool left = false;
        cal += node->val;
        if(cal == sum && node->left == NULL && node->right == NULL){
            return true;
        }
        else{
            if(node->left != NULL){
                left = path(node->left, sum, cal, solution);
            } 
            if(node->right != NULL){
                right = path(node->right, sum, cal, solution);
            }
        }
        //solution.pop_back();
        //cal -= node-> val;
        return (left || right);
    }
};
