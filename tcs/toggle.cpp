#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

const int DIGIT_COUNT = 10;
const int SEGMENT_SIZE = 3;

vector<string> extractMatrix(const vector<string>& lines, int start_col) {
    vector<string> matrix;
    for (int i = 0; i < SEGMENT_SIZE; ++i) {
        matrix.push_back(lines[i].substr(start_col, SEGMENT_SIZE));
    }
    return matrix;
}
int hammingDistance(const vector<string>& a, const vector<string>& b) {
    int distance = 0;
    for (int i = 0; i < SEGMENT_SIZE; ++i) {
        for (int j = 0; j < SEGMENT_SIZE; ++j) {
            if (a[i][j] != b[i][j]) {
                ++distance;
            }
        }
    }
    return distance;
}
unordered_set<int> findPossibleDigits(const vector<string>& matrix, const vector<vector<string>>& digits) {
    unordered_set<int> possible_digits;
    for (int i = 0; i < DIGIT_COUNT; ++i) {
        int distance = hammingDistance(matrix, digits[i]);
        if (distance <= 1) {
            possible_digits.insert(i);
        }
    }
    return possible_digits;
}

int main() {
    vector<vector<string>> digitMatrices(DIGIT_COUNT);
    vector<string> inputLines(SEGMENT_SIZE);
    for (int i = 0; i < SEGMENT_SIZE; ++i) {
        cin >> inputLines[i];
    }
    for (int i = 0; i < DIGIT_COUNT; ++i) {
        digitMatrices[i] = extractMatrix(inputLines, i * SEGMENT_SIZE);
    }
    vector<string> numberLines(SEGMENT_SIZE);
    for (int i = 0; i < SEGMENT_SIZE; ++i) {
        cin >> numberLines[i];
    }
    int numDigits = numberLines[0].size() / SEGMENT_SIZE;
    vector<vector<string>> numberMatrices(numDigits);
    for (int i = 0; i < numDigits; ++i) {
        numberMatrices[i] = extractMatrix(numberLines, i * SEGMENT_SIZE);
    }
    vector<unordered_set<int>> possibleDigits(numDigits);
    for (int i = 0; i < numDigits; ++i) {
        possibleDigits[i] = findPossibleDigits(numberMatrices[i], digitMatrices);
        if (possibleDigits[i].empty()) {
            cout << "Invalid" << endl;
            return 0;
        }
    }

    long long totalSum = 0;
    long long factor = 1;

    for (int i = numDigits - 1; i >= 0; --i) {
        long long segmentSum = 0;
        for (int digit : possibleDigits[i]) {
            segmentSum += digit;
        }
        totalSum += segmentSum * factor;
        factor *= DIGIT_COUNT;
    }
    cout << totalSum << endl;
    return 0;
}
