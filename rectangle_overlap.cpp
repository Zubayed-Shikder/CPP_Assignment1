#include <iostream>
#include <vector>

using namespace std;

bool is_Rectangle_Overlap(vector<int>& rec1, vector<int>& rec2) {
    if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0]) return false;
    if (rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) return false;
    return true;
}

int main() {
    vector<int> rec1(4), rec2(4);

    cout << "Enter the coordinates of the first rectangle (x1 y1 x2 y2): ";
    for (int& x : rec1) cin >> x;

    cout << "Enter the coordinates of the second rectangle (x1 y1 x2 y2): ";
    for (int& x : rec2) cin >> x;

    // Output (true/false) based on overlap
    cout << (is_Rectangle_Overlap(rec1, rec2) ? "true" : "false") << endl;

    return 0;
}