#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

// Create new node
Node* createNode(char val) {
    Node* n = new Node;
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Check if operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Construct Expression Tree from Postfix
Node* constructTree(string postfix) {
    stack<Node*> st;
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        Node* node = createNode(ch);

        if (isOperator(ch)) {
            // Pop two operands
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            node->left = left;
            node->right = right;
        }
        st.push(node);
    }
    return st.top();
}

// Recursive traversals
void inorder(Node* root) {
    if (root) {
        if (isOperator(root->data)) cout << "(";
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
        if (isOperator(root->data)) cout << ")";
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

// Non-recursive traversals
void inorderNonRec(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        cout << curr->data;
        curr = curr->right;
    }
}

void preorderNonRec(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* node = st.top(); st.pop();
        cout << node->data;
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
}

void postorderNonRec(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top(); s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data;
        s2.pop();
    }
}

// Evaluate numeric postfix expression tree
double evaluate(Node* root) {
    if (!root) return 0;
    if (!isOperator(root->data))
        return root->data - '0'; // convert char to int

    double leftVal = evaluate(root->left);
    double rightVal = evaluate(root->right);

    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        case '^': return pow(leftVal, rightVal);
    }
    return 0;
}

// Convert to Prefix (Preorder)
void toPrefix(Node* root) {
    preorder(root);
}

// Convert to Infix
void toInfix(Node* root) {
    inorder(root);
}

// Height of tree
int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

// Menu
int main() {
    string postfix;
    Node* root = NULL;
    int choice;

    cout << "Enter Postfix Expression (e.g., AB+C*D-): ";
    cin >> postfix;
    root = constructTree(postfix);

    do {
        cout << "\n===== EXPRESSION TREE MENU =====\n";
        cout << "1. Recursive Traversals\n";
        cout << "2. Non-Recursive Traversals\n";
        cout << "3. Evaluate Expression (if numeric)\n";
        cout << "4. Convert to Prefix and Infix\n";
        cout << "5. Display Height of Tree\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder: "; inorder(root); cout << endl;
                cout << "Preorder: "; preorder(root); cout << endl;
                cout << "Postorder: "; postorder(root); cout << endl;
                break;

            case 2:
                cout << "Inorder (Non-Recursive): "; inorderNonRec(root); cout << endl;
                cout << "Preorder (Non-Recursive): "; preorderNonRec(root); cout << endl;
                cout << "Postorder (Non-Recursive): "; postorderNonRec(root); cout << endl;
                break;

            case 3:
                cout << "Evaluated Result = " << evaluate(root) << endl;
                break;

            case 4:
                cout << "Prefix: "; toPrefix(root); cout << endl;
                cout << "Infix: "; toInfix(root); cout << endl;
                break;

            case 5:
                cout << "Height of Tree = " << height(root) << endl;
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}