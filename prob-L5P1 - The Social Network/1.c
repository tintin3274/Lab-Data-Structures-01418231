#include <stdio.h>
#include <stdlib.h>


typedef struct Friend_{
    char name;
    struct Friend_ *next;
}Friend;

typedef struct Node_{
    char name;
    struct Friend_ *friend;
    struct Node_ *next;
}Node;


Node* addNode(char name){
    Node* new = malloc(sizeof(Node*));
    new->name = name;
    new->friend = NULL;
    new->next = NULL;
    return new;
}

void addFriend(Friend **list, char name){
    if(*list == NULL){
        Friend *new = malloc(sizeof(Friend*));
        new->name = name;
        new->next = NULL;
        *list = new;
    }
    else{
        while(1){
            if(*list->name == name){break;}
            else if(*list->next == NULL){
                Friend *new = malloc(sizeof(Friend*));
                new->name = name;
                new->next = NULL;
                *list->next = new;
                break;
            }
            *list = *list->next;
        }
    }
}

int main(){
    char n1, n2;
    int i, n;
    Node *head = malloc(sizeof(Node*));
    Node *p1, *p2;
    scanf("%d", &n);
    for(i=0; i<n ;i++){
        scanf("%c %c", &n1, &n2);
        p1 = addNode(n1);
        p2 = addNode(n2);
        if(i==1){
            head->next = p1;
            p1->next = p2;
            addFriend(&p1->friend, n2);
            addFriend(&p2->friend, n1);
        }
        else{
            Node *current = head->next;
            Friend *list = NULL;

            while(1){
                if(current->name == n1){
                    list = current->friend;
                    addFriend(list, n2);
                    break;
                }
                else if(current->next == NULL){
                    current->next = addNode(n1);
                    current = current->next;
                    list = current->friend;
                    addFriend(list, n2);
                    break;
                }
                else{
                    current = current->next;
                }
            }

            current = head->next;
            while(1){
                if(current->name == n2){
                    list = current->friend;
                    addFriend(list, n1);
                    break;
                }
                else if(current->next == NULL){
                    current->next = addNode(n2);
                    current = current->next;
                    list = current->friend;
                    addFriend(list, n1);
                    break;
                }
                else{
                    current = current->next;
                }
            }
        }
    }
}