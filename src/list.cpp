#include "list.h"

  List& List::operator=(const List& list2) //���������
  {
	List lst(list2);
	Clean();
	Node* tek = lst.GetHead();
	while (tek != NULL)
	{
		InserToTail(tek -> data);
		tek = tek -> next;
	}
	return *this;
  };

  List::List(const List& list2) //���������
  {
	if (list2.head != NULL)
	{
		Node* tek = list2.GetHead();
		head = NULL;
		tail = NULL;
		while (tek != NULL)
		{
			InserToTail(tek -> data);
			tek = tek -> next;
		}
	}
	else
	{
		head = NULL;
		tail = NULL;
	}
  };

  void List::InserToHead(const DataType& d) // �������� ������� d ������ //���������
  {
		Node* NewNode = new Node;
		NewNode -> next = head;
		NewNode -> data = d;
		head = NewNode;
		if (tail == NULL)
			tail = head;
  };

  void List::InserToTail(const DataType& d) // �������� ������� d ��������� //���������
  {
	   Node* NewNode = new Node;
		NewNode -> data = d;
		NewNode -> next = NULL;
		if (tail)
			tail -> next = NewNode;
		else
			head = NewNode;
		tail = NewNode;
  };

  void List::InsertAfter(Node* node, const DataType& d) // �������� ������� d ����� ����� node //���������
  {
	if (head)
	{
		if (node)
		{
			Node* NewNode = new Node;
			NewNode -> data = d;
			NewNode -> next = node -> next;
			node -> next = NewNode;
		}
	}
	else
		throw "insert after for empty list";
  };

  void List::Delete(const DataType& d) // ������� ����� �� ��������� data = d //���������
  {
	Node* i = head;
	Node* what;
	if (head)
	{
		if (i -> data == d)
		{
			head = i -> next;
			delete(i);
		}
		else
		{
				while ((i -> next != NULL) && (i -> next -> data != d))
				{
					i = i -> next;
				}
				if ((i -> next != NULL) && (i -> next -> data == d))
				{
					what = i -> next;
					i -> next = what -> next;
					delete(what);
				}
		}
	}
  };

  Node* List::Search(const DataType& d) // ����� ��������� �� ����� �� ��������� data = d //���������
  {
	Node* i = head;
	if (head)
	{
		while ((i != NULL) && (i -> data != d))
		{
			i = i->next;
		}
		if ((i != NULL) && (i -> data == d))
			return i;
		else
			return 0;
	}
	else
		return 0;
  };

  void List::Clean() // ������� ��� ������ //���������
  {
	Node* NewHead = head;
	while (head)
	{
		NewHead = head -> next;
		delete(head);
		head = NewHead;
	}
	head = NULL;
	tail = NULL;
  };

  int List::GetSize() const // ������ ����� ������� � ������ //���������
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

  Node* List::GetHead() const // �������� ��������� �� ������ ����� ������ //���������
  {
		return head;
  };

  Node* List::GetTail() const // �������� ��������� �� ��������� ����� ������ //���������
  {
		return tail;
  };

  void List::Inverse() // ������������� ������, �.�. ������ ������ ���� � �������� ������� //���������
  {
		List src = *this;
		Node* i = src.head;
		Clean();
		while (i != NULL)
		{
			InserToHead(i -> data);
			i = i->next;
		}
  };

  List List::Merge(Node* node, List& list2) // ������� ������3, ������� ������2 � ������� ������ ����� ��������� node  //���������
  {
	  if (node)
	  {
		List Res(*this);
		Node* i = list2.head;
		Node* tek = Res.Search(node -> data);
		while (i)
		{
			Res.InsertAfter(tek, i -> data);
			tek = tek -> next;
			i = i -> next;
		}
		return Res;
	  }
	  else
		  return *this;
  };

  List List::Merge(List& list2) // ������� ������3, ������� � ����� �������� ������ ������2 //���������
  {
		List Res(*this);
		Node* i = list2.head;
		while (i)
		{
			Res.InserToTail(i -> data);
			i = i -> next;
		}
		return Res;
  };

  bool List::operator==(const List& list2) const
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
