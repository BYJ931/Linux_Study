#include "ParseXml.h"
#include "iostream.h"

CParseXml::CParseXml(const string& filepath)
{
    m_xmlpath = filepath;
}

CParseXml::~CParseXml()
{
    
}

UINT32 CParseXml::GetInfo(CSoPara& Para)
{
    XMLDocument XmlDoc;
	int Rtn = XmlDoc.LoadFile(m_xmlpath);
	if (Rtn)
	{
		
	}
}