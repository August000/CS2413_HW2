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
// Having a temp pointer makes things easier later
// Also when initializing pointers it's preferable to use nullptr over NULL
Course* temp = nullptr;

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
            Course* newTail = new Course(newcapacity);
            
            newTail->setPrevPtr(prevTail);
            prevTail->setNextPtr(newTail);
            tail = newTail;
        }
    }
};

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

    // This method inserts after a specific pointer
    // you can delete this call, it's just here to show you it works
    // insertAfterNode(tail, 10);

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
