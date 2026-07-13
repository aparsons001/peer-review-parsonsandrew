#include "scoreboard.hpp"
#include <iostream>

using namespace std;

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

double calculateAverage(const int scores[], int size) {
    if (scores == nullptr || size <= 0) {
        return 0.0;
    }

    int total = calculateTotal(scores, size);
    double average = static_cast<double>(total) / size;

    return average;
}

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

bool isValidSize(int size) {
    return size > 0;
}
