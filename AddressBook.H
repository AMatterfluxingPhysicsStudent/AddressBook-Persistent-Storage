#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;


/*
ReadMe:
The prototype functions are organized so that they map out the functions
Changes are done by "Change all instances" function in the editor.
Navigation when editing is often done by ctrl+f "[function name]", not by scrolling.

*/

struct node {
  int StorageID;
  string personLastName;
  string personFirstName;
  string email;
  string phoneNumber;
  string address;
  struct node* next;
  struct node* last;
};

//int main
  struct node* loadFile(struct node*, int&);
    //struct node* createLL (struct node*, int&);
  void NList (struct node*, int&);
  string MenuMain();
  struct node* callChosen(string menuChoice, struct node* head, int &count, int &loopContinue);
    struct node* humanNode(struct node*, int&);
      struct node* createLL (struct node*, struct node*, int&);
  void NodeSearchMenu(struct node*, int &);
    struct node* conNum(struct node*, int, string);
    struct node* conLN (struct node*, string);
    struct node* conFN (struct node*, string);
    struct node* conPN (struct node* head, string);
    struct node* conE (struct node*, string);
    struct node* conA (struct node*, string);
      void viewNodeContents (struct node*);
        void editNode(struct node*);
        void deleteNode(struct node*, int&);

  void saveToFile(struct node*, int&);




#endif