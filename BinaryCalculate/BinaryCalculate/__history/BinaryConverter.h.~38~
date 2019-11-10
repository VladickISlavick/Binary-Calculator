//---------------------------------------------------------------------------

#ifndef BinaryConverterH
#define BinaryConverterH
#include <dstring.h>
//---------------------------------------------------------------------------
class BinaryConverter {
private:
    //AnsiString operation =
	const int size = 16;
	void SearchOperation(AnsiString expression);
public:
	AnsiString expression;

	enum eOperation{
		NONE = 0, ADD = 1, SUBT = 2, MULTI = 3, DIVISION = 4
	}MathOperation;

	BinaryConverter();
	BinaryConverter(AnsiString expression);

	AnsiString toBinary(AnsiString str);
	AnsiString toInversingBinary(AnsiString str);
	AnsiString SearchDigit(AnsiString expression);

    int StrLen(char* str);
    int StrLen(const char* str);
};
//---------------------------------------------------------------------------
#endif
