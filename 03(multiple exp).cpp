#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

// ---------- Utility Functions ----------
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// ---------- Construct Expression Tree from Prefix ----------
Node* constructTree(string prefix) {
    stack<Node*> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        Node* newNode = createNode(ch);

        if (isOperator(ch)) {
            Node* left = st.top(); st.pop();
            Node* right = st.top(); st.pop();
            newNode->left = left;
            newNode->right = right;
        }
        st.push(newNode);
    }
    return st.top();
}

// ---------- Traversals ----------
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// ---------- Mirror the Tree ----------
void mirrorTree(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// ---------- Height of Tree ----------
int height(Node* root) {
    if (!root) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

// ---------- Count Operators ----------
int countOperators(Node* root) {
    if (!root) return 0;
    int count = isOperator(root->data) ? 1 : 0;
    return count + countOperators(root->left) + countOperators(root->right);
}

// ---------- MAIN PROGRAM ----------
int main() {
    Node* trees[10];        // array to store up to 10 trees
    string expressions[10]; // to store the expressions
    int treeCount = 0;
    int choice;

    do {
        cout << "\n===== EXPRESSION TREE MENU =====\n";
        cout << "1. Construct & Store Expression Tree\n";
        cout << "2. Display Traversals of All Trees\n";
        cout << "3. Compare Height of Trees\n";
        cout << "4. Identify Tree with Max Operators\n";
        cout << "5. Display Mirrored Version of All Trees\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (treeCount >= 10) {
                    cout << "Storage full! Cannot add more trees.\n";
                    break;
                }
                string prefix;
                cout << "Enter Prefix Expression: ";
                cin >> prefix;
                Node* root = constructTree(prefix);
                trees[treeCount] = root;
                expressions[treeCount] = prefix;
                treeCount++;
                cout << "Tree constructed and stored successfully!\n";
                break;
            }

            case 2: {
                if (treeCount == 0) {
                    cout << "No trees constructed yet!\n";
                    break;
                }
                for (int i = 0; i < treeCount; i++) {
                    cout << "\nExpression " << i+1 << ": " << expressions[i] << "\n";
                    cout << "Inorder: "; inorder(trees[i]); cout << endl;
                    cout << "Preorder: "; preorder(trees[i]); cout << endl;
                    cout << "Postorder: "; postorder(trees[i]); cout << endl;
                }
                break;
            }

            case 3: {
                if (treeCount == 0) {
                    cout << "No trees available!\n";
                    break;
                }
                cout << "\nHeights of Expression Trees:\n";
                for (int i = 0; i < treeCount; i++) {
                    cout << "Expression " << i+1 << " (" << expressions[i] 
                         << "): Height = " << height(trees[i]) << endl;
                }
                break;
            }

            case 4: {
                if (treeCount == 0) {
                    cout << "No trees available!\n";
                    break;
                }
                int maxOps = 0, index = -1;
                for (int i = 0; i < treeCount; i++) {
                    int count = countOperators(trees[i]);
                    if (count > maxOps) {
                        maxOps = count;
                        index = i;
                    }
                }
                if (index != -1) {
                    cout << "\nTree with Maximum Operators:\n";
                    cout << "Expression " << index+1 << " (" << expressions[index] 
                         << ") with " << maxOps << " operators.\n";
                }
                break;
            }

            case 5: {
                if (treeCount == 0) {
                    cout << "No trees available!\n";
                    break;
                }
                cout << "\nMirrored Trees (Inorder Traversal):\n";
                for (int i = 0; i < treeCount; i++) {
                    cout << "\nOriginal Expression " << i+1 << ": " << expressions[i] << "\n";
                    mirrorTree(trees[i]);
                    cout << "Mirrored Inorder: "; inorder(trees[i]); cout << endl;
                    mirrorTree(trees[i]); // restore original
                }
                break;
            }

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}