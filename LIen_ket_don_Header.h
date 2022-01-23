#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
using namespace std;

//-------------Item---------------------------
//Lớp phần tử
template <class InfoType>
class Item
{
	public:
		InfoType Info;
		Item<InfoType>* Next;
	public:
		Item(InfoType theInfo);
		Item();
		void Display();
};

//Tạo phần tử mới có nội dung theInfo
template <class InfoType>
Item<InfoType>::Item(InfoType theInfo)
{
	Info = theInfo;
	Next = NULL;
}

//Constructor:Tạo phần tử trống
template <class InfoType>
Item<InfoType>::Item()
{

}

//Hiện thị phần tử
template <class InfoType>
void Item<InfoType>::Display()
{
	cout << Info << endl;
}
//--------------------------------------------------------


//----------------LinkedList----------------------------------
template <class InfoType>
class LinkedList
{
	private:
		Item<InfoType>* Header;
		int Count;
	public:
		//Constructor: Tạo danh sách rỗng
		LinkedList();

		//Kiểm tra danh sách rỗng
		bool IsEmpty();

		//Thêm Info vào đầu danh sách
		void InsertFirst(InfoType theInfo);

		//Thêm Info vào danh sách có thứ tự tăng dần
		void InsertOrder(InfoType theInfo);

		//Tìm theInfo trong danh sách chưa có thứ tự
		Item<InfoType>* Find(InfoType theInfo);

		//Tìm info trong danh sách tăng dần
		Item<InfoType>* FindOrder(InfoType theInfo);

		//Loại bỏ theinfo trong danh sách chưa có thứ tự
		void Remove(InfoType theInfo, bool& error);

		//Loại bỏ theInfo trong danh sách tăng dần
		void RemoveOrder(InfoType theInfo, bool& error);

		//Hiện thị danh sách
		void Display();

		//Hủy bỏ danh sách
		void Clear();

		//Destructor: Hủy bỏ danh sách
		~LinkedList();
};

//Constructor: Tạo danh sách rỗng
template <class InfoType>
LinkedList<InfoType>::LinkedList()
{
	Header = new Item<InfoType>();
	Header->Next = NULL;
	Count = 0;
}

//Kiểm tra danh sách rỗng
template <class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	return Header->Next == NULL;
}

//Thêm Info vào đầu danh sách
template <class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	q->Next = Header->Next;
	Header->Next = q;
	Count++;
}

//Thêm info vào danh sách có thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cont = true;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = tp->Next;

	while (p != NULL && cont)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else
			cont = false;

	Item<InfoType>* q = new Item<InfoType>(theInfo);
	tp->Next = q;
	q->Next = p;
	Count++;
}

//Tìm info trong danh sách chưa có thứ tự
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;
	
	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;

	return p;
}

//Tim info trong danh sách có thứ tự tăng dân
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::FindOrder(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;

	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;

	return p;
}

//Loại bỏ info trong danh sách chưa có thứ tự
template <class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = tp->Next;

	while (p != NULL && !found)
		if (p->Info == theInfo)
			found = true;
		else
		{
			tp = p;
			p = p->Next;
		}

	if (found)
	{
		tp->Next = p->Next;
		delete p;
		Count--;
	}
	
	error = !found;
}

//Loại bỏ info trong danh sách có thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = tp->Next;

	while (p != NULL && !found)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else if (p->Info == theInfo)
			found = true;
		else
			p = NULL;

	if (found)
	{
		tp->Next = p->Next;
		delete p;
		Count--;
	}

	error = !found;
}

//Hiện thị danh sách
template <class InfoType>
void LinkedList<InfoType>::Display()
{
	if (IsEmpty())
		cout << "Danh sach rong.\n";
	else
	{
		cout << "Danh sach: \n";
		Item<InfoType>* p = Header->Next;
		
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu: " << Count << endl;
	}
}

//Huy bo danh sach
template <class InfoType>
void LinkedList<InfoType>::Clear()
{
	Item<InfoType>* p;
	while (Header->Next != NULL)
	{
		p = Header->Next;
		Header->Next = p->Next;
		delete p;
	}
	Count = 0;
}

//Deconstructor: Huy danh sách.
template <class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}

//------------------------------------------------------------

#endif // !_HEADER_H_
