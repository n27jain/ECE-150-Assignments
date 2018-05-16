#include <iostream>
using namespace std;

const int maxDogNameLength = 20;
enum DOG_TYPE { POINTER, BEAGLE, SAMOYED, PITBULL, SHITDOG };
	    
struct Data {
  int id;
  DOG_TYPE type;
  char name[maxDogNameLength];
};

struct Node {
  Data  data;
  Node* next;
};

bool addNode(Node*& list, const Data& dog) {
  Node* newNode = new Node;
  if (newNode) {
    newNode->data = dog;       // Shallow copy is fine
    newNode->next = list;
    list = newNode;
    return true;
  }
  return false;
}

bool deleteNode(Node*& list, const int doggieID) {
  Node* cur = list;
  
  if (cur == 0)                   // No first element
    return false;
  if (cur->data.id == doggieID) { // It's the first element
    list = list->next;
    delete cur;
    return true;
  }
  while (cur->next) {
    if (cur->next->data.id == doggieID) {
      Node* tmp = cur->next;
      cur->next = cur->next->next;
      delete tmp;
      return true;
    }
    cur = cur->next;    
  }
  return false;
}

const Data* find(const Node* list, DOG_TYPE t) {
  const Node* cur = list;
  while (cur) {
    if (cur->data.type == t)
      return &(cur->data);
    cur = cur->next;
  }
  return 0;
}

int myStringCopy(char dest[], const char src[], const int maxSize) {
  int i = 0;
  for (; (i < maxSize) && (src[i] != 0); ++i) {
    dest[i] = src[i];
  }
  if (i < maxSize)
    dest[i] = 0;
  return i;
}

void displayList(const Node* list) {
  const Node* cur = list;
  int i = 0;
  while (cur) {
    cout << i << ": " << cur->data.id << " --> ";
    cur = cur->next;
  }
  cout << "EOL" << endl;
}

int main() {
  Node* dogDatabase = 0;

  Data d1;
  d1.id = 417923;
  d1.type = BEAGLE;
  myStringCopy(d1.name, "Reggie", maxDogNameLength);
	cout<<d1.name<<endl;
  Data d2;
  d2.id = 666666;
  d2.type= SHITDOG;
  myStringCopy(d2.name, "Sexy", maxDogNameLength);
  
  
  
  if (!addNode(dogDatabase, d1)) {
    cerr << "Error: unable to add to dog DB" << endl;
    return -1;
  }
  else if (!addNode(dogDatabase, d2)) {
    cerr << "Error: unable to add to dog DB" << endl;
    return -1;
  }
  displayList(dogDatabase);
}




