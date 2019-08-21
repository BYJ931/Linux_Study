#include "SoSerialPara.h"


CSoSerialPara::CSoSerialPara()
{
    m_CommPara = SERIAL_DEFAULT_PARA_ARGUMENTS;
    m_Rs485SwitchTime = SERIAL_DEFAULT_PARA_485_CTRL_TIME;
    m_ReceiveTimeout = SERIAL_DEFAULT_PARA_RCV_TIMEOUT;
    m_HardType = SERIAL_TYPE_485;
    m_FrameType = SERIAL_RCV_TYPE_TIME_OUT;
    m_FrameHead = SERIAL_DEFAULT_PARA_FRAME_HEAD;
    m_FrameTail = SERIAL_DEFAULT_PARA_FRAME_TAIL;
    m_Baudrate = "19200";
    m_StopBit = "1";
    m_DataBit = "8";
    m_ParityBit = "n";
}


CSoSerialPara::~CSoSerialPara()
{
}
bool CSoSerialPara::operator==(const CSoSerialPara& SP) const
{
    if (m_HardType == SP.m_HardType && m_Rs485SwitchTime == SP.m_Rs485SwitchTime
        && m_CommPara == SP.m_CommPara && m_ReceiveTimeout == SP.m_ReceiveTimeout
        && m_FrameType == SP.m_FrameType && m_FrameHead == SP.m_FrameHead
        && m_FrameTail == SP.m_FrameTail)
    {
        return true;
    }
    return false;
}
CSoSerialPara::CSoSerialPara(const CSoSerialPara& SP)
{
    m_HardType = SP.m_HardType;
    m_Rs485SwitchTime = SP.m_Rs485SwitchTime;
    m_CommPara = SP.m_CommPara;
    m_ReceiveTimeout = SP.m_ReceiveTimeout;
    m_FrameType = SP.m_FrameType;
    m_FrameHead = SP.m_FrameHead;
    m_FrameTail = SP.m_FrameTail;
    m_Baudrate = SP.m_Baudrate;
    m_StopBit = SP.m_StopBit;
    m_DataBit = SP.m_DataBit;
    m_ParityBit = SP.m_ParityBit;
}
CSoSerialPara& CSoSerialPara::operator=(const CSoSerialPara& SP)
{
    m_HardType = SP.m_HardType;
    m_Rs485SwitchTime = SP.m_Rs485SwitchTime;
    m_CommPara = SP.m_CommPara;
    m_ReceiveTimeout = SP.m_ReceiveTimeout;
    m_FrameType = SP.m_FrameType;
    m_FrameHead = SP.m_FrameHead;
    m_FrameTail = SP.m_FrameTail;
    m_Baudrate = SP.m_Baudrate;
    m_StopBit = SP.m_StopBit;
    m_DataBit = SP.m_DataBit;
    m_ParityBit = SP.m_ParityBit;

    return *this;
}




void CSoSerialPara::SetPara(const string& Input)
{
    m_CommPara = Input;
    ///拆分
    SerialParaSplit(m_CommPara, m_Baudrate, m_ParityBit, m_DataBit, m_StopBit);
//    AS2_STRING_DEBUG("%s : %s : %s : %s\n", m_Baudrate.c_str(), m_ParityBit.c_str(),
//        m_DataBit.c_str(), m_StopBit.c_str());
}
std::string CSoSerialPara::GetPara(void)
{
    return m_CommPara;
}

void CSoSerialPara::SetHardType(const UINT32 SerialType)
{
    m_HardType = SerialType;
}
UINT32 CSoSerialPara::GetHardType(void)
{
    return m_HardType;
}
string CSoSerialPara::GetHardTypeStr(void)
{
    return toString(m_HardType);
}

void CSoSerialPara::SetRS485SwitchTime(const UINT32 SwitchTime)
{
    m_Rs485SwitchTime = SwitchTime;
}
UINT32 CSoSerialPara::GetRS485SwitchTime(void)
{
    return m_Rs485SwitchTime;
}

void CSoSerialPara::SetReceiveTimeOut(const UINT32 TimeLength)
{
    m_ReceiveTimeout = TimeLength;
}
UINT32 CSoSerialPara::GetReceiveTimeOut(void)
{
    return m_ReceiveTimeout;
}

void CSoSerialPara::SetFrameType(const UINT32 FrameType)
{
    m_FrameType = FrameType;
}
void CSoSerialPara::SetFrameType(const string& sType)
{
    if (sType == gRecvType[SERIAL_RCV_TYPE_HEAD_TAIL])
    {
        m_FrameType = SERIAL_RCV_TYPE_HEAD_TAIL;
    }
    else
    {
        m_FrameType = SERIAL_RCV_TYPE_TIME_OUT;
    }
}
UINT32 CSoSerialPara::GetFrameType(void)
{
    return m_FrameType;
}
string CSoSerialPara::GetFrameTypeStr(void)
{
    return gRecvType[m_FrameType];
}

void CSoSerialPara::SetFrameHead(const UINT8 FrameHead)
{
    m_FrameHead = FrameHead;
}
UINT8 CSoSerialPara::GetFrameHead(void)
{
    return m_FrameHead;
}
string CSoSerialPara::GetFrameHeadStr(void)
{
    return formatHex(m_FrameHead, 2);
}

void CSoSerialPara::SetFrameTail(const UINT8 FrameTail)
{
    m_FrameTail = FrameTail;
}
UINT8 CSoSerialPara::GetFrameTail(void)
{
    return m_FrameTail;
}
string CSoSerialPara::GetFrameTailStr(void)
{
    return formatHex(m_FrameTail, 2);
}

string CSoSerialPara::GetBaudrate(void)
{
    return m_Baudrate;
}
string CSoSerialPara::GetParityBit(void)
{
    return m_ParityBit;
}
string CSoSerialPara::GetDataBit(void)
{
    return m_DataBit;
}
string CSoSerialPara::GetStopBit(void)
{
    return m_StopBit;
}