#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node {
    int data;
    struct node *next;
}node;
void create(node **);
void display(node *);
void formloop(node *,int);
int detech(node *);
void main(){
    int ans,pos;
    node *head = (node *)NULL;
    create(&head);
    display(head);
    printf("\n");
    printf("enter position from which you want to form loop");
    scanf("%d",&pos);
    formloop(head,pos);
    ans = detech(head);
    printf("%d",ans);
}
void create(node **h){
    node *temp,*newnode;
    int ele;
    printf("enter number");
    while (1)
    {
        scanf("%d",&ele);
        if(ele==-1)
          break;
        else{
            newnode = (node *)malloc(sizeof(node));
            newnode->next = NULL;
            newnode->data = ele;
            if(*h == NULL){
                temp= *h= newnode;
            }
            else{
                temp->next = newnode;
                temp = newnode;
            }
        }  
    }
}  
void display(node *h){
    if(h==NULL){
        printf("list is empty");
    }
    else{
        while (h!=NULL)
        {
            printf("%d",h->data);
            h = h->next;
        }
        
    }
} 
void formloop(node *h,int pos){
    int count=1;
    node *temp,*ptemp;
    ptemp = h;
    temp = h;
    while(temp->next!=NULL){
        count++;
        temp = temp->next;
    }
    if(pos<1||pos>count-1){
        printf("invalid position");
    }
    else{
       for(int i =1;i<pos;i++){
        ptemp = ptemp->next;
    }
    temp ->next = ptemp;
    }
}
int detech(node *h){
    node *fast,*slow;
    fast = h;
    slow = h;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}