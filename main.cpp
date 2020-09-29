#include <iostream>
using namespace std;

class Course {
private:
    int capacity;
    Course* ptr_prev;
    Course* ptr_next;
public:
    Course(int capacity){
        this->capacity = capacity;
    };
    
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

Course* head = NULL;
Course* tail = NULL;

void insertNewNode (int newcapacity){

    if(head == NULL){
        Course* newNode = new Course (newcapacity);
        head = newNode;
    }
    else{
        if(tail == NULL){
            tail = new Course (newcapacity);
            head->setNextPtr(tail);
            tail->setPrevPtr(head);
        }
        else{
            Course* prevTail = tail;
            Course* newTail = new Course (newcapacity);
            
            newTail->setPrevPtr(prevTail);
            prevTail->setNextPtr(newTail);
            tail = newTail;
        }
    }
};

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

int binarySearch (int key){
    
    Course* first = head;
    Course* last = tail;
    
    while(first != last){
        first = first->getNextPtr();
        last = last->getPrevtPtr();
    }
    return 0;
}

int main() {
    
    int task,searchKey,capacity;
    
    cin >> task;
    cin >> searchKey;
    
    for(int i =0; i<8;i++){
        cin >> capacity;
        insertNewNode(capacity);
    }
       
    switch(task){
        case 0:
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
                
                while(startNode != NULL){
                    
                    if(searchKey < head->getCapacity()){
    
                    }
                    else if(head->getCapacity() < searchKey < tail->getCapacity()){
                        
                    }
                    else if(tail->getCapacity() < searchKey ){
                        insertNewNode(searchKey);
                    }
                    startNode = startNode->getNextPtr();
                }
            }
            
            break;
    }
    

    Course* nextNode = head;
    while(nextNode->getNextPtr() != NULL){
        cout << nextNode->getCapacity();
        nextNode = nextNode->getNextPtr();
    }
    
    
}
