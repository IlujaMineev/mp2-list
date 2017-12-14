#include "list.h"

  void List::InserToHead(const DataType& d) // вставить элемент d первым
  {
	if (Node* NewNode = new Node)
	{
		if (head)
			head -> prew = NewNode;
		NewNode -> next = head;
		NewNode -> data = d;
		head = NewNode;	
	}
  };

  void List::InserToTail(const DataType& d) // вставить элемент d последним
  {
	if (Node* NewNode = new Node)
	{
		NewNode -> prew = tail;
		NewNode -> data = d;
		tail = NewNode;
	}
  };

  void List::InsertAfter(Node* node, const DataType& d) // вставить элемент d после звена node
  {
	Node* temp;
	if (Node* NewNode = new Node)
	{
		NewNode -> data = d;
		NewNode -> next = node;
		NewNode -> prew = node -> prew;
		node -> prew = NewNode;
		node -> next = NewNode;
	}
  };

  void List::Delete(const DataType& d) // удалить звено со значением data = d
  {
	Node* i;
	while (i)
	{
		if (i -> data = d)
		{
			i -> prew -> next = i -> next;
			i -> next -> prew = i -> prew;
			delete(i);
			head = i;
		}
	};
  };
  Node* List::Search(const DataType& d) // найти указатель на звено со значением data = d
  {
	Node* i = head;
	while (i -> data != d)
	{
		i = i->next;
	}
  };

  void List::Clean() // удалить все звенья
  {
	Node* NewHead;
	while (NewHead)
	{
		NewHead = head -> next;
		delete(head);
		head = NewHead;
	}

  };

  int List::GetSize() // узнать число звеньев в списке
  {
  
  };

  Node* List::GetHead() // получить указатель на первое звено списка
  {
  
  };

  void Inverse() // инвертировать список, т.е. звенья должны идти в обратном порядке
  {
  
  };

  List List::Merge(Node* node, const List& list2) // создать список3, добавив список2 в текущий список после указателя node  
  {
	List Res;
	Node* src = head;
	while (src)
	{
		
	}

  };

  List List::Merge(const List& list2) // создать список3, добавив в конец текущего списка список2
  {
  
  };