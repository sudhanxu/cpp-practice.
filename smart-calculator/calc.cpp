
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Function to get a valid number from the user
double getNumber(string message) {
    double number;

    while (true) {
        cout << message;
        cin >> number;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return number;
        }
    }
}

// Basic mathematical operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double modulus(double a, double b) {
    return fmod(a, b);
}

double calculatePower(double base, double exponent) {
    return pow(base, exponent);
}

double calculateSquareRoot(double number) {
    return sqrt(number);
}

double calculatePercentage(double amount, double percentage) {
    return (amount * percentage) / 100;
}

// Display calculator menu
void showMenu() {
    cout << "\n";
    cout << "========================================\n";
    cout << "          SMART CALCULATOR              \n";
    cout << "========================================\n";

    cout << "  1. Addition\n";
    cout << "  2. Subtraction\n";
    cout << "  3. Multiplication\n";
    cout << "  4. Division\n";
    cout << "  5. Modulus\n";
    cout << "  6. Power\n";
    cout << "  7. Square Root\n";
    cout << "  8. Percentage\n";
    cout << "  9. Exit\n";

    cout << "----------------------------------------\n";
}

int main() {

    int choice;
    double num1, num2, result;

    cout << fixed << setprecision(2);

    cout << "\nWelcome to Smart Calculator!\n";

    while (true) {

        showMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "\nInvalid choice! Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 9) {
            cout << "\nThank you for using Smart Calculator!\n";
            cout << "Have a great day!\n";
            break;
        }

        if (choice < 1 || choice > 9) {
            cout << "\nInvalid choice! Please select 1 to 9.\n";
            continue;
        }

        if (choice == 7) {

            num1 = getNumber("Enter a number: ");

            if (num1 < 0) {
                cout << "\nError: Square root of a negative number is not supported here.\n";
                continue;
            }

            result = calculateSquareRoot(num1);
        }

        else {

            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");

            switch (choice) {

                case 1:
                    result = add(num1, num2);
                    break;

                case 2:
                    result = subtract(num1, num2);
                    break;

                case 3:
                    result = multiply(num1, num2);
                    break;

                case 4:
                    if (num2 == 0) {
                        cout << "\nError: Division by zero is not allowed.\n";
                        continue;
                    }

                    result = divide(num1, num2);
                    break;

                case 5:
                    if (num2 == 0) {
                        cout << "\nError: Modulus by zero is not allowed.\n";
                        continue;
                    }

                    result = modulus(num1, num2);
                    break;

                case 6:
                    result = calculatePower(num1, num2);
                    break;

                case 8:
                    result = calculatePercentage(num1, num2);
                    break;
            }
        }

        if (!isfinite(result)) {
            cout << "\nError: The result is outside the supported numeric range.\n";
            continue;
        }

        cout << "\n----------------------------------------\n";
        cout << "Result: " << result << endl;
        cout << "----------------------------------------\n";
    }

    return 0;
}
