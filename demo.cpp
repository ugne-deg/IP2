#include "LinkedList.h"
#include <iostream>
#include <utility> // std::pair

using namespace std;
using namespace theList;

int main() {
    cout << "=== Demo.cpp ===" << endl;

    // 1. Constructor (LinkedList())
    LinkedList myList;
    cout << "Creating empty list." << endl;

    // 2. insertStart(int data)
    myList.insertStart(10);
    myList.insertStart(20);
    cout << "Added elements: 10, 20 (with insertStart)" << endl;

    // 3. operator+=(int data)
    myList += 30;
    cout << "Added element: 30 (with operator+=)" << endl;

    // 4. toString()
    cout << "\nCurrent List state (toString()):" << endl;
    cout << myList.toString() << endl;

    // 5. display()
    cout << "List elements (with display()): ";
    myList.display();

    // 6. Copy constructor (LinkedList(const LinkedList& other))
    LinkedList listCopy(myList);
    cout << "\nCreated a copy of the list (via copy constructor)." << endl;

    // 7. operator==
    if (myList == listCopy) {
        cout << "Comparison: Original and copy are EQUAL (operator==)." << endl;
    }

    // 8. update(int oldData, int newData)
    myList.update(10, 15);
    cout << "Value 10 changed to 15 (via update())." << endl;

    // 9. operator%=
    myList %= make_pair(20, 25);
    cout << "Value 20 changed to 25 (via operator%=)." << endl;

    // 10. operator!=, operator<, operator>, operator<=, operator>=
    if (myList != listCopy) {
        cout << "After changes, lists are NOT EQUAL (operator!=)." << endl;
    }
    
    cout << "Comparison operators demonstration:" << endl;
    cout << "myList < listCopy: " << (myList < listCopy ? "Yes" : "No") << endl;
    cout << "myList > listCopy: " << (myList > listCopy ? "Yes" : "No") << endl;
    cout << "myList <= listCopy: " << (myList <= listCopy ? "Yes" : "No") << endl;
    cout << "myList >= listCopy: " << (myList >= listCopy ? "Yes" : "No") << endl;

    // 11. operator[] (Search by value)
    int searchValue = 25;
    int position = myList[searchValue];
    cout << "\nSearching for value " << searchValue << " (operator[])." << endl;
    cout << "Position: " << position << endl;

    // 12. operator= (Assignment)
    LinkedList assignedList;
    assignedList = myList;
    cout << "Assignment performed (operator=)." << endl;

    // 13. deleteStart()
    myList.deleteStart();
    cout << "\nFirst element deleted (via deleteStart())." << endl;

    // 14. operator-=
    myList -= 0;
    cout << "First element deleted (via operator-=)." << endl;
    cout << myList.toString() << endl;

    // 15. operator! (Clear)
    !myList;
    cout << "List cleared (via operator!)." << endl;
    cout << "Final state: " << myList.toString() << endl;

    // 16. Destructor (~LinkedList())
    cout << "\n=== DEMONSTRATION FINISHED (Destructors will be called automatically) ===" << endl;

    return 0;
}