#pragma once
#ifndef _FIRST_H_
#define _FIRST_H_

#include <iostream>
using namespace std;

//Lớp phần tử
template <class InfoType>
class Item
{
	public:
		InfoType Info;	//Nội dung của phần tử
		Item<InfoType>* Next;	//Phần tử kế tiếp
	public:
		//Constructor:Tạo phần tử mới có nội dung theInfo
		Item(InfoType theInfo);

		//Hiện thị nội dung của phần tử
		void Display();
};


template <class InfoType>
class LinkedList
{
	private:
		Item<InfoType>* First;
		int Count;
	public:
		//Constructor: tạo danh sách rỗng
		LinkedList();

		//Kiểm tra danh sách rỗng
		bool IsEmpty();

		//Thêm Info vào đầu danh sách
		void InsertFirst(InfoType theInfo);

		//Thêm Info vào danh sách có thứ tự tăng dần
		void InserOrder(InfoType theInfo);

		//Tìm Info trong danh sách chưa có thứ tự
		Item<InfoType>* Find(InfoType theInfo);

		//Tìm Info trong danh sách có thứ tự tăng dần
		Item<InfoType>* FindOrder(InfoType theInfo);

		//Tìn info trong danh sách chưa có thứ tự
		//bool Find(InfoType theInfo);

		//Tìm Info trong danh sách có thứ tự tăng dần
		//bool FindOrder(InfoType theInfo);

		//Loại Info trong danh sách chưa có thứ tự
		void Remove(InfoType theInfo, bool &error);

		//LOại Info trong danh sách có thứ tự tăng dần
		void RemoveOrder(InfoType theInfo, bool &error);

		//Sắp xếp thứ tự tăng dần
		void BubbleSort();

		//Hiện thị dánh sách
		void Display();

		//Hủy danh sách
		void Clear();

		//Destructor: Hủy danh sách
		~LinkedList();

	private:
		void Swap(InfoType& x, InfoType& y);
};

//--------------Item---------------------------------
//Constructor: tạo phần tử mới có nội dung theinfo
template <class InfoType>
Item<InfoType>::Item(InfoType theInfo)
{
	Info = theInfo;
	Next = NULL;
}

//Hiện thị nội dung phần tử
template <class InfoType>
void Item<InfoType>::Display()
{
	cout << Info << endl;
}


//--------------LinkedList--------------------------
//Constructor: Tạo danh sách rỗng
template <class InfoType>
LinkedList<InfoType>::LinkedList()
{
	First = NULL;
	Count = 0;
}

//Kiểm tra danh sách rỗng
template <class InfoType>
bool LinkedList<InfoType>::IsEmpty()
{
	bool result = First == NULL;
	return result;
}

//Thêm theInfo vào đầu danh sách
template <class InfoType>
void LinkedList<InfoType>::InsertFirst(InfoType theInfo)
{
	Item<InfoType>* q = new Item<InfoType>(theInfo);

	//Thêm phần tử q vào đầu danh sách
	q->Next = First;	//Phần tử q trỏ vào phần tử đầu tiên
	First = q;	//First là q
	Count++;	//Tăng số lượng phần tử
}

//Thêm info vào danh sách cso thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::InserOrder(InfoType theInfo)
{
	//Tìm vị trí thêm Info vào danh sách
	bool cont = true;		//còn tiếp tục
	Item<InfoType>* tp=NULL;		//tp là phần tử ngay trước p
	Item<InfoType>* p = First;	//p là phần tử đầu tiên
	//p còn là phần tử của danh sách và tiếp tục
	while (p != NULL && cont)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else
			cont = false;

	//Tạo phần tử mới q có khóa là theInfo
	Item<InfoType>* q = new Item<InfoType>(theInfo);
	if (p == First)	//p là phần tử đầu tiên
		//Thêm phần tử q vào đầu danh sách
		First = q;	//First trỏ q
	else
		//Thêm phần tử q giữa tp và p
		tp->Next = q;	//phần tử tp trỏ q
	q->Next = p;		//Phần tử q trỏ p
	Count++;		//Tăng số lương phần tử
}

//Tìm info trong danh sách chưa có thứ tự
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;	//chưa tìm thầy
	Item<InfoType>* p = First;	//p là phần tử dầu tiên
	//p là phần tử của danh sách và chưa tìm thấy
	while (p != NULL && !found)
		if (p->Info == theInfo)	//khóa của p==theInfo
			found == true;	//Tìm thấy
		else
			p = p->Next;	//p đến phần tử kế tiếp
	return p;
}

//Tìn Info trong danh sách chưa có thứ tự
/*template <class InfoType>
bool LinkedList<InfoType>::Find(InfoType theInfo)
{
	bool found = false;	//Chưa tìm thấy
	Item<InfoType>* p = First;	//p là phần tử đầu tiên
	p là phần tử của danh và chưa tìm thấy
	while (p != NULL && !found)
		if (p->Info == theInfo)	//Khóa của p=theInfo
			found = true;	//Tìm thấy
		else
			p = p->Next;	// đến phần tử kế tiếp
	return found;
}*/

//Tìm Info trong danh sách có thứ tự tăng dần
template <class InfoType>
Item<InfoType>* LinkedList<InfoType>::FindOrder(InfoType theInfo)
{
	bool found = false;	//Chưa tìm thấy
	Item<InfoType>* p = First;
	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p == NULL;
	return p;
}

//Tìm Info trong danh sách có thứ tự tăng dần
/*template <class InfoType>
bool LinkedList<InfoType>::FindOrder(InfoType theInfo)
{
	bool found = false;	//Chưa tìm thấy
	Item<InfoType>* p = First;
	while (p != NULL && !found)
		if (p->Info < theInfo)
			p = p->Next;
		else if (p->Info == theInfo)
			found = true;
		else
			p == NULL;
	return found;
}*/

//Loại bỏ Info trong danh sách chưa có thứ tự
template <class InfoType>
void LinkedList<InfoType>::Remove(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp;
	Item<InfoType>* p = First;
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
		if (p == First)
			First = p->Next;
		else
			tp->Next = p->Next;
		delete p;
		Count--;
	}
	error = !found;
}

//Loại bỏ Info trong danh sách có thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::RemoveOrder(InfoType theInfo, bool& error)
{
	bool found = false;
	Item<InfoType>* tp=NULL;
	Item<InfoType>* p = First;
	while (p != NULL && !found)
		if (p->Info < theInfo)
		{
			tp = p;
			p = p->Next;
		}
		else if (p->Info == theInfo)
			found = true;
		else
			p == NULL;
	if (found)
	{
		if (p == First)
			First = p->Next;
		else
			tp->Next = p->Next;
		delete p;
		Count--;
	}
	error = !found;
}

//Hoán đổi vị trí x, y
template <class InfoType>
void LinkedList<InfoType>::Swap(InfoType& x, InfoType& y)
{
	InfoType temp = x;
	x = y;
	y = temp;
}

//Sắp xếp thứ tự tăng dần
template <class InfoType>
void LinkedList<InfoType>::BubbleSort()
{
	Item<InfoType>* end = NULL;
	Item<InfoType>* last = NULL;
	bool flag = true;
	while (flag)
	{
		flag = false;
		Item<InfoType>* p = First;
		while (p != end)
		{
			Item<InfoType>* q = p->Next;
			if (q != end)
			{
				if (p->Info > q->Info)
				{
					flag = true;
					Swap(p->Info, q->Info);
					last = q;
				}
			}
			p = q;
		}
		end = last;
	}
}

//Hiện thị danh sách
template <class InfoType>
void LinkedList<InfoType>::Display()
{
	if (IsEmpty())
		cout << "Danh sach rong \n";
	else
	{
		cout << "Danh sach: \n";
		Item<InfoType>* p = First;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu: " << Count << endl;
	}
}

//Huy danh sách
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
	Count = 0;
}

//Destructor: Huy bo danh sach. Ket qua danh sach rong
template <class InfoType>
LinkedList<InfoType>::~LinkedList()
{
	Clear();
}
#endif // !_FIRST_H_