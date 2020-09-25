#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//�����˳�
int num[10000];
int shang[10000];
void timee(int m)
{
	int jw = 0;
	for (int i = 0; i < 10000; i++)
	{
		num[i] = num[i] * m + jw;
		jw = num[i] / 10;
		num[i] %= 10;
	}
}
void divided(int m)
{
	int shang_ind = 0;//大数商的index
	int remainder = 0;//余数
	int flat = 0;//判定有效数据
	for (int i = 9999; i >= 0; i--)
	{
		if (num[i] != 0)flat = 1;
		if (flat == 1)
		{
			shang[shang_ind++] = (num[i] + remainder * 10) / m;
			remainder = (num[i] + remainder * 10) % m;
		}
	}
	for (int i = 0; i < shang_ind; i++)
	{
		cout << shang[i];
	}
	cout << endl;
	int num_index = 0;
	for (int i = shang_ind - 1; i >= 0; i--)
	{
		num[num_index++] = shang[i];
	}

	for (int i = num_index; i < 10000; i++)
	{
		num[i] = 0;
	}
}
int main()
{
	cout<<"github"<<endl;
	int n, max = 0;
	cin >> n;
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < 6 && a; i++, a /= 10)
	{
		num[i] = a % 10;
		cout << "num[" << i << "]=" << num[i] << endl;
	}
	for (int i = 1; i < n + 1; i++)
	{
		cin >> a >> b;
		if (a * b > max)
		{
			max = a * b;
		}
		timee(a);
	}
	int flat = 0;
	for (int i = 9999; i >= 0; i--)
	{
		if (num[i] != 0)flat = 1;
		if (flat == 1) {
			cout << num[i];
			continue;
		}
		if (i == 0 && flat == 0)
		{
			cout << "1";
		}
	}
	cout << endl;
	divided(max);
	flat = 0;
	for (int i = 9999; i >= 0; i--)
	{
		if (num[i] != 0)flat = 1;
		if (flat == 1) {
			cout << num[i];
			continue;
		}
		if (i == 0 && flat == 0)
		{
			cout << "1";
		}
	}
}