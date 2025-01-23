#include <stdio.h>
#include <string.h>

void myStrRev(char* str);

// Function to convert decimal to binary and return as a string
void decimalToBinary(int decimal, char* binary) {
    int i = 0;
    if (decimal == 0) {
        strcpy(binary, "0");
        return;
    }
    while (decimal > 0) {
        binary[i++] = '0' + (decimal % 2);
        decimal /= 2;
    }
    binary[i] = '\0';
    myStrRev(binary);
}

// Function to convert binary to decimal
int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

// Function to convert decimal to octal
void decimalToOctal(int decimal, char* octal) {
    int i = 0;
    if (decimal == 0) {
        strcpy(octal, "0");
        return;
    }
    while (decimal > 0) {
        octal[i++] = '0' + (decimal % 8);
        decimal /= 8;
    }
    octal[i] = '\0';
    myStrRev(octal);
}

// Function to convert octal to decimal
int octalToDecimal(const char* octal) {
    int decimal = 0;
    int length = strlen(octal);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 8 + (octal[i] - '0');
    }
    return decimal;
}

// Function to convert hexadecimal to binary
void hexadecimalToBinary(const char* hex, char* binary) {
    unsigned int hexNum;
    sscanf(hex, "%x", &hexNum);
    
    int i = 0;
    if (hexNum == 0) {
        strcpy(binary, "0");
        return;
    }
    
    while (hexNum > 0) {
        binary[i++] = '0' + (hexNum % 2);
        hexNum /= 2;
    }
    binary[i] = '\0';
    myStrRev(binary);
}

// Function to convert binary to hexadecimal
void binaryToHexadecimal(const char* binary, char* hexadecimal) {
    int length = strlen(binary);
    
    // Pad the binary string with leading zeros to ensure it's a multiple of 4
    int padding = (4 - (length % 4)) % 4;
    
    char paddedBinary[129];
    
    // Initialize paddedBinary with zeros
    for (int i = 0; i < padding; i++) paddedBinary[i] = '0';
    
    strcpy(paddedBinary + padding, binary);

    hexadecimal[0] = '\0'; // Initialize the output string
    
    for (int i = 0; i < length + padding; i += 4) {
        char group[5];
        strncpy(group, paddedBinary + i, 4);
        group[4] = '\0';
        
        if (strcmp(group, "0000") == 0) strcat(hexadecimal, "0");
        else if (strcmp(group, "0001") == 0) strcat(hexadecimal, "1");
        else if (strcmp(group, "0010") == 0) strcat(hexadecimal, "2");
        else if (strcmp(group, "0011") == 0) strcat(hexadecimal, "3");
        else if (strcmp(group, "0100") == 0) strcat(hexadecimal, "4");
        else if (strcmp(group, "0101") == 0) strcat(hexadecimal, "5");
        else if (strcmp(group, "0110") == 0) strcat(hexadecimal, "6");
        else if (strcmp(group, "0111") == 0) strcat(hexadecimal, "7");
        else if (strcmp(group, "1000") == 0) strcat(hexadecimal, "8");
        else if (strcmp(group, "1001") == 0) strcat(hexadecimal, "9");
        else if (strcmp(group, "1010") == 0) strcat(hexadecimal, "A");
        else if (strcmp(group, "1011") == 0) strcat(hexadecimal, "B");
        else if (strcmp(group, "1100") == 0) strcat(hexadecimal, "C");
        else if (strcmp(group, "1101") == 0) strcat(hexadecimal, "D");
        else if (strcmp(group, "1110") == 0) strcat(hexadecimal, "E");
        else if (strcmp(group, "1111") == 0) strcat(hexadecimal, "F");
    }
}

// Function to convert MKS to FPS
void mksToFps(float meters, float kilograms) {
    float feet = meters * 3.28084f; // Convert meters to feet
    float pounds = kilograms * 2.20462f; // Convert kilograms to pounds

    printf("MKS to FPS: %.2f meters -> %.2f feet\n", meters, feet);
    printf("%.2f kg -> %.2f lbs\n", kilograms, pounds);
}

// Function to convert FPS to MKS
void fpsToMks(float feet, float pounds) {
    float meters = feet / 3.28084f; // Convert feet to meters
    float kilograms = pounds / 2.20462f; // Convert pounds to kilograms

    printf("FPS to MKS: %.2f feet -> %.2f meters\n", feet, meters);
    printf("%.2f lbs -> %.2f kg\n", pounds, kilograms);
}

// Function to reverse a string
void myStrRev(char* str) {
    size_t i = 0; // Use size_t for indexing
    size_t j = strlen(str) - 1; // Use size_t for length

    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

// Driver code
int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Hexadecimal to Binary\n");
        printf("6. Binary to Hexadecimal\n");
        printf("7. MKS to FPS Conversion\n");
        printf("8. FPS to MKS Conversion\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        if (choice == 9) {
            printf("Goodbye!\n");
            break;
        }

        char input[100]; // Buffer for user input
        char result[129]; // Buffer for results

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &choice);
                decimalToBinary(choice, result);
                printf("Decimal to Binary: %s\n", result);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", input);
                int binaryResult = binaryToDecimal(input);
                printf("Binary to Decimal: %d\n", binaryResult);
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &choice);
                decimalToOctal(choice, result);
                printf("Decimal to Octal: %s\n", result);
                break;

            case 4:
                printf("Enter an octal number: ");
                scanf("%s", input);
                int octalResult = octalToDecimal(input);
                printf("Octal to Decimal: %d\n", octalResult);
                break;

            case 5:
                printf("Enter a hexadecimal number: ");
                scanf("%s", input);
                hexadecimalToBinary(input, result);
                printf("Hexadecimal to Binary: %s\n", result);
                break;

            case 6:
                printf("Enter a binary number: ");
                scanf("%s", input);
                binaryToHexadecimal(input, result);
                printf("Binary to Hexadecimal: %s\n", result);
                break;

            case 7:
            {
                float meters, kilograms;
                printf("Enter meters: ");
                scanf("%f", &meters);
                printf("Enter kilograms: ");
                scanf("%f", &kilograms);

                mksToFps(meters, kilograms); 
            }
            break;

            case 8:
            {
                float feet, pounds;
                printf("Enter feet: ");
                scanf("%f", &feet);
                printf("Enter pounds: ");
                scanf("%f", &pounds);

                fpsToMks(feet, pounds); 
            }
            break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }



}