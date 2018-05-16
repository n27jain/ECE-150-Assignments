#include <stdlib.h>
#include <fstream>

#include <iostream>
using namespace std;


bool parseLine(const char line[],int min ,int max, int lineNumber){
	

	int i=0;
	
	bool error=false;// this bool will be true once we have successfully checked the string.
	
	int id=0;
	int grade=0;
	
	while (line[i]!=',' && error!=true){
		
		if (line[i]==' '){
			//do nothing
		}
		else if (line[i]>=48&&line[i]<=59){
			
			int current =line[i]-48;
			id=id*10+current;
			
		}
		else{
			error=true;
		}
		
		i++;
	}
	while (line[i]!='\0' && error!=true){// we look at the grade now
	
		if (line[i]==' '){
			//do nothing
		}
		else if (line[i]>=48&&line[i]<=59){
			
			int current =line[i]-48;
			grade=grade*10+current;
		}
		else{
	
			error==true;
		}
	
		i++;
	}
	
	if ((id<min||id>max)||(grade<0||grade>100)){
		return false;
	}
	
	
	else if (error){
		return false;
	}
	
	cout<<id<<" "<<grade<<endl;
	return true;

}



int main(const int argc, const char* const argv[]) {
	
	int minAcceptableID=0;
	int maxAcceptableID=90000000;
	int min=minAcceptableID;
	int max= maxAcceptableID;
	
	const int maxLineLength=100;
	char line[maxLineLength];
	ifstream infile;
	//const char fileName[];
	infile.open(argv[1]);
	
	
	if (!infile.is_open()){
		return -1;
	}
	bool done=false;
	int fileLineNumber=0;
	
	
	while(!done){
		++fileLineNumber;
		
		if (!infile.getline(line, maxLineLength)){
			if(infile.eof()){
				done=true;
			}
			else {
				return-1;
			}
		}
		
		bool parse= parseLine(line,min, max, fileLineNumber);
	
		if (parse==false){
		
		}
		
	}
	
	cout<<9/10<<endl;
	//doHistogramStuff();
	
	return 0;
}



