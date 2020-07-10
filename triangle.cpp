//---------------------------------------------------------------------------

#pragma hdrstop

#include "triangle.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---�� ������� �� ��� �� ����---------------------------------------------
void _2stor::solve1(float a1, float b1, float C){
	this->a1 = a1;
	this->b1 = b1;
	this->C = C;
	//������� �������� ��� ���������� �������
	this->c1 = sqrt(pow(a1,2) + pow(b1,2) - 2*a1*b1*cos(C * Pi / 180));

	//��� ������� ��������, ��� ��� ���������� ����
	this->A = acos((pow(b1,2) + pow(c1,2) - pow(a1,2)) / (2*b1*c1)) * 180 / Pi;
	this->B = 180 - (A + C);

	S_P();
}
//---��� �������-------------------------------------------------------------
void _3stor::stor3(float a1, float b1, float c1){
	this->a1 = a1;
	this->b1 = b1;
	this->c1 = c1;

	//������� ��������
	this->A = acos((pow(b1,2) + pow(c1,2) - pow(a1,2)) / (2*b1*c1)) * 180 / Pi;
	this->B = acos((pow(a1,2) + pow(c1,2) - pow(b1,2)) / (2*a1*c1)) * 180 / Pi;
	this->C = 180 - A - B;

	S_P();
}
//---�� ������� �� ��� �������----------------------------------------------
void _naprotiv::naprotiv(float a1, float b1, float A){
	float D;
	//---������� �� ��������� ������---------------------------------
	D = b1*sin(A * Pi / 180) / a1;

	if (D > 1 || a1 < B && A > 90) {
		ShowMessage("��������� �� �� ��������!");
		return;
	}
	else if (D == 1) this->B = 90;
	else if (D < 1)	 this->B = asin(D) * 180 / Pi;
	//-------------------------------------------------------------------

	this->a1 = a1;
	this->b1 = b1;
	this->A = A;

	this->C = 180 - B - A;
	//������� ������
	this->c1 = (a1 * sin(C * Pi / 180) / sin(A * Pi / 180));

	S_P();
}
//---������� �� ��� ��������� ����-------------------------------------------
void _kutiki::kutiki(float a1, float B, float C){
	this->a1 = a1;
	this->B = B;
	this->C = C;
	this->A = 180 - B - C;

    //������� ������
	this->b1 = (a1 * sin(B * Pi / 180)) / sin(A * Pi / 180);
	this->c1 = (a1 * sin(C * Pi / 180)) / sin(A * Pi / 180);

	S_P();
}
