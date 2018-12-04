#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node * Next;

	public:
		Node()
		{
			data = 0;
		}
	};
	Node * top;
	int countNode;
	int capacity;
public:
	Stack()
	{
		countNode = -1;
		top = NULL;
		capacity = 30;
	}
	Stack(int Capacity)
	{
		countNode = -1;
		top = NULL;
		capacity = Capacity;
	}
	bool isEmpty()
	{
		if (countNode==-1)		
			return true;		 
		else		
			return false;		
	}
	bool isFull()
	{
		if (countNode == capacity)
			return true;
		else
			return false;
	}
	void push(T comingData)
	{
		if (!isFull())
		{
			Node * newNode = new Node;
			newNode->data = comingData;
			newNode->Next = top;
			top = newNode;
			countNode++;
		}
		else
			cout << "Stack is Full"<<endl;

	}
	T  pop()
	{
		if (!isEmpty())
		{
			Node * newPtr = top;
			T dataToSend = top->data;
			newPtr = top;
			top = top->Next;
			countNode--;

			delete newPtr;
			return dataToSend;
		}
		else
			cout << "Stack is empty"<<endl;
	}

	void clear()
	{
		while (!isEmpty())
		{
			char tempValue;
			tempValue = pop();
		}
		countNode == 0;
	}
	//~StactList();
};

bool delimitersOk(const string &expression)
{
	Stack<char> stack;
	bool boolToReturn = false;
	string tempString = expression;
	for (int i = 0; tempString[i] !='\0'; i++)
	{
		if (tempString[i] == '(' || tempString[i] == '{' || tempString[i] == '[')
		{
			stack.push(tempString[i]);
		}
		if (tempString[i] == ')')
		{
			char tempCharToMatch = stack.pop();
			if (tempCharToMatch == '(')
			{
				boolToReturn = true;				
			}
			else
			{
				return boolToReturn;
			}
		}

		else if (tempString[i] == '}')
		{
			char tempCharToMatch = stack.pop();
			if (tempCharToMatch == '(')
			{
				boolToReturn = true;
			}
			else
			{
				return boolToReturn;
			}
		}

		else if (tempString[i] == ']')
		{
			char tempCharToMatch = stack.pop();
			if (tempCharToMatch == '[')
			{
				boolToReturn = true;
			}
			else
			{
				return boolToReturn;
			}
		}
	}
	return boolToReturn;
}