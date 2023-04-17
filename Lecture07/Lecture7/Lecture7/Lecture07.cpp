#include <iostream>

using namespace std;

class MobilePhone
{
public:
	MobilePhone()
	{
		cout << "MobilePhone�� �����մϴ�" << endl;
	}
	virtual ~MobilePhone()
	{
		cout << "MobilePhone�� �Ҹ��ŵ�ϴ�" << endl;
	}

	virtual void TurnOn()
	{
		cout << "MobilePhone�� �մϴ�." << endl;
	}
	void TurnOff()
	{
		cout << "MobilePhone�� ���ϴ�." << endl;
	}
};

class IPhone : public MobilePhone
{
public:
	IPhone()
	{
		cout << "IPhone�� �����մϴ�" << endl;
	}
	~IPhone()
	{
		cout << "IPhone�� �Ҹ��ŵ�ϴ�" << endl;
		/*~MobilePhone();*/
	}

	void ApplePay()
	{
		cout << "ApplePay: ���Ѵ��б��� ��ϱ� 230234879238749283794829���� �����Ǿ����ϴ�" << endl;
	}
	void Siri()
	{
		cout << "Siri : ����� ������ ���� �ڰ��� �����ϴ�." << endl;
	}
	void TurnOn()
	{
		cout << "��" << endl;
	}
};

class Galaxy : public MobilePhone
{
public:
	Galaxy()
	{
		cout << "Galaxy�� �����մϴ�" << endl;
	}
	~Galaxy()
	{
		cout << "Galaxy�� �Ҹ��ŵ�ϴ�" << endl;
	}

	void SamsungPay()
	{
		cout << "SamsungPay: ���Ѵ��б��� ��ϱ� 1���� �����Ǿ����ϴ�" << endl;
	}
	void Bixby()
	{
		cout << "Bixby : ������ �̼��� ���ض�" << endl;
	}
	void TurnOn()
	{
		cout << "����" << endl;
	}

};


void main()
{
	cout << "MobilePhone�� ���� �����Դϴ�\n" << endl;
	cout << endl;

	MobilePhone** mp = new MobilePhone * [2];
	mp[0] = new IPhone();
	mp[1] = new Galaxy();

	for (size_t i = 0; i < 2; i++)
	{
		mp[i]->TurnOn();
		delete(mp[i]);
	}
}
