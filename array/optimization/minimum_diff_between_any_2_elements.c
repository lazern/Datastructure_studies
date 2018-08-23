#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int ar[] = {60,20,25,72,44,52};
	int size = 6;
	int minDiff = INT_MAX;
	
	sort(ar, ar+size);
	
	int i;
	
	for(i =0; i < size; i++){
	    
	    if (minDiff > ar[i+1] - ar[i] )
	        minDiff = ar[i+1] - ar[i];
	}
	
	printf ("Minimum difference is =%d\n",minDiff);
	
	return 0;
}