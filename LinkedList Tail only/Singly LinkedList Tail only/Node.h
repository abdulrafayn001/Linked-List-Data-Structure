#pragma once

template<typename T>
class Node
{
private:
	T Data;
	Node<T> *Next;
	Node<T> *Previous;
public:
	Node(T D, Node<T> *N = nullptr, Node<T> *P = nullptr)
	{
		Data = D;
		Next = N;
		Previous = P;
	}
	T GetData()
	{
		return Data;
	}
	Node<T>* GetNext()
	{
		return Next;
	}
	Node<T>* GetPrevious()
	{
		return Previous;
	}
	void SetData(T D)
	{
		Data = D;
	}
	void SetNext(Node<T> *N)
	{
		Next = N;
	}
	void SetPrevious(Node<T> *P)
	{
		Previous = P;
	}
	~Node()
	{

	}
};
