#include <stdio.h>
// implement the factorial using recursion
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}
// implement factorial without recursion
int factorial_without_recursion(int n) {
    int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

// implement tower of hanoi using recursion
void tower_of_hanoi(int n, char source, char destination, char temp) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
    } else {
        tower_of_hanoi(n - 1, source, temp, destination);
        printf("Move disk %d from %c to %c\n", n, source, destination);
        tower_of_hanoi(n - 1, temp, destination, source);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The factorial of %d is %d\n", n, factorial(n));
    printf("The factorial of %d is %d\n", n, factorial_without_recursion(n));
    // take number of disks from user
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("The tower of hanoi of %d disks is:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}
