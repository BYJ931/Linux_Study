#include "SoInfo.h"

CSoInfo::CSoInfo()
{
    m_DeviceType = 0;
}

CSoInfo::~CSoInfo()
{
    
}

CSoInfo& CSoInfo::operator=(const CSoInfo& Obj)
{
    m_SoName = Obj.m_SoName;
    m_Name = Obj.m_Name;
    m_Factory = Obj.m_Factory;
    m_Model = Obj.m_Model;
    m_DeviceType = Obj.m_DeviceType;
    m_Version = Obj.m_Version;
    return *this;
}

bool CSoInfo::operator==(const CSoInfo& Obj)
{
    if(m_SoName!=Obj.m_SoName || m_Name != Obj.m_Name || m_Version != Obj.m_Version || m_Factory != Obj.m_Factory 
        || m_Model != Obj.m_Model || m_DeviceType != Obj.m_DeviceType)
    {
        return false;        
    }
    
    return true;
}

void CSoInfo::SetSoName(const string& sName)
{
     m_SoName = sName;
}

string CSoInfo::GetSoName(void)
{
    return m_SoName;    
}

void CSoInfo::SetName(const string& sName)
{
     m_Name = sName;
}

string CSoInfo::GetName(void)
{
    return m_Name;    
}

void CSoInfo::SetFactory(const string& sFactory)
{
     m_Factory = sFactory;
}

string CSoInfo::GetFactory(void)
{
    return m_Factory;    
}

void CSoInfo::SetModel(const string& sModel)
{
     m_Model = sModel;
}

string CSoInfo::GetModel(void)
{
    return m_Model;    
}


void CSoInfo::SetVersion(const string& sVersion)
{
     m_Version = sVersion;
}

string CSoInfo::GetVersion(void)
{
    return m_Version;    
}


void CSoInfo::SetDeviceType(const UINT32 Type)
{
     m_DeviceType = Type;
}

UINT32 CSoInfo::GetDeviceType(void)
{
    return m_DeviceType;    
}

