#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
	List* list = new DoubleLinkedList();

    list->CreateMonster("Wolf", 10);
    list->CreateMonster("Slime", 5);
    list->CreateMonster("Dragon", 100);

    std::cout << "=======prt============" << std::endl;
    list->PrintMonsters();

    list->Delete("Wolf");
    //list->Delete("Slime");
    list->Delete("Dragon");
    std::cout << "\n==========Delte_result============" << std::endl;
    list->PrintMonsters();


    list->DeleteAll();
    std::cout << "\n=========DelteAll_Result============" << std::endl;
    list->PrintMonsters();

	return 0;
}