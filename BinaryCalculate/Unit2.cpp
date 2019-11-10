//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <dstring.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
BinaryConverter *binary;
AnsiString *firstDigit;
AnsiString *secondDigit;
AnsiString *result;
AnsiString *expression;
AnsiString *MATHOPERATION;
AnsiString firstDigitNorm;
AnsiString secondDigitNorm;
bool mathOperation;
bool bin = false;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Calcul(){
	if (!bin) {
		float valueFirst;
		float valueSecond;
		const char* strFirstDigit = firstDigit->c_str();
		const char* strSecondDigit = secondDigit->c_str();

		if (strFirstDigit[0] == '-' && strSecondDigit[0] == '-') {
			AnsiString strTemp = binary->deleteMinus(*firstDigit);
			AnsiString strTemp1 = binary->deleteMinus(*secondDigit);
			valueFirst = -1 * StrToFloat(strTemp);
			valueSecond = -1 * StrToFloat(strTemp1);
		}else if (strFirstDigit[0] == '-' && strSecondDigit[0] != '-') {
			AnsiString strTemp = binary->deleteMinus(*firstDigit);
			valueFirst = -1 * StrToFloat(strTemp);
			valueSecond = StrToFloat(*secondDigit);
		}else if (strFirstDigit[0] != '-' && strSecondDigit[0] == '-') {
			AnsiString strTemp1 = binary->deleteMinus(*secondDigit);

			valueFirst = StrToFloat(*firstDigit);
			valueSecond = -1 * StrToFloat(strTemp1);
		}else {
			valueFirst = StrToFloat(*firstDigit);
			valueSecond = StrToFloat(*secondDigit);
		}

		switch (binary->MathOperation) {
		case BinaryConverter::eOperation::NONE:return;
		case BinaryConverter::eOperation::ADD://��������
			MATHOPERATION = new AnsiString("+");
			result = new AnsiString(FloatToStr(valueFirst + valueSecond));
		break;
		case BinaryConverter::eOperation::SUBT://���������
			MATHOPERATION = new AnsiString("-");
			result = new AnsiString(FloatToStr(valueFirst - valueSecond));
		break;
		case BinaryConverter::eOperation::MULTI://���������
			MATHOPERATION = new AnsiString("*");
			result = new AnsiString(FloatToStr(valueFirst * valueSecond));
		break;
		case BinaryConverter::eOperation::DIVISION://�������
			MATHOPERATION = new AnsiString("/");
			result = new AnsiString(FloatToStr(valueFirst / valueSecond));
		break;
		}
	} else{
		firstDigitNorm = binary->toNormal(firstDigit);
		secondDigitNorm = binary->toNormal(secondDigit);

		float valueFirst = StrToFloat(firstDigitNorm);
		float valueSecond = StrToFloat(secondDigitNorm);

		switch (binary->MathOperation) {
		case BinaryConverter::eOperation::NONE:return;
		case BinaryConverter::eOperation::ADD://��������
			MATHOPERATION = new AnsiString("+");

			result = new AnsiString(FloatToStr(valueFirst + valueSecond));
		break;
		case BinaryConverter::eOperation::SUBT://���������
			MATHOPERATION = new AnsiString("-");

			result = new AnsiString(FloatToStr(valueFirst - valueSecond));
		break;
		case BinaryConverter::eOperation::MULTI://���������
			MATHOPERATION = new AnsiString("*");

			result = new AnsiString(FloatToStr(valueFirst * valueSecond));
		break;
		case BinaryConverter::eOperation::DIVISION://�������
			MATHOPERATION = new AnsiString("/");

			result = new AnsiString(FloatToStr(valueFirst / valueSecond));
		break;
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CalcClick(TObject *Sender)
{
	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	char operation[]= {"+,-,*,/"};
    int lengthOp = StrLen(operation);
	int length = StrLen(str);
	bool number = false;

	for (int i = 0; i < length; i++) {
		if ((str[i] >= '0' && str[i] <= '9') || str[0] == '-') {
			number = true;
		} else {
			bool cont = false;

			for (int j = 0; j < lengthOp; j++) {
				if(str[i] == operation[j]){
                    cont = true;
				}
			}

			if (cont) continue;

			number = false;
			break;
		}
	}

	if (!number) {
		ShowMessage("������� �����");
		return;
	}

	if (Edit1->Text == '-')return;

	if (Edit1->Text != "") {
		if (!bin) {
			expression  = new AnsiString(Edit1->Text);
			firstDigit  = new AnsiString(binary->SearchDigit(*expression));
			secondDigit = new AnsiString(binary->SearchDigit(*expression));

			Calcul();

			const char* strFirstDigit = firstDigit->c_str();
			const char* strSecondDigit = secondDigit->c_str();

			if (strFirstDigit[0] == '-' && strSecondDigit[0] == '-') {
				AnsiString binaryFirstString = binary->toBinary(*firstDigit);
				AnsiString binarySecondString = binary->toBinary(*secondDigit);

				Label1->Caption = binary->toInversingBinary(binaryFirstString);
				this -> ListBox2 -> Items -> Add(Label1->Caption);

				Label2->Caption = *MATHOPERATION;
				this -> ListBox2 -> Items -> Add(Label2->Caption);

				Label3->Caption = binary->toInversingBinary(binarySecondString);
				this -> ListBox2 -> Items -> Add(Label3->Caption);

				Label4->Caption = binary->toBinary(*result);
				this -> ListBox2 -> Items -> Add(Label4->Caption);

			}else if (strFirstDigit[0] == '-' && strSecondDigit[0] != '-') {
				AnsiString binaryFirstString = binary->toBinary(*firstDigit);

				Label1->Caption = binary->toInversingBinary(binaryFirstString);
				this -> ListBox2 -> Items -> Add(Label1->Caption);

				Label2->Caption = *MATHOPERATION;
				this -> ListBox2 -> Items -> Add(Label2->Caption);

				Label3->Caption = binary->toBinary(*secondDigit);
				this -> ListBox2 -> Items -> Add(Label3->Caption);

				AnsiString binaryResult = binary->toBinary(*firstDigit);
				Label4->Caption = binary->toInversingBinary(binaryResult);
				this -> ListBox2 -> Items -> Add(Label4->Caption);

			}else if (strFirstDigit[0] != '-' && strSecondDigit[0] == '-') {
				AnsiString binarySecondString = binary->toBinary(*secondDigit);

				Label1->Caption = binary->toBinary(*firstDigit);
				this -> ListBox2 -> Items -> Add(Label1->Caption);

				Label2->Caption = *MATHOPERATION;
				this -> ListBox2 -> Items -> Add(Label2->Caption);

				Label3->Caption = binary->toInversingBinary(binarySecondString);
				this -> ListBox2 -> Items -> Add(Label3->Caption);

				AnsiString binaryResult = binary->toBinary(*firstDigit);
				Label4->Caption = binary->toInversingBinary(binaryResult);
				this -> ListBox2 -> Items -> Add(Label4->Caption);

			}else {
					Label1->Caption = binary->toBinary(*firstDigit);
				this -> ListBox2 -> Items -> Add(Label1->Caption);

					Label2->Caption = *MATHOPERATION;
				this -> ListBox2 -> Items -> Add(Label2->Caption);

					Label3->Caption = binary->toBinary(*secondDigit);
				this -> ListBox2 -> Items -> Add(Label3->Caption);

					Label4->Caption = binary->toBinary(*result);
				this -> ListBox2 -> Items -> Add(Label4->Caption);
			}

Label6->Caption = *firstDigit + " " + *MATHOPERATION + " " + *secondDigit + " = " + *result;
			this -> ListBox1 -> Items -> Add(Label6 -> Caption);
			this -> ListBox1 -> Items -> Add(" ");
			this -> ListBox2 -> Items -> Add(" ");

			Edit1->Text = *result;
			mathOperation = false;
			Conv -> Visible = true;
			Clear();
		} else {
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
				ShowMessage("������� �����");
				return;
			}

			if (Edit1->Text == '-')return;

			if (Edit1->Text != "") {
				expression  = new AnsiString(exp);
				firstDigit  = new AnsiString(binary->SearchDigit(*expression));
				secondDigit = new AnsiString(binary->SearchDigit(*expression));

				Calcul();

				Label1->Caption = firstDigitNorm + *MATHOPERATION + secondDigitNorm + " = " + *result;
				AnsiString binRes = binary->toBinary(*result);
				ListBox1 -> Items -> Add(Label1->Caption);
				ListBox1 -> Items -> Add(" ");

				ListBox2 -> Items -> Add(*firstDigit);
				ListBox2 -> Items -> Add(*MATHOPERATION);
				ListBox2 -> Items -> Add(*secondDigit);
                ListBox2 -> Items -> Add(binary -> toBinary(*result));

                ListBox2 -> Items -> Add(" ");
				mathOperation = false;
			}
		}
	}else{
		Label5->Caption = "������� ������";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Clear(){
	if (binary != nullptr) delete binary;
	if (expression != nullptr) delete expression;
	if (result != nullptr) delete result;
	if (firstDigit != nullptr) delete firstDigit;
	if (secondDigit != nullptr) delete secondDigit;
	if (MATHOPERATION != nullptr) delete MATHOPERATION;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Load(TObject *Sender)
{
	AnsiString listName1 = "���������� �������������:";
	AnsiString listName2 = "�������� �������������:";

    this -> ListBox1 -> Items -> Add(listName1);
	this -> ListBox2 -> Items -> Add(listName2);

	Edit1 -> Text = "";
	binary = new BinaryConverter();
	mathOperation = false;

	//����� �� ����� ���� ���������� �� �����
	Label1 -> Caption = "";
	Label2 -> Caption = "";
	Label3 -> Caption = "";
	Label4 -> Caption = "";
	Label5 -> Caption = "";
	Label6 -> Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Close(TObject *Sender, TCloseAction &Action)
{
    Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button0Click(TObject *Sender)
{
	Edit1->Text += Button0->Caption;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Edit1->Text += Button1->Caption;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button2->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button3->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button4->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button5->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button6->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button7->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button8->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
	if (!bin)Edit1->Text += Button9->Caption;
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonSubtClick(TObject *Sender)
{
	if (!bin){
		if (Edit1->Text == '-')return;

		AnsiString exp = Edit1->Text;
		const char *str = exp.c_str();
		int length = StrLen(str);
		//���� �� ����� �����
		for (int i = 0; i < length; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') return;
			else if (str[i] >= 'a' && str[i] <= 'z') return;
		}

		if (!mathOperation) {
			Conv->Visible = false;

			binary->MathOperation = BinaryConverter::eOperation::SUBT;
			mathOperation = true;
			Edit1->Text += ButtonSubt->Caption;
		}
	} else{
		if (Edit1->Text == "") return;

		if (!mathOperation) {
			Conv->Visible = false;

			binary->MathOperation = BinaryConverter::eOperation::SUBT;
			mathOperation = true;
			Edit1->Text += ButtonSubt->Caption;
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonDivisionClick(TObject *Sender)
{
	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	int length = StrLen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return;
		else if (str[i] >= 'a' && str[i] <= 'z') return;
	}

	Conv->Visible = false;

	if (Edit1->Text == "")return;
	else if (Edit1->Text == '-')return;

	if (!mathOperation) {
		binary->MathOperation = BinaryConverter::eOperation::DIVISION;
		mathOperation = true;
		Edit1->Text += ButtonDivision->Caption;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonAddClick(TObject *Sender)
{
	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	int length = StrLen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return;
		else if (str[i] >= 'a' && str[i] <= 'z') return;
	}

	if (Edit1->Text == "")return;
	else if (Edit1->Text == '-')return;

	if (!mathOperation) {
		Conv->Visible = false;

		binary->MathOperation = BinaryConverter::eOperation::ADD;
		mathOperation = true;
		Edit1->Text += ButtonAdd->Caption;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonMultiClick(TObject *Sender)
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
		Conv->Visible = false;

		binary->MathOperation = BinaryConverter::eOperation::MULTI;
		mathOperation = true;
		Edit1->Text += ButtonMulti->Caption;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonCEClick(TObject *Sender)
{
	Conv->Visible = true;
	mathOperation = false;

	Label1->Caption = "";
	Label2->Caption = "";
	Label3->Caption = "";
	Label4->Caption = "";
	Label5->Caption = "";

	Label6->Caption = "";

	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClearSymbolClick(TObject *Sender)
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

	Label1->Caption = "";
	Label2->Caption = "";
	Label3->Caption = "";
	Label4->Caption = "";
	Label5->Caption = "";

	Label6->Caption = "";

	for (int i = 1; i < length; i++) {
		for (int j = 0; j < lengthOperation; j++) {
			if(textStr[i] == operation[j]){
				Conv->Visible = false;
				return;
			}
		}
	}
	Conv->Visible = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::ConvClick(TObject *Sender)
{
	AnsiString exp = Edit1->Text;
	const char *str = exp.c_str();
	int length = StrLen(str);
	bool number = false;

	for (int i = 0; i < length; i++) {
		if ((str[i] >= '0' && str[i] <= '9') || str[0] == '-') {
			number = true;
		}else{
			number = false;
			break;
		}
	}

	if (Edit1->Text == '-') {
		ShowMessage("������� �����");
		return;
	} else if (!number) {
		ShowMessage("������� �����");
		return;
	}

	if (str[0] == '-'){
		AnsiString message = binary->toBinary(exp);
		AnsiString inversMsg = binary->toInversingBinary(message);

		ShowMessage("����� " + Edit1->Text + " � �������� ������������� " + inversMsg);
	}else{
		AnsiString message = binary->toBinary(exp);

		ShowMessage("����� " + Edit1->Text + " � �������� ������������� " + message);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Binary1Click(TObject *Sender)
{
	bin = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Close1Click(TObject *Sender){
    bin = false;
}
//---------------------------------------------------------------------------
