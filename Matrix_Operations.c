#include<stdio.h>

void input(int arr[20][20]){
	printf("Enter elements of matrix: ");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
	}
}

void print(int arr[20][20]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
}

void addition(int arr1[20][20],int arr2[20][20]){
	printf("\nThe addition of both the matrices is:\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf(" %d",arr1[i][j]+arr2[i][j]);
		}
		printf("\n");
	}
}

void subtraction(int arr1[20][20],int arr2[20][20]){
	printf("\nThe difference is:\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf(" %d",arr1[i][j]-arr2[i][j]);
		}
		printf("\n");
	}
}

void multiplication(int arr1[20][20],int arr2[20][20]){
	printf("\nThe product of both the matrices is:\n");
	int product =0,a=0;
	for(int k=0;k<3;k++){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a = arr1[k][j]*arr2[j][i];
				product +=a;		
			}
			printf(" %d",product);
			product =0;
		}
		printf("\n");
	}
}

void transpose(int arr1[20][20]){
	printf("\nThe transpose of the matrix is:");
	int t[20][20];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			t[i][j] = arr1[j][i];
		}

	}
	printf("\n");
}

int main()
{
	int arr1[20][20],arr2[20][20],op=0;
	printf("Choose an option:\n1. Display\n2. Addition\n3. Subtraction\n4. Multiplication\n5. Transpose\nYour Option: ");
	scanf("%d",&op);
	switch(op){
		case 1: 
			input(arr1);
			print(arr1);
			break;

		case 2: 
			input(arr1);
			input(arr2);
			addition(arr1,arr2);
			break;

		case 3: 
			input(arr1);
			input(arr2);
			subtraction(arr1,arr2);
			break;

		case 4: 
			input(arr1);
			input(arr2);
			multiplication(arr1,arr2);
			break;

		case 5:
			int trans[20][20];
			input(arr1);
			transpose(arr1);
			print(trans);
			break;

		default:
			printf("Invalid Operation");
	};

	return 0;
}
