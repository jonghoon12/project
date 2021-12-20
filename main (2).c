#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y,t) (t)=(x),(x)=(y),(y)=(t)
typedef struct node{
	int time;
    char data[1000];
    struct node *next;
}NODE;
typedef struct{
    NODE *head;
}NODE_h;
NODE_h *createNode();
void insert(NODE_h *L,int t,char *d);
void search(NODE_h *L,int t);
void sort(NODE_h *L);
void printList(NODE_h *L);
void delete(NODE_h *L,int t);
int main(){
    NODE_h *L;
    L=createNode();
    int n=1,t;
    char data[1000];
    while (n){
        scanf("%d",&n);
        switch (n){
        case 1:
            scanf("%d",&t);
            scanf("%s",&data);
            //fgets(data,1000,stdin);
            insert(L,t,data);
            sort(L);
            break;
        case 2:
            scanf("%d",&t);
            search(L,t);
            break;
        case 3:
            printList(L);
            break;
        case 4:
            scanf("%d",&t);
            delete(L,t);
            break;
        //case 5:
        //    sort(L);
        //    break;
        default:
            break;
        }
    }
    
}
NODE_h *createNode(){
    NODE_h *L;
    L = (NODE_h *)malloc(sizeof(NODE_h));
    L->head=NULL;
    return L;
}
void insert(NODE_h *L,int t,char *d){
    NODE* newNode;
    NODE* temp;
    newNode = (NODE *)malloc(sizeof(NODE));
    strcpy(newNode->data,d);
    newNode->time=t;
    newNode->next=NULL;
    if(L->head==NULL){
        L->head=newNode;
        return;
    }
    temp=L->head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void search(NODE_h *L,int t){
    NODE *temp;
	temp=L->head;
	while(temp!=NULL){
		if(temp->time==t){
            printf("%s\n",temp->data);
			return ;
		}
		else temp=temp->next;
	}
    printf("NOT FIND\n");
}
void sort(NODE_h *L){
    /*여기다 정렬 코드 짜면됨*/
}
void printList(NODE_h *L){
	NODE *p;
	p=L->head;
	while(p != NULL){
		printf("%d : %s\n",p->time,p->data);
		p=p->next;
	}
}
void delete(NODE_h *L,int t){
    NODE *temp;
    NODE *front;
    front = L->head;
	temp=L->head;
	while(temp!=NULL){
		if(temp->time==t){
            if(temp==L->head){
                L->head=temp->next;
                return;
            }
            front->next=temp->next;
			return ;
		}
		else {
            front=temp;
            temp=temp->next;
            }
	}
}
