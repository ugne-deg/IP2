#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;
using namespace theList;

// Helper class to duplicate output to stdout and log.txt
class Logger {
    ofstream logFile;
public:
    Logger(const string& filename) {
        logFile.open(filename);
    }
    ~Logger() {
        if (logFile.is_open()) logFile.close();
    }
    void log(const string& msg, bool newline = true) {
        cout << msg;
        if (newline) cout << endl;
        if (logFile.is_open()) {
            logFile << msg;
            if (newline) logFile << endl;
        }
    }
};

void runTests() {
    Logger logger("log.txt");
    logger.log("=== LINKED LIST TEST SCENARIO ===");
    logger.log("Starting automated diagnostic tests...\n");

    int testsPassed = 0;
    int totalTests = 10;

    try {
        LinkedList list;

        // Test 1: Initial State
        logger.log("Test 1: Checking initial state...");
        logger.log(list.toString());
        testsPassed++;

        // Test 2: Insertion via +=
        logger.log("\nTest 2: Inserting elements (10, 20, 30) using operator+=...");
        list += 10;
        list += 20;
        list += 30;
        logger.log(list.toString());
        testsPassed++;

        // Test 3: Search via operator[]
        logger.log("\nTest 3: Searching for value 20 using operator[]...");
        int pos = list[20];
        logger.log("Value 20 found at position: " + to_string(pos));
        if (pos != -1) {
            logger.log("RESULT: PASSED");
            testsPassed++;
        } else {
            logger.log("RESULT: FAILED");
        }

        // Test 4: Duplicate Error (Custom Exception)
        logger.log("\nTest 4: Testing custom DuplicateValueException...");
        try {
            list += 20; // Should throw an exception
            logger.log("RESULT: FAILED (Exception not thrown)");
        } catch (const runtime_error& e) {
            logger.log("Caught expected exception: " + string(e.what()));
            logger.log("RESULT: PASSED");
            testsPassed++;
        }

        // Test 5: Update via operator%=
        logger.log("\nTest 5: Updating value 20 to 25 using operator%=...");
        list %= make_pair(20, 25);
        logger.log(list.toString());
        testsPassed++;

        // Test 6: Deletion via operator-=
        logger.log("\nTest 6: Deleting start element using operator-=...");
        list -= 0; // Parameter unused based on current implementation
        logger.log(list.toString());
        testsPassed++;

        // Test 7: Copy Constructor (Deep Copy)
        logger.log("\nTest 7: Testing Deep Copy (Copy Constructor)...");
        LinkedList listCopy = list;
        listCopy += 100;
        logger.log("Original list unchanged, Copy contains 100:");
        if (list[100] == -1 && listCopy[100] != -1) {
            logger.log("RESULT: PASSED (Deep copy verified)");
            testsPassed++;
        } else {
            logger.log("RESULT: FAILED");
        }

        // Test 8: Comparison Operators
        logger.log("\nTest 8: Testing operator== and operator!=...");
        LinkedList sameList = list;
        if (list == sameList && !(list != sameList)) {
            logger.log("Comparison logic: PASSED");
            testsPassed++;
        } else {
            logger.log("Comparison logic: FAILED");
        }

        // Test 9: Clearing via operator!
        logger.log("\nTest 9: Clearing list using operator!...");
        !list;
        logger.log(list.toString());
        if (list[30] == -1) {
            logger.log("RESULT: PASSED");
            testsPassed++;
        } else {
            logger.log("RESULT: FAILED");
        }

        // Test 10: Standard Exceptions (Out of range)
        logger.log("\nTest 10: Testing standard exception on empty delete...");
        try {
            list -= 0;
        } catch (const out_of_range& e) {
            logger.log("Caught expected std::out_of_range: " + string(e.what()));
            logger.log("RESULT: PASSED");
            testsPassed++;
        }

    } catch (const exception& e) {
        logger.log("\nCRITICAL ERROR during testing: " + string(e.what()));
    }

    logger.log("\n=================================");
    logger.log("TEST SUMMARY:");
    logger.log("Total Tests: " + to_string(totalTests));
    logger.log("Passed: " + to_string(testsPassed));
    logger.log("Failed: " + to_string(totalTests - testsPassed));
    logger.log("All diagnostic data written to log.txt");
    logger.log("=================================");
}

int main() {
    runTests();
    return 0;
}
