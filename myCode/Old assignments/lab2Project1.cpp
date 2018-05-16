#include <iostream>
#include <stdlib.h>

using namespace std;

int main (const int argc, const char* argv[]){
	
	
	
	if(argc<3){
		cerr<<"Error: Unable to compute GCD and/or LCM because of insufficent arguments."<<endl;
		return -1;
	}
	else if (argv[1]<0||argv[2]<0){
		cerr<<"Error: Unable to compute GCD and/or LCM because one or more values are negative. "<<endl;
	}
	else{
		
		int a=atoi(argv[1]);
		int b=atoi(argv[2]);
		int GCD=0;
		int LCM=0;
		
		
		if (a<b){
		
			if(b%a==0){
				GCD=a;
				
			}
			else{
				int x=a/2;// divide the smaller number by two. Any number greater thanits half cannot be a divisor.
				
				while(x>0){
					if(b%x==0&&a%x==0){// is this is a divisor
						GCD=x;
						x=-1;// End the while loop now.
					}
					x--;// Reduce the potential factor by one. As we go down, 
				}
				
			}
		
		
		
		}
		else if (a>b){
		
			if(a%b==0){
				GCD=b;
				
			}
			else{
				int x=b/2;// divide the smaller number by two. Any number greater thanits half cannot be a divisor.
				
				while(x>0){
					if(a%x==0&&b%x==0){// is this is a divisor
						GCD=x;
						x=-1;// End the while loop now.
					}
					x--;// Reduce the potential factor by one. As we go down, 
				}
				
			}
		}
		LCM=(a*b)/GCD;
		cout<<GCD<<endl;
		cout<<LCM<<endl;
	}
	return 0;
}
		