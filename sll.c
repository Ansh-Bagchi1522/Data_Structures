#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	int rno;
	char name[30];
	struct student *next;
};

void create(struct student *head){
    struct student *newnd,*last;
    last=head;
    char ch;
    printf("Do you want to create SLL (y/n)?");
    scanf(" %c",&ch);
    while(ch=='y'){
        newnd=(struct student *)malloc(sizeof(struct student));
        printf("\nEnter registration number: ");
        scanf("%d",&newnd->rno);
        printf("\nEnter name: ");
        scanf("%s",newnd->name);
        newnd->next=NULL;
        last->next=newnd;
        last=newnd;
        printf("\nDo you want to add more node (y/n)?");
        scanf(" %c",&ch);
    }
}

int lenLL(struct student *head){
    int count=0;
    struct student *temp;
    temp=head->next;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insert_position(struct student *head){
    int postn,len;
    struct student *newnd,*last,*temp;
    printf("Enter position to add node: ");
    scanf("%d",&postn);
    len=lenLL(head);
    if(postn<=len+1){
        int i=1;
        temp=head;
        while(i<postn){
            i++;
            temp=temp->next;
        }
        newnd=(struct student *)malloc(sizeof(struct student));
        printf("\nEnter registration number: ");
        scanf("%d",&newnd->rno);
        printf("\nEnter name: ");
        scanf("%s",newnd->name);
        newnd->next=temp->next;
        temp->next=newnd;
    }
}

void del_position(struct student *head){
    int postn,len,i;
    struct student *temp,*target;
    i=1;
    temp=head;
    printf("Enter position to add node: ");
    scanf("%d",&postn);
    len=lenLL(head);
    if(postn>len)
        printf("Node can't be deleted");
    else{
        while(i<postn && temp!=NULL){
            temp=temp->next;
            i++;
        }
        if(temp->next!=NULL){
            target = temp->next;
            temp->next=temp->next->next;
            free(target);
        }
    }
}

void display(struct student *head){
    struct student *temp;
    temp=head->next;
    if(head->next==NULL)
        printf("LL is empty");
    else{
        while(temp!=NULL){
            printf("\nAddress: %p",(void *)temp);
            printf("\nReg no: %d",temp->rno);
            printf("\nName: %s",temp->name);
            printf("\nNext address: %p\n",(void *)temp->next);
            temp = temp->next;
        }
    }
}

void reverse(struct student *head){
    struct student *lastrev=NULL,*present,*infuture=NULL;
    present = head->next;
    while(present != NULL){
        infuture = present->next;
        present->next = lastrev;
        lastrev = present;
        present = infuture;
    }
    head->next = lastrev;
}

void sort(struct student *head){
    struct student *curr1,*curr2;
    struct student temp;
    curr1 = head->next;
    while(curr1 != NULL){
        curr2 = curr1->next;
        while(curr2 != NULL){
            
            if(curr1->rno > curr2->rno){
                temp.rno = curr1->rno;
                curr1->rno = curr2->rno;
                curr2->rno = temp.rno;

                strcpy(temp.name,curr1->name);
                strcpy(curr1->name,curr2->name);
                strcpy(curr2->name,temp.name);
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
}

int main()
{
    struct student *head;
    int choice=1;
    head = (struct student*)malloc(sizeof(struct student));
    head->rno = 0;
    head->next = NULL;
    create(head);
    while(choice !=0){
        printf("\n1. Display\n2. Insert(position)\n3. Delete(position)\n4. Total\n5. Sort\n6. Reverse\nEnter Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            display(head);
            break;

            case 2:
            insert_position(head);
            break;

            case 3:
            del_position(head);
            break;

            case 4:
            printf("Total count = %d",lenLL(head));
            break;

            case 5:
            printf("Sorted List\n");
            sort(head);
            display(head);
            break;

            case 6:
            printf("Reversed List\n");
            reverse(head);
            display(head);
            break;
        }
    }      
}