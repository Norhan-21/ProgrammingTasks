#include <stdio.h>
#include <string.h>

typedef struct {
    char username[30];
    char password[30];
} User;

User users[100];
int numUsers = 0;

void registerUser() {
    if (numUsers >= 100) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful!\n");
}

int loginUser() {
    char username[30];
    char password[30];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    char choice[10];


    while (1) {
     printf(" choice register or login: ");
    scanf("%s", choice);

    if (strcmp(choice, "register") == 0) {
        registerUser();
    } else if (strcmp(choice, "login") == 0) {
        loginUser();
    } else {
        printf("Please choose 'register' or 'login'.\n");
    }
    }
    return 0;
}
