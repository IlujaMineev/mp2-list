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

  void List::Delete(const DataType& d) // ������� ����� �� ��������� data = d
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
  Node* List::Search(const DataType& d) // ����� ��������� �� ����� �� ��������� data = d
  {
	Node* i = head;
	while (i -> data != d)
	{
		i = i->next;
	}
  };

  void List::Clean() // ������� ��� ������
  {
	Node* NewHead;
	while (NewHead)
	{
		NewHead = head -> next;
		delete(head);
		head = NewHead;
	}

  };

  int List::GetSize() // ������ ����� ������� � ������
  {
  
  };

  Node* List::GetHead() // �������� ��������� �� ������ ����� ������
  {
  
  };

  void Inverse() // ������������� ������, �.�. ������ ������ ���� � �������� �������
  {
  
  };

  List List::Merge(Node* node, const List& list2) // ������� ������3, ������� ������2 � ������� ������ ����� ��������� node  
  {
	List Res;
	Node* src = head;
	while (src)
	{
		
	}

  };

  List List::Merge(const List& list2) // ������� ������3, ������� � ����� �������� ������ ������2
  {
  
  };