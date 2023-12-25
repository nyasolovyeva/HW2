#include <iostream>
#include <vector>
#include <algorithm>


/*Task 1*/
void CvC()
{
	//1
	const float a = 7;
	const float* const ptr1 = &a;

	//2
	typedef long int b_t;
	b_t t = 1;
	b_t* ptr2 = &t;

	//3
	double b = 8;
	double* ptr3 = &b;

	//4
	const short int c = 9;
	const short int* ptr4 = &c;

	//5
	typedef const float d_t;
	d_t d = 10;
	d_t* const ptr5 = &d;

	//6
	typedef char s_t;
	s_t s = 3;
	s_t* ptr6 = &s;

	//7
	double f = 2;
	double* const ptr7 = &f;

	//8
	typedef unsigned int r_t;
	r_t r = 2;
	r_t* const ptr8 = &r;
}



/*Task 2*/
double* createArray(int size)
{
	double* arr = new double[size];
	return arr;
}


void fillArray(double* arr, int size)
{
	std::cout << "Enter values for your massive: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void showArray(double* arr, int size)
{
	std::cout << "Here you can see elements of ypur massive: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void releaseArray(double* arr)
{
	delete[] arr;
}



/*Task 3*/
void number12(int* array, int size) // функция, которая меняет значения четных и нечетных ячеек массива
{
	for (int i = 0; i < size; i += 2) // Каждый раз берём числа не подряд, а через одного. Идём по чётным ячейкам, начиная нуля
	{
		if (i + 1 < size) // условие для того, чтобы не выйти за массив
		{
			// рассматриваем два числа подряд и меняем местами
			int temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
		}
	}
}



/*Task 4*/
// функция для заполнения массива
void fill(int** array4, int row, int col)
{
	for (int i = 0; i < row; i++) // перебор строчек
	{
		for (int j = 0; j < col; j++) // перебор столбцов
		{
			array4[i][j] = rand() % 41 + 10; // генерация рандомных чисел от 10 до 50
		}
	}
}

// функция для показа на экран
void show(int** array4, int row, int col)
{
	for (int i = 0; i < row; i++) // перебор строчек
	{
		for (int j = 0; j < col; j++) // перебор столбцов
		{
			std::cout << array4[i][j] << " "; // вывод
		}
		std::cout << std::endl;
	}
}



/*Task 5*/
// Функция сложения
int add(int x, int y) {
	return x + y;
}

// Функция вычитания
int sub(int x, int y) {
	return x - y;
}

// Функция умножения
int mul(int x, int y) {
	return x * y;
}

// Функция деления
int divide(int x, int y) {
	return x / y;
}



/*Task 1 leetcode*/
int minimumDifference(std::vector<int>& nums, int k)
{
	sort(nums.begin(), nums.end()); //Отсортировать вектор в возрастающей последовательности

	int minDifference = INT_MAX; //Максимально возможное целое число
	for (int i = 0; i + k - 1 < nums.size(); i++)
	{
		//Находим минимальную разницу среди k оценок подряд
		minDifference = std::min(minDifference, nums[i + k - 1] - nums[i]);
	}

	return minDifference;
}


/*Task 2 leetcode*/
int findLucky(std::vector<int>& arr)
{
	int maxch = -INT_MAX; //Минимально возможное целое число
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] > maxch) maxch = arr[i]; //Находим максимальное число в векторе
	}
	int* mas = new int[maxch + 1];
	for (int i = 0; i < maxch + 1; ++i)
	{ //Заполняем массив нулями
		mas[i] = 0;
	}
	for (int i = 0; i < arr.size(); ++i)
	{ //На соответсвующем числу индексе прибавляем счетчик(Кол-во определенного числа во входном массиве)
		mas[arr[i]]++;
	}

	int luckyNum = -1;
	//  Ищем элемент, который равен количеству вхождений его в вектор
	for (int i = 1; i < maxch + 1; ++i)
	{
		if (i == mas[i])
		{
			luckyNum = std::max(luckyNum, i);
		}
	}
	return luckyNum;
}



/*Task 3 leetcode*/
int majorityElement(std::vector<int>& nums) // Находит число, которое входит в массив больше n/2 раз
{
	int candidate = 0;
	int count = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (count == 0) {
			candidate = nums[i];
			count++;
		}
		else if (candidate == nums[i])
		{
			count++;
		}
		else {
			count--;
		}
	}
	return candidate;
}


int main()
{
	/*Task 1*/
	CvC();


	/*Task 2*/
	char choice;
	do
	{
		int size;
		std::cout << "2) Enter the size of your massive: " << std::endl;
		std::cin >> size;

		double* arr = createArray(size);
		fillArray(arr, size);
		showArray(arr, size);
		releaseArray(arr);

		std::cout << "Do you want to continue thr programm? Please, enter y or n: " << std::endl;
		std::cin >> choice;
	} while (choice == 'y');



	/*Task 3*/
	int* array = new int[12];  // инициализация массива
	for (int i = 0; i < 12; i++) // заполнение массива числами от 1 до 12
	{
		array[i] = i + 1;
	}

	std::cout << "3) Original array: ";
	// вывод исходного массива 
	for (int i = 0; i < 12; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	number12(array, 12); // вызов функции, которая поменяет значения четных и нечетных ячеек массива

	std::cout << "Array after swapping: ";
	// вывод массива после изменения
	for (int i = 0; i < 12; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	delete[] array;
	array = 0;



	/*Task 4*/
	int row, col;
	std::cout << "4) Enter the number of rows: ";
	std::cin >> row;
	std::cout << "Enter the number of columns: ";
	std::cin >> col;

	int** array4 = new int* [row];
	for (int i = 0; i < row; i++) {
		array4[i] = new int[col]; // в каждой строке выделяем память для массива, у которого будет col эллементов - col столбцов
	}

	std::srand(std::time(nullptr)); // используем текущее время в качестве начального числа для генератора случайных

	fill(array4, row, col);
	show(array4, row, col);

	for (int i = 0; i < row; i++)
	{
		delete[] array4[i];
	}




	/*Task 5*/
	int(*pfunc)(int, int); // создаётся указатель на функцию

	double a = 0;
	double b = 0;
	char oper;
	std::cout << "5) Enter two numbers and operation: ";
	std::cin >> a >> b;
	std::cin.get();
	std::cin.get(oper);

	while (oper != ' ')
	{
		if (oper == '+')
		{
			pfunc = add;
			std::cout << (*pfunc)(a, b) << std::endl;
			std::cout << "Enter two numbers and operation: ";
		}
		if (oper == '-')
		{
			pfunc = sub;
			std::cout << (*pfunc)(a, b) << std::endl;
			std::cout << "Enter two numbers and operation: ";
		}

		if (oper == '*')
		{
			pfunc = mul;
			std::cout << (*pfunc)(a, b) << std::endl;
			std::cout << "Enter two numbers and operation: ";

		}

		if (oper == '/')
		{
			pfunc = divide;
			std::cout << (*pfunc)(a, b) << std::endl;
			std::cout << "Enter two numbers and operation: ";

		}
		std::cin >> a >> b;
		std::cin.get();
		std::cin.get(oper);
	}


	/*Task 1 leetcode*/
	std::vector<int> nums1;;
	int n1;
	std::cout << "1) Enter the number of numbers in the array: " << std::endl;
	std::cin >> n1;
	int vr1;
	for (int i = 0; i < n1; ++i) 
	{
		std::cout << "Enter a number: " << std::endl;
		std::cin >> vr1;
		nums1.push_back(vr1);
	}
	int k;
	std::cout << "Enter k = " << std::endl;
	std::cin >> k;
	int result1 = minimumDifference(nums1, k);
	std::cout << "Minimum difference: " << result1 << std::endl;



	/*Task 2 leetcode*/
	std::vector<int> nums2;
	int n2;
	std::cout << "2) Enter the number of numbers in the array: " << std::endl;
	std::cin >> n2;
	int vr2;
	for (int i = 0; i < n2; ++i) 
	{
		std::cout << "Enter a number: " << std::endl;
		std::cin >> vr2;
		nums2.push_back(vr2);
	}
	int result2 = findLucky(nums2);
	std::cout << "The largest lucky integer: " << result2 << std::endl;



	/*Task 3 leetcode*/
	std::vector<int> nums3;
	int n3;
	std::cout << "3) Enter the number of numbers in the array: " << std::endl;
	std::cin >> n3;
	int vr3;
	for (int i = 0; i < n3; ++i) 
	{
		std::cout << "Enter a number: " << std::endl;
		std::cin >> vr3;
		nums3.push_back(vr3);
	}
	int result3 = majorityElement(nums3);
	std::cout << "Majority element: " << result3 << std::endl;


	return 0;
}