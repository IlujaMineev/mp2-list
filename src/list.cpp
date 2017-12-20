#include "list.h"

  List& List::operator=(List& list2)
  {
	Clean();
	Node* tek = list2.GetHead();
	InserToHead(tek -> data);
	while (tek != NULL)
	{
		InserToTail(tek -> data);
		tek = tek -> next;
	}
	return *this;
  };

  void List::InserToHead(const DataType& d) // вставить элемент d первым
  {
	if (Node* NewNode = new Node)
	{
		NewNode -> next = head;
		NewNode -> data = d;
		head = NewNode;	
	}
  };

  void List::InserToTail(const DataType& d) // вставить элемент d последним
  {
	if (Node* NewNode = new Node)
	{
		NewNode -> data = d;
		NewNode -> next = NULL;
		if (tail)
			tail -> next = NewNode;
		tail = NewNode;
	}
  };

  void List::InsertAfter(Node* node, const DataType& d) // вставить элемент d после звена node
  {
	if (Node* NewNode = new Node)
	{
		NewNode -> data = d;
		NewNode -> next = node -> next;
		node -> next = NewNode;
	}
  };

  void List::Delete(const DataType& d) // удалить звено со значением data = d
  {
	Node* i = head;
	Node* what;
	if (i -> data == d)
	{
		head = i -> next;
		delete(i);
	}
	while (i)
	{
		if (i -> next -> data == d)
		{
			what = i -> next;
			i -> next = i -> next -> next;
			if (what -> data == tail -> data)
				tail = i;
			delete(what);
		}
		i = i -> next;
	}
  };

  Node* List::Search(const DataType& d) // найти указатель на звено со значением data = d
  {
	Node* i = head;
	while ((i != NULL) && (i -> data != d))
	{
		i = i->next;
	}
	if (i -> data == d)
		return i;
	else
		return 0;
  };

  void List::Clean() // удалить все звенья
  {
	Node* NewHead = head;
	while (NewHead)
	{
		NewHead = head -> next;
		delete(head);
	}
	head = NULL;
  };

  int List::GetSize() const // узнать число звеньев в списке
  {
	  int it = 0;
	  Node* i = head;
	  while (i != NULL)
	{
		i = i->next;
		it++;
	}
	return it;
  };

  Node* List::GetHead() const // получить указатель на первое звено списка
  {
		return head;
  };

  Node* List::GetTail() const // получить указатель на последнее звено списка
  {
		return tail;
  };

  void List::Inverse() // инвертировать список, т.е. звенья должны идти в обратном порядке
  {
		List src;
		Node* i = head;
		while (i != NULL)
		{
			src.InserToHead(i -> data);
			i = i->next;
		}
		(*this).Clean();
		i = src.GetHead();
		for (int s = 0; s < src.GetSize(); s++)
		{
			(*this).InserToHead(i -> data);
			i = i -> next;
		}
  };

  List List::Merge(Node* node, List& list2) // создать список3, добавив список2 в текущий список после указателя node  
  {
		List Res = *this;
		Node* i = list2.head;
		Node* tek = node;
		while (i)
		{
			Res.InsertAfter(tek, i -> data);
			tek = tek -> next;
			i = i -> next;
		}
		return Res;
  };

  List List::Merge(List& list2) // создать список3, добавив в конец текущего списка список2
  {
		List Res = *this;
		Node* i = list2.head;
		Node* tek = tail;
		while (i)
		{
			Res.InsertAfter(tek, i -> data);
			tek = tek -> next;
			i = i -> next;
		}
		return Res;
  };

  bool List::operator==(const List& list2)
  {
	  if (GetSize() == list2.GetSize())
	  {
		  Node* tek1 = head;
		  Node* tek2 = list2.head;
		  while (tek1)
		  {
			  if (tek1 -> data != tek2 -> data)
				  return false;
			  tek1 = tek1 -> next;
			  tek2 = tek2 -> next;
		  }
	  }
	  else
		  return false;
	  return true;
  };
