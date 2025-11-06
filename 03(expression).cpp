/*Write a menu-driven program to construct the expression tree from the given prefix expression. 
Example: +-a*bc/def and perform the following operations. 
1.Traverse it using the inorder, preorder, and postorder, traversal, (recursive, and non-recursive ) 
2. change a tree so that rows of the left and right pointers are swapped at every node.*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

// Create new node
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Check if operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Construct Expression Tree from Prefix
Node* constructTree(string prefix){
    stack<Node*> st;
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--){
        char ch = prefix[i];
        Node* newNode = createNode(ch);
        if (isOperator(ch)){
            // Pop two operands
            Node* left = st.top(); st.pop();
            Node* right = st.top(); st.pop();
            newNode->left = left;
            newNode->right = right;
        }
        st.push(newNode);
    }
    return st.top();
}
 
// Recursive traversals
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Non-Recursive Traversals
void inorderNonRec(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderNonRec(Node* root) {
    if (root == NULL) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* node = st.top(); st.pop();
        cout << node->data << " ";
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
}

void postorderNonRec(Node* root) {
    if (root == NULL) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top(); s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Swap left and right children at every node
void swapTree(Node* root) {
    if (root == NULL)
        return;
    swap(root->left, root->right);
    swapTree(root->left);
    swapTree(root->right);
}

// Main menu
int main() {
    Node* root = NULL;
    string prefix;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Construct Expression Tree (from Prefix)\n";
        cout << "2. Inorder Traversal (Recursive & Non-Recursive)\n";
        cout << "3. Preorder Traversal (Recursive & Non-Recursive)\n";
        cout << "4. Postorder Traversal (Recursive & Non-Recursive)\n";
        cout << "5. Swap Left and Right Children\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Prefix Expression (e.g. +AB): ";
                cin >> prefix;
                root = constructTree(prefix);
                cout << "Expression Tree constructed successfully.\n";
                break;

            case 2:
                cout << "Recursive Inorder: ";
                inorder(root);
                cout << "\nNon-Recursive Inorder: ";
                inorderNonRec(root);
                cout << endl;
                break;

            case 3:
                cout << "Recursive Preorder: ";
                preorder(root);
                cout << "\nNon-Recursive Preorder: ";
                preorderNonRec(root);
                cout << endl;
                break;

            case 4:
                cout << "Recursive Postorder: ";
                postorder(root);
                cout << "\nNon-Recursive Postorder: ";
                postorderNonRec(root);
                cout << endl;
                break;

            case 5:
                swapTree(root);
                cout << "Tree swapped successfully.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
