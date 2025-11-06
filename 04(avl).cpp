#include <iostream>
#include <string>
using namespace std;

struct AVLnode {
    string keyword, meaning;
    AVLnode *left, *right;
    int ht; // height of node
};

class AVLtree {
public:
    AVLnode *root;

    AVLtree() { root = NULL; }

    AVLnode* insert(AVLnode* root, string newkey, string mean);
    AVLnode* rotate_left(AVLnode* x);
    AVLnode* rotate_right(AVLnode* x);
    AVLnode* LL(AVLnode* x);
    AVLnode* LR(AVLnode* x);
    AVLnode* RR(AVLnode* x);
    AVLnode* RL(AVLnode* x);
    void inorder(AVLnode* root);
    void descending(AVLnode* root);
    int height(AVLnode* root);
    int BalanceFactor(AVLnode* root);
    bool search(AVLnode* root, string key);
    AVLnode* findMin(AVLnode* root);
    AVLnode* deleteNode(AVLnode* root, string key);
};

// Compute height of a node
int AVLtree::height(AVLnode *root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

// Compute balance factor
int AVLtree::BalanceFactor(AVLnode *root) {
    return height(root->left) - height(root->right);
}

// Rotate right
AVLnode* AVLtree::rotate_right(AVLnode *x) {
    AVLnode *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Rotate left
AVLnode* AVLtree::rotate_left(AVLnode *x) {
    AVLnode *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// LL rotation
AVLnode* AVLtree::LL(AVLnode *T) {
    cout << "\nLL Rotation performed\n";
    return rotate_right(T);
}

// LR rotation
AVLnode* AVLtree::LR(AVLnode *T) {
    cout << "\nLR Rotation performed\n";
    T->left = rotate_left(T->left);
    return rotate_right(T);
}

// RR rotation
AVLnode* AVLtree::RR(AVLnode *T) {
    cout << "\nRR Rotation performed\n";
    return rotate_left(T);
}

// RL rotation
AVLnode* AVLtree::RL(AVLnode *T) {
    cout << "\nRL Rotation performed\n";
    T->right = rotate_right(T->right);
    return rotate_left(T);
}

// Insert new node
AVLnode* AVLtree::insert(AVLnode *root, string newkey, string mean) {
    if (root == NULL) {
        AVLnode *curr = new AVLnode;
        curr->keyword = newkey;
        curr->meaning = mean;
        curr->left = curr->right = NULL;
        curr->ht = 1;
        return curr;
    }

    if (newkey < root->keyword)
        root->left = insert(root->left, newkey, mean);
    else if (newkey > root->keyword)
        root->right = insert(root->right, newkey, mean);
    else {
        cout << "\nDuplicate key not allowed!";
        return root;
    }

    // Rebalance if required
    int bf = BalanceFactor(root);

    if (bf > 1 && newkey < root->left->keyword) return LL(root);
    if (bf > 1 && newkey > root->left->keyword) return LR(root);
    if (bf < -1 && newkey > root->right->keyword) return RR(root);
    if (bf < -1 && newkey < root->right->keyword) return RL(root);

    root->ht = height(root);
    return root;
}

// Inorder (Ascending)
void AVLtree::inorder(AVLnode *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        inorder(root->right);
    }
}

// Descending order display
void AVLtree::descending(AVLnode *root) {
    if (root != NULL) {
        descending(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        descending(root->left);
    }
}

// Search key
bool AVLtree::search(AVLnode *root, string key) {
    int comparisons = 0;
    while (root != NULL) {
        comparisons++;
        if (key == root->keyword) {
            cout << "\nFound! Meaning: " << root->meaning;
            cout << "\nComparisons made: " << comparisons << endl;
            return true;
        }
        if (key < root->keyword)
            root = root->left;
        else
            root = root->right;
    }
    cout << "\nKey not found. Comparisons made: " << comparisons << endl;
    return false;
}

// Find minimum node
AVLnode* AVLtree::findMin(AVLnode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
AVLnode* AVLtree::deleteNode(AVLnode* root, string key) {
    if (root == NULL)
        return root;

    if (key < root->keyword)
        root->left = deleteNode(root->left, key);
    else if (key > root->keyword)
        root->right = deleteNode(root->right, key);
    else {// KEY = ROOT -> KEYWORD
        
        // Case 1: Node has only one child or no child
        if (root->left == NULL || root->right == NULL) {

                        AVLnode* temp;

                        // If left child exists, assign it to temp
                        if (root->left != NULL)
                            temp = root->left;
                        else
                            temp = root->right;

                                // If no child at all (leaf node)
                                if (temp == NULL) {
                                    temp = root;
                                    root = NULL;
                                } else {
                                    // If one child, copy its data into current node
                                    *root = *temp;
                                }

                        // Free memory of the child or old node
                        delete temp;
        }

        // Case 2: Node has two children
        else {
                        AVLnode* temp = findMin(root->right);
                        root->keyword = temp->keyword;
                        root->meaning = temp->meaning;
                        root->right = deleteNode(root->right, temp->keyword);
        }
    }

    if (root == NULL)
        return root;

    // Rebalance after deletion
    int bf = BalanceFactor(root);
    
    if (bf > 1 && BalanceFactor(root->left) >= 0) return LL(root);
    if (bf > 1 && BalanceFactor(root->left) < 0)  return LR(root);
    if (bf < -1 && BalanceFactor(root->right) <= 0) return RR(root);
    if (bf < -1 && BalanceFactor(root->right) > 0)  return RL(root);

    root->ht = height(root);
    return root;
}

// Main Function
int main() {
    AVLtree T;
    int choice;
    string key, mean;

    do {
        cout << "\n--- AVL Tree Dictionary Menu ---\n";
        cout << "1. Insert (Key, Value)\n";
        cout << "2. Display (Ascending)\n";
        cout << "3. Display (Descending)\n";
        cout << "4. Search a Key\n";
        cout << "5. Delete a Key\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Key: ";
                cin >> key;
                cout << "Enter Meaning: ";
                cin >> mean;
                T.root = T.insert(T.root, key, mean);
                break;

            case 2:
                cout << "\nAscending Order:\n";
                T.inorder(T.root);
                break;

            case 3:
                cout << "\nDescending Order:\n";
                T.descending(T.root);
                break;

            case 4:
                cout << "Enter key to search: ";
                cin >> key;
                T.search(T.root, key);
                break;

            case 5:
                cout << "Enter key to delete: ";
                cin >> key;
                T.root = T.deleteNode(T.root, key);
                cout << "Deleted successfully (if existed).\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    cout << "\nTime Complexity for Searching: O(log n)\n";
    cout << "Maximum Comparisons = Height of Tree = O(log n)\n";
    return 0;
}
