#ifndef _SOINFO_H_
#define _SOINFO_H_

#include "vector"
#include "string"
#include "type.h"

using std::vector;
using std::string;


class CSoInfo{

public:
    CSoInfo();

    ~CSoInfo();

    CSoInfo(const CSoInfo &Obj);

    CSoInfo &operator=(const CSoInfo &Obj);

    bool operator==(const CSoInfo &Obj);

    void SetSoName(const string& sName);

    string GetSoName(void);

    void SetName(const string& sName);

    string GetName(void);

    void SetFactory(const string& sFactory);

    string GetFactory(void);

    void SetModel(const string& sModel);

    string GetModel(void);

    void SetVersion(const string& sVersion);

    string GetVersion(void);

    void SetDeviceType(const UINT32 Type);

    UINT32 GetDeviceType(void);

private:
    string m_SoName;
    string m_Version;
    string m_Name;
    string m_Factory;
    string m_Model;
    UINT32 m_DeviceType;

};





#endif //_SOINFO_H_
