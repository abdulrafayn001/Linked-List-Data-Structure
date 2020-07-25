#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
template<typename T>
class DTLinkedList
{
	Node<T> *Tail;
	int size;
public:
	template<typename T>
	class iterator
	{
	private:
		Node<T> *Ptr;
	public:
		iterator() : Ptr(nullptr) {}

		iterator(Node<T> *newPtr) : Ptr(newPtr) {}

		bool operator!=(const iterator& itr) const
		{
			return Ptr != itr.Ptr;
		}

		bool operator==(const iterator& itr) const
		{
			return Ptr == itr.Ptr;
		}

		T operator*()
		{
			return Ptr->GetData();
		}

		void operator=(T D)
		{
			Ptr->SetData(D);
		}

		iterator operator--(int)
		{
			iterator temp = *this;
			Ptr = Ptr->GetPrevious();
			return temp;
		}
	};

	DTLinkedList()
	{
		Tail = nullptr;
		size = 0;
	}

	DTLinkedList(const DTLinkedList& otherList)
	{
		Node<T> *current = otherList.Tail;
		this->Tail = new Node<T>(current->GetData());
		Node<T> *thisTail = this->Tail;
		current = current->GetPrevious();

		while (current)
		{
			thisTail->SetPrevious(new Node<T>(current->GetData()));
			current = current->GetPrevious();
			thisTail = thisTail->GetPrevious();
		}
		this->size = otherList.size;
	}

	void InsertAtEnd(T D)
	{
		if (Tail == nullptr)
		{
			Tail =  new Node<T>(D);
		}
		else
		{
			Node<T> *Temp = new Node<T>(D);
			Temp->SetPrevious(Tail);
			Tail->SetNext(Temp);
			Tail = Temp;
			Temp = nullptr;
		}
		size++;
	}

	void InsertAtFront(T D)
	{
		if (Tail == nullptr)
		{
			Tail = new Node<T>(D);
		}
		else
		{
			Node<T> *newNode = new Node<T>(D);
			Node<T> *tmp = Tail;
			while (tmp->GetNext())
				tmp = tmp->GetNext();
			tmp->SetPrevious(newNode);
		}
		size++;
	}

	void Delete()
	{
		if (Tail != nullptr && Tail->GetPrevious() == nullptr)
		{
			delete Tail;
			Tail = nullptr;
			size--;
		}
		else
		{
			Node<T> *Temp = Tail->GetPrevious();
			Tail->SetPrevious(nullptr);
			delete Tail;
			Tail = Temp;
			Temp = nullptr;
			size--;
		}
	}

	int Size()
	{
		return size;
	}

	friend ostream& operator<<(ostream&, const DTLinkedList<T>& dt)
	{
		Node<T> *T = dt.Tail;
		cout << "X";
		while (T)
		{
			cout << " <= ";
			cout << T->GetData();
			T = T->GetPrevious();
		}
		cout << endl;
		return cout;
	}

	DTLinkedList& operator=(const DTLinkedList& otherList)
	{
		if (this == &otherList)
		{
			return *this;
		}

		if (this->Tail != nullptr)
		{
			while (this->Tail->GetPrevious())
			{
				this->Delete();
			}
		}

		if (otherList.Tail == nullptr)
		{
			return *this;
		}

		Node<T> *current = otherList.Tail;
		this->Tail = new Node<T>(current->GetData());
		Node<T> *thisTail = this->Tail;
		current = current->GetPrevious();

		while (current)
		{
			thisTail->SetPrevious(new Node<T>(current->GetData()));
			current = current->GetPrevious();
			thisTail = thisTail->GetPrevious();
		}
		this->size = otherList.size;
		return *this;
	}

	iterator<T> begin() const
	{
		return iterator<T>(nullptr);
	}

	iterator<T> end() const
	{
		return iterator<T>(Tail);
	}

	void Clear()
	{
		if (this->Tail != nullptr)
		{
			while (this->Tail->GetPrevious())
			{
				this->Delete();
			}
		}
	}

	~DTLinkedList(){}
};
