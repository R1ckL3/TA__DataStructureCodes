#include <iostream>
#include <unistd.h>
using namespace std;

class node {
    private:
        int value;
        node *next;
        node *previous;
        int *valuePtr;
    public:
        node(int value) {
            this -> value = value;
            this -> valuePtr = &value; 
            this -> next = nullptr;
            this -> previous = nullptr;
        }
        int getValue(){
            return *valuePtr;
        }
        node *setNext(node *node){
            this -> next = node;
        }
        node *setPrevious(node *node){
            this -> previous = node;
        }
        node *getNext() {
            return next;
        }
        node *getPrevious(){
            return previous;
        }
        
};
class linkList{
    private:
        int linkSize;
        node *listHead;
        node *listEnd;
    public:
        linkList(int value) {
            node *newNode = new node(value);
            listHead = newNode;
            listEnd = newNode;
        }
        node *getListHead(){
            return listHead;
        }
        node *getListEnd(){
            return listEnd;
        }
        node *insertNodeAtEnd(node){
            this -> newNode -> next(newNode);
        }
        void insertAtEnd(int value){
            node *newNode = new node (value);
            newNode -> setNext(newNode);  
            node *insertNodeAtEnd(newNode);
        }
        void insertAtHead(int value){
            node *newNode = new node (value);
            newNode -> setPrevious(newNode);
        }
        node getValue(){
            return this -> getValue();
        }
        // void display() {
        //     node* temp = head;
        //     while(temp != nullptr){
        //         cout << temp -> getValue() << " ";
        //         temp = temp -> getNext();
        //     }
        //     cout << endl;
        // }
  
        // ~linkedList() {
        //     node* current = head;
        //     node* nextnode;
        //     while (current != nullptr) {
        //         nextnode = current -> getNext();
        //         delete current;
        //         current = nextnode;
        //     }
        // }
};
class stack{
    private:
        int counter;
        char stackArr[100];
    public:
        stack(){
            counter = 0;
        }
        void push(char input){
            if(counter < 100){
                stackArr[counter] = input;
                counter++;
            }
            else{
                cout << "STACK IS FULL !" << endl;
            }
        }
        char pop(){
            if(counter == 0){
                cout << "STACK IS EMPTY" << endl;
            }
            else{
                cout << stackArr[counter - 1] << " removed" << endl;
                counter--;
                return stackArr[counter];
            }
        }
        void peek(){
            if(counter == 0){
                cout << "STACK IS EMPTY" << endl;
            }
            else{
                cout << stackArr[counter - 1] << endl;
            }
        }
        void isEmpty(){
            if(counter == 0){
                cout << "IS EMPTY" << endl;
            }
            else{
                cout << "IS NOT" << endl;
            }
        }
};
class poly{
    private:
        char input[150];
        char sign[7];                           // +- */ ^ () 
        char *abovernace[4][2];
    public:
        poly(){
            sign[0] = '+';
            sign[1] = '-';
            sign[2] = '*';
            sign[3] = '/';
            sign[4] = '^';
            sign[5] = '(';
            sign[6] = ')';
            abovernace[0][0] = &sign[0];
            abovernace[0][1] = &sign[1];
            abovernace[1][0] = &sign[2];
            abovernace[1][1] = &sign[3];
            abovernace[2][0] = &sign[4];
            abovernace[3][1] = &sign[5];
            abovernace[3][0] = &sign[6];
        }

};
class menu{
    private:
        bool appIsOpen;
        bool linkedList;
        int mode;
    public:
        menu(){
            appIsOpen = true;
            linkedList = false;
            mainMenu(appIsOpen);
        }
        void mainMenu(bool status){
            while(status){
                int choice;
                system("clear");
                cout << "WELCOME" << endl;
                cout << "for stack enter '1'" << endl;
                cout << "for linked list enter '2'" << endl;
                cout << endl;
                cout << "To close app enter '0'" << endl;
                cout << "INPUT : ";
                cin >> choice;
                cout << "endl";
                switch(choice){
                    case 0:{
                        status = false;
                        break;
                    }
                    case 1:{

                        break;
                    }
                    case 2:{
                        linkedList = true;
                        while(linkedList){
                            system("clear");
                            int linkedListChoice;
                            cout << "Which type of linkedList?" << endl;
                            cout << "0.Simple linked list  1.Double linked list " << endl <<  "2.Recursive linked list 3.double recursive linked list" << endl;
                            cout << "To get back '4'" << endl;
                            cout << "INPUT : ";
                            cin >> linkedListChoice;
                            cout << "endl";
                                switch(linkedListChoice){
                                    case 0:{
                                        system("clear");
                                        cout << "Simple linked list" << endl;
                                        break;
                                    }
                                    case 1:{
                                        system("clear");
                                        cout << "Double linked list" << endl;
                                        break;
                                    }
                                    case 2:{
                                        system("clear");
                                        cout << "Recursive linked list" << endl;
                                        break;
                                    }
                                    case 3:{
                                        system("clear");
                                        cout << "double recursive linked list" << endl;
                                        break;
                                    }
                                    case 4:{
                                        system("clear");
                                        cout << "returning ..." << endl;
                                        sleep(2);
                                        linkedList = false; 
                                        break;
                                    }
                                    default :{
                                        
                                        break;
                                    }
                                }
                            }
                        }
                    default:{
                        break;
                    }
                }
            }
        }

};
int main(){
    menu menu;
    // menu menu;
    // poly p;
    int input;
    cin >> input;
    linkList list(input);
    cout << list.getListHead() << endl;
    cout << list.getListEnd() << endl;
    // cout << list.getValue();

}
