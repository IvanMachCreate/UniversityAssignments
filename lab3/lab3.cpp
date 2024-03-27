#include <iostream>
#include <fstream>
using namespace std;

bool is_prime(int number)
{
    if ((!(number % 2) && (number > 2)) || number == 1)
    {
        return false;
    }
    else
    {
        for (int x = 3; x * x <= number; x += 2)
        {
            if (!(number % x))
            {
                return false;
            }
        }
    }
    return true;
}

int next_prime(int number)
{
    if (is_prime(number))
    {
        return number;
    }
    else
    {
        while (!is_prime(number))
        {
            number++;
        }
        return number;
    }
}

int main()
{

    // Read integer numbers (>= 1) from a given txt file placed at ./input_cases
    // Justify whether a number is a prime. If not, calculate the first prime number that is greater than it.
    // Output the results using cout.

    cout << "Hello, welcome to lab3 (Function & FileIO)" << endl;

    char input_case_path[100];
    cout << "The path for input cases (e.g   ./input_cases/case5.txt ) :" << endl;
    cin >> input_case_path;
    ifstream fin(input_case_path);

    if (!fin)
    {
        cout << "Error: Can not open " << input_case_path << endl;
        return -1;
    }
    else
    {
        int j = 0;
        while (!fin.eof())
        {
            fin >> j;
            j = next_prime(j);
            cout << j << endl;
        }

        cout << "Finish! Please check whether the results are correct :)" << endl;
    }

    fin.close();
    return 0;
}
