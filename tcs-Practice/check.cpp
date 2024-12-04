// LCS: time complexity:O(n*M) space:O(min(n,m))
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << "Length of Longest Common Subsequence: " << LCS(str1, str2) << endl;
    return 0;
}


//Longets Increasing Subsequnce:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    vector<int> dp(arr.size(), 1);
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Length of Longest Increasing Subsequence: " << longestIncreasingSubsequence(arr) << endl;
    return 0;
}



//0/1 KnapSack Problem: O(n*W) pace:o(n*W) 
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items and capacity of knapsack: ";
    cin >> n >> W;

    vector<int> weights(n), values(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Maximum value in knapsack: " << knapsack(W, weights, values, n) << endl;
    return 0;
}




//Count Distinct Pairs in an Array with Difference K : time: o(n) space too
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countDistinctPairs(vector<int>& arr, int K) {
    unordered_set<int> elements, visited;
    int count = 0;

    for (int num : arr) {
        if (elements.count(num - K) && !visited.count(num - K)) {
            count++;
            visited.insert(num - K);
        }
        if (elements.count(num + K) && !visited.count(num + K)) {
            count++;
            visited.insert(num + K);
        }
        elements.insert(num);
    }

    return count;
}

int main() {
    int n, K;
    cout << "Enter size of array and value of K: ";
    cin >> n >> K;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Number of distinct pairs with difference " << K << ": " << countDistinctPairs(arr, K) << endl;
    return 0;
}





//Q4: Fibonacci Sequence with Tabulation and Memoization
#include <iostream>
#include <vector>
using namespace std;

// Memoization
int fibMemo(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

// Tabulation
int fibTabulation(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<int> memo(n + 1, -1);
    cout << "Fibonacci (Memoization): " << fibMemo(n, memo) << endl;
    cout << "Fibonacci (Tabulation): " << fibTabulation(n) << endl;

    return 0;
}






//Fermat Primality Test

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function for modular exponentiation
int powerMod(int a, int b, int m) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

bool fermatTest(int n, int k) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    srand(time(0));
    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 3);
        if (powerMod(a, n - 1, n) != 1) return false;
    }
    return true;
}

int main() {
    int n, k;
    cout << "Enter number to check primality and iterations (k): ";
    cin >> n >> k;

    if (fermatTest(n, k)) {
        cout << n << " is probably prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }

    return 0;
}




//Sieve of Eratosthenes and Segmented Sieve

#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    cout << "Primes up to " << n << ":\n";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n = 1000000;
    sieveOfEratosthenes(n);
    return 0;
}
//segmented seive
void segmentedSieve(int l, int r) {
    int limit = sqrt(r) + 1;
    vector<bool> prime(limit + 1, true);
    vector<int> primes;

    // Basic Sieve of Eratosthenes
    for (int i = 2; i * i <= limit; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++) {
        if (prime[i]) primes.push_back(i);
    }

    vector<bool> isPrime(r - l + 1, true);

    for (int p : primes) {
        int start = max(p * p, (l + p - 1) / p * p);
        for (int j = start; j <= r; j += p) {
            isPrime[j - l] = false;
        }
    }

    cout << "Primes in range [" << l << ", " << r << "]:\n";
    for (int i = 0; i < r - l + 1; i++) {
        if (isPrime[i] && (i + l > 1)) cout << (i + l) << " ";
    }
    cout << endl;
}

int main() {
    int l = 1, r = 1000000;
    segmentedSieve(l, r);
    return 0;
}




//happy numbers

#include <iostream>
#include <unordered_set>
using namespace std;

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> visited;
    while (n != 1 && !visited.count(n)) {
        visited.insert(n);
        n = sumOfSquares(n);
    }
    return n == 1;
}

int nextHappyNumber(int n) {
    n++;
    while (!isHappy(n)) n++;
    return n;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Next happy number after " << n << ": " << nextHappyNumber(n) << endl;
    return 0;
}




//Tiling Problem Using Memoization
#include <iostream>
#include <vector>
using namespace std;

int tilingProblem(int n, vector<int>& dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = tilingProblem(n - 1, dp) + tilingProblem(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the size of the board (n): ";
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << "Number of ways to tile the board: " << tilingProblem(n, dp) << endl;

    return 0;
}




// Primality Testing (O(√n) Algorithm)
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is a prime number.\n";
    else
        cout << n << " is not a prime number.\n";

    return 0;
}



//sum-string
#include <iostream>
#include <string>
using namespace std;

bool isSumString(string str, int start, int len1, int len2) {
    string num1 = str.substr(start, len1);
    string num2 = str.substr(start + len1, len2);

    long n1 = stol(num1);
    long n2 = stol(num2);

    string sumStr = to_string(n1 + n2);
    int sumLen = sumStr.length();

    if (start + len1 + len2 + sumLen == str.length()) return true;

    if (start + len1 + len2 + sumLen > str.length()) return false;

    string nextStr = str.substr(start + len1 + len2, sumLen);

    return sumStr == nextStr && isSumString(str, start + len1, len2, sumLen);
}

bool checkSumString(string str) {
    int n = str.length();
    for (int len1 = 1; len1 < n; len1++) {
        for (int len2 = 1; len1 + len2 < n; len2++) {
            if (isSumString(str, 0, len1, len2)) return true;
        }
    }
    return false;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    if (checkSumString(str))
        cout << str << " is a sum-string." << endl;
    else
        cout << str << " is not a sum-string." << endl;

    return 0;
}


//minimum coin chnage
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;
    cout << "Enter the total amount: ";
    cin >> amount;

    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int result = minCoins(coins, amount);
    if (result == -1) {
        cout << "No solution exists!" << endl;
    } else {
        cout << "Minimum number of coins needed: " << result << endl;
    }

    return 0;
}

//climbing stirs
#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n <= 1) return 1;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;

    cout << "Number of ways to climb the stairs: " << climbStairs(n) << endl;

    return 0;
}


//binomial coefficient
#include <iostream>
#include <vector>
using namespace std;

int binomialCoefficient(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "Binomial Coefficient C(" << n << ", " << k << "): " << binomialCoefficient(n, k) << endl;
    return 0;
}


//box stacking problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
    int height, width, depth;
};

bool compare(Box a, Box b) {
    return a.width * a.depth > b.width * b.depth;
}

int maxStackHeight(vector<Box>& boxes) {
    vector<Box> allRotations;
    for (auto box : boxes) {
        allRotations.push_back({box.height, max(box.width, box.depth), min(box.width, box.depth)});
        allRotations.push_back({box.width, max(box.height, box.depth), min(box.height, box.depth)});
        allRotations.push_back({box.depth, max(box.width, box.height), min(box.width, box.height)});
    }

    //sort(allRotations.begin(), allRotations.end(), compare);

    int n = allRotations.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        dp[i] = allRotations[i].height;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (allRotations[i].width < allRotations[j].width &&
                allRotations[i].depth < allRotations[j].depth) {
                dp[i] = max(dp[i], dp[j] + allRotations[i].height);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Box> boxes = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}};
    cout << "Maximum stack height: " << maxStackHeight(boxes) << endl;
    return 0;
}


//edit distance
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
    int height, width, depth;
};

bool compare(Box a, Box b) {
    return a.width * a.depth > b.width * b.depth;
}

int maxStackHeight(vector<Box>& boxes) {
    vector<Box> allRotations;
    for (auto box : boxes) {
        allRotations.push_back({box.height, max(box.width, box.depth), min(box.width, box.depth)});
        allRotations.push_back({box.width, max(box.height, box.depth), min(box.height, box.depth)});
        allRotations.push_back({box.depth, max(box.width, box.height), min(box.width, box.height)});
    }
   // sort(allRotations.begin(), allRotations.end(), compare);

    int n = allRotations.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        dp[i] = allRotations[i].height;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (allRotations[i].width < allRotations[j].width &&
                allRotations[i].depth < allRotations[j].depth) {
                dp[i] = max(dp[i], dp[j] + allRotations[i].height);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Box> boxes = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}};
    cout << "Maximum stack height: " << maxStackHeight(boxes) << endl;
    return 0;
}

//balanced partition problem 
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int num : nums)
        total += num;

    if (total % 2 != 0)
        return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    if (canPartition(nums))
        cout << "Array can be partitioned into two subsets with equal sums." << endl;
    else
        cout << "Array cannot be partitioned into two subsets with equal sums." << endl;

    return 0;
}

//quick sort
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    return 0;
}




//Binary Search vs. Linear Search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return true;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool linearSearch(const vector<int>& arr, int target) {
    for (int num : arr) {
        if (num == target) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    // Binary Search
    if (binarySearch(arr, target))
        cout << "Found using Binary Search.\n";
    else
        cout << "Not found using Binary Search.\n";

    // Linear Search
    if (linearSearch(arr, target))
        cout << "Found using Linear Search.\n";
    else
        cout << "Not found using Linear Search.\n";

    return 0;
}

/*
Efficiency Analysis
Binary Search    Time Complexity: 𝑂(log𝑛)
                Space Complexity: O(1).
Linear Search:   Time Complexity: O(n).
                 Space Complexity: O(1).
 */



//bubble and merge sort
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    vector<int> arrCopy = arr;

    clock_t start = clock();
    bubbleSort(arr);
    clock_t end = clock();
    cout << "Bubble Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    mergeSort(arrCopy, 0, arrCopy.size() - 1);
    end = clock();
    cout << "Merge Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}



//Next Prime Palindrome
#include <iostream>
#include <string>
using namespace std;
bool isPrimeOptimized(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
bool isPalindrome(int n) {
    string s = to_string(n);
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

int nextPrimePalindrome(int n) {
    while (true) {
        n++;
        if (isPalindrome(n) && isPrimeOptimized(n)) return n;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Next prime palindrome: " << nextPrimePalindrome(num) << endl;

    return 0;
}
