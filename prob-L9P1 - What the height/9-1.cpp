#include <iostream>
#include <sstream>
using namespace std;

typedef struct node{
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
}Node;

Node* createRoot(int key){
    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = NULL;
    // Initialize left child, and right child as NULL
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addNode(int key, Node* root){
    Node *y = NULL;
    Node *x = root; 
    while (x != NULL)
    {
        y = x;
        if (key <= x->key) x = x->left;
        else x = x->right;
    }

    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = y;
    // Initialize left child, and right child as NULL
    node->left = NULL;
    node->right = NULL;
    if(node->parent != NULL) {
        if(key <= node->parent->key) node->parent->left = node;
        else node->parent->right = node;
    }

}

void high(int key, Node* node, int h){
    if(node == NULL) return;
    if(key == node->key){
        cout << h;
    }
    else if(key < node->key) high(key, node->left, h+1);
    else if (key > node->key) high(key, node->right, h+1);
}

int main(){
    bool haveroot = false;
    Node* root = createRoot(5);

    string line, s;
    int i, n;
    getline(cin, line);
    istringstream iss(line);

    while ( getline( iss, s, ' ' ) ) {
        n = stoi(s);
        if(!haveroot){
            root = createRoot(n);
            haveroot = true;
        } 
        else addNode(n, root);
    }
    cin >> n;
    high(n, root, 1);
}