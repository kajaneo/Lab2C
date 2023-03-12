#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>



//������ �50
int main() {
	int N = 10; //��������� ���������� ����
	int t; // ��������� ���������� (�������� ����), ����� ������� ����� ����� ��������� �������

	std::queue<int> a; //��������� � ��������� ������� (�������� ����) ��� ������� ������
	for (int i = 0; i < N/2; ++i) 
		std::cin >> t, a.push(t);

	std::queue<int> b; //��������� � ��������� ������� (�������� ����) ��� ������� ������
	for (int i = 0; i < N/2; ++i) 
		std::cin >> t, b.push(t);

	int go = 0;
	while (!a.empty() && !b.empty() && go < 100000) //�������, ��� ������� ���� �� �������������
	{
		int aa = a.front(); //����� ������� ����� ������� ������ �� �������
		int	bb = b.front(); //����� ������� ����� ������� ������ �� �������
	
		if (aa == 0 && bb == 9) { //���� � ������� 0 � � ������� 9, ��
			a.push(aa); //������ ������� ����� ������� ������ � ����� ������� ������� ������
			a.push(bb); //������ ������� ����� ������� ������ � ����� ������� ������� (�� ���� ��� ����� ������)
		}

		else if (aa == 9 && bb == 0) { //���� � ������� 9 � � ������� 0, ��
			b.push(aa); //������ ������� ����� ������� ������ � ����� ������� ������� ������
			b.push(bb); //������ ������� ����� ������� ������ � ����� ������� ������� (�� ���� ��� ���� ������)
		}

		else if (aa > bb) { //���� ����� ���� �������
			a.push(aa);
			a.push(bb);
		}

		else if (bb > aa) { // ���� ������ ���� �������
			b.push(aa);
			b.push(bb);
		}

		a.pop(); //������� ������ ������� (������� ������ ��� ���������) ������� ������� ������
		b.pop(); //������� ������ ������� ������� ������� ������
		go++; //����������� ���
	}

		if (a.empty()) //���� � ������� ��� ����, �� �����, ��� ������� ������
			std::cout << "second " << go;

		else if (b.empty()) //���� � ������� ��� ����, �� �����, ��� ������� ������
			std::cout << "first " << go; 

		else
			std::cout << "botva"; //���� �� ������ ������ ������, �� ����� �� �������
	}
	/*if (N > 100000)
		std::cout << "botva";*/
