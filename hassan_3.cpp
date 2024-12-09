#include <iostream>
using namespace std;

int main() {
    const int DAYS = 7; 
    double temperatures[DAYS]; 

   
    cout << "Enter the temperatures for the week (7 days):" << endl;
    for (int i = 0; i < DAYS; i++) {
        cout << "Day " << (i + 1) << ": ";
        cin >> temperatures[i]; 
    }

  
    double total = 0;
    for (int i = 0; i < DAYS; i++) {
        total += temperatures[i]; 
    }
    double average = total / DAYS; 

    
    cout << "The average temperature for the week is: " << average << " degrees." << endl;

    return 0;
}
