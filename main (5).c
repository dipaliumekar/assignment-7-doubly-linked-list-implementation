/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct abc
{
    char name[20];
    int PRN;
    struct abc*prv;
    struct abc*next;
};
void insertS(struct abc*);
void insertM(struct abc*);
struct abc* deleteP(struct abc*);
void deleteS(struct abc*);
void deleteM(struct abc*);
void count(struct abc*);
void reverse(struct abc*);
void display(struct abc*);



void main()
{
    int ch,y;
    struct abc *head,*temp;       //first node
    head=(struct abc*)malloc(sizeof(struct abc));
    printf("enter the name and PRN of president:\n");
    scanf(" %s",head->name);
    scanf("%d",&head->PRN);
    head->next=NULL;
    head->prv=NULL;
    insertS(head);
    temp=head;
      do{
        printf("============*MENU*============\n");
        printf("enter choice :\n1.insert member \n2.delete president \n3.delete secretary \n4.delete member \n5.count member \n6.reverse \n7.display \n8.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        
        case 1:
        insertM(head);
        break;
       
        case 2:
        head=deleteP(head);
        break;
       
        case 3:
        deleteS(head);
        break;
       
        case 4:
        deleteM(head);
        break;
         
        case 5:
        count(head);
        break;
       
        case 6:
        reverse(temp);
        break;
       
        case 7:
        display(head);
        break;
       
        case 8:
        exit;
       
       
        default :
        printf("wrong choice !!");
       
        }
        printf("\ndo want to continue ?(0/1)");
        scanf("%d",&y);
    }
    while(y==1);
}
void insertS(struct abc*head)  //insert secretary
{
    struct abc*new;  //last node
    new=(struct abc*)malloc(sizeof(struct abc));
    printf("enter the name and PRN of secretary:\n");
    scanf(" %s",new->name);
    scanf("%d",&new->PRN);
    new->next=NULL;
    new->prv=NULL;
    head->next=new;
    new->prv=head;
   
}
void insertM(struct abc*head)  //insert member
{
    struct abc*new,*temp;
    new=(struct abc*)malloc(sizeof(struct abc));
    printf("enter the name and PRN of member:\n");
    scanf(" %s",new->name);
    scanf("%d",&new->PRN);
    new->next=NULL;
    new->prv=NULL;
    temp=head;
    temp=head->next;
    head->next=new;
    new->prv=head;
    new->next=temp;
    temp->prv=new;
}

struct abc* deleteP(struct abc*head)  // delete president
{
 struct abc*temp;
 temp=head;
 head=head->next;
 head->prv=NULL;
 free(temp);
 
return head;

}
void deleteS(struct abc*head)  //delete secretary
{
    struct abc*temp,*prv;
   
    while(temp->next!=NULL)
    {
         temp->prv=temp;
        temp=temp->next;
    }
    temp->prv->next=NULL;
    free(temp);
}

void deleteM(struct abc*head)
{
    struct abc *temp;
    temp=head->next;
    head->next=temp->next;
    temp->next->prv=head;
    free(temp);
    temp=NULL;
    
}

void count(struct abc*head)
{
    int count=0;
    struct abc*temp;
    temp=head;
    while(temp!=NULL);
    {
        count++;
        temp=temp->next;
        
    }
    printf("the count is %d=",count);
    
}


void reverse(struct abc*temp)
{
    if(temp !=NULL)
    {
        printf("\n %s %d",temp->name,temp->PRN);
        temp=temp->prv;
        reverse(temp);
        
    }
}

void display(struct abc*head)  //display
{
    struct abc*temp=head;
    while(temp!=NULL)
    {
        printf("\nname :%s\t PRN:%d",temp->name,temp->PRN);
        temp=temp->next;
        }
}