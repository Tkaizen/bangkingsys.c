#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10

// Structure for a Bank Account
typedef struct {
    char account_holder[100];
    float account_balance;
} BankAccount;

// Array to store bank accounts
BankAccount accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function to create a new account
void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Sorry, the bank is at full capacity.\n");
        return;
    }

    printf("Enter the account holder's name: ");
    scanf("%s", accounts[account_count].account_holder);
    accounts[account_count].account_balance = 0.0f;
    printf("Account created successfully for %s.\n", accounts[account_count].account_holder);
    account_count++;
}

// Function to find an account by account holder's name
BankAccount* find_account(const char* account_holder) {
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account_holder, account_holder) == 0) {
            return &accounts[i];
        }
    }
    return NULL;
}

// Function to deposit money into an account
void deposit_money() {
    char name[100];
    float amount;

    printf("Enter account holder's name: ");
    scanf("%s", name);

    BankAccount* account = find_account(name);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        account->account_balance += amount;
        printf("Deposited %.2f. New balance: %.2f\n", amount, account->account_balance);
    } else {
        printf("Deposit amount must be positive.\n");
    }
}

// Function to withdraw money from an account
void withdraw_money() {
    char name[100];
    float amount;

    printf("Enter account holder's name: ");
    scanf("%s", name);

    BankAccount* account = find_account(name);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= account->account_balance) {
        account->account_balance -= amount;
        printf("Withdrew %.2f. New balance: %.2f\n", amount, account->account_balance);
    } else if (amount > account->account_balance) {
        printf("Insufficient funds.\n");
    } else {
        printf("Withdrawal amount must be positive.\n");
    }
}

// Function to check the account balance
void check_balance() {
    char name[100];

    printf("Enter account holder's name: ");
    scanf("%s", name);

    BankAccount* account = find_account(name);
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Current balance for %s: %.2f\n", account->account_holder, account->account_balance);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Welcome to the Bank ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("Thank you for using the bank! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
