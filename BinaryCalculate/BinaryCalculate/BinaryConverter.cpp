//---------------------------------------------------------------------------

#pragma hdrstop

#include "BinaryConverter.h"
//---------------------------------------------------------------------------
BinaryConverter::BinaryConverter(){
	MathOperation = eOperation::NONE;
}

BinaryConverter::BinaryConverter(AnsiString expression){
	MathOperation = eOperation::NONE;
	this->expression = expression;
}

void BinaryConverter::SearchOperation(AnsiString expression){
	const char* strExpression = expression.c_str();
	int length = StrLen(strExpression);

	for (int i = 0; i < length; i++) {
		switch (strExpression[i]) {
			case '+':MathOperation = eOperation::ADD; break;
			case '-':MathOperation = eOperation::SUBT; break;
			case '*':MathOperation = eOperation::MULTI; break;
			case '/':MathOperation = eOperation::DIVISION; break;
		}
	}
}

int BinaryConverter::StrLen(char* str){
	int i = 0;
	while(str[i] != '\0')i++;

    return i;
}

int BinaryConverter::StrLen(const char* str){
	int i = 0;
	while(str[i] != '\0')i++;

	return i;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
