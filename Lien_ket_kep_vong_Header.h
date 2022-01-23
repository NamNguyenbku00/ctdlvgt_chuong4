#pragma once
#ifndef _LKKV_HEADER_H_
#define _LKKV_HEADER_H_

#include <iostream>
using namespace std;

//-----------------Item----------------------
//Lớp phần tử
template <class InfoType>
class Item
{
	public:
		InfoType Info;
		Item<InfoType>* Next;
		Item<InfoType>* Previous;
	public:
		//Constructor: Tạo phần tử mới có nội dung info
		Item(InfoType theInfo);
		//Constructor: Tạo phần tử rỗng
		Item();
		//Hiển thị nội dung của phần tử
		void Display();
};

//Constructor: Tạo phan tu có noi dung theInfo
template <class InfoType>
Item<InfoType>::Item(InfoType theInfo)
{
	Info = theInfo;
	Next = NULL;
	Previous = NULL;
}

//Constructor: Tạo phần tử trống
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

//-------------------------------------

//----------------LinkedList-----------------
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
		//Thêm info vào đầu danh sách
		void InsertFirst(InfoType theInfo);
		//Thêm info vào cuối danh sách
		void InsertLast(InfoType theInfo);
		//thêm info vào danh sách có thứ tự tăng dần
		void InsertOrder(InfoType theInfo);
		//Tìm info cho danh sach chưa có thứ tự
		Item<InfoType>* Find(InfoType theInfo);
		//Tìm info vào danh sách có thứ tự tăng dần
		Item<InfoType>* FindOrder(InfoType theInfo);
		//Loại bỏ info cho danh sách chưa có thứ tự
		void Remove(InfoType theInfo, bool &error);
		//Loại bỏ info cho danh sách có thứ tự tăng dần
		void RemoveOrder(InfoType theInfo, bool& error);
		//Hiển thị danh sách theo chiều thuận
		void DisplayNext();
		//Hiển thị danh sách theo chiều nghịch
		void DisplayPrevious();
		//Hủy bỏ danh sách
		void Clear();
		//Destructor: Hủy bỏ danh sách
		~LinkedList();
};

//Constructor: Tạo dánh sách rỗng
template <class InfoType>
LinkedList<InfoType>::LinkedList()
{
	Header = new Item<InfoType>();
	Header->Next = Header;
	Header->Previous = Header;
	Count = 0;
}

//Kiểm tra danh sách rỗng
template <class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	return Header->Next == Header;
}

//Thêm info vào đầu danh sách
template <class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	Item<InfoType>* sp = Header->Next;

	Header->Next = q;
	q->Next = sp;

	sp->Previous = q;
	q->Previous = Header;
	Count++;
}

//Thêm info vào cuối danh sách
template <class InfoType>
void LinkedList<InfoType>::InsertLast(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	Item<InfoType>* tp = q->Previous;

	tp->Next = q;
	q->Next = Header;

	Header->Previous = q;
	q->Previous = tp;
	Count++;
}

//Thêm info vào danh sách cho thứ tự tăng dân
template <class InfoType>
void LinkedList<InfoType>::InsertOrder(InfoType theInfo)
{
	bool cont = true;
	Item<InfoType>* p = Header->Next;
	
	while (p != Header && cont)
		if (p->Info < theInfo)
			p = p->Next;
		else
			cont = false;

	Item<InfoType>* q = new Item<InfoType>(theInfo);
	Item<InfoType>* tp = p->Previous;

	tp->Next = q;
	q->Next = p;

	q->Previous = tp;
	p->Previous = q;

	Count++;
}

//Tìm Info trong danh sách chưa có thứ tự
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

//Tìm info trong chuỗi có thứ tự tăng dần
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
			p = NULL;
	return p;
}

//Loại bỏ info trogn danh sách chưa có thứ tự
template <class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool &error)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;

	while (p != Header && !found)
		if (p->Info == theInfo)
			found = true;
		else
			p = p->Next;

	if (found)
	{
		Item<InfoType>* tp = p->Previous;
		Item<InfoType>* sp = p->Next;

		tp->Next = sp;
		sp->Previous = tp;
		delete p;
		Count--;
	}
	error = !found;
}

//Loại bỏ info trong danh sách tăng dần
template <class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* p = Header->Next;

	while (p != Header && !found)
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

		tp->Next = sp;
		sp->Previous = tp;
		delete p;
		Count--;
	}
	error = !found;
}

//Hiển thị theo chiều thuân
template <class InfoType>
void LinkedList<InfoType>::DisplayNext()
{
	if (IsEmpty())
		cout << "Danh sach rong.\n";
	else
	{
		cout << "Noi dung theo chieu thuan: \n";
		Item<InfoType>* p = Header->Next;
		while (p != Header)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu: " << Count << endl;
	}
}

//Hiển thị danh sách theo chiều nghịch
template <class InfoType>
void LinkedList<InfoType>::DisplayPrevious()
{
	if (IsEmpty())
		cout << "Danh sach rong.\n";
	else
	{
		cout << "Noi dung theo chieu nghịch: \n";
		Item<InfoType>* p = Header->Previous;
		while (p != Header)
		{
			p->Display();
			p = p->Previous;
		}
		cout << "So phan tu: " << Count << endl;
	}
}

//Xóa danh sách
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
	Header->Previous = Header;
	Count = 0;
}

//Destructor: Xóa danh sách
template <class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}

//--------------------------------------

#endif // !_LKKV_HEADER_H_
