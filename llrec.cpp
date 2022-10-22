#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  //cant assume smaller & larger are empty upon entry
  smaller = nullptr;
  larger = nullptr;

  
  if (head == nullptr){
  }

	if (head == NULL){ //if input linked list is empty.
    //std::cout << "Input linked list is empty." << std::endl;
		return; 
	}
  else{
    llpivot(head->next, smaller, larger, pivot);
    if (head->val < pivot || head->val == pivot){//smaller
      head->next = smaller; //overwrites head's previous subsequent nodes and makes new subsequent nodes be the smaller nodes
      smaller = head;
    }
    if (head->val > pivot){ //larger
      head->next = larger;
      larger = head;
    }
  }
  head = nullptr;
}

