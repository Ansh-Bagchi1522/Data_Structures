#include <stdio.h>
#include<string.h>
#define max 30
int top=-1;
char stack[max][100]={'0'};

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
    char postfix[100];
    printf("Enter postfix expression: ");
    postfix_evaluate(postfix);
}