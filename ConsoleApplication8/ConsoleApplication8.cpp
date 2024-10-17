#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    string file_name;
    cout << "\tЗадание 1 и 2\n\nВведите имя файла: ";
    cin >> file_name;
    FILE* file = fopen(file_name.c_str(), "r");
    if (file != NULL) {
        char letters[100]{ "\0" };
        fread(letters, sizeof(letters[1]), 100, file);
        cout << "\nСодержание:\n" << letters << endl << endl;
        fclose(file);
    }
    else
        cout << "\nТакого файла не существует" << endl << endl;

    string OUT, IN;
    cout << "\tЗадание 3\n\nВведите имя первого файла: ";
    cin >> OUT;
    cout << "Введите имя второго файла: ";
    cin >> IN;
    FILE* out = fopen(OUT.c_str(), "r");
    FILE* in = fopen(IN.c_str(), "a");
    if (out != NULL and in != NULL) {
        char buffer[100]{ "\0" };
        fread(buffer, sizeof(buffer[1]), 100, out);
        fwrite(buffer, sizeof(char), sizeof(buffer), in);
        fclose(out);
        fclose(in);
    }
    else
        cout << endl << "Файлы пустые" << endl;

    return 0;
}