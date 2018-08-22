#include <stdio.h>

//Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.



void print_Array(int* ar, int size){
        int i;
        for (i=0; i < size; i++)
                printf("%d ", ar[i]);

}

int* rotate_ar(int* ar, int size, int rotate_factor){
        int i,j=0;
        for (i = size;; i++){
                if(j > (rotate_factor-1))
                        break;

                ar[i] = ar[j];

                j++;
        }
        
	return &ar[rotate_factor];
}


int main(){
	int ar[] = {1,2,3,4,5,6,7};
	int rotate_factor = 2;
	//printf ("How many elements to rotate ?");
	//scanf ("%d",rotate_factor);
	

	printf ("\nArray before rotation\n");
	
	print_Array(ar,7);

	int*p = rotate_ar(ar,7,rotate_factor);

	printf ("\nArray after rotation\n");
	
	print_Array(p,7);

	return 0;
}
