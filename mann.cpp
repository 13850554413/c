//多个参数
#include<iostream>
using namespace std;

int nn(int a, int b, int c, int d, int e, int f, int g);
void chin(void);
int main()
{
	int a, b, c, d, e, f, g;
	cout << "输入一个数，这些数会相加。" << endl;
	chin();
	cin >> a;
	chin();
	cin >> b;
	chin();
	cin >> c;
	chin();
	cin >> d;
	chin();
	cin >> e;
	chin();
	cin >> f;
	chin();
	cin >> g;
	int h = nn(a, b, c, d, e, f, g);
	cout << "这些数相加等于：" << h << endl;
	return 0;
}

int nn(int a, int b, int c, int d, int e, int f, int g)
{
	return a + b + c + d + e + f + g;
}
void chin(void)
{
	cout << "输入一个数：";
}
