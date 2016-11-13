#include <iostream>
#include <vector>
#include <math.h>
#include <string>

bool performOperation(int userChoice);
bool projections();
double dotProduct(bool isSilent, std::vector<int> v, std::vector<int> u);
double findMagintude(bool isSilent, std::vector<int> v);
std::vector<std::vector<int>> getMatrix();
std::vector<int> getVector();
std::string formatVector(std::vector<int> v);

int main()
{
	int userChoice = 10;
	while (userChoice != 0)
	{
		std::cout << "Welcome to the Math Helper application." << "\n"
			<< "Enter 1 to dot two vectors.\n" 
			<< "Enter 2 to cross two vectors.\n" 
			<< "Enter 3 to find the magnitude of a vector.\n" 
			<< "Enter 4 to project one vector onto another.\n" << std::endl;
		
		std::cin >> userChoice;

		performOperation(userChoice);
	}
}

bool performOperation(int userChoice)
{
	switch (userChoice)
	{
	case 1:
		dotProduct(false, getVector(), getVector());
		break;
	case 2:
		break;
	case 3:
		findMagintude(false, getVector());
	case 4:
		projections();
	}
	return true;
}

std::vector<int> getVector()
{
	int n;
	std::cout << "Enter the size of the vector: ";
	std::cin >> n;
	std::vector<int> vector(n);

	for (int i = 0; i < n; i++)
	{
		int x;
		std::cout << "Enter the value at " << i << ": " << std::endl;
		std::cin >> vector[i];
	}

	return vector;
}

std::vector<std::vector<int>> getMatrix()
{
	int nRows, nCols;

	std::cout << "Enter the number of rows in the matrix: ";
	std::cin >> nRows;
	std::cout << "Enter the number of columns in the matrix: ";
	std::cin >> nCols;

	std::vector<std::vector <int>> matrix (nRows, std::vector<int> (nCols));

	std::cout << "Enter the entries (left to right order):" << std::endl;
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			std::cout << "A[" << i << "][" << j << "]: ";
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}

bool projections()
{
	std::cout << "Projection of the first vector onto the second.\n\n";
	std::cout << "Enter the first vector.\n";
	std::vector<int> v = getVector();
	std::cout << "\nEnter the second vector.\n"; 
	std::vector<int> u = getVector();

	double coeff = dotProduct(true, v, u) / pow(findMagintude(true, u), 2);
	for (int i = 0; i < u.size(); i++)
	{
		u[i] *= coeff;
	}
	std::cout << "\nThe projection is: \n" << formatVector(u);

	return true;
}

double dotProduct(bool isSilent, std::vector<int> v, std::vector<int> u)
{
	int n = v.size();
	if (n != u.size())
	{
		std::cout << "Vectors must be of the same size.\n";
		return -99999;
	}

	double count = 0;
	for (int i = 0; i < n; i++)
	{
		count += v[i] * u[i];
	}

	if(!isSilent)
		std::cout << "The result is " << count << ".\n" << std::endl;
	return count;
}

double findMagintude(bool isSilent, std::vector<int> v)
{
	double magnitude = sqrt(dotProduct(true, v, v));
	if (!isSilent)
		std::cout << "The magnitude of the vector is " << magnitude << ".\n\n";

	return magnitude;
}

std::string formatVector(std::vector<int> v)
{

}