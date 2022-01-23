#pragma once
#ifndef _LKDV_HEASER_H
#define _LKDV_HEASER_H

#include <iostream>
using namespace std;

//----------------------Item------------------
//Lớp phần tử
template <class InfoType>
class Item {
	public:
		InfoType Info;
		Item<InfoType>* Next;
	public:
		//Constructor: Tạo phần tử mới có nội dung TheInfo
		Item(InfoType theInfo);
		//Constructor: tạo phần tử trống
		Item();
		//Hiện thị nội dung của phần tử
		void Display();
};

//Constructor: Tạo phần tử mới có nội dung theInfo
template <class InfoType>
Item<InfoType>::Item(InfoType theInfo)
{
	Info = theInfo;
	Next = NULL;
}

//Constructor: Tạo phần tử rỗng
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

//------------------LinkedList-----------------------------
template <class InfoType>
class LinkedList
{
	private:
		Item<InfoType>* Header;
		int Count;
	public:
		//Constructor: Tạo danh sách rỗng
		LinkedList();
		//Kiểm tra dánh sách rỗng
		bool IsEmpty();
		//Thêm info vào đầu danh sách
		void InsertFirst(InfoType theInfo);
		//Thêm info vào danh sách có phần tử tăng dần
		void InsertOrder(InfoType theInfo);
		//Tìm info trong danh sách chưa có thứ tự
		Item<InfoType>* Find(InfoType theInfo);
		//Tìm info trogn danh sách có thứ tự tăng dần
		Item<InfoType>* FindOrder(InfoType theInfo);
		//Loại bỏ Info trong danh sách chưa có thứ tự
		void Remove(InfoType theInfo, bool& error);
		//Loại bỏ info trogn danh sách có thứ tự tăng dần
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
	Header->Next = Header;
	Count = 0;
}

//Kiểm tra danh sách rỗng
template <class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	return Header->Next == Header;
}

//Thêm phần tử vào đầu danh sách
template <class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	q->Next = Header->Next;
	Header->Next = q;
	Count++;
}

//Thêm phần tử vào danh sách có thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cont = true;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = tp->Next;

	while (p != Header && cont)
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

//Tìm phần tử trong danh sách chưa có thứ tự
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;

	while (p != Header && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;
	if (!found)
		p = NULL;
	return p;
}

//Tìm info trong danh sách có thứ tự
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::FindOrder(InfoType theInfo)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;

	while (p != Header && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p = Header;
	if (!found)
		p = NULL;

	return p;
}

//Loại bỏ Info trong danh sách chưa có thứ tự
template <class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp = Header;
	Item<InfoType>* p = tp->Next;

	while (p != Header && !found)
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

	while (p != Header && !found)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else if (p->Info == theInfo)
			found = true;
		else
			p = Header;

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
		while (p != Header)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu cua danh sach: " << Count << endl;
	}
}

//Huy danh sach
template <class InfoType>
void LinkedList<InfoType>::Clear()
{
	Item<InfoType>* p;
	while (Header->Next != Header)
	{
		p = Header->Next;
		Header->Next = p->Next;
		delete p;
	}
	Count = 0;
}

//Destructor: Huy danh sach
template <class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}

//---------------------------------------------------------------

#endif // !_LKDV_HEASER_H