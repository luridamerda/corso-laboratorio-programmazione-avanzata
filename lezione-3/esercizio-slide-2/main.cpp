#include <iostream>
#include <complex>

void printMenu() {
    std::cout << "Complex Number Calculator\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::complex<double> num1, num2, result;
    double real, imag;
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 5) {
            break;
        }

        std::cout << "Enter the real and imaginary part of the first complex number: ";
        std::cin >> real >> imag;
        num1 = std::complex<double>(real, imag);

        std::cout << "Enter the real and imaginary part of the second complex number: ";
        std::cin >> real >> imag;
        num2 = std::complex<double>(real, imag);

        switch (choice) {
            case 1:
                result = num1 + num2;
                std::cout << "Result: " << result << "\n";
                break;
            case 2:
                result = num1 - num2;
                std::cout << "Result: " << result << "\n";
                break;
            case 3:
                result = num1 * num2;
                std::cout << "Result: " << result << "\n";
                break;
            case 4:
                if (num2 == std::complex<double>(0, 0)) {
                    std::cout << "Error: Division by zero\n";
                } else {
                    result = num1 / num2;
                    std::cout << "Result: " << result << "\n";
                }
                break;
            default:
                std::cout << "Invalid option\n";
                break;
        }
    }

    return 0;
}