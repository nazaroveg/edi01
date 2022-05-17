// edi_01.cpp 
//nazaroveg@yandex.ru

 #include <iostream>
 #include <fstream>
 void plus(int*&, int);

 void minus(int*&, int);
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
			fin >> n[i];
			//std::cout << *n << "\n";		//проверка+
		}
		int two = 0;
		fin >> two;
		int* m = new int[two];
		
		for (int i = 0; i < two; ++i)
		{
			fin >> m[i];
			//std::cout << m[i] << "\n";   //+
		}

		fin.close();

		minus(m, two);
		plus(n, one);
		
		std::ofstream fout;
		fout.open("out.txt");
		fout << two << "\n";
		for (int i = 0; i < two; ++i)
		{
			fout << m[i] << " ";
		}
		fout << " \n" << one << "\n";
		for (int i = 0; i < one; ++i)
		{
			fout << n[i] << " ";
		}
		fout.close();
		
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
	//std::cout << n[one-1];
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


