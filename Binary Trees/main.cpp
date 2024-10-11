#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Insertion into a Binary Tree (Level Order Insertion)
TreeNode* insert(TreeNode* root, int x) {
    if (root == NULL) {
        return new TreeNode(x);
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        // Check the left child
        if (temp->left != NULL) {
            q.push(temp->left);
        } else {
            temp->left = new TreeNode(x);
            return root;
        }

        // Check the right child
        if (temp->right != NULL) {
            q.push(temp->right);
        } else {
            temp->right = new TreeNode(x);
            return root;
        }
    }

    return root;
}

// Searching in a Binary Tree (Level Order Search)
bool search(TreeNode* root, int x) {
    if (root == NULL) {
        return false;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp->data == x) {
            return true;
        }

        if (temp->left != NULL) {
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }

    return false;
}



// Helper function to delete the deepest node
void deleteDeepest(TreeNode* root, TreeNode* dNode) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp == dNode) {
            delete dNode;
            return;
        }

        if (temp->right) {
            if (temp->right == dNode) {
                temp->right = NULL;
                delete dNode;
                return;
            } else {
                q.push(temp->right);
            }
        }

        if (temp->left) {
            if (temp->left == dNode) {
                temp->left = NULL;
                delete dNode;
                return;
            } else {
                q.push(temp->left);
            }
        }
    }
}
// Deletion from a Binary Tree (Level Order Deletion)
TreeNode* deleteNode(TreeNode* root, int x) {
    if (root == NULL) {
        return NULL;
    }

    // If tree has only one node
    if (root->left == NULL && root->right == NULL) {
        if (root->data == x) {
            delete root;
            return NULL;
        } else {
            return root;
        }
    }

    queue<TreeNode*> q;
    q.push(root);

    TreeNode* targetNode = NULL;
    TreeNode* lastNode = NULL;

    while (!q.empty()) {
        lastNode = q.front();
        q.pop();

        if (lastNode->data == x) {
            targetNode = lastNode;
        }

        if (lastNode->left != NULL) {
            q.push(lastNode->left);
        }

        if (lastNode->right != NULL) {
            q.push(lastNode->right);
        }
    }

    if (targetNode != NULL) {
        int lastNodeData = lastNode->data;
        deleteDeepest(root, lastNode);
        targetNode->data = lastNodeData;
    }

    return root;
}
// Preorder Traversal
void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal (BFS)
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << "\n";

    int x;
    cout << "Enter number to search: ";
    cin >> x;
    if (search(root, x)) {
        cout << x << " found in the tree.\n";
    } else {
        cout << x << " not found in the tree.\n";
    }

    int y;
    cout << "Enter number to delete: ";
    cin >> y;
    root = deleteNode(root, y);

    cout << "Level Order Traversal after deletion: ";
    levelOrder(root);
    cout << "\n";

    return 0;
}
