#include <iostream>
using namespace std;

typedef struct node{
    string key;
    struct node* parent;
    struct node* left;
    struct node* right;
}Node;

Node* createRoot(string key){
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

Node* createNode(string key, Node* parent, string p){
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

void addRelation(Node* node, string k1, string k2, string p){
    if(node == NULL) return;

    if(node->key == k1) createNode(k2, node, p);

    addRelation(node->left, k1, k2, p);
    addRelation(node->right, k1, k2, p);
}

void travel(Node* node, int* c){
    if(node == NULL) return;

    if(node->left == NULL && node->right == NULL) *c = *c+1;

    travel(node->left, c);
    travel(node->right, c);
}

void countLeaf(Node* node){
    int countL = 0;
    int countR = 0;
    travel(node->left, &countL);
    travel(node->right, &countR);
    cout << countL << " " << countR << endl;
}

int main(){
    
    int i, n;
    string n1, n2, p;
    cin >> n1 >> n;
    Node* root = createRoot(n1);
    for(i=0; i<n; i++){
        cin >> n1 >> n2 >> p;
        addRelation(root, n1, n2, p);
    }
    countLeaf(root);
}



