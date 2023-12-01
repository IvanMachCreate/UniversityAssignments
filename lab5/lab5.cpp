#include <iostream>
#include <iomanip>
using namespace std;

// Task 1: Simplified parenthesis matching problem. Implement a recursive function to solve the parenthesis matching problem.
// Note: you are not allowed to use loop(s)!
// {'{','(', ')','}'} --> true
// {'{','(', ']','}'} --> false
bool isMatch(const char arr[], int start, int end)
{
    if ((end - start) < 0)
    {
        return true;
    }
    else if ((start - end) == 0)
    {
        return false;
    }
    switch (arr[start])
    {
    case '{':
        return ((arr[end] == '}') ? isMatch(arr, start + 1, end - 1) : false);
        break;
    case '[':
        return ((arr[end] == ']') ? isMatch(arr, start + 1, end - 1) : false);
        break;
    case '(':
        return ((arr[end] == ')') ? isMatch(arr, start + 1, end - 1) : false);
        break;
    }
}

// Task 2: Solve the variation of Fibonacci problem using recursion.
// The extended Fibonacci problem is modified to require computing the (n)th Fibonacci number, i.e.,fn, and the (n-1)th Fibonacci number i.e.,fn_1, given the initial values f0 and f1.
// Note: you are not allowed to use loop(s)!
// f(0) = f0.
// f(1) = f1.
// f(n) = f(n-1) + f(n-2) for n >= 2.
void extendedFibonacci(int n, int &fn, int &fn_1, int f0, int f1)
{
    if (n > 1)
    {
        extendedFibonacci(n - 1, fn, fn_1, f1, f0 + f1);
    }
    else
    {
        if (n)
        {
            fn_1 = f0;
            fn = f1;
        }
        else
        {
            fn = fn_1;
            fn_1 = 0;
        }
    }
}

// Task 3:
// In this task, students are required to implement a function of myPow() using recursion.
// Noted to consider the case when n<0.
// Note: you are not allowed to use loop(s)!
double myPow(double x, int n)
{
    if (n < 0)
    {
        return 1 / (myPow(x, -n));
    }
    else if (n > 0)
    {
        return x * myPow(x, n - 1);
    }
    else
    {
        return 1;
    }
}

// Task 4: Optional Task
// In this task, students are required to implement a function of mergeArrays() using recursion.
// Given two arrays sorted in descending order, you need to merge the two arrays into one array that is also sorted in descending order.
// Note: you are not allowed to use loop(s)!
void mergeArrays(const int arr1[], int first1, int last1, const int arr2[], int first2, int last2, int result[], int index)
{
    if (first1 > last1 ) {
        if (first2 > last2 ) {
            return;
        }
        else {
            result[index] = arr2[first2];
            mergeArrays(arr1, first1 + 1, last1 , arr2, first2, last2, result, index + 1) ;
        }
    }
    else if (first2 > last2){
        if(first1 > last1) {
            return;
        }
        else {
            result[index] = arr1[first1];
            mergeArrays(arr1, first1 + 1, last1 , arr2, first2, last2, result, index + 1) ;
        }
    }
    else {
        if (arr1[first1] > arr2[first2]){
            result[index] = arr1[first1] ;
            mergeArrays(arr1, first1 + 1, last1, arr2, first2, last2, result, index + 1); 
        }
        else {
            result[index] = arr2[first2] ;
            mergeArrays(arr1, first1, last1, arr2 , first2 + 1, last2, result, index + 1 );
        }
    
        
    }
    

}

/* YOU MUST NOT MODIFY THE MAIN FUNCTION BELOW */
int main()
{
    cout << "Welcome to the Lab 5!" << endl;
    cout << "There are 3 required tasks and 1 optional task: " << endl;
    int task;
    while (true)
    {
        cout << "===========================================================" << endl;
        cout << "Task 1: Solve the simplified parenthesis matching problem using recursion!" << endl;
        cout << "Task 2: Solve the variation of Fibonacci problem using recursion!" << endl;
        cout << "Task 3: Implement the power function!" << endl;
        cout << "Task 4 (optional): Merge two sorted arrays into one array in descending order !" << endl;

        cout << "\nSelect the task (Enter 1, 2, 3 or 4) or Enter -1 to quit: ";
        cin >> task;

        if (task == -1)
        {
            cout << "Bye!" << endl;
            break;
        }

        switch (task)
        {
        case 1:
            // Task 1: Implement isMatch() to solve the simplified parenthesis matching problem
            cout << "Task 1: Solve the simplified parenthesis matching problem using recursion!" << endl;
            char arr[100];
            int n;
            cout << "Enter the number of brackets: ";
            cin >> n;
            cout << "Each element must be a bracket symbol (i.e. '{', '[', '(', '}', ']', ')')." << endl;
            cout << "Enter the elements of the array: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
                if ((arr[i] != '(') && (arr[i] != ')') && (arr[i] != '{') && (arr[i] != '}') && (arr[i] != '[') && (arr[i] != ']'))
                {
                    cout << "The element must be a bracket symbol (i.e. '{', '[', '(', '}', ']', ')'), please enter again: " << endl;
                    --i;
                    continue;
                }
            }

            if (isMatch(arr, 0, n - 1))
            {
                cout << "\nThe parenthesis is matching." << endl;
            }
            else
            {
                cout << "\nThe parenthesis is not matching." << endl;
            }
            break;
        case 2:
            // Task 2: Implement extendedFibonacci(), the variation of Fibonacci problem using recursion
            cout << "Task 2: Solve the variation of Fibonacci problem using recursion!" << endl;
            int n1, fn, fn_1, f0, f1;
            cout << "Enter the value of n: ";
            cin >> n1;
            cout << "Enter the value of f0: ";
            cin >> f0;
            cout << "Enter the value of f1: ";
            cin >> f1;
            extendedFibonacci(n1, fn, fn_1, f0, f1);
            cout << "\nThe " << n1 << "th Fibonacci number is " << fn << endl;
            cout << "The " << n1 - 1 << "th Fibonacci number is " << fn_1 << endl;
            break;
        case 3:
            // Task 3: Implement myPow() to handle +ve and -ve exponenet value
            cout << "Task 3: Implement the power function!" << endl;
            double x;
            int n2;
            cout << "Enter the base value x: ";
            cin >> x;
            cout << "Enter the exponent value n: ";
            cin >> n2;
            cout << setprecision(4);
            cout << "\nThe value of " << x << "^" << n2 << " is: " << myPow(x, n2) << endl;
            break;
        case 4:
            //Task 4: Merge 2 sorted arrays, implement mergeArrays()
            //Task 4 is Optional Task
            cout << "Task 4 (optional): Reorganize the two arrays in a one array sorted in descending order !" << endl;
            int arr1[100], n3;
            cout << "Enter the size of the first array: ";
            cin >> n3;
            cout << "Enter the elements of the first array (in descending order): " << endl;
            for (int i = 0; i < n3; i++)
            {
                cin >> arr1[i];
            }
            int arr2[100], n4;
            cout << "Enter the size of the second array: ";
            cin >> n4;
            cout << "Enter the elements of the second array (in descending order): " << endl;
            for (int i = 0; i < n4; i++)
            {
                cin >> arr2[i];
            }

            int result[200];
            mergeArrays(arr1, 0, n3 - 1, arr2, 0, n4 - 1, result, 0);
            cout << "\nThe merge array is: ";
            for (int i = 0; i < n3 + n4; i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;
            break;
        default:
            return 0;
        }
    }
    return 0;
}
