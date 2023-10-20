#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char username[30];
    char password[30];
} User;

typedef struct {
    bool active;
} FlagStruct;

typedef union {
    User user;
    FlagStruct flagStruct;
} u1;

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

int loginUser(u1 u1) {
    char username[30];
    char password[30];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (u1.flagStruct.active) {
        for (int i = 0; i < numUsers; i++) {
            if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
                printf("Login successful!\n");
                return 1;
            }
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    char choice[10];
    u1 u1;

    while (1) {
        printf("Choice: Register or Login? ");
        scanf("%s", choice);

        if (strcmp(choice, "register") == 0) {
            char status[10];
            printf("Enter your status (true or 1 for active , false or 0 for inactive): ");
            scanf("%s", status);

        if (strcmp(status, "true") == 0 || strcmp(status, "1") == 0) {
                u1.flagStruct.active = true;
            }else if (strcmp(status, "false") == 0 || strcmp(status, "0") == 0) {
                 u1.flagStruct.active = false;
             }else {
                printf("your status is Undefined and it will be by default false \n ");
                u1.flagStruct.active = false;
            }
            registerUser();
        } else if (strcmp(choice, "login") == 0 && u1.flagStruct.active) {
            loginUser(u1);
        } else {
            printf(" You are inactive Please go to register and Change the status.\n");
            continue;
        }
    }

    return 0;
}
