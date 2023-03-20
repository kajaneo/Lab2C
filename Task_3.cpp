#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void Sort(list<string>& l) { //������� ���������� �� �����������
    int n = l.size(); //������ ���������� ������, ��� ��� �� ����� ����� ��� ���������
    int n1 = n - 1;
    for (int i = 0; i < n1; i++) { //���������� �� ������ ������ ������ ���� ��� �� ����������
        auto it1 = l.begin();
        auto it2 = next(it1, 1); 

        
        for (int j = 0; j < n1 - i; j++) {
            // Convert to integers and compare
            int num1 = stoi(it1->substr(0, it1->find(" "))); //���������� ��������� �� �������� �� �������
            int num2 = stoi(it2->substr(0, it2->find(" ")));//� ��������������� �� � �����

            if (num1 > num2) { //���� ��������� ����� � ������ ���� ������ ������ ������, 
                swap(*it1, *it2); //�� ������ �� �������
            }

            it1++; //���� ������
            it2++;
        }
    }
}


int main() {
    list<string> l; //������� ������ ���� ������
    string str; //�������� ������
    while (getline(cin, str)) {//���� ���������� ������ ������
    if (str == "end") break; //��� ����� ��������� ������� ��� � �����������
        l.push_back(str); //������ ��������� ������� ���� � ����� ������
    }

    Sort(l); //���� �����������

    for (auto it = l.begin(); it != l.end(); it++) { //������� ���������� ������
        cout << (*it) << " ";
    }
}