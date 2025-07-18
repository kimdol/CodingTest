#include <iostream>
#include <functional>
#include "DoubleLinkedList.h"


// 클로저를 반환하는 함수
std::function<int(int)> adder(int value) {
    return [value](int x) -> int { return value + x; };
}


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

    // 클로저 생성
    auto add_five = adder(5);

    // 클로저 사용
    std::cout << "10 + 5 = " << add_five(10) << std::endl;

	return 0;
}