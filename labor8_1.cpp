#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція для підрахунку кількості входжень символів 'B', 'A', 'S', 'I', 'C' у рядку
int CountBASICChars(char* str, int& countB, int& countA, int& countS, int& countI, int& countC) {
    countB = countA = countS = countI = countC = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case 'B': countB++; break;
            case 'A': countA++; break;
            case 'S': countS++; break;
            case 'I': countI++; break;
            case 'C': countC++; break;
        }
    }
    return countB + countA + countS + countI + countC; // загальна кількість символів "BASIC"
}

// Функція для заміни кожного входження слова "BASIC" на "Delphi" у рядку
char* ReplaceBASICWithDelphi(char* str) {
    size_t len = strlen(str);
    if (len < 5) return str;  // мінімальна довжина для можливості заміни

    char* tmp = new char[len * 2 + 1];  // виділяємо достатньо місця для нових символів
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len) {
        if (strncmp(&str[i], "BASIC", 5) == 0) {  // якщо знаходимо "BASIC"
            strcat(t, "Delphi");
            t += 6;
            i += 5;
        } else {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t = '\0';
    strcpy(str, tmp);  // копіюємо змінений рядок у початковий
    return tmp;
}

// Головна функція
int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Завдання 1: Підрахунок входжень символів "BASIC"
    int countB, countA, countS, countI, countC;
    int totalBASICChars = CountBASICChars(str, countB, countA, countS, countI, countC);
    cout << "\nКількість входжень кожного символу з \"BASIC\":\n";
    cout << "B: " << countB << "\n";
    cout << "A: " << countA << "\n";
    cout << "S: " << countS << "\n";
    cout << "I: " << countI << "\n";
    cout << "C: " << countC << "\n";
    cout << "Загальна кількість символів з \"BASIC\": " << totalBASICChars << endl;

    // Завдання 2: Заміна "BASIC" на "Delphi"
    char* dest = ReplaceBASICWithDelphi(str);
    cout << "\nModified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;  // очищення виділеної пам'яті
    return 0;
}