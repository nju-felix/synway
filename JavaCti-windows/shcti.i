%module  shcti
%{
#include <shpa3api.h>
%}
/////////////////////////////////////
enum{
	F_RCVDTMFSENS=1,		//接收DTMF敏感度
	F_TXDTMFAMP=2,			//发送DTMF信号强度
	F_RCVPHONUMHOLDUP=3,	//被叫号码拦截标记

	// Added by xxb for 模拟电话线被叫摘机检测新算法,2003.2.27	
	F_RELATIVEENGYHOOKDETECT=4, //是否启用模拟电话线被叫摘机检测新算法

	//Added by xxb,for 一号信令R2滤波点数不可调,2003.3.7
	F_RXR2FILTERTIME=5, //R2接收滤波时间
	F_RECTOFILEA_CALLBACKTIME = 6, //Appended by xxb, for SsmRecToFileA回调时间可调, 2003.06.24
	F_CALLERIDSTYLE=7,	
	F_InVoiceToBus=8, //Added by xxb,for 来话上总线 DTMF切音,2004.04.19
	F_ClearInVoiceOnRcvDtmf=9, //Added by xxb,for 来话上总线 DTMF切音,2004.04.19
	F_MixerResToBus=10, //added by xxb,for 混音源上总线,2004.06.02
	F_HighAndLowFreqEnScale=11, //appended by cqb for 过滤语音中误判的DTMF , 2004.11.01
	F_DualAndAllFreqEnScale=12 //appended by cqb for 过滤语音中误判的DTMF , 2004.11.01

};
// function "SsmGetBlockReason()"
//-----------------------------------------------------------------------
enum{
	BLOCKBY_NULL,
	BLOCKBY_TupRcvMGB,
	BLOCKBY_TupRcvHGB,
	BLOCKBY_TupRcvSGB,
	BLOCKBY_TupWaitRLGTimeout,
	BLOCKBY_TupBlockByApp,
};

//-----------------------------------------------------------------------
#define BLOCKREMOTE_Unblocked			0	// no block-signal is issued
#define BLOCKREMOTE_Blocked				1	// is in blocked state now
#define BLOCKREMOTE_WaitBlockAck		2	// waiting for acknowledgement signal after sending block-signal
#define BLOCKREMOTE_WaitUnblockAck		3	// waiting for acknowledgement signal after sending unblock-signal

//-----------------------------------------------------------------------
#define BLOCK_AppBlockCic	0x00000001	// channel is blocked by invoking SsmBlockLocalCh()
#define BLOCK_TupRcvBLO		0x00000002	// channel is blocked by received BLO
#define BLOCK_TupRcvSGB		0x00000004	// channel is blocked by received SGB
#define BLOCK_TupRcvHGB		0x00000008	// channel is blocked by received HGB
#define BLOCK_TupRcvMGB		0x00000010	// channel is blocked by received MGB
#define BLOCK_AppBlockPCM	0x00000020	// channel is blocked by invoking SsmBlockLocalPCM()


//-----------------------------------------------------------------------
// Definition of channel unavailable reason
//-----------------------------------------------------------------------
#define UNAVAILABLE_PcmSyncLos		0x00000001	
#define UNAVAILABLE_Mtp3Unusuable	0x00000002	

//-----------------------------------------------------------------------
// 函数调用失败原因的常量定义，用于函数SsmGetLastErrCode()返回值
//-----------------------------------------------------------------------
enum{
	C_ERROR_INIT_FAILURE      =0,
	C_ERROR_SSMAPI_UNOPENED   =1,
	C_ERROR_INVALID_APPCH     =2,
	C_ERROR_UNSUPPORTED_OP    =3,
	C_ERROR_INDEX_UNOPENED    =4,
	C_ERROR_INVALID_BUSCH     =5,
	C_ERROR_OP_UNOPENED       =6,
	C_ERROR_INVALID_FORMAT    =7,
	C_ERROR_INVALID_PARAMETER =8,
	C_ERROR_FILEOP_FAILURE    =9,
	C_ERROR_MEMORY_FAILURE    =10,
	C_ERROR_RESOURCE_USEUP    =11,
	C_ERROR_SYSTEM            =12,
	C_ERROR_IdleChNotFound    =13,		// appended by cxg for SS7,10.22,2001
	C_ERROR_OP_FAILURE		  =14,		//appended by xxb, for 停录放音会出现句柄无效,2003.7.18
	C_ERROR_INVALID_APPSPYCIC =15,
//++++start++++ fax error code      
	C_ERROR_FAX_NOFILE	  = 16
//++++end++++ fax error code
};

//-----------------------------------------------------------------------
// 自动拨号任务失败的常量定义，用于函数SsmGetAutoDialFailureReason()返回值
//-----------------------------------------------------------------------
enum{
	ATDL_NULL=0,								// 没有呼出任务
	ATDL_Cancel=1,								// 应用程序主动取消
	ATDL_WaitDialAnsTimeout=2,					// 等待被叫应答超时
	ATDL_WaitRemotePickupTimeout=3,				// 等待被叫摘机超时
	ATDL_PcmSyncLos=4,							// PCM链路基本祯失步超过100ms

	ATDL_Mtp3Unusable=10,						// No.7信令：信令不可用
	ATDL_RcvSSB=11,								// No.7信令：收到SSB
	ATDL_RcvSLB=12,								// No.7信令：收到SLB
	ATDL_RcvSTB=13,								// No.7信令：收到STB
	ATDL_RcvUNN=14,								// No.7信令：收到UNN
	ATDL_RcvSEC=15,								// No.7信令：收到SEC
	ATDL_RcvCGC=16,								// No.7信令：收到CGC
	ATDL_RcvNNC=17,								// No.7信令：收到NNC
	ATDL_RcvCFL=18,								// No.7信令：收到CFL
	ATDL_RcvLOS=19,								// No.7信令：收到LOS
	ATDL_RcvSST=20,								// No.7信令：收到SST
	ATDL_RcvACB=21,								// No.7信令：收到ACB
	ATDL_RcvDPN=22,								// No.7信令：收到DPN
	ATDL_RcvEUM=23,								// No.7信令：收到EUM
	ATDL_RcvADI=24,								// No.7信令：收到ADI
	ATDL_RcvBLO=25,								// No.7信令：收到BLO
	ATDL_DoubleOccupy=26,						// No.7信令：检出同抢
	ATDL_CircuitReset=27,						// No.7信令：收到电路/群复原信号
	ATDL_BlockedByRemote=28,					// No.7信令：电路被对端交换机闭塞

	ATDL_SS1WaitOccupyAckTimeout=40,			// No.1信令：等待占用应答信号超时
	ATDL_SS1RcvCAS_HANGUP=41,					// No.1信令：收到后向拆线信号
	ATDL_SS1RcvA4=42,							// No.1信令：收到A4信号（机键拥塞）
	ATDL_SS1RcvA5=43,							// No.1信令：收到A5信号（空号）
	ATDL_SS1RcvUndefinedAx=44,					// No.1信令：收到未定义的后向A组信号
	ATDL_SS1RcvUndefinedAxOnTxCallerId=45,		// No.1信令：送主叫时收到未定义的后向A组信号
	ATDL_SS1WaitAxTimeout=46,					// No.1信令：等候接收后向A组信号超时
	ATDL_SS1WaitAxStopTimeout=47,				// No.1信令：等候后向A组信号停发超时
	ATDL_SS1WaitAxTimeoutOnTxCallerId=48,		// No.1信令：送主叫时等候后向A组信号超时
	ATDL_SS1WaitAxStopTimeoutOnTxCallerId=49,	// No.1信令：送主叫时等候后向A组信号停发超时
	ATDL_SS1RcvKB2=50,							// No.1信令：收到KB2信号(用户“市忙”)
	ATDL_SS1RcvKB3=51,							// No.1信令：收到KB3信号(用户“长忙”)
	ATDL_SS1RcvKB4=52,							// No.1信令：收到KB4信号（机键拥塞）
	ATDL_SS1RcvKB5=53,							// No.1信令：收到KB5信号（空号）
	ATDL_SS1RcvUndefinedKB=54,					// No.1信令：收到未定义的KB信号
	ATDL_SS1WaitKBTimeout=55,					// No.1信令：接收后向KB信号超时
	ATDL_SS1WaitKBStopTimeout=56,				// No.1信令：等候被叫方停发后向KB信号超时

	ATDL_ISDNNETISBUS	= 60,					//ISDN：网络忙
	ATDL_ISDNEMPTYNO	= 61,					//ISDN:所拨的是空号.

	ATDL_IllegalMessage = 65,                   //SS7:非法消息
	ATDL_RcvREL         = 66,                   //ISUP:收到释放消息
};



//-----------------------------------------------------------------------
// 自动拨号任务执行情况的常量定义，函数SsmChkAutoDial()的返回值
//-----------------------------------------------------------------------
enum{
	DIAL_STANDBY        = 0,	// 没有自动拨号任务
	DIAL_DIALING        = 1,	// 正在自动拨号
	DIAL_ECHOTONE       = 2,	// 发送完被叫号码后检测到了回铃音
	DIAL_NO_DIALTONE    = 3,	// 没有拨号音，自动拨号失败。
	DIAL_BUSYTONE       = 4,	// 被叫用户忙，自动拨号结束
	DIAL_ECHO_NOVOICE   = 5,	// 模拟外线通道拨号结束并收到回铃音后出现无声，自动拨号结束
	DIAL_NOVOICE        = 6,	// 模拟外线通道拨号结束后在指定时间内没有检测到任何声音，自动拨号结束
	DIAL_VOICE          = 7,	// 被叫用户摘机，自动拨号结束
	DIAL_VOICEF1        = 8,	// 被叫用户摘机且收到频率F1的声音（模拟外线通道），自动拨号结束
	DIAL_VOICEF2        = 9,	// 被叫用户摘机且收到频率F2的声音（模拟外线通道），自动拨号结束
	DIAL_NOANSWER       = 10,	// 无人接听，自动拨号失败
	DIAL_FAILURE        = 11,	// 自动拨号失败
	DIAL_INVALID_PHONUM = 12,	// 空号，自动拨号结束
};

//-----------------------------------------------------------------------
// 通道挂起原因常量定义，函数SsmGetPendingReason()的返回值
//-----------------------------------------------------------------------
enum{
	ANALOGOUT_NO_DIALTONE=0,				// 模拟通道：自动拨号时没有检测到拨号音，自动拨号失败。
	ANALOGOUT_BUSYTONE=1,					// 模拟通道：自动拨号结束后检测到拨号音，自动拨号失败。
	ANALOGOUT_ECHO_NOVOICE=2,				// 模拟通道：自动拨号结束后并检测到回铃后出现无。
	ANALOGOUT_NOANSWER=3,					// 模拟通道：自动拨号结束后检测到回铃信号但在指定的时间内没有应答。
	ANALOGOUT_TALKING_REMOTE_HANGUPED=4,	// 模拟通道：在"通话"状态时检测对方挂机
	ANALOGOUT_NOVOICE=5,					// 模拟通道：自动拨号结束后检测到线路上出现无声

	PEND_WaitBckStpMsg=10,					// 数字中继通道：等待应用程序设置被叫用户状态

	SS1IN_BWD_KB5=11,						// No.1信令通道：等待主叫拆线
	PEND_RemoteHangupOnTalking=12,			// 数字中继通道：自动呼入进入通话后检测到主叫用户先挂机

	PEND_AutoDialFailed=13,					// 数字中继通道：自动拨号失败
	PEND_SsxUnusable=14,					// 数字中继通道：信令不可用
	PEND_CircuitReset=15,					// 数字中继通道：电路复原
	PEND_PcmSyncLos=16,						// 数字中继通道：基本祯同步丢失时间超过100ms

	SS1OUT_TALKING_REMOTE_HANGUPED=20,		// 数字中继通道：自动呼出进入通话后检测到被叫用户先挂机
	PEND_CalleeHangupOnTalking=20,			// 数字中继通道：自动呼出进入通话后检测到被叫用户先挂机

	SS1OUT_NOANSWER=21,						// No.1信令通道：等待被叫用户摘机超时
	SS1OUT_NOBWDACK=22,						// No.1信令通道：等待占用应答信号超时
	SS1OUT_DIALING_BWD_HANGUP=23,			// No.1信令通道：收到后向拆线信号
	SS1OUT_BWD_A5=24,						// No.1信令通道：收到A=5（空号）信号
	SS1OUT_BWD_KB5=25,						// No.1信令通道：收到KB=5（空号）信号
	SS1OUT_BWD_KB2=26,						// No.1信令通道：用户“市忙”
	SS1OUT_BWD_KB3=27,						// No.1信令通道：用户”长忙“
	SS1OUT_BWD_A4=28,						// No.1信令通道：机键拥塞
	SS1OUT_BWD_KB4=29,						// No.1信令通道：收到KB=4（机键拥塞）信号
	SS1OUT_TIMEOUT_BWD_A=30,				// No.1信令通道：等候接收后向A组信号超时
	SS1OUT_TIMEOUT_BWD_A_STOP=31,			// No.1信令通道：等候后向A组信号停发超时
	SS1OUT_TIMEOUT_BWD_KB=32,				// No.1信令通道：接收后向KB信号超时
	SS1OUT_TIMEOUT_BWD_KB_STOP=33,			// No.1信令通道：等候被叫方停发后向KB信号超时
	SS1OUT_TIMEOUT_CALLERID_BWD_A1=34,		// No.1信令通道：收到未定义的后向A组信号
	SS1OUT_TIMEOUT_CALLERID_BWD_A1_STOP=35,	// No.1信令通道：发送CALLERID时等候后向A组信号停发超时
	SS1OUT_UNDEFINED_CALLERID_BWD_A=36,		// No.1信令通道：发送主叫号码时收到未定义的后向A组信号
	SS1OUT_UNDEFINED_BWD_A=37,				// No.1信令通道：收到未定义的后向A组信号
	SS1OUT_UNDEFINED_BWD_KB=38,				// No.1信令通道：收到未定义的KB信号
	
	ISDN_CALLOVER		= 41,			//呼叫结束,对方先挂机.
	ISDN_WAIT_RELEASE	= 42,			//等待释放
	ISDN_HANGING		= 43,			//拆线中
	ISDN_RELEASING		= 44,			//正在释放

	ISDN_UNALLOCATED_NUMBER = 45,		//ISDN，未分配的号码
	ISDN_NETWORK_BUSY		= 46,		//ISDN, 网络忙。
	ISDN_CIRCUIT_NOT_AVAILABLE= 47,		//ISDN, 指定的电路不可用。
	PEND_CalleeHangupOnWaitRemotePickUp=48,		// added by cqb for SHCTI030902 数字中继通道：自动呼出后等待被叫挂机时检测到被叫用户先挂机

	ISUP_HardCircuitBlock    = 49,
	ISUP_RemoteSuspend       = 50,

	PEND_RcvHGBOrSGB		 = 51,//Appended by xxb,for 接收到对端交换机SGB/HGB后驱动错误处理,2003.11.27

	ISDN_NO_ANSWER			=52,		//ISDN, 无应答
	ISDN_CALL_REJ			=53,		//ISDN, 呼叫拒绝
};

//-----------------------------------------------------------------------
// 通道状态常量定义，函数SsmGetChState()的返回值
//-----------------------------------------------------------------------
enum{
	S_CALL_STANDBY =0,					//“空闲”状态
	S_CALL_PICKUPED=1,					//“摘机”状态
	S_CALL_RINGING =2,					//“振铃”状态
	S_CALL_TALKING =3,					//“通话”状态

	S_CALL_ANALOG_WAITDIALTONE  =4,		// “等待拨号音”状态  （模拟通道）
	S_CALL_ANALOG_TXPHONUM      =5,		// “拨号”状态        （模拟通道）
	S_CALL_ANALOG_WAITDIALRESULT=6,		// “等待拨号结果”状态（模拟通道）

	S_CALL_PENDING            =7,		// “挂起”状态
	S_CALL_OFFLINE            =8,		// “断线”状态        （录音通道）
	S_CALL_WAIT_REMOTE_PICKUP =9,		// “等待被叫摘机”状态
	S_CALL_ANALOG_CLEAR      =10,		//  **内部状态**       （模拟通道）
	S_CALL_UNAVAILABLE       =11,		// “通道不可用”状态
	S_CALL_LOCKED            =12,		// “呼出锁定”状态

	S_CALL_RemoteBlock	     =19,		// “对端闭塞”状态
	S_CALL_LocalBlock        =20,		// “本端闭塞”状态

	S_CALL_Ss1InWaitPhoNum  =30,		// “等待接收被叫号码”状态			（No.1信令呼入）
	S_CALL_Ss1InWaitFwdStop =31,		// “等待前向停发”状态				（No.1信令呼入）
	S_CALL_Ss1InWaitCallerID=32,		// “等待接收CALLERID号码”状态		（No.1信令呼入）
	S_CALL_Ss1InWaitKD      =33,		// “等待接收KD信号”状态			（No.1信令呼入）
	S_CALL_Ss1InWaitKDStop  =34,		// “等待KD信号停发”状态			（No.1信令呼入）
	S_CALL_SS1_SAYIDLE      =35,		// “发送示闲信令”状态				（No.1信令）
	S_CALL_SS1WaitIdleCAS   =36,		// “等待对端示闲”状态				（No.1信令）
	S_CALL_SS1PhoNumHoldup  =37,		// “冗余号码拦截”状态				（No.1信令）
	S_CALL_Ss1InWaitStopSendA3p=38,		// “等待停发A3p信号”状态			（No.1信令）


	S_CALL_Ss1OutWaitBwdAck       =40,	// “等待后向占用证实信令”状态		（No.1信令呼出）
	S_CALL_Ss1OutTxPhoNum         =41,	// “发送被叫号码”状态				（No.1信令呼出）
	S_CALL_Ss1OutWaitAppendPhoNum =42,	// “等待应用程序追加电话号码”状态	（No.1信令呼出）
	S_CALL_Ss1OutTxCallerID       =43,	// “发送主叫号码”状态				（No.1信令呼出）
	S_CALL_Ss1OutWaitKB           =44,	// “等待接收KB信号”状态			（No.1信令呼出）
	S_CALL_Ss1OutDetectA3p        =45,	// “检测A3p信号(脉冲)”状态		（No.1信令呼出）


	S_FAX_Wait    = S_CALL_STANDBY,		// “空闲”状态								（传真通道）
	S_FAX_ROUND   = 50,					// “状态转移过程中”状态					（传真通道）
	S_FAX_PhaseA  = 51,					// “传真呼叫建立”状态						（传真通道）
	S_FAX_PhaseB  = 52,					// “传真报文前处理”状态					（传真通道）
	S_FAX_SendDCS = 53,					// “传真发送中向接收方发送DCS信号”状态    （传真通道）
	S_FAX_Train   = 54,					// “传真报文传输前传输训练”状态			（传真通道）
	S_FAX_PhaseC  = 55,					// “传真报文传输中”状态					（传真通道）
	S_FAX_PhaseD  = 56,					// “传真报文后处理”状态					（传真通道）
	S_FAX_NextPage= 57,					// “传真报文传输下一页”状态				（传真通道）
	S_FAX_AllSent = 58,					// “传真发送中报文传输结束”状态			（传真通道）
	S_FAX_PhaseE  = 59,					// “传真呼叫释放”状态						（传真通道）
	S_FAX_Reset   = 60,					// “复位MODEM”状态						（传真通道）
	S_FAX_Init    = 61,					// “初始化MODEM”状态						（传真通道）
	S_FAX_RcvDCS  = 62,					// “传真接收中接收发方的DCS信号”状态		（传真通道）
	S_FAX_SendFTT = 63,					// “传真接收中向发方发送训练失败信号FTT”状态		（传真通道）
	S_FAX_SendCFR = 64,					// “传真接收中向发方发送可接受的证实信号CFR”状态  （传真通道）

	S_TUP_WaitPcmReset    = 70,			// “等待电路群复原”状态		（No.7信令TUP协议）
	S_TUP_WaitSAM         = 71,			// “等待后续地址消息”状态		（No.7信令TUP协议）
	S_TUP_WaitGSM         = 72,			// “等待GSM消息”状态			（No.7信令TUP协议）
	S_TUP_WaitCLF         = 73,			// “等待主叫拆线信号”状态		（No.7信令TUP协议）
	S_TUP_WaitPrefix      = 74,			// “等待接收入局字冠”状态		（No.7信令TUP协议）
	S_TUP_WaitDialAnswer  = 75,			// “等待拨号结果”状态			（No.7信令TUP协议）
	S_TUP_WaitRLG         = 76,			// “等待释放监护信号”状态		（No.7信令TUP协议）
	S_TUP_WaitSetCallerID = 77,

	S_ISDN_OUT_WAIT_NET_RESPONSE	= 81,	//ISDN：等待网络响应
	S_ISDN_OUT_PLS_APPEND_NO		= 82,	//ISDN：请追加号码
	S_ISDN_IN_CHK_CALL_IN			= 83,	//ISDN：检测到呼入
	S_ISDN_IN_RCVING_NO				= 84,	//ISDN：正在接收号码
	S_ISDN_IN_WAIT_TALK				= 85,	//ISDN：准备进入通话
	S_ISDN_OUT_WAIT_ALERT			= 86,	//ISDN: 等待对方发提醒信号

	S_ISDN_CALL_BEGIN				= 87,	//ISDN：呼出时为刚发起呼叫，呼入时为刚检测到呼入
	S_ISDN_WAIT_HUANGUP				= 88,	//ISDN:等待释放完成

	S_CALL_SENDRING                 = 100,  //磁石模块正在发送振铃

	S_SPY_STANDBY					= S_CALL_STANDBY,	//监控：空闲
	S_SPY_RCVPHONUM                 = 105,  //监控：接收号码
	S_SPY_RINGING					= S_CALL_RINGING,	//监控：振铃
	S_SPY_TALKING					= S_CALL_TALKING,	//监控：通话

	S_SPY_SS1RESET					= 110,	//SS1监控：复原
	S_SPY_SS1WAITBWDACK				= 111,	//SS1监控：等待后向证实
	S_SPY_SS1WAITKB					= 112,	//SS1监控：等待KB

	S_ISUP_WaitSAM                 = 120,// ISUP:等待后继号码
	S_ISUP_WaitRLC                 = 121,// ISUP:等待释放完成消息
	S_ISUP_WaitReset               = 122,// ISUP:电路复原
	S_ISUP_LocallyBlocked          = 123,// ISUP:本地闭塞，即本地闭塞远端呼出
	S_ISUP_RemotelyBlocked         = 124,// ISUP:远端闭塞，即远端闭塞本端呼出
	S_ISUP_WaitDialAnswer          = 125,// ISUP:等待呼出结果
	S_ISUP_WaitINF                 = 126,// ISUP:等待主叫号码
	S_ISUP_WaitSetCallerID         = 127,

};

enum { 
	//语音识别
	E_PROC_Recognize,		//0x0000        //语音识别结束事件

	//ISDN呼叫
	E_CHG_ISDNStatus,		//0x0001        //ISDN底层状态改变事件

	//ss7
	E_RCV_Ss7Msu,		//0x0002        //SS7 MSU接收通知事件
	E_CHG_Mtp3State,		//0x0003        //Mtp3状态改变事件

	//传真
	E_CHG_FaxChState,		//0x0004        //传真通道传真状态改变事件
	E_CHG_FaxPages,		//0x0005        //传真接收/发送页结束事件
	E_PROC_FaxEnd,		//0x0006        //传真结束事件

	//PCM线路同步状态
	E_CHG_PcmLinkStatus,	//0x0007    //PCM线路同步状态改变事件

	//录音通道
	E_CHG_LineVoltage,	//0x0008        //录音通道线路电压变化事件

	//ss1
	E_RCV_CAS,		//0x0009        //接收到的CAS值有变化
	E_RCV_R2,			//0x000A        //收到新的R2 值

	//DTMF接收
	E_PROC_WaitDTMF,		//0x000B        //WaitDTMF任务结束事件
	E_CHG_RcvDTMF,		//0x000C

	//DTMF发送
	E_PROC_SendDTMF,		//0x000D        //发送DTMF任务结束事件

	//发送闪断
	E_PROC_SendFlash,		//0x000E        //发送闪断任务结束事件

	//放音
	E_PROC_PlayEnd,		//0x000F        //放音任务结束
	E_PROC_PlayFile,		//0x0010        //文件放音进程指示
	E_PROC_PlayFileList,	//0x0011    //文件列表放音进程指示
	E_PROC_PlayMem,		//0x0012        //内存放音进程指示

	//录音
	E_PROC_RecordEnd,		//0x0013        //录音任务结束
	E_PROC_RecordFile,		//0x0014        //文件录音任务进展指示
	E_PROC_RecordMem,		//0x0015        //内存录音任务进展指示

	//FSK发送
	E_PROC_SendFSK,		//0x0016        //发送FSK任务结束事件

	//FSK接收
	E_PROC_RcvFSK,		//0x0017        //RcvFSK任务结束

	//呼叫控制
	E_CHG_ChState,		//0x0018        //通道状态发生变化
	E_PROC_AutoDial,		//0x0019        //AutoDial任务有进展
	E_CHG_RemoteChBlock,	//0x001A
	E_CHG_RemotePCMBlock,	//0x001B
	E_SYS_ActualPickup,		//0x001C        //外线通道实际摘机
	E_CHG_RingFlag,		//0x001D        //铃流电平变化
	E_CHG_RingCount,		//0x001E        //振铃计数变化
	E_CHG_CIDExBuf,		//0x001F        //CID扩展接收缓冲区变化
	E_CHG_RxPhoNumBuf,		//0x0020        //被叫号码接收缓冲区变化
	E_CHG_PolarRvrsCount,	//0x0021   //外线通道极性反转
	E_SYS_RemotePickup,		//0x0022        //模拟电话线相对能量算法检测被叫摘机

	//座席
	E_CHG_FlashCount,		//0x0023        //flash计数发生变化
	E_CHG_HookState,		//0x0024        //Hook状态发生变化

	//信号音检测
	E_CHG_ToneAnalyze,	//0x0025        //信号音分析结果变化事件
	E_OverallEnergy,		//0x0026
	E_CHG_OvrlEnrgLevel,	//0x0027    //全频能量标识输出事件
	E_CHG_BusyTone,		//0x0028        //忙音计数变化事件
	E_CHG_BusyToneEx,		//0x0029        //松散忙音变化
	E_CHG_VocFxFlag,		//0x002A        //单音频信号音电平变化
	E_CHG_ToneValue,		//0x002B        //信号音电平变化
	E_CHG_RingEchoToneTime,	//0x002C
	E_CHG_PeakFrq,		//0x002D        //PeakFrq有变化
	E_SYS_BargeIn,		//0x003E        //检测到BargeIn
	E_SYS_NoSound,		//0x002F        //检测到NoSound

	//定时器
	E_SYS_TIMEOUT,		//0x0030        //定时器事件

	//信令监控
	E_CHG_SpyState,		//0x0031        //被监控电路的接续状态通知事件
	E_CHG_SpyLinkStatus,	//0x0032    //被监控的PCM链路状态通知事件
};

enum { 
	TIMER_ONE, 
	TIMER_PERIODIC 
};

enum { 	
	NO_EVENT,			// 无事件方式
	EVENT_POLLING,		//事件轮询
	EVENT_CALLBACK,		//事件回调
	EVENT_MESSAGE		//windows消息
};

//文件放音进程指示输出参数类型.
enum {  
	PLAYPERCENT, 
	PLAYTIME, 
	DATABYTESPLAYED, 
	DATABYTESTOPLAY 
};

//内存录放音进程指示输出参数类型.
enum { 	
	END_HALF_BUFFER, 
	END_BUFFER, 
	MEM_OFFSET 
};

//文件录音进程指示输出参数类型.
enum 
{ 
	RECORD_TIME, 
	RECORD_BYTES 
};

///////////////////////////////////////

%include cpointer.i
%include typemaps.i
%pointer_functions(int, intp);
%apply int* OUTPUT { int* r};

typedef char         	CHAR;
typedef float           FLOAT;
typedef int		BOOL;
typedef int             INT;
typedef long		LONG;
typedef void            VOID;

typedef unsigned char	BYTE;
typedef unsigned char   UCHAR;
typedef unsigned int    UINT;
typedef unsigned long   DWORD;
typedef unsigned long   ULONG;
typedef unsigned short  USHORT;
typedef unsigned short	WORD;
typedef BOOL            *LPBOOL;
typedef BYTE            *LPBYTE;
typedef BYTE            *PBYTE;
typedef CHAR            *LPSTR;
typedef CHAR            *LPTSTR;
typedef CHAR            *PCHAR;
typedef DWORD           *LPDWORD;
typedef DWORD           *PDWORD;
typedef WORD            *LPWORD;
typedef WORD            *PWORD;
typedef UCHAR           *PUCHAR;
typedef long		*LPLONG;
typedef long		*PLONG;
typedef void            *LPVOID;
typedef const CHAR      *LPCSTR;
typedef const CHAR      *LPCTSTR;
typedef const void      *LPCVOID;
typedef void      	*PVOID;	
/////////////////////////////////////////

typedef struct _MESSAGE_INFO 
{
	WORD wEventCode;
	int nReference;
	DWORD dwParam;		//输出参数
} MESSAGE_INFO, *PMESSAGE_INFO;

typedef struct _EVENT_SET_INFO 
{
	DWORD dwWorkMode;
	LPVOID lpHandlerParam;
	DWORD dwOutCondition;
	DWORD dwOutParamVal;
	DWORD dwUser;
} EVENT_SET_INFO, *PEVENT_SET_INFO;

typedef struct tagFAX_FILE_SCT
{
	char		szFileName[256];
	int		nStartPage;
	int		nEndPage;
	int		nReserve1;
	int		nReserve2;
}FAX_FILE_SCT, *PFAX_FILE_SCT;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ INITIALIZATION OPERATION  @@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmStartCti(LPSTR lpSsmCfgFileName, LPSTR lpIndexCfgFileName);
int  SsmCloseCti();
void  SsmGetLastErrMsg(LPSTR szErrMsgBuf);
char * SsmGetLastErrMsgA(void);
int  SsmGetLastErrCode();
int  SsmGetMaxUsableBoard();
int  SsmGetMaxCfgBoard();
int  SsmGetRxDtmfBufSize();
int  SsmGetAccreditId(int nBId);
int  SsmGetMaxCh(void);
int  SsmGetChType(int ch);
int  SsmSetMaxIdxSeg(WORD wMaxIdxSeg);
int  SsmLoadIndexData(int	nSegNo, LPSTR pAlias, int nCodec, LPSTR	pVocFile, long lStartPos, long lLen);
int  SsmFreeIndexData(int nSegNo);
int  SsmGetTotalIndexSeg();
int  SsmPauseCard();
int  SsmRestartCard();

int  SsmGetAccreditIdEx(int nBId);	
int  SsmGetBoardModel(int nBId);		
void  SsmSetDV(BOOL bEnable);			
BOOL  SsmGetDV(void);

DWORD  SsmGetPciSerialNo(int nBId);

DWORD  SsmGetIntCount();
int  SsmSetListenMode(int nMode);

int  SsmStartBoard(int nBId);	
int  SsmStopBoard(int nBId);
int  SsmGetChHdInfo(int ch, int * pnBId, int * pnBCh);
int  SsmGetAppChId(int * AppchId, int BrdId, int BrdChId);

int  SsmSetChState(int ch, int nState);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ PLAY OPERATION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmSetPlayVolume(int ch, int nVolume);
int  SsmSetDtmfStopPlay(int ch, BOOL bDspf);
int  SsmGetDtmfStopPlayFlag(int ch);
int  SsmSetBargeinStopPlay(int ch, BOOL bBispf);
int  SsmGetBargeinStopPlayFlag(int ch);
int  SsmPlayFile(int ch, LPSTR pszFileName, int nFormat, DWORD dwStartPos, DWORD dwLen);
int  SsmStopPlay(int ch);
int  SsmStopPlayFile(int ch);
int  SsmPausePlay(int ch);
int  SsmRestartPlay(int ch);
int  SsmFastFwdPlay(int ch);
int  SsmFastBwdPlay(int ch);
int  SsmSetPlayTime(int ch, DWORD dwTime);
long  SsmGetPlayedTimeEx(int ch);
int   SsmGetPlayingFileInfo(int ch , int *pnFormat , long *pnTotalTime);
int  SsmSetPlayPrct(int ch, DWORD dwPercentage);
long  SsmGetPlayedTime(int ch);
int  SsmGetPlayedPercentage(int ch);
long  SsmGetDataBytesToPlay(int ch);
int  SsmCheckPlay(int ch);
int  SsmGetPlayType(int ch);
int  SsmPlayIndexString(int ch, LPSTR pszIdxStr);
int  SsmPlayIndexList(int ch, WORD wIdxListLen, PWORD pwIdxList);
int  SsmStopPlayIndex(int ch);
int  SsmClearFileList(int ch);
int  SsmAddToFileList(int ch, LPSTR pszFileName, int nFormat, DWORD dwStartPos, DWORD dwLen);
int  SsmPlayFileList(int ch);
int  SsmStopPlayFileList(int ch);
int  SsmPlayMem(int ch, int nFormat, LPBYTE pBuf, DWORD dwBufSize, DWORD dwStartOffset, DWORD dwStopOffset);
int  SsmGetPlayOffset(int ch, DWORD* pdwPlayOffset);
int  SsmSetStopPlayOffset(int ch, DWORD dwStopPlayOffset);
int  SsmStopPlayMem(int ch);
int  SsmClearPlayMemList(void);
int  SsmAddToPlayMemList(LPBYTE pBuf, DWORD dwDataLen, int nFormat);
int  SsmPlayMemList(int ch, PWORD pMemList, WORD wMemListLen);
int  SsmStopPlayMemList(int ch);

int  SsmSetDTMFStopPlayCharSet(int ch, LPSTR lpstrDtmfCharSet);
int  SsmGetDTMFStopPlayCharSet(int ch, LPSTR lpstrDtmfCharSet);
int  SsmSetHangupStopPlayFlag(int ch, BOOL bHangupStopRecFlag );
int  SsmPlayMemBlock(int ch,
		int nFormat,
		LPBYTE pBuf,
		DWORD dwBufSize,
		PLAYMEMBLOCKHANDLER OnPlayMemBlockDone,
		PVOID pV);

int  SsmStopPlayMemBlock(int ch);
long  SsmGetDataBytesPlayed(int ch);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@    RECORD OPERATION   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmSetRecVolume(int ch, int nVolume);
int  SsmGetRecType(int ch);
int  SsmRecToFile(int ch, LPSTR pszFileName, int nFormat, DWORD dwStartPos, DWORD dwBytes, DWORD dwTime, int nMask);
int  SsmRecToFileA(int ch, LPSTR pszFileName, int nFormat,
		DWORD dwStartPos, DWORD dwBytes, DWORD dwTime, int nMask,
		LPRECTOMEM	pfnRecToMem);

int  SsmRecToFileEx(int ch, LPSTR pszFileName, int nFormat,
		DWORD dwStartPos, DWORD dwBytes, DWORD dwTime, int nMask,
		BOOL bSaveToFileOnBargin, DWORD dwRollbackTime);

int  SsmPauseRecToFile(int ch);
int  SsmRestartRecToFile(int ch);
long  SsmGetRecTime(int ch);
long  SsmGetDataBytesToRecord(int ch);
int  SsmStopRecToFile(int ch);
int  SsmChkRecToFile(int ch);
int  SsmRecToMem(int ch, int nFormat, LPBYTE pBuf, DWORD dwBufSize, DWORD dwStartOffset);
int  SsmStopRecToMem(int ch);
long  SsmGetRecOffset(int ch);

int  SsmGetRecAGCSwitch(int ch);
int  SsmSetRecAGC(int ch, BOOL bEnable);

int  SsmQueryOpRecMixer(int ch);
int  SsmSetRecMixer(int ch, BOOL bEnRecMixer, int nMixerVolume);
int  SsmGetRecMixerState(int ch, int* pnEnRecMixer, int* pnMixerVolume);

int  SsmSetPrerecord(int ch, BOOL bEnable, int nMode, WORD wInsertTime, int nFormat);
int  SsmSetTruncateTail(int ch, DWORD	dwTime);
long  SsmGetTruncateTailTime(int ch);
int  SsmGetPrerecordState(int ch, int* pnMode, PWORD pwInsertTime, int* pnFormat);
int  SsmSetDTMFStopRecCharSet(int ch, LPSTR lpstrDtmfCharSet);
int  SsmGetDTMFStopRecCharSet(int ch, LPSTR lpstrDtmfCharSet);
int  SsmSetHangupStopRecFlag(int ch, BOOL bHangupStopRecFlag );
int  SsmCheckRecord(int ch);
int  SsmRecordMemBlock(int ch, int nFormat, LPBYTE pBuf,
		DWORD dwBufSize, RECORDMEMBLOCKHANDLER OnRecMemBlockDone, PVOID pV);
int  SsmStopRecordMemBlock(int ch);
int  SsmSetNoModuleChBusRec(int ch, int nRec);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@   RxDTMF OPERATION   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmEnableRxDtmf(int ch, BOOL bRun);
int  SsmClearRxDtmfBuf(int ch);
int  SsmGetDtmfStr(int ch, LPSTR pszDtmf);
char*  SsmGetDtmfStrA(int ch);
int  SsmGetRxDtmfLen(int ch);
int  SsmGet1stDtmf(int ch, char* pcDtmf);
int  SsmGet1stDtmfClr(int ch, char* pcDtmf);
int  SsmGetLastDtmf(int ch, char* pcDtmf);
int  SsmSetWaitDtmf(int ch, WORD wTimeOut, WORD wMaxLen, char cEndChar, BOOL bWithEndChar);
int  SsmChkWaitDtmf(int ch, LPSTR	pszDtmf);

int  SsmCancelWaitDtmf(int ch);	
int  SsmSetWaitDtmfEx(int ch, WORD wTimeOut, WORD wMaxLen, char cEndChar, BOOL bWithEndChar);

int  SsmSetRxDtmfHandler(int ch, RXDTMFHANDLER OnRcvDtmf, PVOID pV);


int  SsmSetWaitDtmfExA(int ch, WORD wTimeOut, WORD wMaxLen, char* szEndChar, BOOL bWithEndChar);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@ TXDTMF OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmQueryTxDtmf(int ch, LPSTR pszDtmf);
int  SsmQueryTxFlash(int ch, LPSTR pszDtmf);
int  SsmSetTxDtmfPara(int ch, WORD wOnTime, WORD wOffTime);
int  SsmGetTxDtmfPara(int ch, PWORD pwOnTime, PWORD pwOffTime);
int  SsmTxDtmf(int ch, LPSTR pszDtmf);
int  SsmStopTxDtmf(int ch);
int  SsmChkTxDtmf(int ch);
int  SsmTxFlash(int ch, WORD time);
int  SsmChkTxFlash(int ch);
int  SsmSetTxFlashCharTime(int ch, WORD time);
int  SsmGetTxFlashCharTime(int ch);	


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ INTER-CH OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmSetLocalFlashTime(int nFlashTime);
int  SsmSetASDT(int ch, BOOL bEnAutoSendDialTone);
int  SsmGetASDT(int ch);
int  SsmSetASTOD(int ch, BOOL bEnAutoSendDialTone);
int  SsmGetASTOD(int ch);
int  SsmGetFlashCount(int ch);
int  SsmClearFlashCount(int ch);
int  SsmGetHookState(int ch);
int  SsmStartRing(int ch);
int  SsmStopRing(int ch);
int  SsmStartRingWithFskCID(int ch, LPSTR pBuf, DWORD dwMaxBit, DWORD dw1stRingOffDelay);
int  SsmStartRingWithCIDStr(int ch, LPSTR pBuf, DWORD dwLen, DWORD dw1stRingOffDelay);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ SEND TONE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmQueryOpSendTone(int ch);
int  SsmSendTone(int ch, int nToneType);
int  SsmSendToneEx(int ch, DWORD dwOnTime, DWORD dwOffTime);
int  SsmStopSendTone(int ch);
int  SsmSetTxTonePara(int ch, int nFreq1, int nVolume1, int nFreq2, int nVolume2);
int  SsmGetTxTonePara(int ch, int* pnFreq1, int* pnVolume1, int* pnFreq2, int* pnVolume2);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@ TONE ANALYZE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmQueryOpToneAnalyze(int ch);
int  SsmClearToneAnalyzeResult(int ch);
int  SsmStartToneAnalyze(int ch);
int  SsmCloseToneAnalyze(int ch);
long  SsmGetOverallEnergy(int ch);
int  SsmGetVocFxFlag(int ch, int nSelFx, BOOL bClear);
int  SsmGetToneAnalyzeResult(int ch);
int  SsmGetBusyToneLen(int ch);
int  SsmGetBusyToneCount(int ch);
int  SsmGetRingEchoToneTime(int ch);

int  SsmGetBusyToneEx(int ch);

int  SsmSetTonePara(int ch, WORD wToneFreq1,WORD wToneBW1,WORD wToneFreq2,WORD wToneBW2,DWORD dwIsToneRatio);
int  SsmSetIsDialToneDtrTime(int ch, WORD wIsDialToneDtrTime);
int  SsmSetBusyTonePeriod(int ch, WORD wBusyTonePeriod);
int  SsmSetIsBusyToneDtrCnt(int ch, WORD wIsBusyToneDtrCnt);
int  SsmSetRingEchoTonePara(int ch, WORD wRingEchoOnTime,WORD wRingEchoOffTime);
int  SsmSetVoiceFxPara(int ch, WORD wSelFx, WORD wFx,WORD wFxBW, DWORD dwIsVocFxRatio, WORD wIsVocFxDtrTime);
int  SsmSetVoiceOnDetermineTime(int ch, WORD wIsVocDtrTime);
int  SsmSetMinVocDtrEnergy(int ch, DWORD dwMinVocDtrEnergy);
int  SsmGetTonePara(int ch, PWORD pwToneFreq1, PWORD pwToneBW1,PWORD pwToneFreq2,PWORD pwToneBW2,PDWORD pdwIsToneRatio);
int  SsmGetIsDialToneDtrTime(int ch, PWORD pwIsDialToneDtrTime);
int  SsmGetBusyTonePeriod(int ch, PWORD pwBusyTonePeriod);
int  SsmGetIsBusyToneDtrCnt(int ch, PWORD pwIsBusyToneDtrCnt);
int  SsmGetRingEchoTonePara(int ch, PWORD pwRingEchoOnTime, PWORD pwRingEchoOffTime);
int  SsmGetIsNoVocDtrmTime(int ch, PWORD pwIsNoVocDtrmTime);
int  SsmGetVoiceFxPara(int ch, WORD wSelFx, PWORD pwFx,PWORD pwFxBW, PDWORD pdwIsVocFxRatio, PWORD pwIsVocFxDtrTime);
int  SsmGetVoiceOnDetermineTime(int ch, PWORD pwIsVocDtrTime);
int  SsmGetMinVocDtrEnergy(int ch, PDWORD pdwMinVocDtrEnergy);

int  SsmQueryOpPeakFrqDetect(int ch);
int  SsmSetPeakFrqDetectBW(int ch, WORD nPeakBW);
int  SsmGetPeakFrqDetectBW(int ch);
long  SsmGetPeakFrqEnergy(int ch);
int  SsmGetPeakFrq(int ch);

int  SsmStart2ndToneAnalyzer(int ch, BOOL bEn);
int  SsmGet2ndToneAnalyzerState(int ch);
int  SsmSet2ndTonePara(int ch, WORD wToneFreq1,WORD wToneBW1,WORD wToneFreq2,WORD wToneBW2,DWORD dwIsToneRatio);
int  SsmGet2ndTonePara(int ch, PWORD pwToneFreq1, PWORD pwToneBW1,PWORD pwToneFreq2,PWORD pwToneBW2,PDWORD pdwIsToneRatio);
int  SsmGet2ndToneAnalyzeResult(int ch);
int  SsmClear2ndToneAnalyzeResult(int ch);
int  SsmGet2ndBusyToneLen(int ch);
int  SsmGet2ndBusyToneCount(int ch);
int  SsmSet2ndBusyTonePeriod(int ch, WORD wBusyTonePeriod);
int  SsmGet2ndBusyTonePeriod(int ch, PWORD pwBusyTonePeriod);
int  SsmSet2ndIsBusyToneDtrCnt(int ch, WORD wIsBusyToneDtrCnt);
int  SsmGet2ndIsBusyToneDtrCnt(int ch, PWORD pwIsBusyToneDtrCnt);
int  SsmSet2ndIsDialToneDtrTime(int ch, WORD wIsDialToneDtrTime);
int  SsmGet2ndIsDialToneDtrTime(int ch, PWORD pwIsDialToneDtrTime);
int  SsmSet2ndRingEchoTonePara(int ch, WORD wRingEchoOnTime,WORD wRingEchoOffTime);
int  SsmGet2ndRingEchoTonePara(int ch, PWORD pwRingEchoOnTime, PWORD pwRingEchoOffTime);
int  SsmSetBusyTonePeriodEx(int ch, int nType, WORD wMax, PWORD pwPeriod);
int  SsmGetBusyTonePeriodEx(int ch, int nType, PWORD pwPeriod);			
WORD  SsmGetToneValue(int ch);
int  SsmSetToneValue(int ch,WORD value);

int  SsmGetOverallEnergyAllCh(int nBeginCh, int nChNum, PDWORD pdwEnergyTable);	

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@ BARGEIN OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmSetNoSoundDtrmTime(int ch, DWORD dwIsNoSoundDtrTime);
int  SsmSetIsBargeInDtrmTime(int ch, WORD wIsBargeInDtrmTime);
int  SsmSetBargeInSens(int ch, int nBargeInSens);
long  SsmGetNoSoundTime(int ch);
long  SsmGetNoSoundDtrmTime(int ch);
int  SsmGetIsBargeInDtrmTime(int ch);
int  SsmGetBargeInSens(int ch);
int  SsmDetectBargeIn(int ch);
int  SsmDetectNoSound(int ch);

int  SsmSetCalleeHookDetectP(int ch,
		WORD wMulti,
		WORD wValidTime);
int  SsmGetCalleeHookDetectP(int ch,
		PWORD pwMulti,
		PWORD pwValidTime);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ RING DETECT OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmQueryOpRingDetect(int ch);
int  SsmGetRingFlag(int ch);
int  SsmGetRingCount(int ch);
int  SsmClearRingCount(int ch);
int  SsmChkOpCallerId(int ch);
int  SsmGetCallerId(int ch, LPSTR szCallerId);
char*  SsmGetCallerIdA(int ch);
int  SsmGetCallerIdEx(int ch, LPSTR szCallerIdEx);
int  SsmClearCallerId(int ch);
int  SsmClearCallerIdEx(int ch);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@ CALL OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmPickup(int ch);
int  SsmCheckActualPickup(int ch);
int  SsmSetPickupNow(int ch, BOOL bFlag);
int  SsmHangup(int ch);
int  SsmAutoDial(int ch, LPSTR szPhoNum);
int  SsmAutoDialEx(int ch, LPSTR szPhoNum , WORD wParam);
int  SsmChkAutoDial(int ch);
int  SsmGetAutoDialFailureReason(int ch);
int  SsmGetBlockReason(int ch);
int  SsmGetChState(int ch);

int  SsmSetPlayDest(int ch, int nSelDest);
int  SsmSetRecBack(int ch, int nRecBack);

int  SsmSearchIdleCallOutCh(WORD wSearchMode, DWORD dwPrecedence);
int  SsmSetAutoCallDirection(int ch, BOOL bEnAutoCall, int nDirection);
int  SsmGetAutoCallDirection(int ch, int* pnDirection);
int  SsmAppendPhoNum(int ch, LPSTR szPhoNum);
int  SsmGetPendingReason(int ch);
long  SsmGetChStateKeepTime(int ch);
int  SsmGetPhoNumStr(int ch, LPSTR pszPhoNum);
char*  SsmGetPhoNumStrA(int ch);
int  SsmGetPhoNumLen(int ch);

int  SsmGet1stPhoNumStr(int ch, LPSTR pszPhoNum);
char*  SsmGet1stPhoNumStrA(int ch);
int  SsmGet1stPhoNumLen(int ch);

int  SsmEnableAutoSendKB(int ch, BOOL bEnable);
int  SsmGetAutoSendKBFlag(int ch);
int  SsmSetKB(int ch, BYTE btSigKB);
int  SsmSetKD(int ch, BYTE btSigKD);
int  SsmSetKA(int ch, BYTE btSigKA);
int  SsmSetTxCallerId(int ch, LPSTR pszTxCallerId);
int  SsmGetTxCallerId(int ch, LPSTR pszTxCallerId);
int  SsmGetKA(int ch);
int  SsmGetKB(int ch);
int  SsmGetKD(int ch);


int  SsmBlockLocalCh(int ch);
int  SsmUnblockLocalCh(int ch);
int  SsmQueryLocalChBlockState(int ch, PDWORD pdwBlockState);

int  SsmBlockLocalPCM(int nLocalPcmNo);
int  SsmUnblockLocalPCM(int nLocalPcmNo);
int  SsmQueryLocalPCMBlockState(int nLocalPcmNo, PDWORD pdwBlockState);

int  SsmQueryOpBlockRemoteCh(int ch);
int  SsmBlockRemoteCh(int ch);
int  SsmUnblockRemoteCh(int ch);
int  SsmGetRemoteChBlockStatus(int ch);

int  SsmBlockRemotePCM(int nLocalPcmNo, DWORD dwBlockMode);
int  SsmUnblockRemotePCM(int nLocalPcmNo, DWORD dwUnblockMode);
int  SsmGetRemotePCMBlockStatus(int nLocalPcmNo, DWORD dwBlockMode);

BOOL  SsmGetWaitAutoDialAnswerTime(WORD * pwSeconds);
BOOL  SsmSetWaitAutoDialAnswerTime(WORD wSeconds);

int  SsmStartPickupAnalyze(int ch);
int  SsmGetPickup(int ch);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@ ADAPTIVE FILTER OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmQueryOpEchoCanceller(int ch);
int  SsmSetEchoCanceller(int ch, BOOL bRun);
int  SsmGetEchoCancellerState(int ch);
int  SsmSetEchoCancellerStudy(int ch, BOOL bRun);
int  SsmGetEchoCancellerStudyState(int ch);
int  SsmGetEchoCancellerRatio(int ch);
int  SsmSaveEchoCancellerPara(int ch);
int  SsmSetEchoCancelDelaySize(int ch,WORD wSize);
WORD  SsmGetEchoCancelDelaySize(int ch);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ CT-BUS OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmListenTo(int ch1,int ch2);
int  SsmListenToEx(int ch1, int nVolume1, int ch2);
int  SsmStopListenTo(int ch1,int ch2);
int  SsmTalkWith(int ch1,int ch2);
int  SsmTalkWithEx(int ch1, int nVlm1, int ch2, int nVlm2);
int  SsmStopTalkWith(int ch1,int ch2);

void  PlayListen(DWORD dwBId, DWORD ch);
void  PlayListenNew(DWORD dwSpeakerCh, DWORD dwMonitorCh);
void  StopListen(DWORD dwBId);
void  StopListenNew(DWORD dwSpeakerCh);

int  SsmLinkFrom(int ch1,int ch2);
int  SsmStopLinkFrom(int ch1,int ch2);
int  SsmLinkFromEx(int ch1, int nVolume1, int ch2);
int  SsmLinkFromAllCh(int ch, int nVolume, int*nListenerTable,int nListenerNum);
int  SsmUnLinkFromAllCh(int ch, int*nListenerTable,int nListenerNum);

int 	SsmLinkToBus(int ch,int ts);
int   SsmUnLinkToBus(int ch,int ts);
int 	SsmLinkFromBus(int ts,int ch);
int 	SsmLinkFromBusEx(int ts, int ch, int vlm);
int 	SsmUnLinkFromBus(int ts,int ch);
int 	SsmListenToPlay(int ch1, int vlm1, int ch2);
int 	SsmUnListenToPlay(int ch1, int ch2);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@ CONFERENCE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmCreateConfGroup(int nMaxMember, int nMaxSpeaker, int nMaxSpeaking, int nMaxSilenceTime);
int  SsmFreeConfGroup(int nGrpId);
int  SsmJoinConfGroup(int nGrpId, int ch, WORD wJoinMode, int nMixerVolume, BOOL bCreateAlways, BOOL bExitGrpAlways);
int  SsmExitConfGroup(int ch, BOOL bFreeGrpAlways);
int  SsmGetConfCfgInfo(PWORD pwMaxMember, PWORD pwMaxSpeaker, PWORD pwMaxSpeaking, PWORD pwMaxSilenceTime);
int  SsmGetTotalConfGroup();
int  SsmGetConfGrpId(int* pnGrpId);
int  SsmGetConfGrpCfgInfo(int nGrpId, PWORD pwMaxMember, PWORD pwMaxSpeaker, PWORD pwMaxSpeaking, PWORD pwMaxSilenceTime);
int  SsmGetConfGrpInfo(int nGrpId, PWORD pwTotalMember, PWORD pwTotalSpeaker, PWORD pwTotalSpeaking);
int  SsmGetConfGrpMmbrId(int nGrpId, int* pnMmbrId);
int  SsmGetConfGrpMmbrInfo(int nGrpId, int nMmbrId, int* pnAppCh, PWORD pwJoinMode, PWORD pwIsSpeaking, PDWORD pdwSilenceTime);
int  SsmGetConfChInfo(int ch, int * pnGrpId, int * pnMmbrId, PWORD pwJoinMode, PWORD pwIsSpeaking, PDWORD pdwSilenceTime);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@ DRIVER  Ver. 1.x COMPATIBLE FUNCTIONS  @@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DWORD  InitCard(DWORD add1,DWORD add2,DWORD add3,DWORD add4,DWORD add5,
		DWORD add6,DWORD add7,DWORD add8,DWORD intno);
void  ShutCard(void);

DWORD  StartRecordFile(DWORD ch,char * fliename);
void  StopRecordFile(DWORD ch);
void  PauseRecord(DWORD ch);
void  RestartRecord(DWORD ch);
DWORD  GetRecordTime(DWORD ch);

DWORD  StartPlayFile(DWORD ch,char * filename);
void  StopPlayFile(DWORD ch);
DWORD  CheckPlayingEnd(DWORD ch);
void  PausePlay(DWORD ch);
void  RestartPlay(DWORD ch);
void  FastPlay(DWORD ch);
void  BackPlay(DWORD ch);
DWORD  GetPlayTime(DWORD ch);
DWORD  GetPlayPercent(DWORD ch);
void  SetPlayTime(DWORD ch,DWORD time);
void  SetPlayPercent(DWORD ch,DWORD percent);

DWORD  LoadIndexFile(DWORD segno,LPSTR filename,DWORD startadr,DWORD length);
void  FreeIndexMem(DWORD segno);
void  PlayIndex(DWORD ch,LPSTR segstring);
void  StopIndex(DWORD ch);
void  DTMFStop(DWORD ch,DWORD if_stop);

DWORD  GetDTMF(DWORD ch);
DWORD  GetDTMFStr(DWORD ch,char * buf);
void  ClearDTMFBuf(DWORD ch);
DWORD  DetectRing(DWORD ch);
void  ClearRing(DWORD ch);
void  HangUp(DWORD ch);
void  PickUp(DWORD ch);
DWORD  DetectInter(DWORD ch);
DWORD  GetFlash(DWORD ch);
void  SetFlashTime(int time);
DWORD  ToneCheck(DWORD ch);
DWORD  GetBusyLen(DWORD ch);
void  DTMFDial(DWORD ch,LPSTR dialstring);
DWORD  DTMFDialEnd(DWORD ch);
void  Flash(DWORD ch,DWORD time);
void  SetPlayVolume(DWORD ch,LONG volume);
void  SetRecVolume(DWORD ch,LONG volume);

DWORD  GetCallerId(DWORD ch,LPSTR buf);

void  SetPickSens(DWORD piont);
DWORD  GetPickUp(DWORD ch);
DWORD  GetNum(DWORD ch,LPSTR buf,DWORD time,DWORD len,int end_char);
void  SetWorkMode(int Mode);
void  SetUserCard(DWORD addr1,DWORD addr2,DWORD addr3,DWORD addr4,DWORD addr5,DWORD addr6,DWORD addr7,DWORD addr8);
void  SendBusyTone(int ch);
void  SendRingEchoTone(int ch);
void  SendDialTone(int ch);
void  StopSendTone(int ch);
void  StartSendRing(int ch);
void  StopSendRing(int ch);
int  Link2Ch(int ch1,int ch2);
void  UnLink2Ch(int ch1,int ch2);
int  Link3Ch(int ch1,int ch2,int ch3);
void  UnLink3Ch(int ch1,int ch2,int ch3);
int  ListenFromCh(int ch1,int ch2);
void  StopListenFromCh(int ch1,int ch2);
void  SetDelay(DWORD ch,DWORD delay);
void  SetLevel(DWORD ch,DWORD level);
DWORD  DetectSound(DWORD ch);
DWORD  GetFax11(DWORD ch);
DWORD  GetFax21(DWORD ch);
DWORD   GetRing(DWORD ch);
void  SetDialSpeed (DWORD point );
void  GetErrorMsg(char *buf);
DWORD  SetMaxSeg(DWORD inmaxsegment);
void  PauseCard(void);
void  RestartCard(void);
//BOOL  SetIRQPriority(int nPriorityClass); masked by wy for python transplant

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@ RECORD MODULE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DWORD  GetLevel(DWORD ch);
void  SetJudge(DWORD ch, DWORD Judge);
int  SsmQueryOpADC(int ch);
int  SsmGetLineVoltage(int ch);
int  SsmSetDtrmLineVoltage(int ch, WORD wDtrmValtage);
int  SsmGetDtrmLineVoltage(int ch);
DWORD  DetectPickUp(DWORD ch);
DWORD  DetectEmpty(DWORD ch);
void  SetSoundJudgeLevel(DWORD ch, DWORD level);
DWORD  GetSoundJudgeLevel(DWORD ch);

int  SsmQueryOpMicGain(int ch);
int  SsmSetMicGain(int ch, int nGain);
int  SsmGetMicGain(int ch);

int  SsmSetIgnoreLineVoltage(int ch, BOOL bEnable);
int  SsmGetIgnoreLineVoltage(int ch);		

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@ POWER-AMPLIFIER OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void  SetVolume(DWORD dwBoardId, DWORD dwVolume);
int  SsmQueryOpPowerAmp(int ch);
int  SsmSetPowerAmpVlm(int ch, int nVolume);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ POLAR REVERSE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DWORD  GetFZCount(DWORD ch);
int  SsmQueryOpPolarRvrs(int ch);
int  SsmGetPolarRvrsCount(int ch);
int  SsmGetPolarState(int ch);
int  SsmSetPolarState(int ch, int nPolar);
int  SsmSetUnimoduleState(int ch, int nLink);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ SS1 OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmQueryOpSS1(int ch);
int  SsmSendCAS(int ch, BYTE btCas);
int  SsmGetCAS(int ch);
int  SsmSetRxR2Mode(int ch, int nMode, BOOL bEnable);
int  SsmGetR2(int ch);
int  SsmSendR2(int ch, int nMode, BYTE btR2);
int  SsmStopSendR2(int ch);

int  SsmGetSendingCAS(int ch);
int  SsmGetSendingR2(int ch, int* pnMode, BYTE* pbtR2);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ PCM LINK OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmGetMaxPcm();
int  SsmGetPcmInfo(int nPcmNo, int* pnSSxMode, int* pnBoardId, int* pnBoardPcmNo, int* pnUsePcmTS16,
		PDWORD pdwRcvrMode, PDWORD pdwEnableAutoCall, PDWORD pdwAutoCallDirection);
int  SsmGetPcmLinkStatus(int nPcmNo, PWORD pwPcmLinkStatus);
int  SsmPcmTsToCh(int nLocalPcmNo, int nTs);
int  SsmChToPcmTs(int ch, int* pnLocalPcmNo, int* pnTs);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ SEND FSK OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmSetFskPara(int nFreqBit0, int nFreqBit1, int nBaudrate, int nMdlAmp);
int  SsmGetFskPara(int* pnFreqBit0, int* pnFreqBit1, int* pnBaudrate, int* pnMdlAmp);
int  SsmTransFskData(unsigned char* pS, int	nSrcLen,int nSyncLen,int nSyncOffLen,unsigned char* pD);
int  SsmStartSendFSK(int ch, LPSTR pBuf, DWORD dwMaxBit);
int  SsmCheckSendFsk(int ch);
int  SsmStopSendFsk(int ch);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@ RECEIVE FSK OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmStartRcvFSK_II(int ch, WORD wTimeOut, WORD wMaxLen, PUCHAR pucMarkCodeBuf, UCHAR ucMarkCodeCount);
int  SsmStartRcvFSK(int ch, WORD wTimeOut, WORD wMaxLen, UCHAR ucEndCode, WORD wEndCodeCount);
int  SsmClearRcvFSKBuf(int ch);
int  SsmCheckRcvFSK(int ch);
int  SsmGetRcvFSK(int ch, PUCHAR pucBuf);
int  SsmStopRcvFSK(int ch);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@ SS7 OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmSendSs7Msu(WORD wMsuLength, PUCHAR pucMsuBuf);
int  SsmGetSs7Msu(PUCHAR* ppucMsuBuf);
int  SsmGetSs7Mtp2Msu(PUCHAR pucPara, PUCHAR* ppucMsuBuf);
int  SsmGetMtp3State();
int  SsmGetMtp3StateEx(int nDpcNo);
int  SsmGetMtp2Status(int nLinkNum);
//added by mengjin for 动态设置主叫用户类别，2004.11.22
int  SsmSetISUPCAT(int nch,  UCHAR ucCallerCAT);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ FAX OPERATION API @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmFaxGetChStateMsg(int ch ,char *buf);
int  SsmFaxGetPages(int ch);
int  SsmFaxStartReceive(int ch,char *filename);
int  SsmFaxStartSend(int ch,char *filename);
int  SsmFaxStop(int ch);
void  SsmFaxSetMaxSpeed(int speed);
int  SsmFaxCheckEnd(int ch);
int  SsmFaxSetID(int ch,char *myid);
int  SsmFaxGetID(int ch,char *myid);
int  SsmFaxSetSendMode(int ch, int mode );
int  SsmFaxGetRcvBytes(int ch);
int  SsmFaxGetSendBytes(int ch);
int  SsmFaxAppendSend(int ch,char *filename);
//int  SsmFaxSetHangup(int ch, BOOL flag);  //masked by wy for python transplant
int  SsmFaxStartSendEx(int ch, char * filename, int nStartPage, int nEndPage);
int  SsmFaxSendMultiFile(int ch, char * szFilePath, char * szFileName);
int  SsmFaxSendMultiFileEx(int ch, FAX_FILE_SCT * pV, int nNum);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@ MODEM OPERATION API  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmEnableCh(int ch );
int  SsmDisableCh(int ch );
int  SsmResetCh(int ch );
int  SsmCheckResetCh(int ch );
int  SsmGetLSR(int ch,unsigned char *retu);
int  SsmGetMSR(int ch ,unsigned char *retu);
int  SsmGetRTS(int ch );
int  SsmGetCTS(int ch );
int  SsmGetOH(int ch );
int  SsmDetectCarry(int ch );

int  SsmFaxGetChState(int ch ,unsigned short *buf);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@ SERIAL PORT IO OPERATION API @@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmReadRxBuf(int ch , int nLen, char *lpcRxBuf);
int  SsmGetRxBufLen(int ch );
void  SsmClearRxBuf(int ch );
int  SsmWriteTxBuf(int ch, int nLen, char * lpcTxBuf);
int  SsmWriteTxBuf_S(int ch, char *s);
int  SsmWriteTxBuf_C(int ch , char buf);
int  SsmGetTxBufRemain(int ch);
int  SsmGetTxBufLen(int ch );
void  SsmClearTxBuf(int ch );

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@ ISDN API @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmISDNSetDialSubAddr(int ch, LPSTR lpSubAddress);
int  SsmISDNSetTxSubAddr(int ch, LPSTR lpSubAddress);
int  SsmISDNGetTxCallerSubAddr(int ch, LPSTR lpSubAddress);
int  SsmISDNGetSubAddr(int ch, LPSTR lpSubAddress);
int  SsmISDNGetCallerSubAddr(int ch, LPSTR lpSubAddress);
int  SsmISDNGetDisplayMsg(int ch, LPSTR lpDispMsg);
int  SsmISDNSetHangupRzn(int ch, int nReason);
int  SsmISDNGetStatus(int nPcmNo, int *pL3Start, 
		int *pL2DStatus, int *pL2D_L3Atom, 
		int * pL3_L2DAtom, int *pRef_ind);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@ ViaVoice recognize OPERATION API @@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmStartRecognize(int ch,int grammarid,int max_time);
int  SsmGetResultCount(int ch);
int  SsmGetCurSens(int ch);
int  SsmGetResult(LPSTR buf,LPSTR index,LPSTR score,int ch);
int  SsmGetNResult(int id,LPSTR buf, LPSTR index, LPSTR score, int ch);
void 	SsmSetSil(int nValue);
void 	SsmSetRecoSound(int nBeginLen,int nEndLen,int nSoundLen);
void 	SsmSetRecoTime(int nRecoTime,int nMaxWait);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@ Set Hardware Flags OPERATION API @@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  SsmSetFlag(int ch, int nType, long lValue);
int  SsmGetFlag(int ch, int nType, long* plValue);

int  SsmSetOvrlEnrgLevel(int ch,WORD wOvrlEnrgLevel);
WORD  SsmGetOvrlEnrgLevel(int ch);
int  SsmSetOvrlEnrgDtrmTime(int ch,WORD wMinTime,WORD wMaxTime);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ SPY  API @@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int   SpyGetState(int nCic);
int   SpyGetCallerId(int nCic,char *pcCid);
int   SpyGetCalleeId(int nCic,char *pcCid);
int   SpyGetCallInCh(int nCic);
int   SpyGetCallOutCh(int nCic);
int   SpyGetMaxCic();
int   SpyStopRecToFile(int  nCic);
int   SpyRecToFile(int nCic, WORD wDirection,
		LPSTR pszFileName, int nCodecFormat,
		DWORD dwStartPos, DWORD dwBytes, 
		DWORD dwTime,  int nMask);
int   SpyGetLinkStatus(int nSpyPcmNo,UCHAR ucFlag);

int  SsmSetTxOriginalCallerID(int ch, BYTE* pszTxCallerId);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ EVENT  API @@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int	 SsmSetEvent (WORD wEvent, int nReference,BOOL bEnable, PEVENT_SET_INFO pEventSet);
int	 SsmWaitForEvent(DWORD dwTimeOut, PMESSAGE_INFO pEvent);
int	 SsmGetEvent(PMESSAGE_INFO pEvent);
int	 SsmStartTimer(WORD wDelay, WORD fuEvent);
int	 SsmStopTimer(int nTimer);
