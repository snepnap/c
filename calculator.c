#include <stdio.h>
#include <math.h>

void menu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float power(float a, float b);
float mod(float a, float b);
float squareRoot(float a);

int main() {
    int choice;
    float num1, num2, result;
    int a;
    printf("enter 1 to start the calculator\n");
    scanf("%d",&a);
    while (a==1) {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            continue;
        }
        if (choice == 8) {
            printf("you idiot\n");
            break;
        }
        if (choice >= 1 && choice <= 5) {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
        } else if (choice == 6) {
            printf("Enter number: ");
            scanf("%f", &num1);
        } else if (choice == 7) {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number (mod): ");
            scanf("%f", &num2);
        }
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 3:
                result = multiply(num1, num2);



                printf("Result: %.2f\n", result);
                break;
            case 4:
                if (num2 != 0)
                    result = divide(num1, num2);
                else {
                    printf("Error: Division by zero!\n");
                    break;
                }
                printf("Result: %.2f\n", result);
                break;
            case 5:
                result = power(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 6:
                if (num1 >= 0) {
                    result = squareRoot(num1);
                    printf("Result: %.2f\n", result);
                } else {
                    printf("Error: Cannot take square root of negative number!\n");
                }
                break;
            case 7:
                if ((int)num2 != 0) {
                    result = mod(num1, num2);
                    printf("Result: %.2f\n", result);
                } else {
                    printf("Error: Modulus by zero!\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("do you wnat to cantinue(1/0)\n");
        scanf("%d",&a);
    }
    
    return 0;
}

void menu() {
    printf("===== Advanced Calculator =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Square Root\n");
    printf("7. Modulus\n");
}

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }
float power(float a, float b) { return pow(a, b); }
float mod(float a, float b) { return (int)a % (int)b; }
float squareRoot(float a) { return sqrt(a); }
