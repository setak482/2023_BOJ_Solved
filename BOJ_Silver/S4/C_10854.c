#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define new(type) (type *)malloc(sizeof(type))

typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;

struct Queue{
    int size;
    NODE *head;
    NODE *tail;
}q;

void push(int data){
    NODE *cur = new(NODE);
    cur->data = data;
    if(q.size == 0){
        q.head = cur;
        q.tail = q.head;
    }
    else{
        q.tail->next = cur;
        q.tail = q.tail->next;
    }
    q.size++;
}

int pop(){
    if(q.size == 0) return -1;
    NODE* front_obj = q.head;
    int front = q.head->data;
    if(q.head->next != NULL)
        q.head = q.head->next;
    q.size--;
    free(front_obj);
    return front;
}

int size(){ return q.size; }
int empty(){ return (q.size==0)?1:0; }
int front(){
    if(q.size == 0) return -1;
    return q.head->data;
}
int back(){
    if(q.size == 0) return -1;
    return q.tail->data;
}

int main(){
    char cmd[8];
    int tc, tmp; scanf("%d", &tc);
    for(int i=0; i<tc; i++){
        scanf("%s", cmd);
        if(strcmp(cmd, "push")==0){
            scanf("%d", &tmp);
            push(tmp);
        }
        else if(strcmp(cmd, "pop")==0) 
            printf("%d\n", pop());
        else if(strcmp(cmd, "size")==0)
            printf("%d\n", size());
        else if(strcmp(cmd, "empty")==0)
            printf("%d\n", empty());
        else if(strcmp(cmd, "front")==0)
            printf("%d\n", front());
        else if(strcmp(cmd, "back")==0)
            printf("%d\n", back());
    }
}