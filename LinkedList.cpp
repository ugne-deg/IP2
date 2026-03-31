#include "LinkedList.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

using namespace std;

namespace theList {
    
    struct Node {
        int data;
        Node* next;

        Node(int data){
        this->data = data;
        this->next = NULL;
        }
    };

    class LinkedList::Impl {
    public:
        Node* head;
        Node* tail;

        Impl(){
            head = NULL;
            tail = NULL;
        }

        Impl(const Impl& other){//deep copy constructor
            head = NULL;
            tail = NULL;
            if(!other.head) return;

            Node* current = other.head;
            while(current){
                this->insertAtEnd(current->data);
                current = current -> next;
            }
        }

        ~Impl() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = NULL;
        }

        std::string toString() const{
            std::stringstream ss;
            int count = 0;
            Node* curr = head;

            while (curr) {
            count++;
            curr = curr->next;
            }

            ss <<"Linked List Info:\n";
            ss << "State: " << (head ? "Has elements" : "Empty") << "\n";
            ss << "Number of elements: " << count << "\n";

            if (head) {
                ss << "Sarting element (Head): " << head->data << "\n";
                ss << "Last element (Tail): " << (tail ? std::to_string(tail->data) : "N/A") << "\n";
                ss << "List: ";
                curr = head;
                while (curr) {
                    ss << curr->data << (curr->next ? " -> " : "");
                    curr = curr->next;
                }
            }

            ss << "\n-------------------------------";
            return ss.str();
        }

        void insert(int data) {

        if (findValue(data) != -1){
            throw DuplicateValueException("Value " + std::to_string(data) + " already exists");
        }

            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            if(tail == NULL) tail = newNode;
        }

        void insertAtEnd(int data){
            Node* newNode = new Node(data);

            if(!head)head = tail = newNode;
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void remove() {
            if (!head) throw std::out_of_range("List is empty");
            Node* temp = head;
            head = head->next;
            if(head == NULL)  tail = NULL;
            delete temp;
        }

        void update(int oldData, int newData) {
            Node* temp = head;
            bool found = false;
            while (temp) {
                if (temp->data == oldData) {
                    temp->data = newData;
                    found = true;
                    return;
                }
                temp = temp->next;
                
            }

            if (!found){
                throw std::invalid_argument("Value to update not found in the list");
            }
        }

        void display() const {
                Node* curr = head;
                while (curr) {
                    cout << curr->data << " ";
                    curr = curr->next;
                }
                cout << endl;
            }

        void clear(){
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
        }

        int findValue(int data) const {
            Node* temp = head;
            int index = 0;
            while (temp) {
                if (temp->data == data) return index;//0 base index
                temp = temp->next;
                index++;
            }
            return -1;//if not found
        }


    };

    LinkedList::LinkedList(){
        pimpl = new Impl();
    }

    LinkedList::LinkedList(const LinkedList& other){
    pimpl = new Impl(*other.pimpl);
    }

    std::string LinkedList::toString() const {
    return pimpl->toString();
    }

    LinkedList& LinkedList::operator=(const LinkedList& other){
    if (this != &other){
        delete pimpl;
        pimpl = new Impl(*other.pimpl);
    }
    return *this;
    }

    LinkedList::~LinkedList(){
        delete pimpl;
    }

    void LinkedList::insertStart(int data){
        pimpl->insert(data);
    }

    void LinkedList::deleteStart() {
        pimpl->remove();
    }

    void LinkedList::update(int old, int next){
        pimpl->update(old, next);
    }

    void LinkedList::display() const {
        pimpl->display();
    }

    void LinkedList::operator!() {
        pimpl->clear();
        }

    void LinkedList::operator+=(int data) { insertStart(data); }
    void LinkedList::operator-=(int) { deleteStart(); }
    void LinkedList::operator%=(pair<int, int> v) { update(v.first, v.second); }

    bool LinkedList::operator==(const LinkedList& other) const {
        Node* curr1 = pimpl->head;
        Node* curr2 = other.pimpl->head;

        while (curr1 && curr2) {
            if (curr1->data != curr2->data) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1 == NULL && curr2 == NULL;
    }

    bool LinkedList::operator!=(const LinkedList& other) const {
        return !(*this == other);
    }

    bool LinkedList::operator<(const LinkedList& other) const {
        Node* curr1 = pimpl->head;
        Node* curr2 = other.pimpl->head;

        while (curr1 && curr2) {
            if (curr1->data < curr2->data) return true;
            if (curr1->data > curr2->data) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return (curr1 == NULL && curr2 != NULL);
    }

    bool LinkedList::operator>(const LinkedList& other) const { return other < *this; }
    bool LinkedList::operator<=(const LinkedList& other) const { return !(*this > other); }
    bool LinkedList::operator>=(const LinkedList& other) const { return !(*this < other); }  

    int LinkedList::operator[](int value) const {
    return pimpl->findValue(value);
    }

}

//used as reference:
//https://prepinsta.com/cpp-program/singly-linked-list