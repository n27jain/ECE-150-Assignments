	
	#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;


int main (){
	
	int *yolo= new int [2];
	yolo[0]=1;
	yolo[1]=2;
	
	int i=2;;
	int new_array[i];
	
	int q=0;
	while (q<i){
		
		new_array[q]=yolo[q];
		cout<<new_array[q]<<endl;
		q++;
	}
}
	