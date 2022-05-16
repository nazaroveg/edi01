// edi_01.cpp 
//nazaroveg@yandex.ru

 #include <iostream>
 #include <fstream>
 void plus(int*&, int);

int main()
{
	//setlocale(LC_ALL, "RUS"); 

	std::ifstream fin;
	fin.open("in.txt");
	if (fin.is_open())
	{
		int one = 0;
		fin >> one;
		int* n =  new int[one];
		
		for (int i = 0; i < one; ++i)
		{
			fin >> *n;
			//std::cout << *n;
		}
		int two = 0;
		fin >> two;
		int* m = new int[two];
		
		for (int i = 0; i < two; ++i)
		{
			fin >> *m;
			//std::cout << *m;
		}
		fin.close();
		plus(n, one);

		for (int i = 0; i < one; ++i)
		{
			std::cout << n[i];
		}


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
	for (int i = 0; i < one; ++i)
	{
		tmp[i] = n[i - 1];
	}
	tmp[one - 1] = a;
	


	delete[]n;
	n = tmp;

}
