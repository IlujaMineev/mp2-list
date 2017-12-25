#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
  DataType data;
  Node* next;
  // здесь могут быть конструкторы, методы, деструктор Node
};

class List
{
	Node* head;
	Node* tail;
  // любые поля
public:
  List() 
  {
	  head = NULL;
	  tail = NULL;
  };
  List(const List& list2); //									  				 												   +
  List& operator=(const List& list2); //																						+
  ~List() {Clean();}; //																											+

  void InserToHead(const DataType& d); // вставить элемент d первым													+
  void InserToTail(const DataType& d); // вставить элемент d последним												+
  void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node						+
  void Delete(const DataType& d); // удалить звено со значением data = d											+
  Node* Search(const DataType& d); // найти указатель на звено со значением data = d							+
  void Clean(); // удалить все звенья																							+
  int GetSize() const; // узнать число звеньев в списке																	+			
  Node* GetHead() const; // получить указатель на первое звено списка												+
  Node* GetTail() const; // получить указатель на последнее звено списка											+

  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
  List Merge(Node* node, List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  List Merge(List& list2); // создать список3, добавив в конец текущего списка список2

  void PrintList()
  {
	  Node* x = GetHead();
	  while (x)
	  {
		  cout<<x -> data<<" -> ";
		  x = x -> next;
	  }
	  cout<<"0"<<endl;
  };

  friend ostream& operator<<(ostream& os, List& l)
  {
	  Node* A = l.GetHead();
	  while (A)
	  {
		  cout<<A -> data<<" -> ";
		  A = A -> next;
	  }
	  cout<<endl;
  };

  bool operator==(const List& list2) const;
};

#endif