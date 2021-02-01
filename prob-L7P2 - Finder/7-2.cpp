#include <iostream>
using namespace std;

typedef struct node{
    string key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
}Node;

Node* createRoot(string key){
    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = NULL;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

Node* createNode(string key, Node* parent){
    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = parent;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    if(node->parent != NULL) {
        if(node->parent->leftChild != NULL) {
            Node* child = node->parent->leftChild;
            while(child->rightSibling != NULL){
                child = child->rightSibling;
            }
            child->rightSibling = node;
        }
        else {
            node->parent->leftChild = node;
        }
    }
    return node;
}

void postorder(Node* node){
    if(node == NULL) return;

    postorder(node->leftChild);
    cout << node->key << " ";
    postorder(node->rightSibling);
}

void preorder(Node* node, string k, string p){
    if(node == NULL) return;

    if(node->key == k) cout << p+node->key;
    preorder(node->leftChild, k, p+node->key+"/");
    preorder(node->rightSibling, k, p);
}

void addRelation(Node* node, string k1, string k2){
    if(node == NULL) return;

    if(node->key == k1) createNode(k2, node);

    addRelation(node->leftChild, k1, k2);
    addRelation(node->rightSibling, k1, k2);
}

int main(){
    
    int i, n;
    string k1, k2;
    cin >> n >> k1;
    Node* root = createRoot(k1);
    for(i=0; i<n; i++){
        cin >> k1 >> k2;
        addRelation(root, k1, k2);
    }
    cin >> k1;
    preorder(root, k1, "");
}