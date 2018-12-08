#include "AddressBook.H"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
  struct node* head = NULL;
  int count = 0;
  string menuChoice;
  cout<<"Welcome to your address book!"<<endl;

  head = loadFile(head, count);
  // cout<<"In int main, Head is "<<head<<endl;

  int loopContinue = 2;
  while(loopContinue < 8){
    cout<<"This is the main menu. ";
    cout<<"Here are all your contacts:"<<endl;
    NList(head, count);
      cout<<endl;
    menuChoice = MenuMain();
    head = callChosen(menuChoice, head, count, loopContinue);
    cout<<endl;
    saveToFile(head, count);
  }

  struct node* currentNode = head;
  struct node* nodeToDelete = NULL;
  
  for(int r = 1; r <= count; r++){
    nodeToDelete = currentNode;
    currentNode = currentNode->next;
    nodeToDelete->personLastName = "";
    nodeToDelete->personFirstName = "";
    nodeToDelete->email = "";
    nodeToDelete->phoneNumber = "";
    nodeToDelete->address = "";
    delete nodeToDelete;
  }
}

