#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    for (int student : students) {
        studentQueue.push(student);
    }
    int sandwichIndex = 0, attempts = 0;
    while (!studentQueue.empty() && attempts < studentQueue.size()) {
        if (studentQueue.front() == sandwiches[sandwichIndex]) {
            studentQueue.pop();
            sandwichIndex++;
            attempts = 0;
        } else {
            int temp = studentQueue.front();
            studentQueue.pop();
            studentQueue.push(temp);
            attempts++;
        }
    }
    return studentQueue.size();
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    vector<int> students(n), sandwiches(n);
    cout << "Enter the preferences of students (0 for circular, 1 for square): ";
    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }
    cout << "Enter the sandwich stack (top to bottom: 0 for circular, 1 for square): ";
    for (int i = 0; i < n; ++i) {
        cin >> sandwiches[i];
    }
    int result = countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
