//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <iostream>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////
//
// #includes for local testing only
//


#ifndef MARMOSET_TESTING
#include <iostream>
#include <time.h>
#include <limits.h>

#endif

//////////////////////////////////////////////////////////////
//
// Enums and structs for use in assignment 

#ifndef MARMOSET_TESTING

enum COURSE
{
	CHE102,
	MATH115,
	MATH117,
	ECE105,
	ECE150,
	ECE190,
	Null
};

struct Assignment
{
	COURSE course;       
	int    assnNum;      // Assignment number
	int    dueMonth;     // 1-12
	int    dueDay;       // 1-31
	char*  description;  // Assignment description
};

#endif


//////////////////////////////////////////////////////////////
//
// Class declaration; modify but do not remove

struct Node {
	
	Node* nextInQueue;
	Assignment* assn;
	
	
	Node(){
		
	nextInQueue=NULL;
	assn=NULL;
	
	}
};

class HomeworkQueue 
{
public:
    bool                enqueue(const Assignment& assignment);
    const Assignment*   dequeue();
    int                 daysTillDue(const COURSE course);
    const Assignment*   dueIn(const int numDays);
	bool 				validInput(const Assignment& assn);
	int 				Localtime();
    HomeworkQueue();    //constructor
    ~HomeworkQueue();   //destructor
private:
    // It is up to you what you store here
	Node * head;
};


//////////////////////////////////////////////////////////////
//
// Your code here ...
//  


bool HomeworkQueue::validInput(const Assignment& assn){
	
	if(assn.course==Null||assn.description==NULL||*assn.description=='\0'||assn.assnNum<0||assn.dueMonth<1||assn.dueDay<1||assn.dueMonth>12||assn.dueDay>30){
			
			return false;
		}
		
	return true;

}

int HomeworkQueue::Localtime(){
	
	struct tm * timenow;
	time_t currenttime;
	time(&currenttime);
	timenow= localtime(&currenttime);
	int abstime= 30*(timenow->tm_mon+1) +timenow->tm_mday;
	
	return abstime;
	
	
}


bool HomeworkQueue::enqueue(const Assignment& assignment)
{
	
	if(assignment.dueMonth>12||assignment.dueMonth<1||assignment.dueDay>30||assignment.dueDay<1||assignment.description==NULL||!validInput(assignment)){
		return false;
		
	}
	
	int time= assignment.dueMonth*30+assignment.dueDay;
	Node* newHome= new Node;
	if (head == NULL){
		head = new Node;
		head ->assn = new Assignment(assignment);
		head ->nextInQueue= NULL;
		return true;
	}
	else if (head ->assn ==NULL){
		head ->assn= new Assignment(assignment);
		return true;
	}
	
	
	else if (time< (head ->assn->dueMonth*30 +head  ->assn ->dueDay)){
		Node* head= new Node;
		head->assn= new Assignment(assignment);
		head->nextInQueue= head ;
		head = head;
		return true;

	}
	else {
		Node* nextCheck= head ;
		
		while (nextCheck->nextInQueue!=NULL){
			
			
			int last= nextCheck->assn->dueMonth*30+nextCheck->assn->dueDay;
			int after= nextCheck->nextInQueue->assn->dueMonth*30+nextCheck->assn->dueDay;
			if (time>=last&& time<after){	// if our time is between the previous and next time...
				Node * newPlace= new Node;
				newPlace->assn= new Assignment(assignment);
				newPlace->nextInQueue= nextCheck->nextInQueue;
				nextCheck->nextInQueue= newPlace;
				return true;
				
			}
			nextCheck= nextCheck->nextInQueue;
			
		}
		nextCheck->nextInQueue= new Node;
		nextCheck->nextInQueue->assn= new Assignment (assignment);
		nextCheck->nextInQueue->nextInQueue=NULL;
		return true; 
		
		
	}
	
	/*if(newHome){
		newHome->nextInQueue= head ->*assn;
		newHome->assn= &copy;
		head = newHome;
		return true;
		
		
	}
	*/
	
	// add to head  based on due date,
	
	
	// return true;  // if worked.
	
	
	return false;
}

const Assignment* HomeworkQueue::dequeue()
{
	if(head ==NULL){
		
		return NULL;
	}
	
	const Assignment * out= head ->assn;
	Node *temp= head ;
	
	head = head ->nextInQueue;
	delete temp;
	
	
	return out;
	
	
}

int HomeworkQueue::daysTillDue(const COURSE course)
{
	const Node * check= new Node;
	check=head;
	
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
	
	if(balance<0){
		return -1;
	}
	
	return balance;
	}
	
	return -1;
}

const Assignment* HomeworkQueue::dueIn(const int numDays)
{
	
	if(head==NULL){
	
		return NULL;
	}
	
	const Node* nextCheck= head;
	int localtime=Localtime();
	int time=  (nextCheck->assn->dueMonth*30+nextCheck->assn->dueDay);
	
	
	Assignment * out= new Assignment[1000];
	int i=0;
	

	
	bool occur=false; 
	
	while (nextCheck!=NULL){
		
			time=  (nextCheck->assn->dueMonth*30+nextCheck->assn->dueDay);
			
			if(!validInput(*nextCheck->assn)){
				
			}
			else if (time-localtime<=numDays){	// if our time is between the previous and next time...
				occur=true;
				out[i]=*nextCheck->assn;
				i++;
			}
			
			nextCheck= nextCheck->nextInQueue;
			
			
		}
		
	if(occur){
		return (const Assignment*) out;
	}
	
	return NULL;
}

HomeworkQueue::HomeworkQueue()
{
	head=new Node;
	head->assn=NULL;
	head->nextInQueue=NULL;
	
	

}

HomeworkQueue::~HomeworkQueue()
{
	//Please clean up
	
	Assignment *check= head->assn;
	
	Node * temp=head->nextInQueue;
	
	delete check;
	delete head;
	
	while(temp->nextInQueue!=NULL){
		
		head=temp;
		check= head->assn;
		temp=head->nextInQueue;
		
		delete check;
		delete head;
		
	}
	
}



		

#ifndef MARMOSET_TESTING
int main(const int argc, const char* const args[]) 
{
	//formatting
	std::cout << std::endl;

	HomeworkQueue hwq;

	char boring[] = "Something something solubility something something gases something";

	Assignment someAssignment = 
	{
		.course = CHE102,
		.assnNum = 1000000,
		.dueMonth = 12,
		.dueDay = 4,
		.description = boring
	};

	if(!hwq.enqueue(someAssignment))
	{
		std::cout << "enqueue() unsuccessful" << std::endl;
	}
	else
	{
		std::cout << "enqueue() successful" << std::endl;
	}

	const Assignment* assnInTheQueue = hwq.dequeue();

	if (!assnInTheQueue)
	{
		std::cout << "dequeue() unsuccessful" << std::endl;

	}
	else 
	{
		std::cout << "dequeue() successful" << std::endl;
	}

	//formatting
	std::cout << std::endl;

    return 0;
}
#endif
