#ifndef _SOSERIALPARA_H_
#define _SOSERIALPARA_H_

#include "vector"
#include "string"
#include "type.h"

using std::vector;
using std::string;

#define SERIAL_PARA_XML_DOC                     ("ConfigSet")
#define SERIAL_PARA_XML_CONFIG                  ("ComConfig")
#define SERIAL_PARA_XML_COM                     ("ComInfo")
#define SERIAL_PARA_XML_TYPE                    ("HardType")
#define SERIAL_PARA_XML_FRAME_TYPE              ("FrameType")
#define SERIAL_PARA_XML_FRAME_HEAD              ("FrameHead")
#define SERIAL_PARA_XML_FRAME_TAIL              ("FrameTail")
#define SERIAL_PARA_XML_RECEIVE_TIMEOUT         ("ReceiveTimeout")
#define SERIAL_PARA_XML_485_SW_TIME             ("RS485SwitchTime")
#define SERIAL_PARA_XML_ARGUMENTS               ("Arguments")

//默认串口参数
#define SERIAL_DEFAULT_PARA_HARD_TYPE           (485)
#define SERIAL_DEFAULT_PARA_FRAME_TYPE          ("TimeOut")
#define SERIAL_DEFAULT_PARA_ARGUMENTS           ("19200,n,8,1")
#define SERIAL_DEFAULT_PARA_485_CTRL_TIME       (1)   // 单位U秒
#define SERIAL_DEFAULT_PARA_RCV_TIMEOUT         (1)   // 单位毫秒
#define SERIAL_DEFAULT_PARA_FRAME_HEAD          (0x7E)
#define SERIAL_DEFAULT_PARA_FRAME_TAIL          (0x0D)
#define SERIAL_DEFAULT_PARA_FRAME_HEAD_STR      ("7E")
#define SERIAL_DEFAULT_PARA_FRAME_TAIL_STR      ("OD")

enum eSerialTypeDef
{
    SERIAL_TYPE_485 = 485,
    SERIAL_TYPE_232 = 232
};

enum eSerialReceiveTypeDef
{
    SERIAL_RCV_TYPE_TIME_OUT = 0,
    SERIAL_RCV_TYPE_HEAD_TAIL
};

const string gRecvType[] = { "TimeOut", "HeadTail" };


class CSoSerialPara{

public:
    CSoSerialPara();

    ~CSoSerialPara();

    CSoSerialPara &operator=(const CSoSerialPara& Obj);

    bool operator==(const CSoSerialPara& Obj)const;

     void SetPara(const string&);
    string GetPara(void);

    void SetHardType(const UINT32 SerialType);
    UINT32 GetHardType(void);
    string GetHardTypeStr(void);

    void SetRS485SwitchTime(const UINT32 SwitchTime);
    UINT32 GetRS485SwitchTime(void);

    void SetReceiveTimeOut(const UINT32 TimeLength);
    UINT32 GetReceiveTimeOut(void);

    void SetFrameType(const UINT32 FrameType);
    void SetFrameType(const string& sType);

    UINT32 GetFrameType(void);
    string GetFrameTypeStr(void);

    void SetFrameHead(const UINT8 FrameHead);
    UINT8 GetFrameHead(void);
    string GetFrameHeadStr(void);

    void SetFrameTail(const UINT8 FrameTail);
    UINT8 GetFrameTail(void);
    string GetFrameTailStr(void);

    string GetBaudrate(void);
    string GetParityBit(void);
    string GetDataBit(void);
    string GetStopBit(void);

private:
    string m_CommPara;                  /// 格式:"115200,n,8,1"
    UINT32 m_Rs485SwitchTime;           /// 单位us
    UINT32 m_ReceiveTimeout;            /// 链路数据接收超时时间
    UINT32 m_HardType;                  /// 硬件端口类型:485 or 232
    UINT32 m_FrameType;                 /// 帧头帧尾方式 or 超时方式
    UINT8 m_FrameHead;
    UINT8 m_FrameTail;

    string m_Baudrate;
    string m_ParityBit;
    string m_DataBit;
    string m_StopBit;


};





#endif //_SOSERIALPARA_H_
