#include<iostream>
#include"LIst.h"
#include"BinaryTree.h"
using namespace std;
typedef void(*VFUNC)(void);
/*
typedef void (*)()     VE;
int   arr[i]     int []*/
void PrintTable(VFUNC table[])//VFUNC * table，数组里面都是指针，以0结束
{
	cout << "虚表指针" << table << endl;
	for (size_t i = 0; table[i] != nullptr; ++i)
	{
		cout << "vatable" << i<<" ：   "<< table[i];
		VFUNC vf = table[i];
		vf();

	}
}
//多态使用虚函数表来实现
//虚函数在编译阶段生成，存储在静态区，推荐把基类的析构函数定义为虚函数，
//虚函数表指针是在构造函数初始化列表阶段初始化的

class Base1
{
public:
	virtual void func1() { cout << "我是base1函数1" << endl; }
	virtual void func2() { cout << "我是base1函数2" << endl; }
	int a;

};

class Base2
{
public:
	virtual void func1() { cout << "我是base2函数1" << endl; }
	virtual void func2() { cout << "我是base2函数2" << endl; }
	int a;

};

class Base3
{
public:
	virtual void func1() { cout << "我是base3函数1" << endl; }
	virtual void func2() { cout << "我是base3函数2" << endl; }
	int aaa;

};

class Derive : public Base2,public Base1,public Base3
{
public:
	virtual void func1() { cout << "我是派生类函数1" << endl; }
	virtual void func3() { cout << "我是派生类函数3" << endl; }
	virtual void func4(){}
	int a;
};
//
//
//class Derive2 :public Base1
//{
//public:
//	virtual void func1() { cout << "我是第二个派生类函数1" << endl; }
//};

void test_duotai(Base1 &base)
{
	base.func1();
}
void test1()
{
#if 0
	PNode phead=nullptr;
	ListInit(&phead);
	int a[6] = { 1,2,3,4,5,6 };
	for (int i = 1; i <= sizeof(a) / sizeof(a[0]); i++)
	{
		push_back(&phead, a[i - 1]);
	}
	print(phead);
	cout << "---------------------------"<<endl;
	//pop_front(&phead);
	pop_back(&phead);
	PNode pos = find(phead, 3);
	Insert(&phead, pos, 1999);
	print(phead);
	cout << "---------------------------" << endl;
	erase(&phead, find(phead, 3));
	print(phead);
	cout << "---------------------------" << endl;
#endif
	int a1[7] = { 1,5,5,4,877,-4,1888888 };

		int ssss[1000] = { 0 };
		int i;
	for (i = 1; i <= 999; ++i)
	{
		ssss[i] =i;
	}
	quick_sort2(ssss, 0, 999);
	for (int i = 0; i < sizeof(ssss)/sizeof(ssss[0]); i++)
	{
		cout << ssss[i] << endl;
	}


}
int& swap(int&a, int&b)
{
	int t = a;
	a = b;
	b = t;
	return a;

}

void test2() {
	int a = 1;
	int & ra = a;
	int b = 20;
	int& c=swap(ra, b);
	cout << a << b << endl;
	c = 3;//会改变a的值
	ra = 2;//
	a = 100;
	cout<<ra << a << c << endl;
	//对a，ra，c的改变都会同时改变3个值


	int abb[] = {1,2,3,4,5 };
	int* ptr = (int*)(&abb + 1);
	printf(" %d %d",*(abb+1) ,*(ptr ));
}
int main()
{
	Base1 b;
	PrintTable((VFUNC*)(*(int*)&b));//取对象b的头四个字节。即强转为int* 。再解引用，然后强转为函数参数类型VFUNC*  
	cout << "_________________________________________" << endl;
	Derive D;
	PrintTable((VFUNC*)(*(int*)&D));
	PrintTable
	(
		(VFUNC*)
		(*(int*)
		(
			(char*)
			&D+sizeof(Base2)
			)
			)
	); //取对象D的头四个字节。即强转为int* 。再解引用，然后强转为函数参数类型VFUNC*,但要加上偏移量才能取到

	cout << "_________________________________________" << endl;

	D.Base1::a = 1;
	D.Base2::a = 0;
	cout << D.Base1::a <<"  "<< D.Base2::a<< endl;

	D.a = 2;
	cout << D.a << endl;

	Base3 b3;
	cout <<"派生类大小:"<<sizeof(D)<<endl <<"基类大小:"<<sizeof(b)<<sizeof(b3)<< endl;
	//D.func1();
	//D.Base1::func1();
	//
	//Base1* pb=&D;
	//pb->func1();
	//b.func1();
	//Base1* pb2 = new Derive();
	//Base1* pb3 = new Derive2();
	//
	//pb2->func1();
	//pb3->func1();
	//cout << "1111111111111111111111111" << endl;
	//test_duotai(b);
	//test_duotai(D);
	//Derive2 dd;
	//test_duotai( dd);

	//派生类继承了基类的虚表  8是base1的虚表指针加一个int  然后派生类是2个8加上自己的int就是20
	test1();
	//ysf_test();
	//test2();
	test_tree();
 	return 0;

}

//虚表是一个数组，