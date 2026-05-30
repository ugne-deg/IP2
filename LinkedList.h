#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <stdexcept>

namespace TheList {

    class DuplicateValueException : public std::runtime_error {
    public:
        DuplicateValueException(const std::string& msg);
    };

    class LinkedList {
    private:
        class Impl;
        Impl* pimpl;

    public:
        std::string toString() const;
        LinkedList();
        LinkedList(const LinkedList& other);//overriden default copy contstructor to make deep copy
        LinkedList& operator=(const LinkedList& other);
        ~LinkedList();

        bool operator==(const LinkedList& other) const;
        bool operator!=(const LinkedList& other) const;
        bool operator<(const LinkedList& other) const;
        bool operator>(const LinkedList& other) const;
        bool operator<=(const LinkedList& other) const;
        bool operator>=(const LinkedList& other) const;        

        void insertStart(int data);
        void deleteStart();
        void update(int oldData, int newData);
        void display() const;

        void operator+=(int data);
        void operator-=(int data);
        void operator%=(std::pair<int, int> values);
        void operator!();
        int operator[](int value) const;

    };
}
#endif
