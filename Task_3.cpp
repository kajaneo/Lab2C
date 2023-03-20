#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void Sort(list<string>& l) { //функция сортировки по возрастанию
    int n = l.size(); //размер введенного списка, так как мы точно можем его посчитать
    int n1 = n - 1;
    for (int i = 0; i < n1; i++) { //проходимся по каждой строке списка пока они не закончатся
        auto it1 = l.begin();
        auto it2 = next(it1, 1); 

        
        for (int j = 0; j < n1 - i; j++) {
            // Convert to integers and compare
            int num1 = stoi(it1->substr(0, it1->find(" "))); //составляем подстроку из символов до пробела
            int num2 = stoi(it2->substr(0, it2->find(" ")));//и преобразовываем ее в число

            if (num1 > num2) { //если введенный класс в строке выше больше класса нижней, 
                swap(*it1, *it2); //то меняем их местами
            }

            it1++; //едем дальше
            it2++;
        }
    }
}


int main() {
    list<string> l; //создали список типа строки
    string str; //объявили строку
    while (getline(cin, str)) {//цикл заполнения списка вводом
    if (str == "end") break; //это чтобы проверить рабочий код в компиляторе
        l.push_back(str); //каждая введенная строчка идет в конец списка
    }

    Sort(l); //идем сортировать

    for (auto it = l.begin(); it != l.end(); it++) { //выводим нормальный список
        cout << (*it) << " ";
    }
}