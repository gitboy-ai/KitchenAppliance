//#include <iostream>
//#include "CKitchenApplianceMicrowave.h"
//#include "CKitchenApplianceRefrigerator.h"
//#include "Node.h"
//#include <string>
//
////template <typename T>
////template <typename T, size_t L>
//
///*
//template <class X> class point
//{
//	point(T x, T y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//	T x;
//	T y;
//};
//*/
//
///*
//T difference(const T& x, const T& y)
//{
//	return x-y;
//}
//*/
//
////class MyArray
////{
////	T arr[L];
////public:
////	MyArray() {}
////};
//
//
///*void displaySide(const int cube[6][3][3], int color)
//{
//	for (int f = 0; f < 6; f++)
//	{
//		for (int r = 0; r < 3; r++)
//		{
//			if (cube[f][r][0] != color)
//			{
//				break;
//			}
//			else
//			{
//				for (int c = 0; c < 3; c++)
//				{
//					std::cout << cube[f][r][c];
//				}
//				std::cout << std::endl;
//			}
//		}
//	}
//}*/
//void displaySide(const int cube[6][3][3], int color)
//{
//	for (int f = 0; f < 6; f++)
//	{
//		for (int r = 0; r < 3; r++)
//		{
//			if (*(*(*(cube + f) + r) + 0) != color) //<- how it happens internally; same as (cube[f][r][0] != color)
//			{
//				break;
//			}
//			else
//			{
//				for (int c = 0; c < 3; c++)
//				{
//					std::cout << *(*(*(cube + f) + r) + c);
//				}
//				std::cout << std::endl;
//			}
//		}
//	}
//}
//
//void pointer()
//{
//	int i = 10, j = 20;
//	int* p = &i;
//	//int& r = &i;
//	std::cout << i << "\n" << *p << "\n" << p << "\n" << &i << "\n" << &i << "\t" << &j << std::endl;
//	p = &j;
//	std::cout << i << "\n" << *p << "\n" << p << "\n" << &i << "\n";
//	p = &j;
//	CKitchenApplianceMicrowave* pMicrowave;
//	CKitchenApplianceMicrowave l_objMicrowave;
//	pMicrowave = &l_objMicrowave;
//	pMicrowave->switchOn();
//
//	//red = 1
//	//blue = 2
//	//green = 3
//	//yellow = 4
//	//white = 5
//	//orange = 6
//
//	int rubiksCube[6][3][3] =
//	{
//		{
//			{{1},{1},{1}},
//			{{1},{1},{1}},
//			{{1},{1},{1}}
//		},
//		{
//			{{2},{2},{2}},
//			{{2},{2},{2}},
//			{{2},{2},{2}}
//		},
//		{
//			{{3},{3},{3}},
//			{{3},{3},{3}},
//			{{3},{3},{3}}
//		},
//		{
//			{{4},{4},{4}},
//			{{4},{4},{4}},
//			{{4},{4},{4}}
//		},
//		{
//			{{5},{5},{5}},
//			{{5},{5},{5}},
//			{{5},{5},{5}}
//		},
//		{
//			{{6},{6},{6}},
//			{{6},{6},{6}},
//			{{6},{6},{6}}
//		}
//	};
//
//	//int*** pointersToCube = &rubiksCube;
//	int l_sideColor;
//	std::cin >> l_sideColor;
//	void (*pfnDisplaySide)(const int[6][3][3], int) = &displaySide;
//	pfnDisplaySide(rubiksCube, l_sideColor);	//caliing from pointer
//	//displaySide(rubiksCube, l_sideColor);		//calling directly
//}
//
//void templates()
//{
//	/*
//	std::cout << sizeof(float) << std::endl;
//	std::cout << sizeof(int) << std::endl;
//	std::cout << sizeof(double) << std::endl;
//	*/
//	//int t = difference<int>(3, 1);
//	//std::cout << t << std::endl;
//	//myFunction<int>(3, 6);
//	/*MyArray<CKitchenApplianceMicrowave*, 10> microwaveShelf;
//	MyArray<CKitchenApplianceRefrigerator*, 10> refrigeratorShelf;*/
//}
//
//
//int main()
//{
//	
//	int myAge = 14;
//	int meow = 2;
//	int woof = 4;
//	int oink = 38;
//	int moo = 100;
//	int quack = 675;
//
//	
//	//std::string myName = "Yuvraj";
//	Node* myLinkedList = new Node(&myAge, node_type_int);
//	//myLinkedList->addNext(myName);
//	Node* intermediateNode = (myLinkedList->addNext(&meow, node_type_int))->addNext(&woof, node_type_int);
//	((intermediateNode->addNext(&oink, node_type_int))->addNext(&moo, node_type_int))->addNext(&quack, node_type_int);
//	myLinkedList->display(myLinkedList);
//	
//}