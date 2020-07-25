#pragma once
#include<iostream>
using namespace std;
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
template<typename T>
class CircularLinkedList
{
	Node<T>* Head;
	Node<T>* Tail;
public:
	CircularLinkedList()
	{
		Head = Tail = nullptr;
	}

	bool IsEmpty()
	{
		return Head == nullptr;
	}

	void InsertAtTail(T val)
	{
		Node<T>*n = new Node<T>(val);
		if (Tail == nullptr)
		{
			Tail = Head = n;
			Tail->SetNext(Head);
			Head->SetPrevious(Tail);
		}
		else
		{
			n->SetPrevious(Tail);
			Tail->SetNext(n);
			Tail = n;
			Tail->SetNext(Head);
			Head->SetPrevious(Tail);
		}
	}

	void InsertAtFront(T val)
	{
		Node<T>*n = new Node<T>(val);
		if (Head == nullptr)
		{
			Tail = Head = n;
			Tail->SetNext(Head);
			Head->SetPrevious(Tail);
		}
		else
		{
			Head->SetPrevious(n);
			n->SetNext(Head);
			Head = n;
			Head->SetPrevious(Tail);
			Tail->SetNext(Head);
		}
	}

	void InsertAfter(T F, T D)
	{
		if (Head == nullptr)
		{
			Tail = Head = new Node<T>(D);
			Tail->SetNext(Head);
			Head->SetPrevious(Tail);
		}
		else
		{
			Node<T> *P = Head;
			Node<T> *Q = Tail;
			if (P != Q)
			{
				int i = 0;
				while (true)
				{
					if (P->GetData() == F)
						break;
					if (Q->GetData() == F)
						break;
					if (Q->GetNext() == P && P->GetPrevious() == Q && i>0|| P == Q)
					{
						InsertAtTail(D);
						return;
					}
					P = P->GetNext();
					Q = Q->GetPrevious();
					i++;
				}
			}
			else
			{
				if (P->GetData() != F)
				{
					InsertAtTail(D);
					return;
				}
			}
			if (P->GetData() == F)
			{
				Node<T> *Temp = new Node<T>(D, P->GetNext(), P);
				P->SetNext(Temp);
				Temp = nullptr;
			}
			else
			{
				Node<T> *Temp = new Node<T>(D, Q->GetNext(), Q);
				Q->SetNext(Temp);
				if (Q == Tail)
				{
					Tail = Temp;
					Head->SetPrevious(Tail);
				}

			}
		}
	}

	void InsertBefore(T F, T D)
	{
		if (Head == nullptr)
		{
			Tail = Head = new Node<T>(D);
		}
		else
		{
			Node<T> *P = Head;
			Node<T> *Q = Tail;
			Node<T> *PL = Head;
			Node<T> *QL = Q->GetPrevious();
			
			if (P != Q)
			{
				int i = 0;
				while (true)
				{
					if (P->GetData() == F)
						break;
					if (Q->GetData() == F)
						break;
					if (Q->GetNext() == P && P->GetPrevious() == Q && (i > 0) || P == Q)
					{
						InsertAtTail(D);
						return;
					}
					PL = P;
					P = P->GetNext();
					Q = Q->GetPrevious();
					QL = Q->GetPrevious();
					i++;
				}
			}
			else
			{
				if (P->GetData() != F)
				{
					InsertAtTail(D);
					return;
				}
				else
				{
					Head = new Node<T>(D, P);
					P->SetPrevious(Head);
					Tail = P;
					return;
				}

			}
			if (P->GetData() == F)
			{
				if (P != Head)
				{
					PL->SetNext(new Node<T>(D, P, PL));
					P->SetPrevious(PL->GetNext());
				}
				else
				{
					P->SetPrevious(new Node<T>(D, P, Tail));
					Head = P->GetPrevious();
					Tail->SetNext(Head);
				}
			}
			else
			{
				QL->SetNext(new Node<T>(D, Q, QL));
				Q->SetPrevious(QL->GetNext());
			}
		}
	}

	Node<T>*  MiddleValue()
	{
		Node<T> *P = Head;
		Node<T> *Q = Tail;
		Node<T> *PL = Head;
		Node<T> *QL = Q->GetPrevious();
		if (P != Q)
		{
			int i = 0;
			while (true)
			{
				if (P == Q)
					return P;
				if (Q->GetNext() == P && P->GetPrevious() == Q && i > 0)
				{
					return P;
				}
				PL = P;
				P = P->GetNext();
				Q = Q->GetPrevious();
				QL = Q->GetPrevious();
				i++;
			}
		}
	}

	Node<T>* FindKthLastElement(int KValue)
	{
		if (IsEmpty())
		{
			return nullptr;
		}
		Node<T>* C = Head;
		if (KValue <= 0)
			return nullptr;
		while (KValue > 0)
		{
			C = C->GetNext();
			if (C == Head)
				return nullptr;
			KValue--;
		}
		Node<T>* S = Head;
		while (C!=Head)
		{
			C = C->GetNext();
			S = S->GetNext();
		}
		return S;
	}

	void DeleteAtEnd()
	{
		if (!IsEmpty())
		{
			if (Head == Tail)
			{
				Tail = nullptr;
				delete Head;
				Head = nullptr;
			}
			else
			{
				Node<T> *Temp = Tail->GetPrevious();
				Tail->SetPrevious(nullptr);
				delete Tail;
				Tail = Temp;
				Tail->SetNext(Head);
				Head->SetPrevious(Tail);
				Temp = nullptr;
			}
		}
	}

	void DeleteAtFront()
	{
		if (!IsEmpty())
		{
			if (Head == Tail)
			{
				Tail = nullptr;
				delete Head;
				Head = nullptr;
			}
			else
			{
				Node<T> *Temp = Head->GetNext();
				Temp->SetPrevious(nullptr);
				delete Head;
				Head = Temp;
				Head->SetPrevious(Tail);
				Tail->SetNext(Head);
				Temp = nullptr;
			}
		}
	}


	void Print()
	{
		if (IsEmpty())
			return;
		Node<T>* Tmp = Head;
		while (true)
		{
			cout << Tmp->GetData() << " ";
			Tmp = Tmp->GetNext();
			if (Tmp==Head)
				break;
		}
	}

	~CircularLinkedList(){
		Node<T>* M = Head;
		while (Head!=Tail)
		{
			Head = M->GetNext();
			delete M;
			M = Head;
		}
		delete Head;
	};
};

