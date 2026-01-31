#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h> 
class BankingSystem {
private:
    std::string customerName;
    double balance;

    static const int MAX_HISTORY = 10;
    std::string history[MAX_HISTORY];
    int head = 0;   // Oldest index
    int count = 0;  // Total items currently in history

public:
    BankingSystem(std::string name, double initialDeposit)
        : customerName(std::move(name)), balance(initialDeposit) {
        addHistory("Account opened with $" + std::to_string((int)initialDeposit));
    }

    void addHistory(const std::string& action) {
        int index = (head + count) % MAX_HISTORY;
        if (count < MAX_HISTORY) {
            history[index] = action;
            count++;
        }
        else {
            // Overwrite oldest and move head forward
            history[head] = action;
            head = (head + 1) % MAX_HISTORY;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addHistory("Deposited: $" + std::to_string((int)amount));
            std::cout << "\n[SUCCESS] Deposit Successful! Current Balance: $" << balance << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "\n[ERROR] Insufficient Balance!" << std::endl;
        }
        else if (amount > 0) {
            balance -= amount;
            addHistory("Withdrew: $" + std::to_string((int)amount));
            std::cout << "\n[SUCCESS] Withdrawal Successful!" << std::endl;
        }
    }

    void displayInfo() const {
        std::cout << "\n========= ACCOUNT DETAILS =========" << std::endl;
        std::cout << "Customer: " << customerName << std::endl;
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Recent Transactions (Last 10):" << std::endl;

        for (int i = 0; i < count; i++) {
            int index = (head + i) % MAX_HISTORY;
            std::cout << " " << (i + 1) << ". " << history[index] << std::endl;
        }
        std::cout << "===================================" << std::endl;
    }
};

int main() {
    std::string name;
    double initial;

    std::cout << "Enter Customer Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Initial Deposit: ";
    std::cin >> initial;

    BankingSystem myAccount(name, initial);

    int choice;
    do {
        // Universal Screen Clear (ANSI)
        std::cout << "\033[2J\033[H";

        std::cout << "================================\n";
        std::cout << "         BANKING SYSTEM         \n";
        std::cout << "================================\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Display Info\n4. Exit\n";
        std::cout << "--------------------------------\nChoice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            double amt;
            std::cout << "Enter amount: "; std::cin >> amt;
            myAccount.deposit(amt);
            std::cout << "\nPress any key to return to menu...";
            _getch(); // Using underscore version for modern compilers
        }
        else if (choice == 2) {
            double amt;
            std::cout << "Enter amount: "; std::cin >> amt;
            myAccount.withdraw(amt);
            std::cout << "\nPress any key to return to menu...";
            _getch();
        }
        else if (choice == 3) {
            myAccount.displayInfo();
            std::cout << "\nPress any key to return to menu...";
            _getch();
        }
    } while (choice != 4);

    return 0;
}