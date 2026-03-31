class Codec {
public:

    // Encodes a tree to a single string using BFS
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "null,";
            }
        }
        // remove trailing comma
        if (!res.empty()) res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree using BFS
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            // Left child
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            // Right child
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }

        return root;
    }
};
