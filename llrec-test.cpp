#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

//removes all 2s in the linked list
struct isTwo{

bool operator()(int num){
  if (num == 2){
    return true;
  }
  return false;
}
};

//removes all odd numbers from the linked list
struct isOdd{

bool operator()(int num){
  if (num % 2 ==1){
    return true;
  }
  return false;
}
};

//removes all even numbers from the linked list
struct isEven{

bool operator()(int num){
  if (num % 2 == 0){
    return true;
  }
  return false;
}
};


//removes all numbers greater than 3 from the linked list
struct greaterThree{

bool operator()(int num){
  if (num > 3){
    return true;
  }
  return false;
}
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
   /*
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    cout << endl;
    // Test out your linked list code
    
    isOdd test1;
    isEven test2;
    
    greaterThree test3;
    

    
    head= llfilter(head, test3);
    cout << "List without numbers greater than 3: ";
    print(head);
    */
    Node* head2 = readList(argv[1]);
    cout << "Original list: ";
    print(head2);    

    isTwo test4;
    head2= llfilter(head2, test4);
    cout << "List without 2 : ";
    print(head2);





    
    return 0;

}
