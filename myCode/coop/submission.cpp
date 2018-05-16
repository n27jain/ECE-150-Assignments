
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node{
	
	Node (){// set each pointer to null initially
		left=0;
		right=0;
	}
	int key;
	string value;
	Node *left;
	Node *right;
	
};

string findValueByKey (Node bob, int key){
	
	int inquiry= bob.key;
	string out= "NO-SUCH-VALUE";
	if (inquiry== key){
		 out= bob.value;
		return out;
	}
	else if (inquiry>key){
		if(bob.left!=NULL){
			Node next= *bob.left;
			return findValueByKey(next, key);
		}
		else{
			return out;
		}
		
	}
	else if (inquiry<key){
		if (bob.right!=NULL){
			Node next= *bob.right;
			return findValueByKey(next, key);
		
		}
		else{
			return out;
		}
	}
	
	
}


int main(const int argc, const char* const argv[]) {

int input = 100;// your parameters here


Node bob;
bob.key=100;
bob.value="Bob";

	//left

		Node bob_2;
		bob_2.key=50;
		bob_2.value="Bob";
		bob.left= &bob_2;

			// right of bob_2

			Node emily_2;
			emily_2.key=64;
			emily_2.value="Emily";
			bob_2.right=&emily_2;

		// no left of bob_2
		// no right of emily_2 or left of emily



	// right of bob

	Node emily;
	emily.key=128;
	emily.value="Emily";
	bob.right= &emily;
		// left emily

		Node georgia;
		georgia.key=110;
		georgia.value="Georgia";
		
		emily.left=&georgia;
		// no left georgia or right of georgia


		// right emily

		Node georgia_2;
		georgia_2.key=130;
		georgia_2.value="Georgia";
		emily.right=&georgia_2;
		
		// no left georgia_2

			// right georgia_2

			Node emily_3;
			emily_3.key=256;
			emily_3.value="Emily";
			georgia_2.right=&emily_3;
			// no left Emily115
			

		string out="";
		out = findValueByKey(bob,input);
		
		cout<<out<<endl;
		return 0;
}


