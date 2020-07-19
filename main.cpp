//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "triangle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Base *t1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void recolor(short GroupNum){
	for (short i = 0; i < Form1->ComponentCount; i++) {
		if(Form1->Components[i]->ClassNameIs("TGroupBox")){
			TGroupBox *tmp = ((TGroupBox*)Form1->Components[i]);
			if(tmp->Name == ("GroupBox" + String(GroupNum)))
				tmp->Font->Color = clGreen;
			else
				tmp->Font->Color = clRed;
		}
	}
}

//---------------------------------------------------------------------------

void show(Base *t1){
	AnsiString s;

	Form1->Label5->Caption = (AnsiString)s.sprintf("%0.1f",t1->A);
	Form1->Label7->Caption = (AnsiString)s.sprintf("%0.1f",t1->B);
	Form1->Label9->Caption = (AnsiString)s.sprintf("%0.1f",t1->C);
	Form1->Label11->Caption = (AnsiString)s.sprintf("%0.1f",t1->a1);
	Form1->Label13->Caption = (AnsiString)s.sprintf("%0.1f",t1->b1);
	Form1->Label15->Caption = (AnsiString)s.sprintf("%0.1f",t1->c1);
	Form1->S2->Caption = (AnsiString)s.sprintf("%0.1f",t1->S);
	Form1->P2->Caption = (AnsiString)s.sprintf("%0.1f",t1->P);
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	recolor(1);

	t1 = new _2stor();
			
	if (Edit1->Text != "" && Edit2->Text != "" && Edit3->Text != "") {
		t1->solve1(StrToFloat(Edit1->Text), StrToFloat(Edit2->Text), StrToFloat(Edit3->Text));
		show(t1);
	}
	
	else{
		ShowMessage("Fill in all fields!");
	}                  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	recolor(2);

	t1 = new _3stor();
	float A, B, C;
	A = StrToFloat(Edit4->Text);
	B = StrToFloat(Edit5->Text);
	C = StrToFloat(Edit6->Text);

	if (A<B+C && B<A+C && C<A+B){
		t1->stor3(A, B, C);
		show(t1);
	}
	else
		ShowMessage("The parties are incorrect!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4KeyPress(TObject *Sender, System::WideChar &Key)
{
	char *str = "0123456789,"; // задание строки допустимых элементов
	TEdit* edt= dynamic_cast<TEdit*>(Sender);

	if (((int)Key==8)) return; // разрешение использовать BackSpace и Enter
	if (!( AnsiStrScan( str, Key))) // проверка на соответствии вводимого элемента допустимым элементам приведенным в строке
		Key = NULL; // если вводимый символ не обнаружен в строке допустимых элементов, значит он отсутствует
	else
		for (short i = 0; i < edt->Text.Length(); i++)
			if(edt->Text[i+1] == ',' && Key == ','){
				Key = NULL;
				break;
			}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	recolor(3);

	t1 = new _naprotiv();

	if (Edit7->Text != "" && Edit8->Text != "" && Edit9->Text != "") {
		t1->naprotiv(StrToFloat(Edit7->Text), StrToFloat(Edit8->Text), StrToFloat(Edit9->Text));
		show(t1);
	}
	
	else{
		ShowMessage("Fill in all fields!");
	} 
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	recolor(4);

	t1 = new _kutiki();
	float a, B, C;
	a = StrToFloat(Edit10->Text);
	B = StrToFloat(Edit11->Text);
	C = StrToFloat(Edit12->Text);

	if (B+C<180){
		t1->kutiki(a, B, C);
		show(t1);
	}
	else
		ShowMessage("The problem has no solution!");
}
//---------------------------------------------------------------------------

