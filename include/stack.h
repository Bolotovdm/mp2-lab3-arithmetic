// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������

#include <iostream>

using namespace std;

// ������ �����

template <class ValType>
class Stack
{
protected:
	ValType *pStack;
	int Size;		// ���������� ������
	int IndexLastElem;	// ������ ���������� �������� � �����
public:
	Stack(int s = 0);
	Stack(const Stack &v);			// ����������� �����������
	~Stack();
	Stack& Push(ValType elem);		// ������� ��������
	Stack& Pop(ValType elem);		// �������� ��������
	ValType Top();		// �������� �������� �������� (��� ��������)
	bool IsEmpty();		// �������� �� �������
	int GetSize();		// ���-�� ��������� � �����
	Stack& Clean();		// ������� �����

};

template <class ValType>
Stack<ValType>::Stack(int s)
{
	if (s<0)
		throw ("Error");
	Size = s;
	IndexLastElem = 0;
	pStack = new ValType[Size];
} /*-------------------------------------------------------------------------*/

template <class ValType>
Stack<ValType>::Stack(const Stack<ValType> &v)
{
	Size = v.Size;
	IndexLastElem = v.IndexLastElem;
	pStack = new ValType[Size];
	for (int i = 0; i <Size; i++)
		pStack[i] = v.pStack[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
Stack<ValType>::~Stack()
{
	delete[] pStack;
} /*-------------------------------------------------------------------------*/

template <class ValType>
 Stack<ValType>& Stack<ValType>::Push(ValType elem)
{
	 if ((Size - IndexLastElem) >= 1)
		 pVector[IndexLastElem + 1] = elem;
	 else
		 if ((Size - IndexLastElem) = 0)
		 {
			 Stack temp(this);
			 delete[] pStack;
			 Size += 1;
			 IndexLastElem += 1;
			 pStack = new ValType[Size];
			 for (int i = 0; i < (Size - 1); i++)
			 {
				 pStack[i] = temp.pStack[i];
			 }
			 pStack[Size] = elem;
		 }
	 return *this;
} /*-------------------------------------------------------------------------*/

 template <class ValType>
Stack<ValType>& Stack<ValType>::Pop(ValType elem)
{
	
}