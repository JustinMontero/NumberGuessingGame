#include <iostream>
#include <cstdlib>
#include <ctime>

void welcome_message(){

    std::cout << "Welcome to the guessing number game \n";
    std::cout << "Guess a number between 0 - 10\n";
}

void number_check() {
    srand(time(0));    
    int randomNum = rand() % 100000;

    int g_number = 0, attempts = 0;  

    do {
        std::cout << "Input your guess below: "; 

        // Input validation loop
        while (!(std::cin >> g_number)) { // Check if input fails
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(10000, '\n'); // Ignore invalid input
            std::cout << "Invalid input! Please enter a number: ";
        }

        attempts++;  // Increase attempt count

        if (g_number < randomNum){
            std::cout << "Too low! Try again.\n";
        } 
        if (g_number > randomNum){
            std::cout << "Too high! Try again.\n";
        }

    } while (g_number != randomNum);

    std::cout << "Great, you got it!!\n";
    std::cout << "Number of attempts: " << attempts << "\n";  
}




int main() {
    char playAgain;

    do {
        welcome_message();
        number_check();

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); // Keep playing if user says "y" or "Y"

    std::cout << "Thanks for playing!\n";
    return 0;
}
