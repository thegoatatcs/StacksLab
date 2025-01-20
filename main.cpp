#include <iostream>
#include "Stack.h"
using namespace std;

void printGameState(const Stack &A, const Stack &B, const Stack &C) {
    cout << "Pole A: ";
    A.display();
    cout << endl << "Pole B: ";
    B.display();
    cout << endl << "Pole C: ";
    C.display();
    cout << endl << endl;
}


void moveDisks(int n, Stack &source, Stack &destination, Stack &auxiliary,
               char s, char d, char a, Stack &A, Stack &B, Stack &C)
{    if (n == 1) {
        int disk = source.pop();
        destination.push(disk);
        cout << "Move disk " << disk << " from rod " << s << " to rod " << d << endl;
        printGameState(A, B, C);
        return;
    }

    moveDisks(n - 1, source, auxiliary, destination, s, a, d, A, B, C);

    int disk = source.pop();
    destination.push(disk);
    cout << "Move disk " << disk << " from rod " << s << " to rod " << d << endl;
    printGameState(A, B, C);
    moveDisks(n - 1, auxiliary, destination, source, a, d, s, A, B, C);
}

void solveTowersOfHanoi(int n) {
    Stack A, B, C;
    for (int i = 1; i <= n; i++) {
        A.push(i);
    }

    cout << "Initial Game State:" << endl;
    printGameState(A, B, C);
    moveDisks(n, A, C, B, 'A', 'C', 'B', A, B, C);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of disks must be greater than 0." << endl;
        return 1;
    }

    cout << "Steps to solve the Towers of Hanoi:" << endl;
    solveTowersOfHanoi(n);

    return 0;
}
