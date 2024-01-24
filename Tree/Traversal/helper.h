#define MAXSIZE 101

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isEmpty(int* top);
void push(struct TreeNode** stack,struct TreeNode* node,int* top);
struct TreeNode* pop(struct TreeNode** stack, int* top);
struct TreeNode* revertList(struct TreeNode* node);