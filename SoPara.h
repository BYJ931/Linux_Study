#ifndef _SOPARA_H_
#define _SOPARA_H_

#include "SoInfo.h"
#include "SoSerialPara.h"
#include "map"

using std::map;


class CSoPara
{

public:
    CSoPara();

    ~CSoPara();

    CSoPara(const CSoPara& Obj);

    CSoPara &operator=(const CSoPara& Obj);

    map<UINT32, string>& GetAIList(void);
    map<UINT32, string>& GetDIList(void);
    map<UINT32, string>& GetDOList(void);
    map<UINT32, string>& GetAOList(void);

    void SetComPara(CSoSerialPara&);
    CSoSerialPara& GetComPara(void);

    void SetSoInfo(CSoInfo&);
    CSoInfo& GetSoInfo(void);

    void AddAI(UINT32 Index, string cellid);
    void AddDI(UINT32 Index, string cellid);
    void AddAO(UINT32 Index, string cellid);
    void AddDO(UINT32 Index, string cellid);
    void Add(UINT32 Index, string cellid, UINT32 Type);

private:
    CSoInfo m_SoInfo;
    CSoSerialPara m_SerialPara;
    map<UINT32,string> m_AIList;
    map<UINT32,string> m_DIList;
    map<UINT32,string> m_AOList;
    map<UINT32,string> m_DOList;

};





#endif //_SOPARA_H_
