/*
Pranav Reddy
lab13.cpp
Debugging and testing practice
*/
#include <iostream>
#include <vector>
using namespace std;

bool faillecture(const vector<int>& attendance_records) {
    int absentcount = 0;
    for (int i = 1; i < attendance_records.size(); ++i) { //change to i=0 to fix fault
        absentcount += attendance_records[i] == 0;
    }
    return absentcount >= 3;
}

int main() {

    // 1. Fault in program
    cout << "1. There is a problem in the program, the loop starts at index 1 instead of 0. so the fix would be i=0\n";

    // 2: Test case that does not execute the fault
    // requirement: skipping index 0 should NOT matter.
    // basically make index 0 = 1 (present), and put absence elsewhere

    vector<int> tc2 = {1,1,1,1,1,1,1,1,1,0}; //record with 10 values
    cout << "2: Test case that does not execute the fault:\n";
    cout << "Attendance: {1,1,1,1,1,1,1,1,1,0}\n";
    cout << "Reason is that index 0 is PRESENT, so skipping it changes nothing.\n";
    bool expected2 = false; // only 1 absence then not fail
    bool actual2 = faillecture(tc2); //call function with test case 2
    cout << "Expected Output: " << expected2 << "\n"; //print outs
    cout << "Actual Output: " << actual2 << "\n\n";



    // 3: Executes the fault but not error state
    // skipping i=0 still produces a good ans
    // Example: index 0 absent, but total absences still < 3

    vector<int> tc3 = {0,1,1,1,1,1,1,1,1,1};
    cout << "3: Executes fault but no error state:\n";
    cout << "Attendance: {0,1,1,1,1,1,1,1,1,1}\n";
    cout << "Reason is skipping index 0 removes one absence but still < 3.\n";

    bool expected3 = false; // 1 absence then not fail like before
    bool actual3 = faillecture(tc3); //call function with test case 3
    cout << "Expected Output: " << expected3 << "\n"; //print outs
    cout << "Actual Output: " << actual3 << "\n\n";

