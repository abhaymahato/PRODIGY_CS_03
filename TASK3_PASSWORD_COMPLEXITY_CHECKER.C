#include <stdio.h>
#include <string.h>
#include <ctype.h>

void passwordcomplexitychecker(char password[]) {
    int length = 0, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    // Check each character in the password
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    length = strlen(password);

    // Assessing the password strength based on the criteria
    if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
        printf("Password Strength: Very Strong\n");
    } else if (length >= 8 && ((hasUpper && hasLower) || (hasUpper && hasDigit) || (hasLower && hasDigit))) {
        printf("Password Strength: Strong\n");
    } else if (length >= 6 && (hasUpper || hasLower) && (hasDigit || hasSpecial)) {
        printf("Password Strength: Moderate\n");
    } else if (length >= 4) {
        printf("Password Strength: Weak\n");
    } else {
        printf("Password Strength: Very Weak\n");
    }

    // Provide suggestions for improvement
    printf("\nSuggestions:\n");
    if (length < 8) printf("- Increase the password length to at least 8 characters.\n");
    if (!hasUpper) printf("- Add at least one uppercase letter (A-Z).\n");
    if (!hasLower) printf("- Add at least one lowercase letter (a-z).\n");
    if (!hasDigit) printf("- Include at least one digit (0-9).\n");
    if (!hasSpecial) printf("- Include at least one special character (e.g., @, #, $, &, etc.).\n");
    else
    printf("- perfect .\n");
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    passwordcomplexitychecker(password);

    return 0;
}
