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
    printf("1312 ������, 1310 ���ؿ��� ���� �ڷᱸ�� �˰��� ������Ʈ ����ǥ �Դϴ�.\n������ �߰��Ͻ÷��� 1�� ����ǥ Ž���� �Ͻ÷��� 2, ��ü����� 3, ���������� 4, ������ 5�� �Է��� �ֽñ� �ٶ��ϴ�.\n");
    while (n){
    	printf("�Է� : ");
        scanf("%d",&n);
        switch (n){
        case 1:
        	printf("�ð� �Է� : ");
            scanf("%d",&t);
            printf("���� �Է� : ");
            scanf("%s",&data);
            //fgets(data,1000,stdin);
            insert(L,t,data);
            //sort(L);
            break;
        case 2:
        	printf("Ž���� �ð� �Է� : ");
            scanf("%d",&t);
            search(L,t);
            break;
        case 3:
            printList(L);
            break;
        case 4:
        	printf("������ ������ �ð� : ");
            scanf("%d",&t);
            delete(L,t);
            break;
        case 5:
            sort(L);
            break;
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
    NODE *temp;
    NODE *key;
    NODE_h *T;
    T=createNode();
    temp=L->head;
    key=L->head;
    while (L->head!=NULL){
        if((key->time)>(temp->time)){
            key=temp;
        }
        if(temp->next==NULL){
            insert(T,key->time,key->data);
            delete(L,key->time);
            temp=L->head;
            key=temp;
        }
        
        temp=temp->next;
    }
    L=T;
    return;
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
