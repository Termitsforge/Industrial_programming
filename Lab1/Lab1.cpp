#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void matInput(int row, int column, int** matrix, bool random)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (random) matrix[i][j] = rand() % 10; 
			else cin >> matrix[i][j];
		}
	}
}
void coutMat(int row, int column, int** matrix) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
void createReduced(int size, int** matrix) {
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	}
}
void AddMatrixs(int row, int column, int** matrixOne, int** matrixTwo, int dop_i, int dop_j, bool create) {
	for (int i = 0; i < row; i++)
	{
		if(create) matrixOne[i] = new int[column];
		for (int j = 0; j < column; j++)
			matrixOne[i][j] = matrixTwo[i+dop_i][j+dop_j];
	}

}
void createMat(int** matrix, int sizeRowMatrix, int sizeColumnMatrix){
	for (int i = 0; i < sizeRowMatrix; i++)
	{
		matrix[i] = new int[sizeColumnMatrix];
	}
}
int Calculate(int row, int column, int count, int f, int** matrix) {
	for (int i = 0; i < row; i++)
	{
		count = 0;
		for (int j = 0; j < column; j++)
		{
			if (matrix[i][j] != 0)
			{
				count++;
			}
		}
		if (count == 0 && i < f)
		{
			f = i;
		}
	}
	return f;
}


void main()
{
	srand(time(NULL));
	int rowMatrixOne, columnMatrixOne, rowMatrixTwo, columnMatrixTwo, Completion, sizeReducedMatrix = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> rowMatrixOne >> columnMatrixOne;
	} while (rowMatrixOne <= 0 || columnMatrixOne <= 0);
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> rowMatrixTwo >> columnMatrixTwo;
	} while (rowMatrixTwo <= 0 || columnMatrixTwo <= 0);

	int** MatrixOne = new int* [rowMatrixOne];
	int** MatrixTwo = new int* [rowMatrixTwo];
	createMat(MatrixOne, rowMatrixOne, columnMatrixOne);
	createMat(MatrixTwo, rowMatrixTwo, columnMatrixTwo);
	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> Completion;
	} while (Completion < 1 || Completion > 2);
	switch (Completion)
	{
	case 1:
		matInput(rowMatrixOne, columnMatrixOne, MatrixOne,false);
		matInput(rowMatrixTwo, columnMatrixTwo, MatrixTwo, false);
		cout << "\nМатрица 1\n\n";
		coutMat(rowMatrixOne, columnMatrixOne, MatrixOne);
		cout << "\nМатрица 2\n\n";
		coutMat(rowMatrixTwo, columnMatrixTwo, MatrixTwo);
		break;
	case 2:
		matInput(rowMatrixOne, columnMatrixOne, MatrixOne, true);
		matInput(rowMatrixTwo, columnMatrixTwo, MatrixTwo, true);
		cout << "\nМатрица 1\n\n";
		coutMat(rowMatrixOne, columnMatrixOne, MatrixOne);
		cout << "\nМатрица 2\n\n";
		coutMat(rowMatrixTwo, columnMatrixTwo, MatrixTwo);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	//Определение sizeReducedMatrix
	while (sizeReducedMatrix < rowMatrixOne || sizeReducedMatrix < rowMatrixTwo || sizeReducedMatrix < columnMatrixOne || sizeReducedMatrix < columnMatrixTwo) sizeReducedMatrix *= 2;

	int** reducedMatrixOne = new int* [sizeReducedMatrix];
	createReduced(sizeReducedMatrix, reducedMatrixOne);
	int** reducedMatrixTwo = new int* [sizeReducedMatrix];
	createReduced(sizeReducedMatrix, reducedMatrixTwo);
	AddMatrixs(rowMatrixOne, columnMatrixOne, reducedMatrixOne, MatrixOne, 0, 0, false);
	AddMatrixs(rowMatrixTwo, columnMatrixTwo, reducedMatrixTwo, MatrixTwo, 0, 0, false);
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	coutMat(sizeReducedMatrix, sizeReducedMatrix, reducedMatrixOne);
	cout << "\nМатрица 2\n\n";
	coutMat(sizeReducedMatrix, sizeReducedMatrix, reducedMatrixTwo);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////
	int** SubmatrixOne_1_1 = new int* [sizeReducedMatrix / 2];
	int** SubmartixOne_1_2 = new int* [sizeReducedMatrix / 2];
	int** SubmatrixOne_2_1 = new int* [sizeReducedMatrix / 2];
	int** SubmatrixOne_2_2 = new int* [sizeReducedMatrix / 2];

	int** SubmatrixTwo_1_1 = new int* [sizeReducedMatrix / 2];
	int** SubmatrixTwo_1_2 = new int* [sizeReducedMatrix / 2];
	int** SubmatrixTwo_2_1 = new int* [sizeReducedMatrix / 2];
	int** SubmatrixTwo_2_2 = new int* [sizeReducedMatrix / 2];

	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmatrixOne_1_1, reducedMatrixOne, 0, 0, true);
	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmartixOne_1_2, reducedMatrixOne, 0, sizeReducedMatrix / 2, true);
	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmatrixOne_2_1, reducedMatrixOne, sizeReducedMatrix / 2, 0, true);
	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmatrixOne_2_2, reducedMatrixOne, sizeReducedMatrix / 2, sizeReducedMatrix / 2, true);

	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmatrixTwo_1_1, reducedMatrixOne, 0, 0, true);
	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmatrixTwo_1_2, reducedMatrixOne, 0, sizeReducedMatrix / 2, true);
	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmatrixTwo_2_1, reducedMatrixOne, sizeReducedMatrix / 2, 0, true);
	AddMatrixs(sizeReducedMatrix / 2, sizeReducedMatrix / 2, SubmatrixTwo_2_2, reducedMatrixOne, sizeReducedMatrix / 2, sizeReducedMatrix / 2, true);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	int** func_P_1 = new int* [sizeReducedMatrix / 2];
	int** func_P_2 = new int* [sizeReducedMatrix / 2];
	int** func_P_3 = new int* [sizeReducedMatrix / 2];
	int** func_P_4 = new int* [sizeReducedMatrix / 2];
	int** func_P_5 = new int* [sizeReducedMatrix / 2];
	int** func_P_6 = new int* [sizeReducedMatrix / 2];
	int** func_P_7 = new int* [sizeReducedMatrix / 2];

	createMat(func_P_1, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(func_P_2, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(func_P_3, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(func_P_4, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(func_P_5, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(func_P_6, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(func_P_7, sizeReducedMatrix / 2, sizeReducedMatrix / 2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < sizeReducedMatrix / 2; i++)
	{
		for (int j = 0; j < sizeReducedMatrix / 2; j++)
		{
			func_P_1[i][j] = 0;
			for (int z = 0; z < sizeReducedMatrix / 2; z++)
			{
				func_P_1[i][j] += (SubmatrixOne_1_1[i][z] + SubmatrixOne_2_2[i][z]) * (SubmatrixTwo_1_1[z][j] + SubmatrixTwo_2_2[z][j]);
			}

			func_P_2[i][j] = 0;
			for (int z = 0; z < sizeReducedMatrix / 2; z++)
			{
				func_P_2[i][j] += (SubmatrixOne_2_1[i][z] + SubmatrixOne_2_2[i][z]) * SubmatrixTwo_1_1[z][j];
			}

			func_P_3[i][j] = 0;
			for (int z = 0; z < sizeReducedMatrix / 2; z++)
			{
				func_P_3[i][j] += SubmatrixOne_1_1[i][z] * (SubmatrixTwo_1_2[z][j] - SubmatrixTwo_2_2[z][j]);
			}

			func_P_4[i][j] = 0;
			for (int z = 0; z < sizeReducedMatrix / 2; z++)
			{
				func_P_4[i][j] += SubmatrixOne_2_2[i][z] * (SubmatrixTwo_2_1[z][j] - SubmatrixTwo_1_1[z][j]);
			}

			func_P_5[i][j] = 0;
			for (int z = 0; z < sizeReducedMatrix / 2; z++)
			{
				func_P_5[i][j] += (SubmatrixOne_1_1[i][z] + SubmartixOne_1_2[i][z]) * SubmatrixTwo_2_2[z][j];
			}

			func_P_6[i][j] = 0;
			for (int z = 0; z < sizeReducedMatrix / 2; z++)
			{
				func_P_6[i][j] += (SubmatrixOne_2_1[i][z] - SubmatrixOne_1_1[i][z]) * (SubmatrixTwo_1_1[z][j] + SubmatrixTwo_1_2[z][j]);
			}

			func_P_7[i][j] = 0;
			for (int z = 0; z < sizeReducedMatrix / 2; z++)
			{
				func_P_7[i][j] += (SubmartixOne_1_2[i][z] - SubmatrixOne_2_2[i][z]) * (SubmatrixTwo_2_1[z][j] + SubmatrixTwo_2_2[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	int** submartixResult_1_1 = new int* [sizeReducedMatrix / 2];
	int** submatrixResult_1_2 = new int* [sizeReducedMatrix / 2];
	int** submatrixResult_2_1 = new int* [sizeReducedMatrix / 2];
	int** submatrixResult_2_2 = new int* [sizeReducedMatrix / 2];

	createMat(submartixResult_1_1, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(submatrixResult_1_2, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(submatrixResult_2_1, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	createMat(submatrixResult_2_2, sizeReducedMatrix / 2, sizeReducedMatrix / 2);
	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < sizeReducedMatrix / 2; i++)
	{
		for (int j = 0; j < sizeReducedMatrix / 2; j++)
		{
			submartixResult_1_1[i][j] = func_P_1[i][j] + func_P_4[i][j] - func_P_5[i][j] + func_P_7[i][j];
			submatrixResult_1_2[i][j] = func_P_3[i][j] + func_P_5[i][j];
			submatrixResult_2_1[i][j] = func_P_2[i][j] + func_P_4[i][j];
			submatrixResult_2_2[i][j] = func_P_1[i][j] - func_P_2[i][j] + func_P_3[i][j] + func_P_6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	int** matrixResult = new int* [sizeReducedMatrix];
	createMat(matrixResult, sizeReducedMatrix, sizeReducedMatrix);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < sizeReducedMatrix / 2; i++)
	{
		for (int j = 0; j < sizeReducedMatrix / 2; j++)
		{
			matrixResult[i][j] = submartixResult_1_1[i][j];
			matrixResult[i][j + sizeReducedMatrix / 2] = submatrixResult_1_2[i][j];
			matrixResult[i + sizeReducedMatrix / 2][j] = submatrixResult_2_1[i][j];
			matrixResult[i + sizeReducedMatrix / 2][j + sizeReducedMatrix / 2] = submatrixResult_2_2[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 1000, s = 1000;

	f = Calculate(sizeReducedMatrix, sizeReducedMatrix, x, f, matrixResult);
	s = Calculate(sizeReducedMatrix, sizeReducedMatrix, x, s, matrixResult);
	int** M6 = new int* [f];
	AddMatrixs(f, s, M6, matrixResult, 0, 0, true);

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	cout << "\nРезультирующая матрица\n\n";
	coutMat(f, s, M6);
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	cout << "Очистка динамической памяти\n";
	for (int i = 0; i < rowMatrixOne; i++)
		delete[] MatrixOne[i];
	for (int i = 0; i < rowMatrixTwo; i++)
		delete[] MatrixTwo[i];
	for (int i = 0; i < sizeReducedMatrix; i++)
	{
		delete[] reducedMatrixOne[i];
		delete[] reducedMatrixTwo[i];
		delete[] matrixResult[i];
	}
	for (int i = 0; i < f; i++)
		delete[] M6[i];
	for (int i = 0; i < sizeReducedMatrix / 2; i++)
	{
		delete[] SubmatrixOne_1_1[i];
		delete[] SubmartixOne_1_2[i];
		delete[] SubmatrixOne_2_1[i];
		delete[] SubmatrixOne_2_2[i];
		delete[] SubmatrixTwo_1_1[i];
		delete[] SubmatrixTwo_1_2[i];
		delete[] SubmatrixTwo_2_1[i];
		delete[] SubmatrixTwo_2_2[i];
		delete[] submartixResult_1_1[i];
		delete[] submatrixResult_1_2[i];
		delete[] submatrixResult_2_1[i];
		delete[] submatrixResult_2_2[i];
		delete[] func_P_1[i];
		delete[] func_P_2[i];
		delete[] func_P_3[i];
		delete[] func_P_4[i];
		delete[] func_P_5[i];
		delete[] func_P_6[i];
		delete[] func_P_7[i];
	}
	delete[] MatrixOne, MatrixTwo, reducedMatrixOne, reducedMatrixTwo, matrixResult, M6;
	delete[] SubmatrixOne_1_1, SubmartixOne_1_2, SubmatrixOne_2_1, SubmatrixOne_2_2, SubmatrixTwo_1_1, SubmatrixTwo_1_2, SubmatrixTwo_2_1, SubmatrixTwo_2_2, submartixResult_1_1, submatrixResult_1_2, submatrixResult_2_1, submatrixResult_2_2;
	delete[] func_P_1, func_P_2, func_P_3, func_P_4, func_P_5, func_P_6, func_P_7;
}