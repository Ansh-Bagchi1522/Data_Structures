#include <stdio.h>
#include <stdlib.h>
struct poly{
	int coeff;
	int exp;
	struct poly *next;
};
void create(struct poly *head){
    struct poly *newnd,*temp3;
    temp3=head;
    char ch;
    printf("Do you want to create polynomial (y/n)?");
    scanf(" %c",&ch);
    while(ch=='y'){
        newnd=(struct poly *)malloc(sizeof(struct poly));
        printf("\nEnter Coefficient: ");
        scanf("%d",&newnd->coeff);
        printf("\nEnter Exponent: ");
        scanf("%d",&newnd->exp);
        newnd->next=head;
        temp3->next=newnd;
        temp3=newnd;
        printf("\nDo you want to add more node (y/n)?");
        scanf(" %c",&ch);
    }
}

void display(struct poly *head){
    struct poly *temp;
    temp=head->next;
    if(head->next==head)
        printf("LL is empty");
    else{
        while(temp!=head){
            printf("%dx^%d",temp->coeff,temp->exp);
            temp=temp->next;
            if (temp!=head)
                printf(" + ");
        }
    }
}

void add(struct poly *h1, struct poly *h2,struct poly *h3) {
    struct poly *temp1,*temp2;
    struct poly *curr, *temp3;
    temp3=h3->next;
    temp1=h1->next;
    temp2=h2->next; 
    int c;
    while (temp1 != h1 && temp2 != h2) {
        
        if (temp1->exp == temp2->exp) {
            c = temp1->coeff + temp2->coeff;
            if(c!=0){
                curr=(struct poly *)malloc(sizeof(struct poly));
                curr->next=h3;
                curr->coeff=c;
                curr->exp=temp1->exp;
                temp3->next=curr;
                temp3=curr;
                }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exp > temp2->exp) {
            curr=(struct poly *)malloc(sizeof(struct poly));
            curr->coeff=temp1->coeff;
            curr->exp=temp1->exp;
            curr->next=h3;
            temp3->next=curr;
            temp3=curr;
            temp1=temp1->next;
        }
        else {
            curr=(struct poly *)malloc(sizeof(struct poly));
            curr->coeff=temp2->coeff;
            curr->exp=temp2->exp;
            curr->next=h3;
            temp3->next=curr;
            temp3=curr;
            temp2=temp2->next;
        }
    }
    while (temp1 != h1) {
        curr=(struct poly *)malloc(sizeof(struct poly));
        curr->coeff=temp1->coeff;
        curr->exp=temp1->exp;
        curr->next=h3;
        temp3->next=curr;
        temp3=curr;
        temp1=temp1->next;
    }
    while (temp2 != h2) {
        curr=(struct poly *)malloc(sizeof(struct poly));
        curr->coeff=temp2->coeff;
        curr->exp=temp2->exp;
        curr->next=h3;
        temp3->next=curr;
        temp3=curr;
        temp2=temp2->next;
    }
}


int main(){
    struct poly *head1,*head2,*head3;
    head1=(struct poly *)malloc(sizeof(struct poly));
    head1->next=head1;
    printf("Enter polynomial 1\n");
    create(head1);
    head2=(struct poly *)malloc(sizeof(struct poly));
    head2->next=head2;
    printf("Enter polynomial 2\n");
    create(head2);
    head3=(struct poly *)malloc(sizeof(struct poly));
    head3->next=head3;
    add(head1,head2,head3);
    printf("Sum of polynomials = ");
    display(head3);
    return 0;
}