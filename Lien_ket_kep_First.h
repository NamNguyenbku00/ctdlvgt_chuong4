#pragma once
#ifndef _LKK_FIRTS_H_
#define _LKK_FIRTS_H_

#include <iostream>
using namespace std;

//------------------------Item------------------------
//Lớp phần tử
template <class InfoType>
class Item
{
	public:
		InfoType Info;
		Item<InfoType>* Next;
		Item<InfoType>* Previous;
	public:
		//Constructor: Tạo phần tử mới có nội dung theInfo
		Item(InfoType theInfo);
		//Hiện thi nội dung của phần tử
		void Display();
};

//Constructor: Tạo phần tử mới có nội dung theInfo
template <class InfoType>
Item<InfoType>::Item(InfoType theInfo)
{
	Info = theInfo;
	Previous = NULL;
	Next = NULL;
}

//Hiện thị nội dung phần tử
template <class InfoType>
void Item<InfoType>::Display()
{
	cout << Info << endl;
}

//---------------------------------------------------

//------------------LinkedList---------------------------
template <class InfoType>
class LinkedList
{
	private:
		Item<InfoType>* First;
		Item<InfoType>* Last;
		int Count;
	public:
		//Constructor: Tạo danh sách rỗng
		LinkedList();
		//Kiểm tra danh sách rỗng
		bool IsEmpty();
		//Thêm Info vào đầu danh sách
		void InsertFirst(InfoType theInfo);
		//Thêm info vào cuối danh sách
		void InsertLast(InfoType theInfo);
		//Thêm info vào danh sách có thứ tự tăng dần
		void InsertOrder(InfoType theInfo);
		//Tìm Info trong danh sách chưa có tứ thự
		Item<InfoType>* Find(InfoType theInfo);
		//Tìm info trong danh sách cso thứ tự tăng dần
		Item<InfoType>* FindOrder(InfoType theInfo);
		//Loại bỏ info ra danh sách chưa có thứ tự
		void Remove(InfoType theInfo, bool& error);
		//Loại bỏ Info vào danh sách có thự tự tăng dần
		void RemoveOrder(InfoType theInfo, bool& error);
		//Hiển thị danh sách theo chiều thuận
		void DisplayNext();
		//Hiển thị danh sách theo chiều nghịch
		void DisplayPrevious();
		//Hủy bỏ danh sách
		void Clear();
		//Destructor: Hủy bỏ danh sach
		~LinkedList();
};

//Constructor: Tạo danh sách rỗng
template <class InfoType>
LinkedList<InfoType>::LinkedList()
{
	First = NULL;
	Last = NULL;
	Count = 0;
}

//Kiểm tra danh sách rỗng
template <class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	return First == NULL;
}

//Thêm info vào đầu danh sách
template <class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);

	if (First != NULL)
		First->Previous = q;
	else
		Last = q;

	q->Next = First;
	First = q;
	Count++;
}

//Thêm info vào cuối danh sách
template <class InfoType>
void LinkedList<InfoType>::InsertLast(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);

	if (Last != NULL)
		Last->Next = q;
	else
		First = q;

	q->Previous = Last;
	Last = q;
	Count++;
}

//Thêm info vào danh sách có thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cont = true;
	Item<InfoType>* p = First;

	while (p != NULL && cont)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			cont = false;
		else
			p = NULL;

	if (p == First)
		InsertFirst(theInfo);
	else
	{
		if (p == NULL)
			InsertLast(theInfo);
		else
		{
			Item<InfoType> *q = new Item<InfoType>(theInfo);
			Item<InfoType>* tp = p->Previous;

			tp->Next = q;
			q->Next = p;

			p->Previous = q;
			q->Previous = tp;
		}
	}
}

//Tìm info trong danh sách chưa có thứ tự
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;

	return p;
}

//Tìm info trong danh sách có thứ tự tăng dần
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::FindOrder(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;
	return p;
}

//Loại bỏ info trogn danh sách chưa có thứ tự
template <class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;

	if (found)
	{
		Item<InfoType>* tp = p->Previous;
		Item<InfoType>* sp = p->Next;

		if (tp != NULL)
			tp->Next = sp;
		else
			First = sp;

		if (sp != NULL)
			sp->Previous = tp;
		else
			Last = sp;

		delete p;
		Count--;
	}
	error = !found;
}

//Loại info trong danh sách có thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* p = First;

	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;

	if (found)
	{
		Item<InfoType>* tp = p->Previous;
		Item<InfoType>* sp = p->Next;

		if (tp != NULL)
			tp->Next = sp;
		else
			First = sp;

		if (sp != NULL)
			sp->Previous = tp;
		else
			Last = tp;

		delete p;
		Count--;
	}
	error = !found;
}

//Hiện thị danh sách theo chiều thuận
template <class InfoType>
void LinkedList<InfoType>::DisplayNext()
{
	if (IsEmpty())
		cout << "Danh sach rong.\n";
	else
	{
		cout << "Noi dung: \n";
		Item<InfoType>* p = First;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu cua danh sach: " << Count << endl;
	}
}

//Hiện thị danh sách theo chiều nghịch
template <class InfoType>
void LinkedList<InfoType>::DisplayPrevious()
{
	if (IsEmpty())
		cout << "Danh sach rong.\n";
	else
	{
		cout << "Noi dung: \n";
		Item<InfoType>* p = Last;
		while (p != NULL)
		{
			p->Display();
			p = p->Previous;
		}
		cout << "So phan tu cua danh sach: " << Count << endl;
	}
}

//Hủy bỏ danh sách
template <class InfoType>
void LinkedList<InfoType>::Clear()
{
	Item<InfoType>* p;
	while (First != NULL)
	{
		p = First;
		First = p->Next;
		delete p;
	}
	Last = NULL;
	Count = 0;
}

//Destructor: Hủy danh sách
template <class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}

//----------------------------------------------------

#endif // !_HEADER_H_