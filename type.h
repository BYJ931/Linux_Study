#ifndef  _TYPE_H_
#define  _TYPE_H_

#include <string>
#include <sstream>

using namespace std;

typedef signed char         SINT8;
typedef unsigned char       UINT8;

typedef signed short        SINT16;
typedef unsigned short      UINT16;

typedef signed int          SINT32;
typedef unsigned int        UINT32;

typedef signed long long    SINT64;
typedef unsigned long long  UINT64;

typedef signed __int64         Int64;
typedef unsigned __int64       UInt64;

template<typename T>
std::string toString(const T& t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

signed int SerialParaSplit(const string& Para, string& Baudrate, string& ParityBit, string& DataBit,
    string& StopBit)
{
    size_t Fst = Para.find(",");
    if (string::npos != Fst)
    {
        Baudrate = Para.substr(0, Fst);
    }
    else
    {
        return -1;
    }

    string Last = Para.substr(Fst + 1);
    Fst = Last.find(",");
    if (string::npos != Fst)
    {
        ParityBit = Last.substr(0, Fst);
    }
    else
    {
        return -1;
    }

    Last = Last.substr(Fst + 1);
    Fst = Last.find(",");
    if (string::npos != Fst)
    {
        DataBit = Last.substr(0, Fst);
    }
    else
    {
        return -1;
    }

    StopBit = Last.substr(Fst + 1);

//    cout << Baudrate << ":" << ParityBit << ":" << DataBit << ":" << StopBit << endl;

    return 0;
}

template <typename T>
bool uIntToStr (T number, unsigned short base, std::string& result, bool prefix = false, int width = -1, char fill = ' ', char thSep = 0)
	/// Converts unsigned integer to string; This is a wrapper function, for details see see the
	/// bool uIntToStr(T, unsigned short, char*, int, int, char, char) implementation.
{
	char res[POCO_MAX_INT_STRING_LEN] = {0};
	std::size_t size = POCO_MAX_INT_STRING_LEN;
	bool ret = uIntToStr(number, base, res, size, prefix, width, fill, thSep);
	result.assign(res, size);
	return ret;
}

string formatHex(UInt64 value, int width, bool prefix = false)
{
	std::string result;
	uIntToStr(value, 0x10, result, prefix, width, '0');
	return result;
}


#endif // ! _TYPE_H_
