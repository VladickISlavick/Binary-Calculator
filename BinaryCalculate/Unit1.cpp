//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Converter *binary;
AnsiString *firstDigit;
AnsiString *secondDigit;
AnsiString *result;
AnsiString *expression;
AnsiString *MATHOPERATION;
bool mathOperation;
//---------------------------------------------------------------------------
void Calculate(){
	AnsiString firstDigitNorm = binary->toNormal(firstDigit);
	AnsiString secondDigitNorm = binary->toNormal(secondDigit);

	float valueFirst = StrToFloat(firstDigitNorm);
	float valueSecond = StrToFloat(secondDigitNorm);

	switch (binary->MathOperation) {
	case Converter::eOperation::NONE:return;
	case Converter::eOperation::ADD://сложение
		MATHOPERATION = new AnsiString("+");

		result = new AnsiString(FloatToStr(valueFirst + valueSecond));
	break;
	case Converter::eOperation::SUBT://вычитание
		MATHOPERATION = new AnsiString("-");

		result = new AnsiString(FloatToStr(valueFirst - valueSecond));
	break;
	case Converter::eOperation::MULTI://умножение
		MATHOPERATION = new AnsiString("*");

		result = new AnsiString(FloatToStr(valueFirst * valueSecond));
	break;
	case Converter::eOperation::DIVISION://деление
		MATHOPERATION = new AnsiString("/");

		result = new AnsiString(FloatToStr(valueFirst / valueSecond));
	break;
	}
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString temp = Button1->Caption;
	AnsiString str = Edit1->Text;
	str += temp;
	Edit1->Text = str;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonMULTIClick(TObject *Sender)
{
if (Edit1->Text == "")return;
	else if (Edit1->Text == '-')return;

	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	int length = StrLen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return;
		else if (str[i] >= 'a' && str[i] <= 'z') return;
	}

	if (!mathOperation) {

		binary->MathOperation = Converter::eOperation::MULTI;
		mathOperation = true;

		AnsiString temp = ButtonMULTI->Caption;
		AnsiString str = Edit1->Text;
		str += temp;
		Edit1->Text = str;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonPLUSClick(TObject *Sender)
{
if (Edit1->Text == "")return;
	else if (Edit1->Text == '-')return;

	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	int length = StrLen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return;
		else if (str[i] >= 'a' && str[i] <= 'z') return;
	}

	if (!mathOperation) {

		binary->MathOperation = Converter::eOperation::MULTI;
		mathOperation = true;
		Edit1->Text += ButtonPLUS->Caption;

		AnsiString temp = ButtonPLUS->Caption;
		AnsiString str = Edit1->Text;
		str += temp;
		Edit1->Text = str;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDIVClick(TObject *Sender)
{
	if (Edit1->Text == "")return;
	else if (Edit1->Text == '-')return;

	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	int length = StrLen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return;
		else if (str[i] >= 'a' && str[i] <= 'z') return;
	}

	if (!mathOperation) {
		binary->MathOperation = Converter::eOperation::MULTI;
		mathOperation = true;
		Edit1->Text += ButtonDIV->Caption;

		AnsiString temp = ButtonDIV->Caption;
		AnsiString str = Edit1->Text;
		str += temp;
		Edit1->Text = str;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSUBTClick(TObject *Sender)
{
if (Edit1->Text == "")return;
	else if (Edit1->Text == '-')return;

	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	int length = StrLen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return;
		else if (str[i] >= 'a' && str[i] <= 'z') return;
	}

	if (!mathOperation) {
		binary->MathOperation = Converter::eOperation::MULTI;
		mathOperation = true;
		Edit1->Text += ButtonSUBT->Caption;

		AnsiString temp = ButtonSUBT->Caption;
		AnsiString str = Edit1->Text;
		str += temp;
		Edit1->Text = str;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCEClick(TObject *Sender)
{
	Edit1->Text = "";
	mathOperation = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCClick(TObject *Sender)
{
	AnsiString text = Edit1->Text;
	char operation[] = "+,-,*,/";
	const char* textStr = text.c_str();

	int lengthOperation = StrLen(operation);
	int length = StrLen(textStr)-1;

	Edit1->Text = "";
	mathOperation = false;

	for (int i = 0; i < length; i++) {
		Edit1->Text += textStr[i];
	}

	for (int i = 1; i < length; i++) {
		for (int j = 0; j < lengthOperation; j++) {
			if(textStr[i] == operation[j]){
				mathOperation = false;
				return;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCALCClick(TObject *Sender)
{
AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	char operation[]= {"+,-,*,/"};
    int lengthOp = StrLen(operation);
	int length = StrLen(str);
	bool number = false;

	for (int i = 0; i < length; i++) {
		if (str[i] == '0' || str[i] == '1') {
			number = true;
		} else {
			bool cont = false;

			for (int j = 0; i < lengthOp; j++) {
				if (operation[j] == str[i]) {
					cont = true;
					break;
				}
			}

			if (cont) {
				continue;
			}

			return;
		}
	}

	if (!number) {
		ShowMessage("Введите число");
		return;
	}

	if (Edit1->Text == '-')return;

	if (Edit1->Text != "") {
		expression  = new AnsiString(exp);
		firstDigit  = new AnsiString(binary->SearchDigit(*expression));
		secondDigit = new AnsiString(binary->SearchDigit(*expression));

		Calculate();


		Label1->Caption = *firstDigit + *MATHOPERATION + *secondDigit + " = " + *result;
		AnsiString binRes = binary->toBinary(*result);
		ShowMessage(binRes);
		mathOperation = false;
        Edit1->Text = *result;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Edit1->Text = "";
	binary = new Converter();
	mathOperation = false;

	//чтобы их можно было перемещать на форме
	Label1->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button0Click(TObject *Sender)
{
	AnsiString temp = Button0->Caption;
	AnsiString str = Edit1->Text;
	str += temp;
	Edit1->Text = str;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{

	delete binary;
	delete expression;
	delete result;
	delete firstDigit;
	delete secondDigit;
	delete MATHOPERATION;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Normal1Click(TObject *Sender)
{
	Form1->Hide();
    Form2->Show();
}
//---------------------------------------------------------------------------


