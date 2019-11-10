//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TButton *Button1;
	TButton *ButtonSUBT;
	TButton *ButtonPLUS;
	TButton *ButtonDIV;
	TButton *ButtonMULTI;
	TButton *ButtonCALC;
	TButton *ButtonC;
	TButton *ButtonCE;
	TButton *Button0;
	TEdit *Edit2;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *Normal1;
	TMenuItem *Close1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonMULTIClick(TObject *Sender);
	void __fastcall ButtonPLUSClick(TObject *Sender);
	void __fastcall ButtonDIVClick(TObject *Sender);
	void __fastcall ButtonSUBTClick(TObject *Sender);
	void __fastcall ButtonCEClick(TObject *Sender);
	void __fastcall ButtonCClick(TObject *Sender);
	void __fastcall ButtonCALCClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button0Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Normal1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};

class Converter {
private:
	int size;
	AnsiString prevDigit;

	void SearchOperation(char expression){
		switch (expression) {
		case '+':MathOperation = eOperation::ADD;break;
		case '-':MathOperation = eOperation::SUBT;break;
		case '*':MathOperation = eOperation::MULTI;break;
		case '/':MathOperation = eOperation::DIVISION;break;
		}
	}

public:
	AnsiString expression;

	enum eOperation{
		NONE = 0, ADD = 1, SUBT = 2, MULTI = 3, DIVISION = 4
	}MathOperation;

	Converter(){
		size = 16;

		MathOperation = eOperation::NONE;
		prevDigit = "";
	}

	Converter(AnsiString expression){
		size = 16;

		this->expression = expression;
		prevDigit = "";
		MathOperation = eOperation::NONE;
	}

	AnsiString toBinary(AnsiString &str){
		AnsiString binaryEx = "";
		const char* strBinaryEx = str.c_str();
		int length, valueEx, interger;

		length = StrLen(strBinaryEx);
		valueEx = StrToInt(str);
		interger = (int)(valueEx / 1);

		binaryEx = ""; //очищаю чтобы загрузить новые данные
		AnsiString bin = "";

		int *bitInterger = new int[size];
		bitInterger[size - 1] = interger < 0 ? 1 : 0;

		for (int i = 0; i < size - 1; i++) {
			bitInterger[i] = interger % 2 == 0 ? 0 : 1;

			interger /= 2;
		}


		for (int i = size - 1; i >= 0; --i) {
			bin += IntToStr(bitInterger[i]);
		}
		delete[] bitInterger;

		return bin;
	}

	AnsiString toNormal(AnsiString *binExpression){
		AnsiString normal = "";
		const char *exStr = binExpression->c_str();
		int length = StrLen(exStr);
		int res = 0;

		for (int i = length - 1; i >= 0; i--) {
			int temp = StrToInt(exStr[i]);

            res += temp * std::pow(2, length - i - 1);
		}

		normal = IntToStr(res);

		return normal;
	}

	String SearchDigit(AnsiString &expression){
		const char* exStr = expression.c_str();
		String digit = "";
		char operation[]= {"+,-,*,/"};
		int lengthOperation = StrLen(operation);

		int length = StrLen(exStr);
		int i = 0;
		bool BREAK = false;

		for (; i < length; i++) {
			String tempStr(exStr[i]);

			if (exStr[i] == '-' && i == 0) {
				digit += tempStr;
				continue;
			}

			//поиск математической операции
			for (int j = 0; j < lengthOperation; j++) {
				if (operation[j] == ',')continue;

				if (exStr[i] == operation[j]) {
					SearchOperation(operation[j]);
					BREAK = true;
				}
			}

			if (BREAK)break;

			digit = digit + tempStr;
		}

		if (digit == prevDigit) {
			bool CONTINUE = false;
			digit = "";

			for (; i < length; i++) {
				for (int j = 0; j < lengthOperation; j++) {
					if (operation[j] == ',')continue;

					if (exStr[i] == operation[j]){
						CONTINUE = true;
						break;
					}
				}

				if (CONTINUE) {
					CONTINUE = false;
					continue;
				}

				digit += exStr[i];
			}
		}

		prevDigit = digit;

		return digit;
	}

	int StrLen(char* str){
		int i = 0;
		while(str[i] != '\0')++i;

		return i;
	}

	int StrLen(const char* str){
		int i = 0;
		while(str[i] != '\0')++i;

		return i;
	}
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
