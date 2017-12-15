#include "list.h"

  void List::InserToHead(const DataType& d) // �������� ������� d ������
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

  void List::InserToTail(const DataType& d) // �������� ������� d ���������
  {
	if (Node* NewNode = new Node)
	{
		NewNode -> prew = tail;
		NewNode -> data = d;
		tail = NewNode;
	}
  };

  void List::InsertAfter(Node* node, const DataType& d) // �������� ������� d ����� ����� node
  {
	if (Node* NewNode = new Node)
	{
		NewNode -> data = d;
		NewNode -> next = node;
		NewNode -> prew = node -> prew;
		node -> prew = NewNode;
		node -> next = NewNode;
	}
  };

  void List::Delete(const DataType& d) // ������� ����� �� ��������� data = d
  {
	Node* i = head;
	while (i)
	{
		if (i -> data = d)
		{
			i -> prew -> next = i -> next;
			i -> next -> prew = i -> prew;
			delete(i);
			if (head == i)
				if (i -> next)
					head = i -> next;
				else 
					head = i -> prew;
		}
		i = i -> next;
	}
  };

  Node* List::Search(const DataType& d) // ����� ��������� �� ����� �� ��������� data = d
  {
	Node* i = head;
	while ((i != NULL) && (i -> data != d))
	{
		i = i->next;
	}
	return i;
  };

  void List::Clean() // ������� ��� ������
  {
	Node* NewHead = head;
	while (NewHead)
	{
		NewHead = head -> next;
		delete(head);
	}
	head = NULL;
  };

  int List::GetSize() // ������ ����� ������� � ������
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

  Node* List::GetHead() // �������� ��������� �� ������ ����� ������
  {
		return head;
  };

  Node* List::GetTail() // �������� ��������� �� ��������� ����� ������
  {
		return tail;
  };

  void List::Inverse() // ������������� ������, �.�. ������ ������ ���� � �������� �������
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

  List List::Merge(Node* node, const List& list2) // ������� ������3, ������� ������2 � ������� ������ ����� ��������� node  
  {
		List Res;
		Node* i = tail;
		while (i != node)
		{
			Res.InserToHead(i -> data);
			i = i -> prew;
		}
		Node* j = tail;
		while (j != node)
		{
			Res.InserToHead(j -> data);
			j = j -> prew;
		}
		while (i != NULL)
		{
			Res.InserToHead(i -> data);
			i = i -> prew;
		}
		return Res;
  };

  List List::Merge(const List& list2) // ������� ������3, ������� � ����� �������� ������ ������2
  {
		List Res;
		Node* i = tail;
		while (i)
		{
			Res.InserToHead(i -> data);
			i = i -> prew;
		}
		i = list2.tail;
		while (i)
		{
			Res.InserToHead(i -> data);
			i = i -> prew;
		}
		return Res;
  };