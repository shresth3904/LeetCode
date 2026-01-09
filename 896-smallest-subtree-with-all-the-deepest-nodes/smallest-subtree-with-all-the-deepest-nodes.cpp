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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<int, pair<TreeNode*, int>> hash;
        stack<TreeNode*> st;
        st.push(root);
        set<TreeNode*> deep_node;
        int max_depth = 0;
        hash[root->val] = {nullptr, 0};
        while (!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            int curr_depth = hash[curr->val].second;
            if (curr_depth > max_depth){
                deep_node.clear();
                deep_node.insert(curr);
                max_depth = curr_depth;
            }
            else if (curr_depth == max_depth) deep_node.insert(curr);


            if (curr->left) {
                st.push(curr->left);
                hash[curr->left->val] = {curr, curr_depth + 1};
            }
            if (curr->right) {
                st.push(curr->right);
                hash[curr->right->val] = {curr, curr_depth + 1};
            }
        }

        while (deep_node.size() > 1){
            set<TreeNode*> parents;
            for (TreeNode* node: deep_node){
                parents.insert(hash[node->val].first);
            }

            deep_node = parents;
        }

        return *deep_node.begin();


    }
};