#include <stdio.h>
#include<string.h>
#define max 30
int top=-1;
char stack[max][100]={'0'};

void rev_str(char one[100],char rev[100]){
	for(int i=0;i<strlen(one);i++){
		rev[i]=one[strlen(one)-i-1];
	}
	for(int i=0;i<strlen(one);i++){
		if(rev[i]=='(')
			rev[i]=')';
		else if(rev[i]==')')
			rev[i]='(';
	}
	rev[strlen(one)]='\0';
}

int isfull(){
	if(top==max-1)
		return 1;
	else
		return -1;
}

void push(char ch[]){
	if(isfull()!=1)
	{
		top++;
		strcpy(stack[top],ch);
	}
}

int isempty(){
	if(top==-1)
		return 1;
	else
		return -1;
}

char pop(char temp[]){
	if(isempty()==1){
		return '\0';
		}
	else{
		strcpy(temp,stack[top]);
		top--;
	}
}

int icp(char ch){
	if(ch=='(')
		return 5;
	if(ch=='^')
		return 4;
	if(ch=='*' || ch=='/' || ch=='%')
		return 2;
	if(ch=='+' || ch=='-')
		return 1;
	else
		return -1;
}

int isp(char ch){
	if(ch=='^')
		return 3;
	if(ch=='*' || ch=='/' || ch=='%')
		return 2;
	if(ch=='+' || ch=='-')
		return 1;
	else
		return -1;
}

int operand(char ch){
	if(ch !='(' && ch!=')' && ch!='^' && ch!='*' && ch!='/' && ch!='%' && ch!='+' && ch!='-')
		return 1;
	else
		return -1;
}

void infix_postfix(char infix[100],char postfix[100]){
	char ch[100],sym='0';
	int i=0,k=0;
	while(infix[i]!='\0'){
		sym = infix[i];
		if(operand(sym)==1){
			postfix[k]=infix[i];
			k++;	
		}
		else{
			if(sym =='('){
				char temp[2];
                temp[0] = '(';
                temp[1] = '\0';

                push(temp);
			}
			else{
				if(sym == ')'){
					pop(ch);
					while(strcmp(ch,"(") != 0){
						postfix[k]=ch[0];
						k++;
						pop(ch);
					}
				}
				else{
					while((isempty()!=1) && (isp(stack[top][0])>= icp(sym)) ){
						pop(ch);
						postfix[k]=ch[0];
						k++;
					}
					char temp[2];
                    temp[0] = sym;
                    temp[1] = '\0';

                    push(temp);
				}
			}
		}
		i++;
	}
	while(isempty()!=1){
		pop(ch);
		postfix[k]=ch[0];
		k++;
	}
	postfix[k] = '\0';

}


void infix_prefix(char infix[100],char prefix[100]){
	char rev[100]={'0'};
	rev_str(infix,rev);

	infix_postfix(rev,prefix);
	rev_str(prefix,rev);
	strcpy(prefix,rev);
	
}

void postfix_infix(char postfix[100],char infix[100]){
	char x,temp[30];
	char op1[100]={'0'},op2[100]={'0'};
	for(int i=0;i<strlen(postfix);i++){
		x = postfix[i];
		if(operand(x)==-1){
			pop(op2);
			pop(op1);
			temp[0] = '(';
			temp[1] = '\0';
			strcat(temp, op1);
            int len = strlen(temp);
            temp[len] = x;
            temp[len + 1] = '\0';
            strcat(temp, op2);

            len = strlen(temp);
            temp[len] = ')';
            temp[len + 1] = '\0';

            push(temp);
        }
		else{
			temp[0] = x;
			temp[1] = '\0';
			push(temp);
		}
			
	}
	pop(infix);
}

void postfix_prefix(char postfix[100],char prefix[100]){
	char x,temp[30];
	char op1[100]={'0'},op2[100]={'0'};
	for(int i=0;i<strlen(postfix);i++){
		x = postfix[i];
		if(operand(x)==-1){
			pop(op2);
			pop(op1);
			temp[0] = x;
			temp[1] = '\0';
			strcat(temp, op1);
            strcat(temp,op2);
			push(temp);
		}
		else{
			temp[0] = x;
			temp[1] = '\0';
			push(temp);
		}
			
	}
	pop(prefix);
}

void postfix_evaluate(char postfix[100]){
    int value_stack[max],value_top = -1,values[100],var_count = 0;
    int op1, op2, result;
    char variables[100],x;

    for(int i = 0; i < strlen(postfix); i++){
        x = postfix[i];
        if(operand(x) == 1)
        {
            int found = 0;
            for(int j = 0; j < var_count; j++){
                if(variables[j] == x){
                    found = 1;
                    break;
                }
            }

            if(found == 0){
                variables[var_count] = x;

                printf("Enter value of %c: ", x);
                scanf("%d", &values[var_count]);

                var_count++;
            }
        }
    }
    for(int i = 0; i < strlen(postfix); i++){
        x = postfix[i];
        if(operand(x) == 1)
        {
            for(int j = 0; j < var_count; j++){
                if(variables[j] == x){
                    value_top++;
                    value_stack[value_top] = values[j];
                    break;
                }
            }
        }
        else
        {
            /* Pop operands */
            op2 = value_stack[value_top];
            value_top--;

            op1 = value_stack[value_top];
            value_top--;

            switch(x)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;

                case '%':
                    result = op1 % op2;
                    break;

                default:
                    printf("Invalid Operator");
                    return;
            }

            value_top++;
            value_stack[value_top] = result;
        }
    }

    result = value_stack[value_top];

    printf("\nResult = %d", result);
}
 

int main()
{
int exit=0;
char infix[100]={'0'},postfix[100]={'0'},prefix[100]={'0'};
int op;
printf("Specify Conversion:\n1. Infix to Postfix\n2. Infix to Prefix\n3. Postfix to Infix\n4. Postfix to Prefix\n5. Postfix Evaluation\nYour Option: ");
scanf("%d",&op);
switch(op){
	case 1:
	printf("Enter Infix expression: ");
	scanf("%s",infix);
	infix_postfix(infix,postfix);
	printf("\nPostfix Expression = %s",postfix);
	break;

	case 2:
	printf("Enter Infix expression: ");
	scanf("%s",infix);
	infix_prefix(infix,prefix);
	printf("\nPrefix Expression = %s",prefix);
	break;

	case 3:
	printf("Enter Postfix expression: ");
	scanf("%s",postfix);
	postfix_infix(postfix,infix);
	printf("\nInfix Expression = %s",infix);
	break;

	case 4:
	printf("Enter Postfix expression: ");
	scanf("%s",postfix);
	postfix_prefix(postfix,prefix);
	printf("\nPrefix Expression = %s",prefix);
	break;

	case 5:
	printf("Enter Postfix expression: ");
	scanf("%s",postfix);
	postfix_evaluate(postfix);
	break;

	default:
	printf("Invalid Operation");
	break;
	}
} 
