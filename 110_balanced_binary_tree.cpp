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


const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new(size_t size) {
	constexpr std::size_t alignment = alignof(std::max_align_t);
	size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
	size_t total_size = size + padding;
	char* aligned_ptr = &buffer[buffer_pos + padding];
	buffer_pos += total_size;
	return aligned_ptr;
}

void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}


struct nodeData {
    bool balanced = true;
    int height = 0;

    nodeData() : balanced(true), height(0) {}
    nodeData(bool balance, int h) : balanced(balance), height(h) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)->balanced;
    }

    nodeData* dfs (TreeNode* root) {
        if (!root /* || !root->val */) return new nodeData();

        nodeData* left = dfs(root->left);
        nodeData* right = dfs(root->right);

        bool isBalanced = left->balanced && right->balanced && 
            // root->left && root->right &&
            std::abs(left->height - right->height) <= 1;

        return new nodeData(isBalanced, 1 + std::max(left->height, right->height));
    }
};

