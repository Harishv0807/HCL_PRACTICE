#include <stdio.h>

int main() {
    int num, original, reverse = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        remainder = num % 10;          // Get last digit
        reverse = reverse * 10 + remainder; // Build reverse number
        num = num / 10;                // Remove last digit
    }

    if (original == reverse)
        printf("It is a Palindrome");
    else
        printf("It is not a Palindrome");

    return 0;
}
