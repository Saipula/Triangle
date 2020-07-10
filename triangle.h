//---------------------------------------------------------------------------

#ifndef triangleH
#define triangleH

#include <math.h>
//---------------------------------------------------------------------------

class Base{
protected:
	double Pi = 3.1415926535897932384626433832795;
	float p;
public:
	float A, B, C, a1, b1, c1, S, P;

	Base(){
		A = 0; B = 0; C = 0;
		a1 = 0; b1 = 0; c1 = 0;
	}

//---�������� �� �����-------------------------------------------------------
	void S_P(){
		P = a1 + b1 + c1;
		p = P/2;
		S = sqrt(p*(p - a1) * (p - b1) * (p - c1)); //������� ������
	}

	virtual void solve1(float a1, float b1, float C){};
	virtual void stor3(float a1, float b1, float c1){};
	virtual void naprotiv(float a1, float b1, float A){};
	virtual void kutiki(float a1, float B, float C){};
};

class _2stor : public Base{
public:
	_2stor() : Base(){}
//---�� ������� �� ��� �� ����---------------------------------------------
	void solve1(float a1, float b1, float C);
};

class _3stor : public Base{
public:
	_3stor() : Base(){}
//---��� �������-------------------------------------------------------------
	void stor3(float a1, float b1, float c1);
};

class _naprotiv : public Base{
public:
	_naprotiv() : Base(){}
//---�� ������� �� ��� �������----------------------------------------------
	void naprotiv(float a1, float b1, float A);
};

class _kutiki : public Base{
public:
    _kutiki() : Base(){}
//---������� �� ��� ��������� ����-------------------------------------------
	void kutiki(float a1, float B, float C);
};

#endif
