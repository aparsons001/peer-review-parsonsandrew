#include "scoreboard.hpp"
#include <iostream>

using namespace std;
//aparsons001 calculates total sum of scores
int calculateTotal(const int scores[], int size) {
    if (scores == nullptr || size <= 0) {
        return 0;
    }

    int total = 0;

    for (int i = 0; i < size; i++) {
        total = total + scores[i];
    }

    return total;
}
// aparsons001 calculates average of scores
double calculateAverage(const int scores[], int size) {
    if (scores == nullptr || size <= 0) {
        return 0.0;
    }

    int total = calculateTotal(scores, size);
    double average = static_cast<double>(total) / size;

    return average;
}
// aparsons001 finds lowest score for sorting
int findLowest(const int scores[], int size) {
    if (scores == nullptr || size <= 0) {
        return 0;
    }

    int lowest = scores[0];

    for (int i = 1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    return lowest;
}
// finds highest score for sorting
int findHighest(const int scores[], int size) {
    if (scores == nullptr || size <= 0) {
        return 0;
    }

    int highest = scores[0];

    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }

    return highest;
}
// aparsons001 finds target score/ index defined by user
int findScore(const int scores[], int size, int target) {
    if (scores == nullptr || size <= 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (scores[i] == target) {
            return i;
        }
    }

    return -1;
}
//aparsons001 sorts scores in ascending order using selection sort
void sortScores(int scores[], int size) {
    if (scores == nullptr || size <= 0) {
        return;
    }

    for (int start = 0; start < size - 1; start++) {
        int lowestIndex = start;

        for (int i = start + 1; i < size; i++) {
            if (scores[i] < scores[lowestIndex]) {
                lowestIndex = i;
            }
        }

        int temp = scores[start];
        scores[start] = scores[lowestIndex];
        scores[lowestIndex] = temp;
    }
}
//aparsons001 prints scores in terminal
void printScores(const int scores[], int size) {
    if (scores == nullptr || size <= 0) {
        cout << "No scores to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << scores[i];

        if (i < size - 1) {
            cout << " ";
        }
    }

    cout << endl;
}
//aparsons validates if size is positive
bool isValidSize(int size) {
    return size > 0;
}
