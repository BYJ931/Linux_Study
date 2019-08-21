#ifndef _PARSEXML_H_
#define _PARSEXML_H_

#include "vector"
#include "string"
#include "tinyxml2/tinyxml2.h"
#include "type.h"
#include "SoPara.h"

using namespace std;
using namespace tinyxml2;
using std::vector;
using std::string;

class CParseXml
{
private:
    string m_xmlpath;
public:
    CParseXml(const string& filepath);
    ~CParseXml();
    UINT32 GetInfo(CSoPara& Para);
};




#endif  //_PARSEXML_H_