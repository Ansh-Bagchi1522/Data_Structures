#include<stdio.h>
void input(int arr[20][20],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}	
	}
}

void display(int arr[20][20],int r,int c){
	printf("\n");
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf(" %d",arr[i][j]);
		}
		printf("\n");	
	}
	printf("\n");
}

void compact(int arr[20][20],int r,int c,int comp[20][20]){
	comp[0][0]= r;
	comp[0][1]=c;
	int k=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]!=0){
				comp[k][0] = i;
				comp[k][1] =j;
				comp[k][2] = arr[i][j];
				k++; 
			}
		}
	}
	comp[0][2] = k-1;
}

void simple_transpose(int comp[20][20],int st[20][20]){
	st[0][0]=comp[0][1];
	st[0][1]=comp[0][0];
	st[0][2] = comp[0][2];
	int k=1;
	for(int i =0; i<comp[0][0];i++){
		for(int j=1;j<=comp[0][2];j++){
			if(comp[j][1]==i){
				st[k][0] = comp[j][1];
				st[k][1] = comp[j][0];
				st[k][2] = comp[j][2];
				k++;
			}
		}
	}
}

void fast_transpose(int comp[20][20],int ft[20][20]){
	int rterm[3] = {0},rpos[3]={0};
	ft[0][0] = comp[0][1];
	ft[0][1] = comp[0][0];
	ft[0][2] = comp[0][2];
	for(int i=0;i<comp[0][1];i++){
		rterm[i] = 0;rpos[i]=0;
		for(int j=0;j<=comp[0][2];j++){
			if(comp[j][1]==i)
				rterm[i]++;
			}
		}
	rpos[0]=1;
	for(int j=0;j<3;j++){
		rpos[j+1] = rpos[j] + rterm[j];
		}
	for(int j=1;j<=comp[0][2];j++){
		ft[rpos[comp[j][1]]][0] = comp[j][1];
		ft[rpos[comp[j][1]]][1] = comp[j][0];
		ft[rpos[comp[j][1]]][2] = comp[j][2];
		rpos[comp[j][1]]++; 	
		}
}

int main()
{
	int arr[20][20],com[20][20],r,c,st[20][20],ft[20][20],op;
	printf("Choose an option:\n1.Display Matrix\n2.Display Compact Form\n3.Simple Transpose\n4.Fast Transpose\nYour Option: ");
	scanf("%d",&op);
	printf("Enter the number of rows: ");
	scanf("%d",&r);
	printf("Enter the number of columns: ");
	scanf("%d",&c);
	
		switch(op){
		case 1: 
		input(arr,r,c);
		display(arr,r,c);
		break;
		
		case 2:
		input(arr,r,c);
		compact(arr,r,c,com);
		printf("Compact Form:");
		display(com,com[0][2] + 1,3);
		break;
		
		case 3:
		input(arr,r,c);
		compact(arr,r,c,com);
		simple_transpose(com,st);
		printf("Simple Transpose:");
		display(st,st[0][2]+1,3);
		break;
		
		case 4:
		input(arr,r,c);
		compact(arr,r,c,com);
		fast_transpose(com,ft);
		printf("Fast Transpose:");
		display(ft,ft[0][2]+1,3);
		
		default:
		printf("Invalid Operation");
		}

	return 0;
}

