// edi_01.cpp 
//nazaroveg@yandex.ru

 #include <iostream>
 #include <fstream>
#include <string>
 void plus(int*, int);
 void minus(int*, int);
 void fwrite(std::ofstream& fout, int*, int);
 static int counter = 0; //счетчик записи

int main()
{
	setlocale(LC_ALL, "RUS"); 
	std::ifstream fin;
	fin.open("in.txt");
	if (fin.is_open())
	{	

		int one = 0;
		fin >> one;

		
		if (one <= 0)
		{
			std::cout << "Ошибка: недопустимый размер первого массива " << one << '\n';
			return -1;
			
		}
		int* n = new int[one]();
		if (n == nullptr)
		{
			std::cout << "Ошибка: невозможно выделить массив, int размера " << one << '\n';
			return -2;
		}
		for (int i = 0; i < one; ++i)
		{
				fin >> n[i];
		}


		int two = 0;
		fin >> two;
		if (one <= 0)
		{
			std::cout << "Ошибка: недопустимый размер второго массива  " << two << '\n';
			return -3;

		}

		int* m = new int[two]();
		if (m == nullptr)
		{
			std::cout << "Ошибка: невозможно выделить массив, int размера " << two << '\n';
			return -4;
		}

		
			for (int j = 0; j < two; ++j)
			{
				fin >> m[j];
			}
		
		fin.close();
		
		   
			plus(n, one);
			minus(m, two);

			std::ofstream fout;
			fout.open("out.txt");
			if (!fout.is_open()) {
				std::cout << "Error: unable to open file " << "out.txt" << " for writing" << '\n';
				return -5;
			}
			fwrite(fout, m, two);
			fwrite(fout, n, one);
			fout.close();

		delete[]n;
		delete[]m;

	}
	else
	{
		std::cerr << "ошибка! файл не найден";
		return 1;
	}
	return 0;
}

void plus(int* n, int one)                
{

	int a = n[0];

	for (int i = 1; i < one; ++i)
	{
		n[i-1] = n[i];
	}
	n[one-1] = a;

}
void minus(int* m, int two)
{
	int a = m[two-1];
	
	for (int i = two-1; i>0; --i)
	{
		m[i] = m[i-1];
	}
	m[0] = a;
}
void fwrite(std::ofstream& fout, int* arr, int size)
{
	fout << size << "\n";
	for (int i = 0; i < size; ++i)
	{
		fout << arr[i] << " ";
	}
	fout << "\n";
}
	

	


