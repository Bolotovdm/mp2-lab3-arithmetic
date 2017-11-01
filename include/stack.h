// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удалени€)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыдел€тьс€ пам€ть

#include <iostream>

using namespace std;

// Ўаблон стека

template <class ValType>
class Stack
{
protected:
	ValType *pStack;
	int Size;		// физический размер
	int IndexLastElem;	// индекс последнего элемента в стеке
public:
	Stack(int s = 0);
	Stack(const Stack &v);			// конструктор копировани€
	~Stack();
	Stack& Push(ValType elem);		// вставка элемента
	Stack& Pop(ValType elem);		// удаление элемента
	ValType Top();		// просмотр верхнего элемента (без удалени€)
	bool IsEmpty();		// проверка на пустоту
	int GetSize();		// кол-во элементов в стеке
	Stack& Clean();		// очистка стека

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