#include <stdio.h>


void print_Array(int* ar, int size);


int main(){


	int ar[] = {1,2,3,4,5,6,7};
	int i,j,x,pos;

	printf("How positions to rotate: ");

	scanf("%d",&pos);


	printf ("Array before rotation\n");
	print_Array(ar, 7);

	int temp[pos];

	for(i =0; i < pos; i++)
		temp[i]=ar[i];

	for (j=0; j< (7-pos); j++){

		ar[j]= ar[j+pos];
	}

	for(x=0; x < pos; x++){
		ar[(7-pos)+x] = temp[x];	
	}

	printf("\nArray after rotation \n");

	print_Array(ar,7);

	printf("\n");		

	return 0;
}



void print_Array(int* ar, int size){
        int i;
        for (i=0; i < size; i++)
                printf("%d ", ar[i]);

}


