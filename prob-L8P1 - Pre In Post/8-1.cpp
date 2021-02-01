#include <iostream>
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

Node* createNode(int key, Node* parent, string p){
    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = parent;
    // Initialize left child, and right child as NULL
    node->left = NULL;
    node->right = NULL;
    if(node->parent != NULL) {
        if(p == "L") {
            parent->left = node;
        }
        else if(p == "R"){
            parent->right = node;
        }
    }
    return node;
}

void postorder(Node* node){
    if(node == NULL) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->key << " ";
}

void preorder(Node* node){
    if(node == NULL) return;

    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){
    if(node == NULL) return;

    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void addRelation(Node* node, int k1, int k2, string p){
    if(node == NULL) return;

    if(node->key == k1) createNode(k2, node, p);

    addRelation(node->left, k1, k2, p);
    addRelation(node->right, k1, k2, p);
}

int main(){
    
    int i, n, n1, n2;
    string p;
    cin >> n >> n1;
    Node* root = createRoot(n1);
    for(i=0; i<n; i++){
        cin >> n1 >> n2 >> p;
        addRelation(root, n1, n2, p);
    }
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}