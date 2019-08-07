#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//Функция удаления лишних символов(скобок, плюсов, минусов)
void removeSymbols(int count, string numbers[], string processed[]) {
    string temp;
    int pos;

    for (int i = 0; i < count; i++) {
        processed[i] = numbers[i];
    }

    for (int i = 0; i < count; i++) {
        temp = processed[i];
        pos = 0;
        while (pos != -1) {
            pos = temp.find(" ");
            if (pos != -1) temp.erase(pos, 1);
        }
        processed[i] = temp;
    }

    for (int i = 0; i < count; i++) {
        temp = processed[i];
        pos = 0;
        while (pos != -1) {
            pos = temp.find("+");
            if (pos != -1) temp.erase(pos, 1);
        }
        processed[i] = temp;
    }

    for (int i = 0; i < count; i++) {
        temp = processed[i];
        pos = 0;
        while (pos != -1) {
            pos = temp.find("-");
            if (pos != -1) temp.erase(pos, 1);
        }
        processed[i] = temp;
    }

    for (int i = 0; i < count; i++) {
        temp = processed[i];
        pos = 0;
        while (pos != -1) {
            pos = temp.find("(");
            if (pos != -1) temp.erase(pos, 1);
        }
        processed[i] = temp;
    }

    for (int i = 0; i < count; i++) {
        temp = processed[i];
        pos = 0;
        while (pos != -1) {
            pos = temp.find(")");
            if (pos != -1) temp.erase(pos, 1);
        }
        processed[i] = temp;
    }
}

int findText(char *s, char *c, int n)
{
    // s - В какой строке искать
    // c - Какую строку искать
    int i, j;
    int lenC, lenS;

    for (lenC = 0; c[lenC]; lenC++);
    for (lenS = 0; s[lenS]; lenS++);

    for (i = 0; i <= lenS - lenC; i++)
    {
        for (j = 0; s[i + j] == c[j]; j++);

        if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) return i;
        if (j == lenC)
        if (n - 1) n--;
        else return i;
    }
    //Иначе вернем -1 как результат отсутствия подстроки
    return -1;
}

int main()
{
    int countOfNums;
    int countOfTemplates;
    string numsBase[1000];
    string templatesBase[1000];
    string processedNumsBase[1000];
    string processedTemplatesBase[1000];

    cin >> countOfNums;
    //Заполняем базу номеров
    for (int i = 0; i < countOfNums; i++) {
        string temp;
        cin >> temp;
        while (temp.length() > 100) {
            cout << "The length of number > 100! Try again." << "\n";
            cin >> temp;
        }
        numsBase[i] = temp;
    }

    cout << "///////////\n";

    cout << "Enter number of templates: ";
    cin >> countOfTemplates;

    //Зполняем базу шаблонов
    for (int i = 0; i < countOfTemplates; i++) {
        string temp;
        cin >> temp;
        while (temp.length() > 100) {
            cout << "The length of number > 100! Try again." << "\n";
            cin >> temp;
        }
        templatesBase[i] = temp;
    }

    cout << "UDal \n";

    //Убираем скобки, плюсы и т.д. у номеров
    removeSymbols(countOfNums, numsBase, processedNumsBase);

    cout << "processedNumsBase[]: \n";
    for (int i = 0; i < countOfNums; i++) {
        cout << processedNumsBase[i] << "\n";
    }

    removeSymbols(countOfTemplates, templatesBase, processedTemplatesBase);

    cout << "processedTemplatesBase[]: \n";
    for (int i = 0; i < countOfNums; i++) {
        cout << processedTemplatesBase[i] << "\n";
    }

    cout << "Processing numbers... \n";

    for (int i = 0; i < countOfNums; i++) {
        cout << "i: " << i << "\n";
        string number = processedNumsBase[i];
        cout << "number: " << number << "\n";

        for (int j = 0; j < countOfTemplates; j++) {
            cout << "j: " << j << "\n";
            string currTemplate = processedTemplatesBase[j];
            cout << "currTemplate: " << currTemplate << "\n";
            int pos;
            pos = currTemplate.find("X");
            if (pos != -1) currTemplate.erase(pos, currTemplate.length() - pos);
            cout << "currTemplate: " << currTemplate;

            //Преобразовываем переменные в тип char*
            char *chNumber = new char[number.length() + 1];
            strcpy(chNumber, number.c_str());
            char *chTemplate = new char[currTemplate.length() + 1];
            strcpy(chTemplate, currTemplate.c_str());

            //Тут работаем с переменной.
            if (findText(chNumber, chTemplate, 1) != -1 ) {
                cout << "EEEEeeeee" << "\n";
            }

            //Не забываем очистить память:
            delete [] chNumber;
            delete [] chTemplate;

        }
    }


    return 0;
}
