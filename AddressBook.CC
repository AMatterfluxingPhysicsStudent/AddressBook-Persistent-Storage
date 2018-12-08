#include "AddressBook.H"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void NList (struct node* head, int &count){
    struct node* currentNode = head;
    int countCheck = 0;
    int o = 1;
    while(currentNode != NULL) {
        cout<<" Contact #"<<o<<":   "<<currentNode->personLastName<<", " <<currentNode->personFirstName<<endl;
        currentNode = currentNode->next;
        countCheck++;
        o++;
      }
    count = countCheck;
    cout<<count<<" contacts exist."<<endl;
  }
  string MenuMain(){
    string string1;
    string firstLet;
    cout<<"Press C to Create a New Contact, V to View a Contact, Q to Quit otherwise."<<endl;
    getline(cin,string1);
    firstLet = string1[0];
    return firstLet;
  }
  void viewNodeContents (struct node* address){ 
    cout<<"Last Name: "<<address->personLastName<<endl;
    cout<<"First Name: "<<address->personFirstName<<endl;
    cout<<"Email: "<<address->email<<endl;
    cout<<"Phone Number: "<<address->phoneNumber<<endl;
    cout<<"Address: "<<address->address<<endl;
  }
  //finding functions using conditions
    struct node* conNum (struct node* head, int count, string nthString){
      int nthInt = stoi(nthString);
      //going to the proper node and retrieving the address
        struct node* currentNode = head;
        int pos = 1;
        while(pos != nthInt||pos > 2*count){
          currentNode = currentNode->next;
          pos++;
        }
        if (pos > 100){
          cout<<"Please enter the position again."<<endl;
          conNum(head, count, nthString);
        }
      //return the address
        return currentNode;  
    }
    struct node* conLN (struct node* head, string lookFor){
      //going to the proper node and retrieving the address
        struct node* currentNode = head;
        while(currentNode->personLastName != lookFor){
          currentNode = currentNode->next;
        }
      //returning the address
        return currentNode;
    }
    struct node* conFN (struct node* head, string lookFor){
      //going to the proper node and retrieving the address
        struct node* currentNode = head;
        while(currentNode->personFirstName != lookFor){
          currentNode = currentNode->next;
        }
      //returning the address
        return currentNode;
    }
    struct node* conPN (struct node* head, string lookFor){
      //going to the proper node and retrieving the address
        struct node* currentNode = head;
        while(currentNode->phoneNumber != lookFor){
          currentNode = currentNode->next;
        }
      //returning the address
        return currentNode;
    }
    struct node* conE (struct node* head, string lookFor){
      //going to the proper node and retrieving the address
        struct node* currentNode = head;
        while(currentNode->email != lookFor){
          currentNode = currentNode->next;
        }
      //returning the address
        return currentNode;
    }
    struct node* conA (struct node* head, string lookFor){
    //going to the proper node and retrieving the address
      struct node* currentNode = head;
      while(currentNode->address != lookFor){
        currentNode = currentNode->next;
      }
      //returning the address
        return currentNode;
    }
  void editNode(struct node* address){
    int loopC = 2;
    while(loopC < 7){
      string editChoice;
      string e;  
      cout<<"Press L to Edit "<<address->personLastName<<endl;
      cout<<"Press F to Edit "<<address->personFirstName<<endl;
      cout<<"Press E to Edit "<<address->email<<endl;
      cout<<"Press P to Edit "<<address->phoneNumber<<endl;
      cout<<"Press A to Edit "<<address->address<<endl;
      cout<<"Press Q to Return to Previous Menu."<<endl;
      getline(cin, editChoice);
      e = editChoice[0];

      if (e == "L"||e == "l"){
        string newLastName;
        cout<<"Enter new last name: ";
        getline(cin, newLastName);
        address->personLastName = newLastName;
      }
      else if (e == "F"||e == "f"){
        string newFirstName;
        cout<<"Enter new First Name: ";
        getline(cin, newFirstName);
        address->personFirstName = newFirstName;
      }
      else if (e == "E"||e == "e"){
        string newEmail;
        cout<<"Enter new Email: ";
        getline(cin, newEmail);
        address->email = newEmail;
      }
      else if (e == "P"||e == "p"){
        string newPhoneNum;
        cout<<"Enter new Phone Number: ";
        getline(cin, newPhoneNum);
        address->phoneNumber = newPhoneNum;
      }
      else if (e == "A"||e == "a"){
        string newAddress;
        cout<<"Enter new Address: ";
        getline(cin, newAddress);
        address->address = newAddress;
      }
      else if (e == "Q"||e == "q"){
        loopC = 10;
      }

      cout<<endl;
    }
  }
  void deleteNode(struct node* address, int &count){
    //link last and next nodes
    struct node* nextNode = address->next;
    struct node* lastNode = address->last;
    lastNode->next = nextNode;
    nextNode->last = lastNode;

    address->personLastName = "";
    address->personFirstName = "";
    address->email = "";
    address->phoneNumber = "";
    address->address = "";
    delete address;
    count--;
    //oof list item deleting is so much easier in linked lists
  }
  void NodeSearchMenu(struct node* head, int &count){
    string holder;
    string searchMethodSelection;
    struct node* address = NULL;
    cout<<"Press N to Select Contact by its Position in the Entries."<<endl;
    cout<<"Press L to Search For Contact by Last Name."<<endl;
    cout<<"Press F to Search For Contact by First Name."<<endl;
    cout<<"Press E to Search For Contact By Email."<<endl;
    cout<<"Press P to Search For Contact By Phone Number."<<endl;
    cout<<"Press A to Search For Contact By Address."<<endl;
    cout<<"Press Q to Return to Previous Menu."<<endl;
    getline(cin, holder);
    searchMethodSelection = holder[0];
    
    if(searchMethodSelection == "N"||searchMethodSelection == "n"){
      string nth;
      cout<<"Enter entry #:";
      getline(cin, nth);
      address = conNum (head, count, nth);
    }
    else if(searchMethodSelection == "L"||searchMethodSelection == "l"){
      string lookFor;
      cout<<"Enter Last Name to Search By: ";
      getline(cin, lookFor);
      address = conLN (head, lookFor);
    }
    else if(searchMethodSelection == "F"||searchMethodSelection == "f"){
      string lookFor;
      cout<<"Enter First Name to Search By: ";
      getline(cin, lookFor);
      address = conFN (head, lookFor);
    }
    else if(searchMethodSelection == "E"||searchMethodSelection == "e"){
      string lookFor;
      cout<<"Enter Email to Search By: ";
      getline(cin, lookFor);
      address = conE (head, lookFor);
    }
    else if(searchMethodSelection == "P"||searchMethodSelection == "p"){
      string lookFor;
      cout<<"Enter Phone Number to Search By: ";
      getline(cin, lookFor);
      address = conPN (head, lookFor);
    }
    else if(searchMethodSelection == "A"||searchMethodSelection == "a"){
      string lookFor;
      cout<<"Enter Address to Search By: ";
      getline(cin, lookFor);
      address = conA (head, lookFor);
    }
    else if(searchMethodSelection == "Q"||searchMethodSelection == "q"){
      return;
    }
    viewNodeContents(address);
    string choice;
    string ch;

    cout<<"Press E to edit the Contact."<<endl;
    cout<<"Press D to delete the Contact."<<endl;
    cout<<"Press R to return to main menu."<<endl;
    getline(cin, choice);
    ch = choice[0];

    if(ch == "E"||ch == "e"){
      editNode(address);
    }
    if(ch == "D"||ch == "d"){
      deleteNode(address, count);
    }
    if(ch == "R"||ch == "r"){
      
    }
  }
  struct node* callChosen(string menuChoice, struct node* head, int &count, int &loopContinue){
    if (menuChoice == "C"||menuChoice == "c"){
      head = humanNode(head, count);
    }
    else if (menuChoice == "V"||menuChoice == "v"){
      NodeSearchMenu(head, count);
    }
    else if (menuChoice == "Q"||menuChoice == "q"){
      loopContinue = 10;
    }
    return head;
  }

  
struct node* humanNode(struct node* head, int &count){
  struct node* newNode = new node;
  //data requesting from the human user
    count++;  
    cout<<"Enter the new contact's Last Name:"<<endl;
    getline(cin, newNode->personLastName);

    cout<<"Enter the new contact's First Name:"<<endl;
    getline(cin, newNode->personFirstName);
    
    cout<<"Enter the new contact's Email:"<<endl;
    getline(cin, newNode->email);

    cout<<"Enter the new contact's Phone Number:"<<endl;
    getline(cin, newNode->phoneNumber);
    
    cout<<"Enter the new contact's Address:"<<endl;
    getline(cin, newNode->address);
    
    newNode->StorageID = count;
    return createLL(head, newNode, count);
}


struct node* createLL (struct node* head, struct node* newNode, int &count){
  cout<<"Inside CreateLL:"<<endl;
  cout<<"struct node* head = "<<head<<endl;
  cout<<"newNode = "<<newNode<<endl;
  if (head == NULL){
    cout<<"Head == NULL activated"<<endl;
    head = newNode;
    cout<<"Head now equals "<<head<<endl;
    head->next = NULL;
  }
  else{
    cout<<"else condition activated"<<endl;
    struct node* currentNode = head;
    while(currentNode->next != NULL){
      currentNode = currentNode->next;
    }
    struct node* LastFilledNode = currentNode;
    LastFilledNode->next = newNode;
    cout<<"LastFilledNode = "<<LastFilledNode<<endl;
    newNode->last = LastFilledNode;
    cout<<"newNode->last  "<<newNode->last<<endl;
    newNode->next = NULL;
    
  }
  return head;
}




/*
ReadMe
The commented out cout commands are not often commented out during the development process, but actively produce printed lines that track what the variables are doing during execution. 

*/


struct node* loadFile(struct node* head, int &count){
  ifstream FileRead;
  FileRead.open("Address Book File", ios::in);
  if(FileRead.fail() == 0){
    cout<<"Loading Existing Contacts..."<<endl;
    // cout<<"File load did not fail."<<endl;
    string str1;
    int compare = 200;
    int cycle = 0;
    while(str1 != "End of File" && cycle < compare){
      // cout<<"At the beginning of this loadFile cycle, head is "<<head<<endl;
      cycle++;
      // cout<<"This is the "<<cycle<<"th cycle."<<endl;
      FileRead>>str1;
      // cout<<"Line 374 has str1 = "<<str1<<endl;
      if(str1 == "PrefaceBegins"){
        FileRead>>str1;
        // cout<<"Line 377 has str1 = "<<str1<<endl;
      }
      int existingCount;
      if(str1 == "Count:"){
        FileRead>>count;
        // cout<<"Line 382 has existingCount = "<<str1<<endl;
        FileRead>>str1;
        // cout<<"Line 384 has str1 = "<<str1<<endl;
      }
      if(str1 == "PrefaceEnds"){
        FileRead>>str1;
        // cout<<"Line 389 has str1 = "<<str1<<endl;
      }
      if(str1 == "NodeBegins"){
        FileRead>>str1;
        // cout<<"Line 393 has str1 = "<<str1<<endl;
      }
      struct node* aNode = new node;
      if(str1 == "StorageID:"){
        FileRead>>aNode->StorageID;
        FileRead>>str1;
        // cout<<"Line 398 has str1 = "<<str1<<endl;
      }
      if(str1 == "LN:"){
        FileRead>>aNode->personLastName;
        FileRead>>str1;
        // cout<<"Line 403 has str1 = "<<str1<<endl;
      }
      if(str1 == "FN:"){
        FileRead>>aNode->personFirstName;
        FileRead>>str1;
        // cout<<"Line 408 has str1 = "<<str1<<endl;
      }
      if(str1 == "E:"){
        FileRead>>aNode->email;
        FileRead>>str1;
        // cout<<"Line 417 has str1 = "<<str1<<endl;
      }
      if(str1 == "PN:"){
        FileRead>>aNode->phoneNumber;
        FileRead>>str1;
        // cout<<"Line 422 has str1 = "<<str1<<endl;
      }
      if(str1 == "A:"){
        FileRead>>aNode->address;
        FileRead>>str1;
        // cout<<"Line 427 has str1 = "<<str1<<endl;
      }
        // cout<<"Here's the node contents:"<<endl;
        // cout<<"StorageID: "<<aNode->StorageID<<endl;
        // cout<<"Last Name: "<<aNode->personLastName<<endl;
        // cout<<"First Name: "<<aNode->personFirstName<<endl;
        // cout<<"Email: "<<aNode->email<<endl;
        // cout<<"phoneNumber: "<<aNode->phoneNumber<<endl;
        // cout<<"Address: "<<aNode->address<<endl;
      if(str1 == "NodeEnds"){
        // cout<<"CreateLL activated"<<endl;
        head = createLL(head, aNode, count);
      }
      // cout<<"After CreateLL Called"<<endl;
      // cout<<"The compare variable is "<<compare<<" and the existing count is "<<existingCount<<"."<<endl;
      compare = existingCount;
      // cout<<"At end of loadFile cycle, head is now "<<head<<endl;
      // cout<<"Ending this cycle"<<endl;
    }
  }
  else {
  }
  
  return head;
}


void saveToFile(struct node* head, int &count){
    fstream File;
    File.open("Address Book File",ios::out);
    File<<"PrefaceBegins"<<endl;
    File<<"Count:"<<endl;
    File<<count<<endl;
    File<<"PrefaceEnds"<<endl;
    struct node* currentNode = head;
    while(currentNode!=NULL){
      File<<"NodeBegins"<<endl;
      File<<"StorageID: "<<currentNode->StorageID<<endl;
      File<<"LN: "<<currentNode->personLastName<<endl;
      File<<"FN: "<<currentNode->personFirstName<<endl;
      File<<"E: "<<currentNode->email<<endl;
      File<<"PN: "<<currentNode->phoneNumber<<endl;
      File<<"A: "<<currentNode->address<<endl;
      currentNode = currentNode->next;
      File<<"NodeEnds"<<endl;
    }
    File<<"End of File";
    File.close();
}