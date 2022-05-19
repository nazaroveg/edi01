// edi_01.cpp 
//nazaroveg@yandex.ru

 #include <iostream>
 #include <fstream>
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
		fin >> one;
		int* n =  new int[one]();
		
		for (int i = 0; i < one; ++i)
		{
			fin >> n[i];
		}
			
		    int two = 0;
			fin >> two;
			int* m = new int[two]();

			for (int i = 0; i < two; ++i)
			{
				fin >> m[i];
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
		}
		fout.close();
		
	}
	counter++;
}