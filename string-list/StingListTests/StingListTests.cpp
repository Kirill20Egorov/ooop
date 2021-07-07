#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../string-list/StringList.h"
#include <iostream>

SCENARIO("Create empty list and try to add elements")
{
	CStringList list;
	REQUIRE(0 == list.GetSize());
	REQUIRE(list.IsEmpty() == true);
	list.PushBack("Mama");
	REQUIRE(1 == list.GetSize());
	REQUIRE(list.GetFrontElement() == "Mama");
	REQUIRE(list.GetBackElement() == "Mama");
	list.PushBack("Papa");
	list.PushFront("Text");
	REQUIRE(list.GetFrontElement() == "Text");
	REQUIRE(list.GetBackElement() == "Papa");
	REQUIRE(list.GetSize() == 3);
	list.Clear();
	REQUIRE(list.GetSize() == 0);
	REQUIRE(list.IsEmpty() == true);
	using namespace std;
	CStringList lst;
	lst.PushBack("one");
	lst.PushBack("two");
	lst.PushBack("three");
	lst.PushBack("four");
	lst.PushBack("two");
	auto it = ++lst.begin();
	lst.Append(it,"hello");
	--it;
	for (auto i : lst)
	{
		cout << i << endl;
	}
	cout << endl;
	lst.Erase(--it);
	auto f = lst.end();
	for (auto i : lst)
	{
		cout << i << endl;
	}
}

