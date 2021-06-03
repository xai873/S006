// S006.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
		char s[255];
		char s1[255];
		char f[] = "%s";
		char fd[] = "%d\n";

		__asm {
			lea eax, s
			push eax
			lea ecx, f
			push ecx
			call scanf
			add esp, 8

			lea eax, s1
			push eax
			lea ecx, f
			push ecx
			call scanf
			add esp, 8

			lea eax, s
			dec eax
			mov ecx, 0
			dec ecx

			cnts :
			inc eax
				inc ecx
				cmp[eax], 0
				jnz cnts

				lea ebx, s1
				dec ebx
				mov edx, 0
				dec edx

				cntsub :
			inc ebx
				inc edx
				cmp[ebx], 0
				jnz cntsub


				push edx
				cmp edx, ecx
				jg end1
				cmp edx, 0
				jz end1

				dec eax
				dec ebx

				f1 :
			cmp edx, 0
				jz end2
				cmp ecx, 0
				jz end1
				push ecx
				mov ch, [eax]
				mov cl, [ebx]
				cmp ch, cl
				pop ecx
				jz skip
				pop edx
				lea ebx, s1
				add ebx, edx
				push edx
				dec ebx
				push ecx
				mov ch, [eax]
				mov cl, [ebx]
				cmp ch, cl
				pop ecx
				jz skip
				dec eax
				dec ecx
				jmp f1
				skip :
			dec eax
				dec ebx
				dec ecx
				dec edx
				jmp f1

				end1 :
			mov ecx, -1
				end2 :
				push ecx
				lea ecx, fd
				push ecx
				call printf
				add esp, 12

		}
	}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
