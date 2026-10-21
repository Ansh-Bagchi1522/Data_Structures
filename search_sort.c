#include<stdio.h>

struct Employee{
int id;
char name[20];
char designation[20];
};

void display_arr(struct Employee emp[30],int n){
	for(int i=0;i<n;i++){
	printf("\nID: %d\nName: %s\nDesignation: %s\n",emp[i].id,emp[i].name,emp[i].designation);	
	printf("\n");
	}	
}

void display(struct Employee emp){
	printf("\nID: %d\nName: %s\nDesignation: %s\n",emp.id,emp.name,emp.designation);	
	printf("\n");
}

void swap_int(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

void swap_struct(struct Employee *a,struct Employee *b){
	struct Employee temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int linear_search(struct Employee e[30],int n){
	int elem;
	printf("Enter ID: ");
	scanf("%d",&elem);
	for(int i=0;i<n;i++){
		if(e[i].id==elem){
			printf("Found at %d index\n",i);
			display(e[i]);
			}
		
		if(i==n){
			printf("NOT found");
			return -1;
			}
	}
} 

void binary_search(struct Employee e[30],int n){
	int l,h,mid;
	l=0;h=n-1;
	int elem;
	printf("Enter ID: ");
	scanf("%d",&elem);
	while(l<=h){
		mid =(l+h)/2;
		if(e[mid].id==elem){
			printf("Found at index %d\n",mid);
			display(e[mid]);
			break;
			}
		else{
			if(e[mid].id>elem){
				h=mid-1;
				}
			else{
				l=mid+1;
				}
			}
		}
	if(l>h){
		printf("Element NOT found in array");
		}
}

void bubble_sort(struct Employee emp[30],int n){
	for(int j=0;j<n-1;j++){
		for(int i=0;i<n-1;i++){
			if(emp[i].id>emp[i+1].id){
				swap_struct(&emp[i],&emp[i+1]);
			}	
		}
	}
}

void selection_sort(struct Employee emp[30],int n){
	int min,idx;
	for(int i=0;i<n-1;i++){
		min = emp[i].id;
		idx = i;
		for(int j=i+1;j<n;j++){
			if(emp[j].id<min){
				min = emp[j].id;
				idx =j;
				}
			}
		swap_struct(&emp[i],&emp[idx]);
		}
}

void insertion_sort(struct Employee emp[30],int n){
	for(int i=1;i<n;i++){
		struct Employee key = emp[i];
		int j = i-1;
		while(j>=0 && emp[j].id>key.id){
			emp[j+1] = emp[j];
			j=j-1;
			}
		printf(" %d",j);
		emp[j+1] =key;
		}	
}

void shell_sort(struct Employee emp[30],int n){
	int gap,swap_int_flag=1,i=0;
	gap=n/2;
	while(gap>0){
		while(swap_int_flag==1){
			swap_int_flag = 0;
			while(i<n-gap){
				if(emp[i].id>emp[i+gap].id){
					swap_struct(&emp[i],&emp[i+gap]);
					swap_int_flag = 1;
					i++;
					}
				i++;
				}
			}
			gap = gap/2;
		}
}



void accept(struct Employee emp[30],int n){
for(int i=0;i<n;i++){
	printf("Enter details of Person %d\n",i+1);
	printf("Enter ID: ");
	scanf("%d",&emp[i].id);
	printf("Enter Name: ");
	scanf("%s",emp[i].name);
	printf("Enter Designation: ");
	scanf("%s",emp[i].designation);
	printf("\n");	
	}
}




int main(){
	struct Employee emp[30];
	int n,op;
	printf("Enter number of employees: ");
	scanf("%d",&n);
	accept(emp,n);
	printf("Enter operation to be done:");
	printf("\n1. Linear Search\n2. Binary Search\n3. Bubble Sort\n4. Selection Sort\n5. Insertion Sort\n6. Shell Sort\nYour Option: ");
	scanf("%d",&op);

	switch(op){
		case 1: 
		linear_search(emp,n);
		break;

		case 2:
		bubble_sort(emp,n);
		binary_search(emp,n);
		break;

		case 3:
		bubble_sort(emp,n);
		printf("Sorted Structure:-");
		display_arr(emp,n);
		break;

		case 4:
		selection_sort(emp,n);
		printf("Sorted Structure:-");
		display_arr(emp,n);
		break;

		case 5:
		insertion_sort(emp,n);
		printf("Sorted Structure:-");
		display_arr(emp,n);
		break;

		case 6:
		shell_sort(emp,n);
		printf("Sorted Structure:-");
		display_arr(emp,n);
		break;

		default:
		printf("Invalid Operation");
		break;
	}
	return 0;
}