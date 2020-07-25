#include<iostream>
#include"DTLinkedList.h"
#include<stack>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

//Task 1
template<typename T>
int ElementsGreaterThenKey(DTLinkedList<T> &DTL, T Key)
{
	int count = { 0 };
	for (auto li = DTL.end(); li != DTL.begin(); li--)
	{
		if (*li > Key)
		{
			cout << *li << " ";
			++count;
		}
	}
	cout << endl;
	return count;
}

//Task 2
template<typename T>
int NumberOfTimesKeyPresent(DTLinkedList<T> &DTL, T Key)
{
	int count = { 0 };
	for (auto li = DTL.end(); li != DTL.begin(); li--)
	{
		if (*li == Key)
			++count;
	}
	return count;
}

//Task 3
//Helper Function for Task 3 (Merge List)

//Q3
template<typename T>
void Swap(T A, T B)
{
	T temp = A;
	B = A;
	A = temp;
}
bool ListBubbleUpDS(DTLinkedList<int> &li)
{
	bool swapped = { false };
	auto prev = li.end(), next = li.end(); next--;
	while (next != li.begin())
	{
		if (*prev > *next)
		{
			int Temp = *next;
			next = *prev;
			prev = Temp;
			swapped = true;
		}
		next--;
		prev--;
	}
	return swapped;
}
void ListBubbleSortDS(DTLinkedList<int> &li)
{
	bool swapped = { false };
	do
	{
		swapped = ListBubbleUpDS(li);
	} while (swapped);
}
//Sort two lists and merge them
DTLinkedList<int> ListMergeANDListSort(DTLinkedList<int> &A, DTLinkedList<int> &B)
{
	DTLinkedList<int> C;
	for (auto li = A.end(); li != A.begin(); li--)
	{
		C.InsertAtEnd(*li);
	}

	for (auto li = B.end(); li != B.begin(); li--)
	{
		C.InsertAtEnd(*li);
	}
	cout << C;
	ListBubbleSortDS(C);
	cout << C;
	return C;
}
//Task 4
bool isPalindrome(DTLinkedList<char> &L)
{
	char tmp = { '\0' };
	int SizeOfList = { L.Size() };
	auto li = L.end();
	stack<char> stk;
	int i = 0;
	while (i < SizeOfList / 2)
	{
		if (*li >= 'a' && *li <= 'z')
			stk.push(*li - 32);
		else
			stk.push(*li);
		li--;
		i++;
	}

	if (SizeOfList % 2 != 0)
		li--;

	while (li != L.begin())
	{
		if (*li >= 'a' && *li <= 'z')
			tmp = *li - 32;
		else
			tmp = *li;
		
		if (tmp != stk.top())
			return false;
		stk.pop();
		li--;
	}
	return true;
}


//Menue
template<typename T>
void InputData(DTLinkedList<T> &DTL)
{
	int Size = { 0 };
	T Value;
	cout << "\t\t Enter Size of Your List: ";
	cin >> Size;
	while (Size > 0)
	{
		cout << "    Enter Value to InsertAtEnd in List of Size " << Size << " : ";
		cin >> Value;
		DTL.InsertAtEnd(Value);
		Size--;
	}
}

//T1
void Task1(DTLinkedList<int> &DTL)
{
	int Key = { 0 };
	InputData(DTL);
	cout << "Enter Value of Key: ";
	cin >> Key;
	cout << "Count: " << ElementsGreaterThenKey(DTL, Key) << endl;
}

//T2
void Task2(DTLinkedList<int> &DTL)
{
	int Key = { 0 };
	InputData(DTL);
	cout << "Enter Value of Key: ";
	cin >> Key;
	cout << "Count: " << NumberOfTimesKeyPresent(DTL, Key);
}

//T3
void Task3(DTLinkedList<int> &DTL, DTLinkedList<int> &DTL2)
{
	int Key = { 0 };
	cout << "Input Data in 1st List" << endl;
	InputData(DTL);

	cout << "List 1: " << DTL << endl;

	cout << "Input Data in 2st List" << endl;
	InputData(DTL2);

	cout << "List 2: " << DTL2 << endl;

	cout << "Merged List: " << ListMergeANDListSort(DTL, DTL2);
}

//T4
void Task4(DTLinkedList<char> &DTL)
{
	InputData(DTL);

	if (isPalindrome(DTL))
		cout << "It's a palindrome" << endl;
	else
		cout << "It's not a palindrome" << endl;
}

void Menue()
{
	DTLinkedList<int> DTL,DTL2;
	DTLinkedList<char> DT;
	int x;
	do
	{
		cout << "_______________________________________________________" << endl;
		cout << "   Enter 1 to Print Elements Greater then Given Key" << endl;
		cout << "  Enter 2 to Print How many times Key Present in List" << endl;
		cout << "\t      Enter 3 to Merge two Lists" << endl;
		cout << "\t     Enter 4 to Check Palindrome" << endl;
		cout << "\t\t    Enter 5 to exit" << endl;
		cout << "_______________________________________________________" << endl;
		cout << "\t\t    Your Choice: ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << endl << "_______________________________________________________" << endl << endl;
			Task1(DTL);
			DTL.Clear();
			cout << endl << "_______________________________________________________" << endl << endl;
			break;
		case 2:
			cout << endl << "_______________________________________________________" << endl << endl;
			Task2(DTL);
			DTL.Clear();
			cout << endl << "_______________________________________________________" << endl << endl;
			break;
		case 3:
			cout << endl << "_______________________________________________________" << endl << endl;
			Task3(DTL, DTL2);
			DTL.Clear();
			DTL2.Clear();
			cout << endl << "_______________________________________________________" << endl << endl;
			break;
		case 4:
			cout << endl << "_______________________________________________________" << endl << endl;
			Task4(DT);
			DT.Clear();
			cout << endl << "_______________________________________________________" << endl << endl;
			break;
		default:
			break;
		}
	} while (x != 5);
}



int main()
{
	Menue();

	return 0;
}