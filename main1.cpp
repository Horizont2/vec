#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Employee {
public:
    string name;
    string position;
    double salary;

    Employee(string n, string p, double s) : name(n), position(p), salary(s) {}
};

int main() {
    vector<Employee> employees = {
        Employee("John Doe", "Manager", 50000),
        Employee("Jane Smith", "Developer", 45000),
        Employee("Emily Johnson", "Designer", 40000)
    };

    vector<string> employeeStrings;
    transform(employees.begin(), employees.end(), back_inserter(employeeStrings),
              [](const Employee& emp) {
                  return emp.name + " - " + emp.position;
              });

    for (const string& empStr : employeeStrings) {
        cout << empStr << endl;
    }

    return 0;
}
