#include "SoPara.h"
#include <iostream>

CSoPara::CSoPara()
{ 
}

CSoPara::~CSoPara()
{ 
}

CSoPara::CSoPara(const CSoPara&Obj):
    m_SoInfo(Obj.m_SoInfo),
    m_SerialPara(Obj.m_SerialPara),
    m_AIList(Obj.m_AIList),
    m_DIList(Obj.m_DIList),
    m_AOList(Obj.m_AOList),
    m_DOList(Obj.m_DOList)
{ 
}

CSoPara& CSoPara::operator=(const CSoPara& Obj)
{
    m_SoInfo = Obj.m_SoInfo;
    m_SerialPara = Obj.m_SerialPara;
    m_AIList = Obj.m_AIList;
    m_DIList = Obj.m_DIList;
    m_AOList = Obj.m_AOList;
    m_DOList = Obj.m_DOList;
    return *this;
}

map<UINT32,string>& CSoPara::GetAIList(void)
{
    return m_AIList;
}

map<UINT32,string>& CSoPara::GetDIList(void)
{
    return m_DIList;
}

map<UINT32,string>& CSoPara::GetAOList(void)
{
    return m_AOList;
}

map<UINT32,string>& CSoPara::GetDOList(void)
{
    return m_DOList;
}

void CSoPara::SetComPara(CSoSerialPara& Para)
{
    m_SerialPara = Para;
}

CSoSerialPara& CSoPara::GetComPara(void)
{
    return m_SerialPara;
}

void CSoPara::SetSoInfo(CSoInfo& Info)
{
    m_SoInfo = Info;
}

CSoInfo& CSoPara::GetSoInfo(void)
{
    return m_SoInfo;    
}

void CSoPara::AddAI(UINT32 Index, string cellid)
{
    if(m_AIList.find(Index) == m_AIList.end())
    {
        m_AIList.insert(pair<UINT32,string>(Index,cellid));
    }
    else
    {
      cout<<"index: "<< toString(Index)<< " cellid: "<<cellid<<endl;
    }
}


void CSoPara::AddDI(UINT32 Index, string cellid)
{
    if(m_DIList.find(Index) == m_DIList.end())
    {
        m_DIList.insert(pair<UINT32,string>(Index,cellid));
    }
    else
    {
      cout<<"index: "<< toString(Index)<< " cellid: "<<cellid<<endl;
    }
}


void CSoPara::AddAO(UINT32 Index, string cellid)
{
    if(m_AOList.find(Index) == m_AOList.end())
    {
        m_AOList.insert(pair<UINT32,string>(Index,cellid));
    }
    else
    {
      cout<<"index: "<< toString(Index)<< " cellid: "<<cellid<<endl;
    }
}


void CSoPara::AddDO(UINT32 Index, string cellid)
{
    if(m_DOList.find(Index) == m_DOList.end())
    {
        m_DOList.insert(pair<UINT32,string>(Index,cellid));
    }
    else
    {
      cout<<"index: "<< toString(Index)<< " cellid: "<<cellid<<endl;
    }
}

void CSoPara::Add(UINT32 Index, string cellid, UINT32 Type)
{
 
    switch (Type)
    {
    case 1:
        AddAI(Index,cellid);
        break;
    case 2:
        AddDI(Index,cellid);
        break;
    case 3:
         AddDO(Index,cellid);
        break;
    case 4:
        AddAO(Index,cellid);
        break;        
    
    default:
        break;
    }
}