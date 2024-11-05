#include <iostream>
#include <vector>

using namespace std;

vector<int> getPascalRow(int row_Index) {
    vector<int> pascalRow(row_Index + 1, 0); // Create a vector to hold the row
    pascalRow[0] = 1; // The first element is always 1

    for (int current_Index = 1; current_Index <= row_Index; ++current_Index) {
        // Calculate the value based on previous value
        pascalRow[current_Index] = (pascalRow[current_Index - 1] * (row_Index - (current_Index - 1))) / current_Index;
    }

    return pascalRow;
}

int main() {
    int inputRowIndex;

    // Get Input from user
    cout << "Enter the row index: ";
    cin >> inputRowIndex;

    // Get and output the result
    vector<int> resultRow = getPascalRow(inputRowIndex);
    
    cout << "The " << inputRowIndex << "-th row of Pascal's triangle is: [";
    for (size_t element_Index = 0; element_Index < resultRow.size(); ++element_Index) {
        cout << resultRow[element_Index];
        if (element_Index < resultRow.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}