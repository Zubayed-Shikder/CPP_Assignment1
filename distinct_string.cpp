#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string k_th_distinct(vector<string>& array, int k) {
    unordered_map<string, int> count_Size;

    // Count outbreak of each string
    for (const string& str : array) {
        count_Size[str]++;
    }

    // Find the k-th distinct string
    for (const string& str : array) {
        if (count_Size[str] == 1) { // Check if it's distinct
            k--;
            if (k == 0) {
                return str; // Return k-th distinct string
            }
        }
    }

    return "";
}

int main() {
    vector<string> array;
    int k;

    // To get Input
    cout << "Enter number of strings: ";
    int n;
    cin >> n;
    
    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        array.push_back(s);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    // Get the result
    string result = k_th_distinct(array, k);

    // Output
    if (result.empty()) {
        cout << "There are fewer than " << k << " distinct strings." << endl;
    } else {
        cout << "The " << k << "-th distinct string is: " << result << endl;
    }

    return 0;
}