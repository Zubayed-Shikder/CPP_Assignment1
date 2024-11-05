#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Function to generate a spiral matrix from linked list values
vector<vector<int>> spiralMatrix(int r, int c, Node* head) {
    vector<vector<int>> mat(r, vector<int>(c, -1)); // Initialize with -1
    vector<int> vals; // Store linked list values

    while (head) {
        vals.push_back(head->val);
        head = head->next;
    }

    int idx = 0; 
    int top = 0, bottom = r - 1, left = 0, right = c - 1;

    // Fill the matrix in spiral order
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right && idx < vals.size(); ++i) mat[top][i] = vals[idx++];
        top++;
        for (int i = top; i <= bottom && idx < vals.size(); ++i) mat[i][right] = vals[idx++];
        right--;
        for (int i = right; i >= left && top <= bottom && idx < vals.size(); --i) mat[bottom][i] = vals[idx++];
        bottom--;
        for (int i = bottom; i >= top && left <= right && idx < vals.size(); --i) mat[i][left] = vals[idx++];
        left++;
    }

    return mat; 
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& m) {
    for (const auto& row : m) {
        cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

// Main function to run the program
int main() {
    int m, n;

    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter values for the linked list (end with -00):" << endl;

    while (true) {
        int value;
        cin >> value;
        if (value == -00) break;

        Node* newNode = new Node(value);

        if (!head) { 
            head = newNode;
            tail = newNode;
        } else { 
            tail->next = newNode;
            tail = newNode;
        }
    }

    vector<vector<int>> resultMatrix = spiralMatrix(m, n, head);
    
    cout << "Output Matrix:" << endl;
    printMatrix(resultMatrix);

    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp; 
    }

    return 0; 
}