//largest 3 numbers

#include <stdio.h>

int main() {
	//code
	int ar[] = {8,7,4,3,5,1};
	
	int first = -1, second = -1, third = -1;
	
	for(int i=0; i< 6; i++){
	    
	    if(ar[i] > first){
	        third = second;
	        second = first;
	        first = ar[i];
	    }
	    else if(ar[i] > second){
	        third = second;
	        second = ar[i];
	    }
	    else if(ar[i] > third){
	        
	        third = ar[i];
	    }
	   
	}
	
	 printf("\nFirst =%d",first);
	 printf("\nSecond =%d",second);
	 printf("\nThird =%d",third);
	    
	return 0;
}