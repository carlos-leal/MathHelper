#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

bool performOperation(int userChoice);
bool projections();
double dotProduct(bool isSilent, std::vector<double> v, std::vector<double> u);
std::vector<double> crossProduct(bool isSilent, std::vector<double> v, std::vector<double> u);
double findMagintude(bool isSilent, std::vector<double> v);
std::vector<std::vector<double>> getMatrix();
std::vector<double> getVector();
std::string formatVector(std::vector<double> v);


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
		crossProduct(false, getVector(), getVector());
		break;
	case 3:
		findMagintude(false, getVector());
	case 4:
		projections();
	}
	return true;
}

std::vector<double> getVector()
{
	int n;
	std::cout << "Enter the size of the vector: ";
	std::cin >> n;
	std::vector<double> vector(n);

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter the value at " << i << ": " << std::endl;
		std::cin >> vector[i];
	}

	return vector;
}

std::vector<std::vector<double>> getMatrix()
{
	int nRows, nCols;

	std::cout << "Enter the number of rows in the matrix: ";
	std::cin >> nRows;
	std::cout << "Enter the number of columns in the matrix: ";
	std::cin >> nCols;

	std::vector<std::vector <double>> matrix (nRows, std::vector<double> (nCols));

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
	std::vector<double> v = getVector();
	std::cout << "\nEnter the second vector.\n"; 
	std::vector<double> u = getVector();

	double coeff = dotProduct(true, v, u) / pow(findMagintude(true, u), 2);
	for (unsigned int i = 0; i < u.size(); i++)
	{
		u[i] *= coeff;
	}
	std::cout << "\nThe projection is: \n" << formatVector(u) << std::endl;

	return true;
}

double dotProduct(bool isSilent, std::vector<double> v, std::vector<double> u)
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

std::vector<double> crossProduct(bool isSilent, std::vector<double> v, std::vector<double> u)
{
	if (v.size() != 3 || u.size() != 3)
	{
		std::cout << "Make the vectors size 3, then try again." << std::endl;
		return v;
	}

	std::vector<double> result(3);
	result[0] = (v[1] * u[2]) - (v[2] * u[1]);
	result[1] = (v[2] * u[0]) - (v[0] * u[2]);
	result[2] = (v[0] * u[1]) - (v[1] * u[0]);

	std::cout << "The cross product is " << formatVector(result) << std::endl << std::endl;
	return result;
}

double findMagintude(bool isSilent, std::vector<double> v)
{
	double magnitude = sqrt(dotProduct(true, v, v));
	if (!isSilent)
		std::cout << "The magnitude of the vector is " << magnitude << ".\n\n";

	return magnitude;
}

std::string formatVector(std::vector<double> v)
{
	std::string s = "< ";
	for (unsigned int i = 0; i < v.size() - 1; i++)
	{
		std::stringstream ss;
		ss << v[i];
		std::string vi = ss.str();
		s += vi + ", ";
	}
	std::stringstream ss;
	ss << v.back();
	std::string vi = ss.str();
	s += vi + " >";

	return s;

}