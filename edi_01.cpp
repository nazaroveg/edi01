// edi_01.cpp 
//nazaroveg@yandex.ru

 #include <iostream>
 #include <fstream>
 void plus(int*&, int);
 void minus(int*&, int);
 void fwrite(int*, int);

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
			plus(n, one);
			
		
		    int two = 0;
			fin >> two;
			int* m = new int[two]();

			for (int i = 0; i < two; ++i)
			{
				fin >> m[i];
			}
			minus(m, two);
			fwrite(m, two);
			fwrite(n, one);

			fin.close();
			

		delete[]n;
		delete[]m;
	}
	else
	{
		std::cerr << "ошибка! файл не найден";
	}
	return 0;
}

void plus(int*& n, int one)
{
	int* tmp = new int[one];
	int a = n[0];
	
	for (int i = 1; i < one; ++i)
	{
		
		tmp[i-1] = n[i];
	}
	tmp[one - 1] = a;
	


	delete[]n;
	n = tmp;

}
void minus(int*& m, int two)
{
	int* tmp1 = new int[two];
	int a = m[two-1];
	
	for (int i = 0; i < two-1; ++i)
	{

		tmp1[i + 1] = m[i];
	}
	tmp1[0] = a;



	delete[]m;
	m = tmp1;



}
void fwrite(int* arr, int size)
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
