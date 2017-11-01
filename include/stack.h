// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

#include <iostream>

using namespace std;

// Шаблон стека

template <class ValType>
class Stack
{
protected:
	ValType *pStack;
	int Size;		// физический размер
	int Index;	// индекс первой свободной ячейки (следующая ячейка, после той, в которую установлен элемент)
public:
	Stack(int s = 0);
	Stack(const Stack &v);			// конструктор копирования
	~Stack();
	Stack& Push(ValType elem);		// вставка элемента
	Stack& Pop(ValType elem);		// удаление элемента
	ValType& Top();		// просмотр верхнего элемента (без удаления)
	bool IsEmpty();		// проверка на пустоту
	int GetSize() {return (Index - 1); }	// кол-во элементов в стеке
	Stack& Clean();		// очистка стека

};

template <class ValType>
Stack<ValType>::Stack(int s)
{
	if (s<0)
		throw ("Error");
	Size = s;
	Index = 0;
	pStack = new ValType[Size];
} /*-------------------------------------------------------------------------*/

template <class ValType>
Stack<ValType>::Stack(const Stack<ValType> &v)
{
	Size = v.Size;
	Index = v.Index;
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
	 if ((Size - Index) >= 1)
	 {
		 pVector[Index] = elem;
		 Index += 1;
	 }
	 else
		 if ((Size - Index) = 0)
		 {
			 Stack temp(this);
			 delete[] pStack;
			 Size = temp.Size + 1;
			 Index = temp.Index + 1;
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
	 Stack temp(this);
	 delete[] pStack;
	 Size = temp.Size;
	 Index = temp.Index - 1;
	 for (int i = 0; i < Index; i++)
	 {
		 pStack[i] = temp.pStack[i];
	 }
	 return *this;
 } /*-------------------------------------------------------------------------*/

 template <class ValType>
 ValType& Stack<ValType>::Top()
 {
	 return pStack[Index - 1];
 }  /*-------------------------------------------------------------------------*/

 template <class ValType>
 bool Stack<ValType>::IsEmpty()
 {
	 if (Index == 0)
		 return 1;
	 else
		 return 0;
 } /*-------------------------------------------------------------------------*/

 template <class ValType>
 Stack<ValType>&  Stack<ValType>::Clean()
 {
	 Stack temp(this);
	 delete[] pStack;
	 Size = temp.Size;
	 Index = 0;
	 pStack = new ValType[Size];
 } /*-------------------------------------------------------------------------*/