#include <stdio.h>

void print_Array(int* ar, int size);
void reverse(int ar[], int arSize);

int main(){

	int ar[] = {1,2,3,4,5,6,7};
	int size = 7;
	print_Array(ar,size);
	printf("\n");
	reverse(ar, size);

	printf("\nArray after reversal\n");

	print_Array(ar,size);

	printf("\n");	
return 0;
	
}

void reverse(int ar[], int arSize){
	
	int i,j=arSize-1,tmp;
	
	for(i=0;i < (arSize/2); i++ ) {

		tmp = ar[i];
		ar[i]=ar[j];
		ar[j]=tmp;
		j--;
	}

}

void print_Array(int* ar, int size){
        int i;
        for (i=0; i < size; i++)
                printf("%d ", ar[i]);

}

