#include<stdio.h>
#define max 5
struct Polynomial{
    int coef;
    int exp;
};

void poly_add(struct Polynomial p1[max],struct Polynomial p2[max],struct Polynomial p3[max]){
    int i=0,j=0,k=0;
    while(i<max && j<max){
        if(p1[i].exp>p2[j].exp){
            p3[k] = p1[i];
            i++;
            k++;
        }
        else if(p2[i].exp>p1[i].exp){
            p3[k] = p2[j];
            k++;
            j++;
        }
        else{
            int temp;
            temp = p1[i].coef + p2[j].coef;
            if(temp !=0){
                p3[k].coef = temp;
                p3[k].exp = p1[i].exp;
                i++,j++,k++;
            }
        }
    }
    while(i<max){
        p3[k] = p1[i];
        i++,k++;
    }
    while(j<max){
        p3[k] = p2[j];
        j++,k++;
    }
}

int Display(struct Polynomial P[max]){
    int i=0;
    printf("Coef\tExp\n");
    while(i<2*max-1){
        printf("%d\t%d\n",P[i].coef,P[i].exp);
        i++;
    }
}

void poly_mul(struct Polynomial P1[max],struct Polynomial P2[max],struct Polynomial P3[max*max]){
    int temp=0,flag=0,exp=0;
    int k=0;
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            temp = P1[i].coef*P2[j].coef;
            if(temp!=0){
                flag=0;
                exp = P1[i].exp + P2[j].exp;
                for(int x=0;x<k;x++){
                    if(P3[x].exp == exp){
                        P3[x].coef+= temp;
                        flag=1;
                        break;
                    }
                     
                }
                if(flag==0){
                    P3[k].exp = exp;
                    P3[k].coef = temp;
                    k++;
                }
            }
        }
    }
}

void main(){
    struct Polynomial P1[max],P2[max],P3[max*max]={0};
    for(int i=0;i<max;i++){
        P1[i].coef = 1;
        P1[i].exp = i;
    }
    for(int i=0;i<max;i++){
        P2[i].coef = 1;
        P2[i].exp = i;
    }
    //poly_add(P1,P2,P3);
    poly_mul(P1,P2,P3);
    Display(P3);
}