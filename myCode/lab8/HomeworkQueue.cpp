//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <time.h>
#include <iostream>
#include <limits.h>

//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#include <time.h>
#include <limits>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING

enum COURSE {CHE102, MATH115, MATH117, ECE105, ECE150, ECE190, Null};

struct Assignment 
{
	COURSE course; // CHE102, MATH117, etc.
	int assnNum; // Assignment Number
	int dueMonth; // Month due (1-12)
	int dueDay; // Day due (1-31)
	char* description; // Assignment description
};

struct HomeworkQueue
{
	Assignment* assn;
	HomeworkQueue* nextInQueue;

};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment);
const Assignment* dequeue(HomeworkQueue*& queue);
int daysTillDue(const HomeworkQueue* q, const COURSE course);
const Assignment* dueIn(const HomeworkQueue* q, const int numDays);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//




int Localtime(){
	
	struct tm * timenow;
	time_t currenttime;
	time(&currenttime);
	timenow= localtime(&currenttime);
	int abstime= 30*(timenow->tm_mon+1) +timenow->tm_mday;
	
	return abstime;
	
	
}

bool validInput(const Assignment& assn){
	
if(assn.course==Null||assn.description==NULL||*assn.description=='\0'||assn.assnNum<0||assn.dueMonth<1||assn.dueDay<1||assn.dueMonth>12||assn.dueDay>30){
		
		return false;
	}
	
return true;

}

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment)
{
	// take assignment reference,
	
	if(assignment.dueMonth>12||assignment.dueMonth<1||assignment.dueDay>30||assignment.dueDay<1||assignment.description==NULL||!validInput(assignment)){
		return false;
		
	}
	
	int time= assignment.dueMonth*30+assignment.dueDay;
	HomeworkQueue* newHome= new HomeworkQueue;
	if (queue== NULL){
		queue= new HomeworkQueue;
		queue->assn = new Assignment(assignment);
		queue->nextInQueue= NULL;
		return true;
	}
	else if (queue->assn ==NULL){
		queue->assn= new Assignment(assignment);
		return true;
	}
	
	
	else if (time< (queue->assn->dueMonth*30 +queue ->assn ->dueDay)){
		HomeworkQueue* head= new HomeworkQueue;
		head->assn= new Assignment(assignment);
		head->nextInQueue= queue;
		queue= head;
		return true;

	}
	else {
		HomeworkQueue* nextCheck= queue;
		
		while (nextCheck->nextInQueue!=NULL){
			
			
			int last= nextCheck->assn->dueMonth*30+nextCheck->assn->dueDay;
			int after= nextCheck->nextInQueue->assn->dueMonth*30+nextCheck->assn->dueDay;
			if (time>=last&& time<after){	// if our time is between the previous and next time...
				HomeworkQueue * newPlace= new HomeworkQueue;
				newPlace->assn= new Assignment(assignment);
				newPlace->nextInQueue= nextCheck->nextInQueue;
				nextCheck->nextInQueue= newPlace;
				return true;
				
			}
			nextCheck= nextCheck->nextInQueue;
			
		}
		nextCheck->nextInQueue= new HomeworkQueue;
		nextCheck->nextInQueue->assn= new Assignment (assignment);
		nextCheck->nextInQueue->nextInQueue=NULL;
		return true; 
		
		
	}
	
	/*if(newHome){
		newHome->nextInQueue= queue->*assn;
		newHome->assn= &copy;
		queue= newHome;
		return true;
		
		
	}
	*/
	
	// add to queue based on due date,
	
	
	// return true;  // if worked.
	
	
	
}
const Assignment* dequeue(HomeworkQueue*& queue){
	
	
	if(queue==NULL){
		
		return NULL;
	}
	
	const Assignment * out= queue->assn;
	HomeworkQueue *temp= queue;
	
	queue= queue->nextInQueue;
	delete temp;
	
	
	return out;
	
	
}
int daysTillDue(const HomeworkQueue* q, const COURSE course){
	
	const HomeworkQueue * check= new HomeworkQueue;
	check=q;
	
	Assignment *x= new Assignment;
	
	x=check->assn;
	
	bool run=true;
	
	
	while (run){
		
		x= check->assn;
		COURSE mycourse= x->course;
		
		if(mycourse==course){
			run=false;
		}
		else if (check->nextInQueue==NULL){
			return INT_MAX;
		}
		
		check= check->nextInQueue;
		
	}
	if (run==false){
		
		
	int days= x->dueMonth*30+ x->dueDay;
	
	int compare = Localtime();
	
	//std::cout <<days << std::endl;
	
	int balance = days-compare;
	return balance;
	}
	
	
	
	

	
	
	return -1;
}



const Assignment* dueIn(const HomeworkQueue* q, const int numDays){
	
	if(q==NULL){
	
		return NULL;
	}
	
	const HomeworkQueue* nextCheck= q;
	int localtime=Localtime();
	int time=  (nextCheck->assn->dueMonth*30+nextCheck->assn->dueDay);
	
	
	Assignment * out= new Assignment[1000];
	int i=0;
	

	
	
	while (nextCheck!=NULL){
			time=  (nextCheck->assn->dueMonth*30+nextCheck->assn->dueDay);
			
			if(!validInput(*nextCheck->assn)){
				
			}
			else if (time-localtime<=numDays){	// if our time is between the previous and next time...
				
				out[i]=*nextCheck->assn;
				i++;
			}
			
			nextCheck= nextCheck->nextInQueue;
			
			
		}
		
	return (const Assignment*) out;
		
		
	
	
	
	return NULL;
}


//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  		// Some test driver code here ....
	std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

	HomeworkQueue* p_queue = new HomeworkQueue;
	p_queue->nextInQueue = NULL;
	p_queue->assn = NULL;

	char sample1[] = "File 1";
	Assignment assn1 = 
	{
		.course = MATH117,
		.assnNum = 0,
		.dueMonth = -11,
		.dueDay = -3,
		.description = sample1
	};
	char sample2[]= "File 2";
    Assignment assn2={
			
		.course= ECE105,
		.assnNum= 2,
		.dueMonth= 8,
		.dueDay= 5,
		.description= sample2
	};
	
	char sample3[] = "File 3";
	Assignment assn3 = 
	{
		.course = ECE150,
		.assnNum = 3,
		.dueMonth = 10,
		.dueDay = 15,
		.description = sample3
	};
	char sample4[] = "File 4";
	Assignment assn4 = 
	{
		.course = ECE150,
		.assnNum = 4,
		.dueMonth = 10,
		.dueDay = 15,
		.description = sample4
	};
	char sample5[] = "File 5";
	Assignment assn5 = 
	{
		.course = ECE150,
		.assnNum = 5,
		.dueMonth = 10,
		.dueDay = 15,
		.description = sample5
	};
	char sample11[] = "File 11";
	Assignment assn11 = 
	{
		.course = MATH117,
		.assnNum = 0,
		.dueMonth = 11,
		.dueDay = 30,
		.description = sample1
	};
	char sample13[] = "File 1";
	Assignment assn13 = 
	{
		.course = ECE150,
		.assnNum = 0,
		.dueMonth = 11,
		.dueDay = 29,
		.description = sample1
	};

	bool add1 = enqueue(p_queue, assn1);
	
	bool add2= enqueue(p_queue, assn2);
	bool add3= enqueue(p_queue, assn3);
	bool add4 = enqueue(p_queue, assn4);
	bool add5= enqueue(p_queue, assn5);
	bool add11= enqueue(p_queue, assn11);
	bool add13= enqueue(p_queue, assn13);
	int day= Localtime();
	int qo= daysTillDue(p_queue, ECE150);
	std::cout <<day << std::endl;
	std::cout <<qo << std::endl;
	HomeworkQueue* check= p_queue;
	
	while (check->nextInQueue!=NULL){
		
		std::cout << check->assn->description << std::endl;
		check=check->nextInQueue;
	}
	
	const Assignment *yolo= dueIn(p_queue, 0);

	std::cout<<std::endl;
	std::cout << yolo[3].description << std::endl;
	
	
	
	
	
	
	
	
	
	
	/*
	const Assignment* p_firstAssignmentInQueue = dequeue(p_queue);
	
	if (p_firstAssignmentInQueue)
	{
		std::cout << "Dequeue successful..." << std::endl;
		std::cout << "Course: " << p_firstAssignmentInQueue->course << std::endl;
		std::cout << "Assignment #: " << p_firstAssignmentInQueue->assnNum << std::endl;
		std::cout << "Day due: " << p_firstAssignmentInQueue->dueDay << std::endl;
		std::cout << "Month due: " << p_firstAssignmentInQueue->dueMonth << std::endl;
		std::cout << "Description: " << p_firstAssignmentInQueue->description << std::endl;
	}
	else
	{
		std::cout << "dequeue() failed" << std::endl;
	}

	delete p_queue;
	*/
	return 0;
}

#endif
