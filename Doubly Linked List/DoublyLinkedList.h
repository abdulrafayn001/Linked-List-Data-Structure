#pragma once
#include"Node.h"
template<typename T>
class DoublyLinkedList
{
	Node<T> *Head;
	Node<T> *Tail;
	void PrintRecursivelyFD(Node<T> *H)
	{
		if (H == nullptr)
		{
			cout << "X" << endl;
			return;
		}
		else
		{
			cout << H->GetData() << "=> ";
			PrintRecursivelyFD(H->GetNext());
		}
	}

	void PrintRecursivelyBD(Node<T> *T)
	{
		if (T == nullptr)
		{
			cout << "X" << endl;
			return;
		}
		else
		{
			cout << T->GetData() << "<= ";
			PrintRecursivelyBD(T->GetPrevious());
		}
	}

	void PrintIterativelyFD()
	{
		Node<T> *Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp->GetData() << "=> ";
			Temp = Temp->GetNext();
		}
		cout << "X" << endl;
	}
public:
	DoublyLinkedList()
	{
		Head = nullptr;
		Tail = nullptr;
	}

	//DoublyLinkedList( DoublyLinkedList<T> &other)
	//{
	//	if (!other.GetHead()) 
	//	{
	//		Head = Tail = nullptr;
	//	}
	//	else 
	//	{
	//		Head = new Node<T>(other.GetHead()->GetData());

	//		Node<T>* ptr = other.GetHead()->GetNext();
	//		while (ptr) 
	//		{
	//			Node<T> *Temp = new Node<T>(ptr->GetData());
	//			Temp->SetPrevious(Tail);
	//			Tail->SetNext(Temp);
	//			Tail = Temp;
	//			ptr = ptr->GetNext();
	//		}
	//	}
	//}

	Node<T>* GetHead()
	{
		return Head;
	}

	Node<T>* GetTail()
	{
		return Tail;
	}

	void InsertAtFront(T D)
	{
		if (Head == nullptr)
		{
			Tail = Head = new Node<T>(D);
		}
		else
		{
			Node<T> *Temp = new Node<T>(D, Head);
			Head->SetPrevious(Temp);
			Head = Temp;
			Temp = nullptr;
		}
	}

	void InsertAtEnd(T D)
	{
		if (Tail == nullptr)
		{
			Tail = Head = new Node<T>(D);
		}
		else
		{
			Node<T> *Temp = new Node<T>(D);
			Temp->SetPrevious(Tail);
			Tail->SetNext(Temp);
			Tail = Temp;
			Temp = nullptr;
		}
	}
	
	void PrintForward()
	{
		PrintIterativelyFD();
		//PrintRecursivelyFD(Head);
	}
	
	void PrintBackward()
	{
		PrintRecursivelyBD(Tail);
	}
	
	void DeleteAtEnd()
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
			Temp = nullptr;
		}
	}

	void DeleteAtFront()
	{
		if (!isEmpty())
		{

		}
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
			Temp = nullptr;
		}

	}

	void InsertAfter(T F, T D)
	{
		if (Head == nullptr)
		{
			Tail = Head = new Node<T>(D);
		}
		else
		{
			Node<T> *P = Head;
			Node<T> *Q = Tail;
			if (P != Q)
			{
				while (true)
				{
					if (P->GetData() == F)
						break;
					if (Q->GetData() == F)
						break;
					if (Q->GetNext() == P && P->GetPrevious() == Q || P == Q)
					{
						InsertAtEnd(D);
						return;
					}
					P = P->GetNext();
					Q = Q->GetPrevious();
				}
			}
			else
			{
				if (P->GetData() != F)
				{
					InsertAtEnd(D);
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
				Temp = nullptr;
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
				while (true)
				{
					if (P->GetData() == F)
						break;
					if (Q->GetData() == F)
						break;
					if (Q->GetNext() == P && P->GetPrevious() == Q || P == Q)
					{
						InsertAtEnd(D);
						return;
					}
					PL = P;
					P = P->GetNext();
					Q = Q->GetPrevious();
					QL = Q->GetPrevious();
				}
			}
			else
			{
				if (P->GetData() != F)
				{
					InsertAtEnd(D);
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
					P->SetPrevious(new Node<T>(D, P));
					Head = P->GetPrevious();
				}
			}
			else
			{
				QL->SetNext(new Node<T>(D, Q, QL));
				Q->SetPrevious(QL->GetNext());
			}
		}
	}

	bool isEmpty()
	{
		return Head == nullptr;
	}

	Node<T>* Search(T K)
	{
		if (isEmpty())
			return nullptr;
		else
		{
			Node<T> *P = Head;
			Node<T> *Q = Tail;
			if (P != Q)
			{
				while (true)
				{
					if (P->GetData() == F)
						break;
					if (Q->GetData() == F)
						break;
					if (P->GetNext() == nullptr)
						return nullptr;
					if (Q->GetPrevious() == nullptr)
						return nullptr;
					if (Q->GetNext() == P && P->GetPrevious() == Q || P == Q)
						return nullptr;
					P = P->GetNext();
					Q = Q->GetPrevious();
				}
			}
			else
			{
				if (P->GetData() != F)
					return nullptr;
			}
			if (P->GetData() == F)
				return P;
			else
				return Q;
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
			while (true)
			{
				if (P == Q)
					return P;
				if (Q->GetNext() == P && P->GetPrevious() == Q)
				{
					return P;
				}
				PL = P;
				P = P->GetNext();
				Q = Q->GetPrevious();
				QL = Q->GetPrevious();
			}
		}
	}


	bool Swap(int LeftIndex, int RightIndex)
	{
		if (LeftIndex == RightIndex)
			return true;
		bool Y = false;
		if ((LeftIndex == RightIndex + 1) || (LeftIndex + 1 == RightIndex))
			Y = true;
		bool LI = true;
		bool RI = true;
		Node<T>*H = Head;
		Node<T>*L = H;
		Node<T>*R = H;
		while (true)
		{
			if (LI == true && LeftIndex == 0)
			{
				L = H;
				LI = false;
			}
			if (RI == true && RightIndex == 0)
			{
				R = H;
				RI = false;
			}
			if (H == nullptr || (RI == false && LI == false))
				break;
			H = H->GetNext();
			LeftIndex--;
			RightIndex--;
		}
		if (LI == false && RI == false)
		{
			Node<T> *PL = L->GetPrevious();
			Node<T> *NL = L->GetNext();
			Node<T> *PR = R->GetPrevious();
			Node<T> *NR = R->GetNext();
			if (Y == true)
			{
				if (NR != L)
				{
					L->SetNext(NR);
					if (NR)
						NR->SetPrevious(L);
					L->SetPrevious(R);
					R->SetNext(L);
					R->SetPrevious(PL);
					if (PL)
						PL->SetNext(R);
				}
				else
				{
					L->SetNext(R);
					R->SetPrevious(L);
					R->SetNext(NL);
					L->SetPrevious(PR);
					if (PR)
						PR->SetNext(L);
					if (NL)
						NL->SetPrevious(R);
				}
			}
			else
			{
				if (PL)
				{
					PL->SetNext(R);
					R->SetNext(NL);
					R->SetPrevious(PL);
					if (NL)
					{
						NL->SetPrevious(R);
					}
				}
				else
				{
					R->SetNext(NL);
					NL->SetPrevious(R);
					R->SetPrevious(L->GetPrevious());
				}

				if (PR)
				{
					PR->SetNext(L);
					L->SetNext(NR);
					L->SetPrevious(PR);
					if (NR)
						NR->SetPrevious(L);
				}
				else
				{
					L->SetNext(NR);
					NR->SetPrevious(L);
					L->SetPrevious(PR);
				}
			}

			if (!L->GetNext())
				Tail = L;
			if (!L->GetPrevious())
				Head = L;

			if (!R->GetNext())
				Tail = R;
			if (!R->GetPrevious())
				Head = R;

			return LI == false && RI == false;
		}
	}

	Node<T>* FindKthLastElement(int KValue)
	{
		if (isEmpty())
		{
			return nullptr;
		}
		Node<T>* C = Head;
		while (KValue > 0)
		{
			C = C->GetNext();
			KValue--;
		}
		Node<T>* S = Head;
		while (C)
		{
			C = C->GetNext();
			S = S->GetNext();
		}
		return S;
	}

	~DoublyLinkedList()
	{
		Node<T>* M = Head;
		while (Head)
		{
			Head = M->GetNext();
			delete M;
			M = Head;
		}
	}
};
