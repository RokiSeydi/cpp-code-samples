#include <iostream>
using namespace std;

struct node {
    int x;
    node *nextNode;
};

class myStack {
    private:
     node *startingNode;
    public:
        myStack();
        void push(int);
        int pop();
        void display();
};

int main(){
    myStack s = myStack();
    cout<<"Pushing 1"<<endl;
    s.push(1);
    s.display();
    cout<<"Pushing 2"<<endl;
    s.push(2);
    s.display();
    cout<<"Pushing 3"<<endl;
    s.push(3);
    s.display();
    cout<<"First pop: "<<s.pop()<<endl;
    s.display();
    cout<<"Second pop: "<<s.pop()<<endl;
    s.display();
    cout<<"Third pop: "<<s.pop()<<endl;
    s.display();

    return 0;
}


//create a function to access the startingNode as the one in the class is private

myStack::myStack(){
    myStack::startingNode = nullptr;
}

// declare a pointer by creating a new object of the class (using new operator)
void myStack::push(int x) {
    node *n = new node;
// we can access the new node by navigating to the variable x and assigning the value x
    n->x = x;
    n->nextNode = nullptr;
    // check if the stack is empty or not, if it is we set the starting node to the new node we created 
    if (myStack::startingNode == nullptr) {
        startingNode = n;
    } else { 
    //if it's not empty we navigate to end of the linked list and we push a new node by creating a new pointer that points
    //to a new starting node
        node *currentNode = myStack::startingNode;
        while (true)
        {
           if(currentNode->nextNode == nullptr) {
               currentNode->nextNode = n;
               break;
           }
           currentNode = currentNode->nextNode;
        }
        
    }
}

// last in first out
int myStack::pop(){
    int requiredValue;

    // we are checking if in the list there's only one node. if we had only one
    //node the next one would point to null

    if(myStack::startingNode->nextNode == nullptr) {

        // in that scenario we are retrieving the only value of node present and set it equal to required value
        requiredValue = myStack::startingNode -> x;

        // garbage collection ( we are removing the node) and then we are setting the initial condition as in the struct

        delete myStack::startingNode;
        myStack::startingNode = nullptr;

        // if we have more than one node, we are going to the end of the linked list and check if the node before
        // the other node is zero. if it is, we gonna extract the value, delete the next node and
        // set it equal to
        
    } else {
        node *currentNode = myStack::startingNode;
        while(true) {
            if(currentNode->nextNode->nextNode == nullptr) {
                requiredValue = currentNode->nextNode->x;
                delete currentNode->nextNode;
                currentNode->nextNode = nullptr;
                break;
            }
            currentNode = currentNode->nextNode;
        }
    }
    return requiredValue;
}


void myStack::display(){
    if(myStack::startingNode != nullptr) {
        node *currentNode = myStack::startingNode;
        while (true)
        {
           cout<< currentNode -> x<< " ";
           if(currentNode -> nextNode == nullptr)
             break;
        currentNode = currentNode -> nextNode;
        }
        
    } else {
        cout <<"Empty stack";
    }

    cout<<endl<<endl;
}