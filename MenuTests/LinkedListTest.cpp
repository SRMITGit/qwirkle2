#include "LinkedListTest.h"
#include <stdexcept>

LinkedListTest::LinkedListTest(){
    head = nullptr;
}

LinkedListTest::LinkedListTest(LinkedListTest& other){
    head = nullptr;
    for(int i = 0; i < other.size(); ++i){
        Menu* menu = new Menu(*other.get(i));
        add_back(menu);
    }
}
LinkedListTest::~LinkedListTest(){
    clear();
}

int LinkedListTest::size(){
    
    int length = 0;

    Node* current = head;
    while(current != nullptr){
        ++length;
        current = current->next;
    }
    return length;
}

Menu* LinkedListTest::get(int index){
    Menu* retCard = nullptr;

    if(index >= 0 && index < size()){

        int counter = 0;
        Node* current = head;

        while(counter<index){
            ++counter;
            current = current->next;
        }

        retCard = current->menu;

    }
    return retCard;
}

void LinkedListTest::add_front(Menu* data){
    Node* node = new Node();
    node->menu = data;
    node->next = head;
    head = node;
}
void LinkedListTest::add_back(Menu* data){
    Node* node = new Node();
    node->menu = data;
    node->next = nullptr;

    if(head == nullptr){
        head = node;
    }else{
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = node;
    }

}

void LinkedListTest::remove_front(){
    if(head != nullptr){
        Node* toDelete = head;
        head = head->next;

        delete toDelete->menu;
        delete toDelete;
    }else{
        throw std::runtime_error("Nothing to remove");
    }

}
void LinkedListTest::remove_back(){
    
    if(head != nullptr){
        Node* current = head;
        //pre should point to node before current;
        Node* prev = nullptr;

        while(current->next != nullptr){
            prev = current;
            current = current->next;
        }

        if(prev == nullptr){
            head = nullptr;
        }else{
            prev->next = nullptr;
        }

        delete current->menu;
        delete current;
    }
    
}

void LinkedListTest::remove(int index){
    if(index >= 0 && index < size()){
        if(head != nullptr){
            int counter = 0;
            Node* current = head;
            //pre should point to node before current;
            Node* prev = nullptr;

            while(counter != index){
                ++counter;
                prev = current;
                current = current->next;
            }

            if(prev == nullptr){
                head = current->next;
            }else{
                prev->next = current->next;
            }

            delete current->menu;
            delete current;
        }
    }
}

void LinkedListTest::clear(){
    while(head != nullptr){
        remove_front();
    }
}