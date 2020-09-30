#include <iostream>
using namespace std;

// Define the class for the node pointers
class Course {
private:
    
    //Setup the variables for the pointer such as next pointer and previous pointer for the doubly linked list
    int capacity;
    Course* ptr_prev;
    Course* ptr_next;
public:
    //Defines the constructor to initialize capacity
    Course(int capacity){
        this->capacity = capacity;
    };
    
    //A bunch of getters and setters
    void setCapacity(int capacity){
        this->capacity = capacity;
    };
    int getCapacity(){
        return this->capacity;
    }
    void setPrevPtr(Course *ptr_prev){
        this->ptr_prev = ptr_prev;
    };
    void setNextPtr(Course *ptr_next){
        this->ptr_next = ptr_next;
    };
    Course* getPrevtPtr(){
        return this->ptr_prev;
    };
    Course* getNextPtr(){
        return this->ptr_next;
    };
};

//defines the Course pointers needed to create a doubly linked list.
Course* head = nullptr;
Course* tail = nullptr;
Course* temp = nullptr;

//Defines the function to chain the nodes in the linked list
void insertNewNode (int newcapacity){
    
    //case where head is null
    if(head == NULL){
        Course* newNode = new Course (newcapacity);
        head = newNode;
    }
    else{
        //case where the tail is null
        if(tail == NULL){
            tail = new Course (newcapacity);
            head->setNextPtr(tail);
            tail->setPrevPtr(head);
        }
        else{
            Course* prevTail = tail;
            Course* newTail = new Course(newcapacity);
            
            newTail->setPrevPtr(prevTail);
            prevTail->setNextPtr(newTail);
            tail = newTail;
        }
    }
};

// This method inserts after a specific pointer
void insertAfterNode(Course* node, int capacity) {
    Course* newNode = new Course(capacity);
    if (node->getNextPtr() != NULL) {
        newNode->setNextPtr(node->getNextPtr());
        node->getNextPtr()->setPrevPtr(newNode);
    }
    node->setNextPtr(newNode);
    newNode->setPrevPtr(node);
}

void insertBeforeNode(Course* node, int capacity) {
    Course* newNode = new Course(capacity);
    if (node->getPrevtPtr() != NULL) {
        newNode->setPrevPtr(node->getPrevtPtr());
        node->getPrevtPtr()->setNextPtr(newNode);
    }
    newNode->setNextPtr(node);
    node->setPrevPtr(newNode);
}

void deleteNode (Course* remove){
    
    if(remove == head){
        head = remove->getNextPtr();
        head->setPrevPtr(NULL);
        remove->setNextPtr(NULL);
        remove = NULL;
    }
    else if(remove == tail){
        tail = remove->getPrevtPtr();
        tail->setNextPtr(NULL);
        remove->setPrevPtr(NULL);
        remove = NULL;
    }
    else{
        Course* prevNode = remove->getPrevtPtr();
        Course* nextNode = remove->getNextPtr();
        prevNode->setNextPtr(nextNode);
        nextNode->setPrevPtr(prevNode);
        remove->setNextPtr(NULL);
        remove->setPrevPtr(NULL);
        remove = NULL;
    }
    
};

// passing head and tail in as arguments makes the recursive part doable
int binarySearch (int key, Course* head, Course* tail){
    
    Course* first = head;
    Course* last = tail;
    Course* temp = nullptr;
    int found = -1;
    
    if(head == tail){
        return found;
    }
    
    // Find the midpoint
    while(first != last || first->getNextPtr() != last){
        first = first->getNextPtr();
        last = last->getPrevtPtr();
        if(first == last){
            temp = first;
            found = first->getCapacity();
        }
        else if(head->getNextPtr() == tail && tail->getPrevtPtr() == head){
            if(head->getCapacity() == key){
                temp = head;
                found = head->getCapacity();
            }
            else if(tail-> getCapacity() == key){
                temp = tail;
                found = tail->getCapacity();
            }
        }
    }
    
    if(key == found){
        int index = 0;
        Course* startingNode = head;
        while(startingNode != temp){
            index++;
        }
    }
    else{
        if(found < key){
            binarySearch(key,head, temp);
        }
        else if(found > key){
            binarySearch(key,temp, tail);
        }
    }
    
    return found;
}

int main() {
    
    int task,searchKey,capacity;
    
    cin >> task;
    cin >> searchKey;
    
    while (cin >> capacity){
        insertNewNode(capacity);
    }

 


    switch(task){
        case 0:
            binarySearch(searchKey, head, tail);
            
            break;
        case 1:
            Course* currentNode = head;
            bool found = false;
            
            while(currentNode != NULL){
                if(currentNode->getCapacity() == searchKey){
                    deleteNode(currentNode);
                    found = true;
                }
                currentNode = currentNode->getNextPtr();
            }
            
            if(found == false){
                Course* startNode = head;
                if(searchKey < head->getCapacity()){
                    insertBeforeNode(startNode, searchKey);
                    head = head->getPrevtPtr();
                }
                else if(tail->getCapacity() < searchKey ){
                    insertNewNode(searchKey);
                }
                else {
                    while (startNode != NULL && searchKey > startNode->getCapacity()) {
                        startNode = startNode->getNextPtr();
                    }
                    insertBeforeNode(startNode, searchKey);
                }
            }
            Course* nextNode = head;
            while(nextNode != NULL){
            cout << nextNode->getCapacity() << ' ';
            nextNode = nextNode->getNextPtr();
    }
            break;
    }


}
