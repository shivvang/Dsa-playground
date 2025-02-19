#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    vector<vector<int>> ans;

    if(root == nullptr) return ans;  // ✅ Edge case check

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<vector<int>> traversal = levelOrderTraversal(root);
    
    for(int i = 0; i < traversal.size(); i++) {
        for(int j = 0; j < traversal[i].size(); j++) { // ✅ Fixed: 'j++' instead of 'i++'
            cout << traversal[i][j] << " ";
        }
        cout << endl; // ✅ Added for better output formatting
    }
    
    return 0;
}

/* 
✅ **Time Complexity:**
   - Every node is processed **once**, taking `O(1)` per node.
   - The queue operations (push/pop) are `O(1)`, and each node is pushed/popped once.
   - The outer while loop runs **O(N)** times (once per node).
   - The inner for loop runs **O(N)** in total across all levels.
   - **Overall: O(N)**

✅ **Space Complexity:**
   - **Best case (balanced tree):** The queue stores at most **one level**, which is `O(log N)`.
   - **Worst case (skewed tree):** The queue stores **O(N)** nodes at once.
   - The answer `ans` stores all `N` nodes, so it takes `O(N)`.
   - **Overall: O(N)**
*/
