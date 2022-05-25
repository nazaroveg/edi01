// edi_01.cpp 
//nazaroveg@yandex.ru

 #include <iostream>
 #include <fstream>
#include <string>
 void plus(int*, int);
 void minus(int*, int);
 void fwrite(int*, int);
 static int counter = 0; //счетчик записи

int main()
{
	setlocale(LC_ALL, "RUS"); 
	std::ifstream fin;
	fin.open("in.txt");
	if (fin.is_open())
	{	

		int one = 0;
		int two = 0;
		
		fin >> one;
		int* n = new int[one]();
		if (one > 0)
		{
			for (int i = 0; i < one; ++i)
			{
				fin >> n[i];
			}
		}
		else
		{
			delete[]n;
			fin.close();
			std::cout << "размер массива не может быть меньше 1";
			return 1;
		}

		fin >> two;
		int* m = new int[two]();
		
		if (two > 0)
		{
			for (int j = 0; j < two; ++j)
			{
				fin >> m[j];
			}
		}
		else
		{
			delete[]m;
			fin.close();
			std::cout << "размер массива не может быть меньше 1";
			return 1;
		}

		fin.close();
		
		
			plus(n, one);
			minus(m, two);
			fwrite(m, two);
			fwrite(n, one);

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
void fwrite(int* arr, int size)
{
	if (counter == 0)
	{
		std::ofstream fout;
		fout.open("out.txt");
		if (fout.is_open())
		{
			fout << size << "\n";
			for (int i = 0; i < size; ++i)
			{
				fout << arr[i] << " ";
			}
			fout << "\n";
		}
		else
		{
			std::cerr << "ошибка! файл для записи не отрыт";
			return;
		}
		fout.close();
		
	}

	else
	{
		std::ofstream fout;
		fout.open("out.txt", std::ios::app);
		if (fout.is_open())
		{
			fout << size << "\n";
			for (int i = 0; i < size; ++i)
			{
				fout << arr[i] << " ";
			}
			fout << "\n";
		}
		else
		{
			std::cerr << "ошибка! файл для записи не отрыт";
			return;
		}
		fout.close();
		
	}
	counter++;
}


