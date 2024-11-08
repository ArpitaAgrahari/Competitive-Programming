#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;

double calculateY(double x, const vector<int>& A, const vector<int>& B) {
    double y = 0;
    for (int i = 0; i < A.size(); ++i) {
        y += sin(A[i] * x + B[i]);
    }
    return y;
}

vector<int> findPeaks(const vector<double>& heights) {
    vector<int> peaks;
    for (int i = 1; i < heights.size() - 1; ++i) {
        if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) {
            peaks.push_back(i);
        }
    }
    return peaks;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    const int numSamples = 100000; // Increased resolution
    vector<double> heights(numSamples);

    // Calculate y-values for each x in the range [0, 2*pi]
    for (int i = 0; i < numSamples; ++i) {
        double x = i * (2 * PI / (numSamples - 1));
        heights[i] = calculateY(x, A, B);
    }

    // Find peaks in the sampled heights
    vector<int> peaks = findPeaks(heights);

    if (peaks.size() < 2) {
        cout << "No valid valleys" << endl;
        return 0;
    }
    double maxValleyWidth = 0;
    int bestValleyIndex = -1;

    for (int i = 0; i < peaks.size() - 1; ++i) {
        double width = (peaks[i + 1] - peaks[i]) * (2 * PI / (numSamples - 1));
    
        if (width > maxValleyWidth) {
            maxValleyWidth = width;
            bestValleyIndex = i;
        }
    }

    // Output the 1-based index of the widest valley
    cout << bestValleyIndex + 1 << endl;

    return 0;
}
