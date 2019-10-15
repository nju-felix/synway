
#ifndef WIN32
	#ifndef OS_LINUX
		#ifndef TYPEDEF_H
			#define TYPEDEF_H

			typedef char         	CHAR;
			typedef float           FLOAT;
			typedef int				BOOL;
			typedef int             INT;
			typedef long			LONG;
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
			typedef long			*LPLONG;
			typedef long			*PLONG;
			typedef void            *LPVOID;

			typedef const CHAR      *LPCSTR;
			typedef const CHAR      *LPCTSTR;
			typedef const void      *LPCVOID;

		#endif // end of #ifndef TYPEDEF_H
	#endif // end of #ifndef OS_LINUX

	#ifndef WINAPI
		#define WINAPI
	#endif

#endif // end of #ifndef WIN32

#ifndef SHCTI_CONST
	#define SHCTI_CONST

//-----------------------------------------------------------------------
// definition of channel type, which can be retrieved by invoking
// function "SsmGetFlag()" and set by invoking "SsmSetFlag()"
//-----------------------------------------------------------------------
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

//-----------------------------------------------------------------------
// definition of channel type, which can be retrieved by invoking
// function "SsmGetChType()"
//-----------------------------------------------------------------------
/*
enum{
	ANALOG_CH=0,
	INTER_CH=1,
	USER_CH=2,
	REC_CH=3,
	SS1_CH=4,
	FAX_CH=5,
	TUP_CH=6,
	ISDN_USER_CH=7,		
	ISDN_NET_CH = 8,
	SOFTFAX_CH = 9,
	MAGNET_CH = 10
};
*/

//-----------------------------------------------------------------------
// definition of blocking reason, which can be retrieved by invoking
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
// Definition of status on blocking remote circuit or circuit groups,
// which might be used by following functions
//		1. "SsmChkBlockRemoteXXX()"
//		2. "SsmChkBlockRemoteXXX()"
//-----------------------------------------------------------------------
#define BLOCKREMOTE_Unblocked			0	// no block-signal is issued
#define BLOCKREMOTE_Blocked				1	// is in blocked state now
#define BLOCKREMOTE_WaitBlockAck		2	// waiting for acknowledgement signal after sending block-signal
#define BLOCKREMOTE_WaitUnblockAck		3	// waiting for acknowledgement signal after sending unblock-signal

//-----------------------------------------------------------------------
// Definition of local blocking status on circuit or circuit groups,
// which might be used by following functions
//		 "SsmQueryLocalXXXBlockState()"
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

	//+++start+++	fax error code
	C_ERROR_FAX_NOFILE		  =16,
	//+++end+++		fax error code
	
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
	S_TUP_WaitSetCallerID = 77,         //  "等待设置主叫"状态          （No.7信令TUP协议）

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
	S_ISUP_WaitSetCallerID         = 127,// ISUP:等待设置主叫

};

// 事件码占用16bytes，采用顺序编码（从0开始编码）。
// 若采用windows消息机制，windows消息编码：事件码+0x7000(WM_USER)
enum{
	//语音识别
	E_PROC_Recognize,	//0x0000	//语音识别结束事件

	//ISDN呼叫
	E_CHG_ISDNStatus,	//0x0001	//ISDN底层状态改变事件

	//ss7
	E_RCV_Ss7Msu,		//0x0002	//SS7 MSU接收通知事件
	E_CHG_Mtp3State,	//0x0003	//Mtp3状态改变事件

	//传真
	E_CHG_FaxChState,	//0x0004	//传真通道传真状态改变事件
	E_CHG_FaxPages,		//0x0005	//传真接收/发送页结束事件
	E_PROC_FaxEnd,		//0x0006	//传真结束事件

	//PCM线路同步状态
	E_CHG_PcmLinkStatus,//0x0007	//PCM线路同步状态改变事件


	//录音通道
	E_CHG_LineVoltage,	//0x0008	//录音通道线路电压变化事件


	//ss1
	E_RCV_CAS,		//0x0009	//接收到的CAS值有变化
	E_RCV_R2,		//0x000A	//收到新的R2 值


	//DTMF接收
	E_PROC_WaitDTMF,	//0x000B	//WaitDTMF任务结束事件
	E_CHG_RcvDTMF,		//0x000C

	//DTMF发送
	E_PROC_SendDTMF,	//0x000D	//发送DTMF任务结束事件


	//发送闪断
	E_PROC_SendFlash,	//0x000E	//发送闪断任务结束事件


	//放音
	E_PROC_PlayEnd,		//0x000F	//放音任务结束
	E_PROC_PlayFile,	//0x0010	//文件放音进程指示
	E_PROC_PlayFileList,//0x0011	//文件列表放音进程指示


	E_PROC_PlayMem,		//0x0012	//内存放音进程指示

	//录音
	E_PROC_RecordEnd,	//0x0013	//录音任务结束
	E_PROC_RecordFile,	//0x0014	//文件录音任务进展指示
	E_PROC_RecordMem,	//0x0015	//内存录音任务进展指示


	//FSK发送
	E_PROC_SendFSK,		//0x0016	//发送FSK任务结束事件

	//FSK接收
	E_PROC_RcvFSK,		//0x0017	//RcvFSK任务结束


	//呼叫控制
	E_CHG_ChState,		//0x0018	//通道状态发生变化
	E_PROC_AutoDial,	//0x0019	//AutoDial任务有进展
	E_CHG_RemoteChBlock,//0x001A
	E_CHG_RemotePCMBlock,//0x001B
	E_SYS_ActualPickup,	//0x001C	//外线通道实际摘机
	E_CHG_RingFlag,		//0x001D	//铃流电平变化
	E_CHG_RingCount,	//0x001E	//振铃计数变化
	E_CHG_CIDExBuf,		//0x001F	//CID扩展接收缓冲区变化
	E_CHG_RxPhoNumBuf,	//0x0020	//被叫号码接收缓冲区变化
	E_CHG_PolarRvrsCount,//0x0021	//外线通道极性反转
	E_SYS_RemotePickup,	//0x0022	//模拟电话线相对能量算法检测被叫摘机

	//座席
	E_CHG_FlashCount,	//0x0023	//flash计数发生变化
	E_CHG_HookState,	//0x0024	//Hook状态发生变化

	//信号音检测
	E_CHG_ToneAnalyze,	//0x0025	//信号音分析结果变化事件
	E_OverallEnergy,	//0x0026
	E_CHG_OvrlEnrgLevel,//0x0027	//全频能量标识输出事件
	E_CHG_BusyTone,		//0x0028	//忙音计数变化事件
	E_CHG_BusyToneEx,	//0x0029	//松散忙音变化
	E_CHG_VocFxFlag,	//0x002A	//单音频信号音电平变化
	E_CHG_ToneValue,	//0x002B	//信号音电平变化
	E_CHG_RingEchoToneTime,	//0x002C
	E_CHG_PeakFrq,		//0x002D	//PeakFrq有变化
	E_SYS_BargeIn,		//0x003E	//检测到BargeIn
	E_SYS_NoSound,		//0x002F	//检测到NoSound

	//定时器
	E_SYS_TIMEOUT,		//0x0030	//定时器事件

	//信令监控
	E_CHG_SpyState,		//0x0031	//被监控电路的接续状态通知事件
	E_CHG_SpyLinkStatus,//0x0032	//被监控的PCM链路状态通知事件
};

typedef struct  _MESSAGE_INFO
{
	WORD	wEventCode;
	int		nReference;
	DWORD	dwParam; //输出参数
}MESSAGE_INFO, *PMESSAGE_INFO;

typedef struct _EVENT_SET_INFO
{
	DWORD dwWorkMode;
	LPVOID lpHandlerParam;
	DWORD dwOutCondition;
	DWORD dwOutParamVal;
	DWORD dwUser;
}EVENT_SET_INFO,*PEVENT_SET_INFO;

typedef struct tagFAX_FILE_SCT
{
	char	szFileName[256];
	int	nStartPage;
	int	nEndPage;
	int	nReserve1;
	int	nReserve2;
}FAX_FILE_SCT, *PFAX_FILE_SCT;

enum
{
TIMER_ONE,
TIMER_PERIODIC 
};

enum
{
	NO_EVENT, // 无事件方式
	EVENT_POLLING, //事件轮询
	EVENT_CALLBACK, //事件回调
	EVENT_MESSAGE //windows消息
};

//文件放音进程指示输出参数类型.
enum
{
	PLAYPERCENT,
	PLAYTIME,
	DATABYTESPLAYED,
	DATABYTESTOPLAY
};

//内存录放音进程指示输出参数类型.
enum
{
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

#endif	// end of #ifndef SHCTI_CONST

#ifndef SHCTI_CALLBACK
	#define SHCTI_CALLBACK

	typedef	void (WINAPI *RXDTMFHANDLER) (int ch, char cDtmf, int nDTStatus, PVOID pV);
	typedef	BOOL (WINAPI *RECORDMEMBLOCKHANDLER) (int ch, int nEndReason, PUCHAR pucBuf, DWORD dwStopOffset, PVOID pV);
	typedef	BOOL (WINAPI *PLAYMEMBLOCKHANDLER) (int ch, int nEndReason, PUCHAR pucBuf, DWORD dwStopOffset, PVOID pV);
	typedef	void (CALLBACK  *LPRECTOMEM) (int ch, LPBYTE lpData, DWORD dwDataLen); //appended by xxb,2002.12.02
	typedef	int  (CALLBACK  *LPFNEVENTCALLBACK) (WORD wEvent, int nReference, DWORD dwParam, DWORD	dwUser);
#endif

#ifdef __cplusplus
	extern "C" {
#endif


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ INITIALIZATION OPERATION  @@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmStartCti(LPSTR lpSsmCfgFileName, LPSTR lpIndexCfgFileName);
int WINAPI SsmCloseCti();
void WINAPI SsmGetLastErrMsg(LPSTR szErrMsgBuf);
char *WINAPI SsmGetLastErrMsgA(void);
int WINAPI SsmGetLastErrCode();
int WINAPI SsmGetMaxUsableBoard();
int WINAPI SsmGetMaxCfgBoard();
int WINAPI SsmGetRxDtmfBufSize();
int WINAPI SsmGetAccreditId(int nBId);
int WINAPI SsmGetMaxCh(void);
int WINAPI SsmGetChType(int ch);
int WINAPI SsmSetMaxIdxSeg(WORD wMaxIdxSeg);
int WINAPI SsmLoadIndexData(int	nSegNo, LPSTR pAlias, int nCodec, LPSTR	pVocFile, long lStartPos, long lLen);
int WINAPI SsmFreeIndexData(int nSegNo);
int WINAPI SsmGetTotalIndexSeg();
int WINAPI SsmPauseCard();
int WINAPI SsmRestartCard();

int WINAPI SsmGetAccreditIdEx(int nBId);	
int WINAPI SsmGetBoardModel(int nBId);		
void WINAPI SsmSetDV(BOOL bEnable);			
BOOL WINAPI SsmGetDV(void);

DWORD WINAPI SsmGetPciSerialNo(int nBId);

DWORD WINAPI SsmGetIntCount();
int WINAPI SsmSetListenMode(int nMode);

int WINAPI SsmStartBoard(int nBId);	//add by wangjiang for cPCI 2003.4.23
int WINAPI SsmStopBoard(int nBId);	//add by wangjiang for cPCI 2003.4.23
int WINAPI SsmGetChHdInfo(int ch, int * pnBId, int * pnBCh);
int WINAPI SsmGetAppChId(int * AppchId, int BrdId, int BrdChId);	//add by JK Shi 2003.9.25

int WINAPI SsmSetChState(int ch, int nState);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ PLAY OPERATION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmSetPlayVolume(int ch, int nVolume);
int WINAPI SsmSetDtmfStopPlay(int ch, BOOL bDspf);
int WINAPI SsmGetDtmfStopPlayFlag(int ch);
int WINAPI SsmSetBargeinStopPlay(int ch, BOOL bBispf);
int WINAPI SsmGetBargeinStopPlayFlag(int ch);
int	WINAPI SsmStopPlay(int ch);
int WINAPI SsmPlayFile(int ch, LPSTR pszFileName, int nFormat, DWORD dwStartPos, DWORD dwLen);
int WINAPI SsmStopPlayFile(int ch);
int WINAPI SsmPausePlay(int ch);
int WINAPI SsmRestartPlay(int ch);
int WINAPI SsmFastFwdPlay(int ch);
int WINAPI SsmFastBwdPlay(int ch);
int WINAPI SsmSetPlayTime(int ch, DWORD dwTime);
long WINAPI SsmGetPlayedTimeEx(int ch);												// added by cqb for SHCTI030902
int  WINAPI SsmGetPlayingFileInfo(int ch , int *pnFormat , long *pnTotalTime);		// added by cqb for SHCTI030902
int WINAPI SsmSetPlayPrct(int ch, DWORD dwPercentage);
long WINAPI SsmGetPlayedTime(int ch);
int WINAPI SsmGetPlayedPercentage(int ch);
long WINAPI SsmGetDataBytesToPlay(int ch);
int WINAPI SsmCheckPlay(int ch);
int WINAPI SsmGetPlayType(int ch);
int WINAPI SsmPlayIndexString(int ch, LPSTR pszIdxStr);
int WINAPI SsmPlayIndexList(int ch, WORD wIdxListLen, PWORD pwIdxList);
int WINAPI SsmStopPlayIndex(int ch);
int WINAPI SsmClearFileList(int ch);
int WINAPI SsmAddToFileList(int ch, LPSTR pszFileName, int nFormat, DWORD dwStartPos, DWORD dwLen);
int WINAPI SsmPlayFileList(int ch);
int WINAPI SsmStopPlayFileList(int ch);
int WINAPI SsmPlayMem(int ch, int nFormat, LPBYTE pBuf, DWORD dwBufSize, DWORD dwStartOffset, DWORD dwStopOffset);
int WINAPI SsmGetPlayOffset(int ch, DWORD* pdwPlayOffset);
int WINAPI SsmSetStopPlayOffset(int ch, DWORD dwStopPlayOffset);
int WINAPI SsmStopPlayMem(int ch);
int WINAPI SsmClearPlayMemList(void);
int WINAPI SsmAddToPlayMemList(LPBYTE pBuf, DWORD dwDataLen, int nFormat);
int WINAPI SsmPlayMemList(int ch, PWORD pMemList, WORD wMemListLen);
int WINAPI SsmStopPlayMemList(int ch);

//appended by xxb for 恒生,01.09,2002 +++++
 int WINAPI SsmSetDTMFStopPlayCharSet(int ch, LPSTR lpstrDtmfCharSet);
 int WINAPI SsmGetDTMFStopPlayCharSet(int ch, LPSTR lpstrDtmfCharSet);
 int WINAPI SsmSetHangupStopPlayFlag(int ch, BOOL bHangupStopRecFlag );
 int WINAPI SsmPlayMemBlock(int ch,
				   int nFormat,
				   LPBYTE pBuf,
				   DWORD dwBufSize,
				   PLAYMEMBLOCKHANDLER OnPlayMemBlockDone,
				   PVOID pV);

 int WINAPI SsmStopPlayMemBlock(int ch);
//appended by xxb for 恒生,01.09,2002 -----
long WINAPI SsmGetDataBytesPlayed(int ch);	//add by wangjiang 2002.12.25


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@    RECORD OPERATION   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmSetRecVolume(int ch, int nVolume);
int WINAPI SsmGetRecType(int ch);
int WINAPI SsmRecToFile(int ch, LPSTR pszFileName, int nFormat, DWORD dwStartPos, DWORD dwBytes, DWORD dwTime, int nMask);
int WINAPI SsmRecToFileA(int ch, LPSTR pszFileName, int nFormat,
						DWORD dwStartPos, DWORD dwBytes, DWORD dwTime, int nMask,
						LPRECTOMEM	pfnRecToMem);

int WINAPI SsmRecToFileEx(int ch, LPSTR pszFileName, int nFormat,
						DWORD dwStartPos, DWORD dwBytes, DWORD dwTime, int nMask,
						BOOL bSaveToFileOnBargin, DWORD dwRollbackTime);

int WINAPI SsmPauseRecToFile(int ch);
int WINAPI SsmRestartRecToFile(int ch);
long WINAPI SsmGetRecTime(int ch);
long WINAPI SsmGetDataBytesToRecord(int ch);
int WINAPI SsmStopRecToFile(int ch);
int WINAPI SsmChkRecToFile(int ch);
int WINAPI SsmRecToMem(int ch, int nFormat, LPBYTE pBuf, DWORD dwBufSize, DWORD dwStartOffset);
int WINAPI SsmStopRecToMem(int ch);
long WINAPI SsmGetRecOffset(int ch);

int WINAPI SsmGetRecAGCSwitch(int ch);
int WINAPI SsmSetRecAGC(int ch, BOOL bEnable);

int WINAPI SsmQueryOpRecMixer(int ch);
int WINAPI SsmSetRecMixer(int ch, BOOL bEnRecMixer, int nMixerVolume);
int WINAPI SsmGetRecMixerState(int ch, int* pnEnRecMixer, int* pnMixerVolume);

int WINAPI SsmSetPrerecord(int ch, BOOL bEnable, int nMode, WORD wInsertTime, int nFormat);
int WINAPI SsmSetTruncateTail(int ch, DWORD	dwTime);
long WINAPI SsmGetTruncateTailTime(int ch);
int WINAPI SsmGetPrerecordState(int ch, int* pnMode, PWORD pwInsertTime, int* pnFormat);
//appended by xxb for 恒生,01.09,2002 +++++
int WINAPI SsmSetDTMFStopRecCharSet(int ch, LPSTR lpstrDtmfCharSet);
int WINAPI SsmGetDTMFStopRecCharSet(int ch, LPSTR lpstrDtmfCharSet);
int WINAPI SsmSetHangupStopRecFlag(int ch, BOOL bHangupStopRecFlag );
int WINAPI SsmCheckRecord(int ch);
int WINAPI SsmRecordMemBlock(int ch, int nFormat, LPBYTE pBuf,
					 DWORD dwBufSize, RECORDMEMBLOCKHANDLER OnRecMemBlockDone, PVOID pV);
int WINAPI SsmStopRecordMemBlock(int ch);
//appended by xxb for 恒生,01.09,2002 -----

int WINAPI SsmSetNoModuleChBusRec(int ch, int bBusRec);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@   RxDTMF OPERATION   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmEnableRxDtmf(int ch, BOOL bRun);
int WINAPI SsmClearRxDtmfBuf(int ch);
int WINAPI SsmGetDtmfStr(int ch, LPSTR pszDtmf);
char* WINAPI SsmGetDtmfStrA(int ch);
int WINAPI SsmGetRxDtmfLen(int ch);
int WINAPI SsmGet1stDtmf(int ch, char* pcDtmf);
int WINAPI SsmGet1stDtmfClr(int ch, char* pcDtmf);
int WINAPI SsmGetLastDtmf(int ch, char* pcDtmf);
int WINAPI SsmSetWaitDtmf(int ch, WORD wTimeOut, WORD wMaxLen, char cEndChar, BOOL bWithEndChar);
int WINAPI SsmChkWaitDtmf(int ch, LPSTR	pszDtmf);

int WINAPI SsmCancelWaitDtmf(int ch);	
int WINAPI SsmSetWaitDtmfEx(int ch, WORD wTimeOut, WORD wMaxLen, char cEndChar, BOOL bWithEndChar);

//appended by xxb for 恒生,01.09,2002 +++++
// 设置接收DTMF字符回调函数：
int WINAPI SsmSetRxDtmfHandler(int ch, RXDTMFHANDLER OnRcvDtmf, PVOID pV);
//appended by xxb for 恒生,01.09,2002 -----
int WINAPI SsmSetWaitDtmfExA(int ch, WORD wTimeOut, WORD wMaxLen, char* szEndChar, BOOL bWithEndChar);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@ TXDTMF OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmQueryTxDtmf(int ch, LPSTR pszDtmf);
int WINAPI SsmQueryTxFlash(int ch, LPSTR pszDtmf);
int WINAPI SsmSetTxDtmfPara(int ch, WORD wOnTime, WORD wOffTime);
int WINAPI SsmGetTxDtmfPara(int ch, PWORD pwOnTime, PWORD pwOffTime);
int WINAPI SsmTxDtmf(int ch, LPSTR pszDtmf);
int WINAPI SsmStopTxDtmf(int ch);
int WINAPI SsmChkTxDtmf(int ch);
int WINAPI SsmTxFlash(int ch, WORD time);
int WINAPI SsmChkTxFlash(int ch);
int WINAPI SsmSetTxFlashCharTime(int ch, WORD time);	//appended by LM for 上海刘锦宏,2001.11.02
int WINAPI SsmGetTxFlashCharTime(int ch);				//appended by LM for 上海刘锦宏,2001.11.02


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ INTER-CH OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmSetLocalFlashTime(int nFlashTime);
int WINAPI SsmSetASDT(int ch, BOOL bEnAutoSendDialTone);
int WINAPI SsmGetASDT(int ch);
int WINAPI SsmSetASTOD(int ch, BOOL bEnAutoSendDialTone);
int WINAPI SsmGetASTOD(int ch);
int WINAPI SsmGetFlashCount(int ch);
int WINAPI SsmClearFlashCount(int ch);
int WINAPI SsmGetHookState(int ch);
int WINAPI SsmStartRing(int ch);
int WINAPI SsmStopRing(int ch);
int WINAPI SsmStartRingWithFskCID(int ch, LPSTR pBuf, DWORD dwMaxBit, DWORD dw1stRingOffDelay);
int WINAPI SsmStartRingWithCIDStr(int ch, LPSTR pBuf, DWORD dwLen, DWORD dw1stRingOffDelay);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ SEND TONE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmQueryOpSendTone(int ch);
int WINAPI SsmSendTone(int ch, int nToneType);
int WINAPI SsmSendToneEx(int ch, DWORD dwOnTime, DWORD dwOffTime);
int WINAPI SsmStopSendTone(int ch);
int WINAPI SsmSetTxTonePara(int ch, int nFreq1, int nVolume1, int nFreq2, int nVolume2);
int WINAPI SsmGetTxTonePara(int ch, int* pnFreq1, int* pnVolume1, int* pnFreq2, int* pnVolume2);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@ TONE ANALYZE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmQueryOpToneAnalyze(int ch);
int WINAPI SsmClearToneAnalyzeResult(int ch);
int WINAPI SsmStartToneAnalyze(int ch);
int WINAPI SsmCloseToneAnalyze(int ch);
long WINAPI SsmGetOverallEnergy(int ch);
int WINAPI SsmGetVocFxFlag(int ch, int nSelFx, BOOL bClear);
int WINAPI SsmGetToneAnalyzeResult(int ch);
int WINAPI SsmGetBusyToneLen(int ch);
int WINAPI SsmGetBusyToneCount(int ch);
int WINAPI SsmGetRingEchoToneTime(int ch);

//++++START++++ appended by CXG for 放宽背靠背忙音检测条件,2001.11.22
int WINAPI SsmGetBusyToneEx(int ch);
//++++END++++ appended by LM for 放宽背靠背忙音检测条件,2001.11.22

int WINAPI SsmSetTonePara(int ch, WORD wToneFreq1,WORD wToneBW1,WORD wToneFreq2,WORD wToneBW2,DWORD dwIsToneRatio);
int WINAPI SsmSetIsDialToneDtrTime(int ch, WORD wIsDialToneDtrTime);
int WINAPI SsmSetBusyTonePeriod(int ch, WORD wBusyTonePeriod);
int WINAPI SsmSetIsBusyToneDtrCnt(int ch, WORD wIsBusyToneDtrCnt);
int WINAPI SsmSetRingEchoTonePara(int ch, WORD wRingEchoOnTime,WORD wRingEchoOffTime);
int WINAPI SsmSetVoiceFxPara(int ch, WORD wSelFx, WORD wFx,WORD wFxBW, DWORD dwIsVocFxRatio, WORD wIsVocFxDtrTime);
int WINAPI SsmSetVoiceOnDetermineTime(int ch, WORD wIsVocDtrTime);
int WINAPI SsmSetMinVocDtrEnergy(int ch, DWORD dwMinVocDtrEnergy);
int WINAPI SsmGetTonePara(int ch, PWORD pwToneFreq1, PWORD pwToneBW1,PWORD pwToneFreq2,PWORD pwToneBW2,PDWORD pdwIsToneRatio);
int WINAPI SsmGetIsDialToneDtrTime(int ch, PWORD pwIsDialToneDtrTime);
int WINAPI SsmGetBusyTonePeriod(int ch, PWORD pwBusyTonePeriod);
int WINAPI SsmGetIsBusyToneDtrCnt(int ch, PWORD pwIsBusyToneDtrCnt);
int WINAPI SsmGetRingEchoTonePara(int ch, PWORD pwRingEchoOnTime, PWORD pwRingEchoOffTime);
int WINAPI SsmGetIsNoVocDtrmTime(int ch, PWORD pwIsNoVocDtrmTime);
int WINAPI SsmGetVoiceFxPara(int ch, WORD wSelFx, PWORD pwFx,PWORD pwFxBW, PDWORD pdwIsVocFxRatio, PWORD pwIsVocFxDtrTime);
int WINAPI SsmGetVoiceOnDetermineTime(int ch, PWORD pwIsVocDtrTime);
int WINAPI SsmGetMinVocDtrEnergy(int ch, PDWORD pdwMinVocDtrEnergy);

int WINAPI SsmQueryOpPeakFrqDetect(int ch);
int WINAPI SsmSetPeakFrqDetectBW(int ch, WORD nPeakBW);
int WINAPI SsmGetPeakFrqDetectBW(int ch);
long WINAPI SsmGetPeakFrqEnergy(int ch);
int WINAPI SsmGetPeakFrq(int ch);

int WINAPI SsmStart2ndToneAnalyzer(int ch, BOOL bEn);
int WINAPI SsmGet2ndToneAnalyzerState(int ch);
int WINAPI SsmSet2ndTonePara(int ch, WORD wToneFreq1,WORD wToneBW1,WORD wToneFreq2,WORD wToneBW2,DWORD dwIsToneRatio);
int WINAPI SsmGet2ndTonePara(int ch, PWORD pwToneFreq1, PWORD pwToneBW1,PWORD pwToneFreq2,PWORD pwToneBW2,PDWORD pdwIsToneRatio);
int WINAPI SsmGet2ndToneAnalyzeResult(int ch);
int WINAPI SsmClear2ndToneAnalyzeResult(int ch);
int WINAPI SsmGet2ndBusyToneLen(int ch);
int WINAPI SsmGet2ndBusyToneCount(int ch);
int WINAPI SsmSet2ndBusyTonePeriod(int ch, WORD wBusyTonePeriod);
int WINAPI SsmGet2ndBusyTonePeriod(int ch, PWORD pwBusyTonePeriod);
int WINAPI SsmSet2ndIsBusyToneDtrCnt(int ch, WORD wIsBusyToneDtrCnt);
int WINAPI SsmGet2ndIsBusyToneDtrCnt(int ch, PWORD pwIsBusyToneDtrCnt);
int WINAPI SsmSet2ndIsDialToneDtrTime(int ch, WORD wIsDialToneDtrTime);
int WINAPI SsmGet2ndIsDialToneDtrTime(int ch, PWORD pwIsDialToneDtrTime);
int WINAPI SsmSet2ndRingEchoTonePara(int ch, WORD wRingEchoOnTime,WORD wRingEchoOffTime);
int WINAPI SsmGet2ndRingEchoTonePara(int ch, PWORD pwRingEchoOnTime, PWORD pwRingEchoOffTime);
int WINAPI SsmSetBusyTonePeriodEx(int ch, int nType, WORD wMax, PWORD pwPeriod);	//appended by LM for 上海刘锦宏,2001.11.02
int WINAPI SsmGetBusyTonePeriodEx(int ch, int nType, PWORD pwPeriod);				//appended by LM for 上海刘锦宏,2001.11.02
WORD WINAPI SsmGetToneValue(int ch);
int WINAPI SsmSetToneValue(int ch,WORD value);

int WINAPI SsmGetOverallEnergyAllCh(int nBeginCh, int nChNum, PDWORD pdwEnergyTable);	//add by wangjiang 2002.12.28 for open conference

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@ BARGEIN OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmSetNoSoundDtrmTime(int ch, DWORD dwIsNoSoundDtrTime);
int WINAPI SsmSetIsBargeInDtrmTime(int ch, WORD wIsBargeInDtrmTime);
int WINAPI SsmSetBargeInSens(int ch, int nBargeInSens);
long WINAPI SsmGetNoSoundTime(int ch);
long WINAPI SsmGetNoSoundDtrmTime(int ch);
int WINAPI SsmGetIsBargeInDtrmTime(int ch);
int WINAPI SsmGetBargeInSens(int ch);
int WINAPI SsmDetectBargeIn(int ch);
int WINAPI SsmDetectNoSound(int ch);

//设置模拟电话线相对能量被叫摘机检测参数
//返回值 0:操作成功, -1:操作失败
int WINAPI SsmSetCalleeHookDetectP(int ch, // 通道号
							 WORD wMulti, //预定倍数
							 WORD wValidTime); //有效时间
//读取模拟电话线相对能量被叫摘机检测参数
//返回值 0:操作成功, -1:操作失败
int WINAPI SsmGetCalleeHookDetectP(int ch, // 通道号
							 PWORD pwMulti, //预定倍数
							 PWORD pwValidTime); //有效时间


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ RING DETECT OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmQueryOpRingDetect(int ch);
int WINAPI SsmGetRingFlag(int ch);
int WINAPI SsmGetRingCount(int ch);
int WINAPI SsmClearRingCount(int ch);
int WINAPI SsmChkOpCallerId(int ch);
int WINAPI SsmGetCallerId(int ch, LPSTR szCallerId);
char* WINAPI SsmGetCallerIdA(int ch);
int WINAPI SsmGetCallerIdEx(int ch, LPSTR szCallerIdEx);
int WINAPI SsmClearCallerId(int ch);
int WINAPI SsmClearCallerIdEx(int ch);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@ CALL OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmPickup(int ch);
int WINAPI SsmCheckActualPickup(int ch);
int WINAPI SsmSetPickupNow(int ch, BOOL bFlag);
int WINAPI SsmHangup(int ch);
int WINAPI SsmAutoDial(int ch, LPSTR szPhoNum);
int WINAPI SsmChkAutoDial(int ch);
int WINAPI SsmGetAutoDialFailureReason(int ch);
int WINAPI SsmGetBlockReason(int ch);
int WINAPI SsmGetChState(int ch);

int WINAPI SsmSetPlayDest(int ch, int nSelDest);
int WINAPI SsmSetRecBack(int ch, int nRecBack);

int WINAPI SsmSearchIdleCallOutCh(WORD wSearchMode, DWORD dwPrecedence);
int WINAPI SsmSetAutoCallDirection(int ch, BOOL bEnAutoCall, int nDirection);
int WINAPI SsmGetAutoCallDirection(int ch, int* pnDirection);
int WINAPI SsmAppendPhoNum(int ch, LPSTR szPhoNum);
int WINAPI SsmGetPendingReason(int ch);
long WINAPI SsmGetChStateKeepTime(int ch);
int WINAPI SsmGetPhoNumStr(int ch, LPSTR pszPhoNum);
char* WINAPI SsmGetPhoNumStrA(int ch);
int WINAPI SsmGetPhoNumLen(int ch);

int WINAPI SsmGet1stPhoNumStr(int ch, LPSTR pszPhoNum);
char* WINAPI SsmGet1stPhoNumStrA(int ch);
int WINAPI SsmGet1stPhoNumLen(int ch);

int WINAPI SsmEnableAutoSendKB(int ch, BOOL bEnable);
int WINAPI SsmGetAutoSendKBFlag(int ch);
int WINAPI SsmSetKB(int ch, BYTE btSigKB);
int WINAPI SsmSetKD(int ch, BYTE btSigKD);
int WINAPI SsmSetKA(int ch, BYTE btSigKA);
int WINAPI SsmSetTxCallerId(int ch, LPSTR pszTxCallerId);
int WINAPI SsmGetTxCallerId(int ch, LPSTR pszTxCallerId);
int WINAPI SsmGetKA(int ch);
int WINAPI SsmGetKB(int ch);
int WINAPI SsmGetKD(int ch);
int WINAPI SsmAutoDialEx(int ch, LPSTR szPhoNum,WORD wParam);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Following functions are newly appended by cxg for applications using SS7
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int WINAPI SsmBlockLocalCh(int ch);
int WINAPI SsmUnblockLocalCh(int ch);
int WINAPI SsmQueryLocalChBlockState(int ch, PDWORD pdwBlockState);

int WINAPI SsmBlockLocalPCM(int nLocalPcmNo);
int WINAPI SsmUnblockLocalPCM(int nLocalPcmNo);
int WINAPI SsmQueryLocalPCMBlockState(int nLocalPcmNo, PDWORD pdwBlockState);

int WINAPI SsmQueryOpBlockRemoteCh(int ch);
int WINAPI SsmBlockRemoteCh(int ch);
int WINAPI SsmUnblockRemoteCh(int ch);
int WINAPI SsmGetRemoteChBlockStatus(int ch);

int WINAPI SsmBlockRemotePCM(int nLocalPcmNo, DWORD dwBlockMode);
int WINAPI SsmUnblockRemotePCM(int nLocalPcmNo, DWORD dwUnblockMode);
int WINAPI SsmGetRemotePCMBlockStatus(int nLocalPcmNo, DWORD dwBlockMode);

BOOL WINAPI SsmGetWaitAutoDialAnswerTime(WORD * pwSeconds);
BOOL WINAPI SsmSetWaitAutoDialAnswerTime(WORD wSeconds);

//Ver3.5.26.
//+++BEGIN+++ Added by xxb for 模拟电话线相对能量算法检测被叫摘机不适用于调用SsmTxDtmf()外拨及二次拨号,2003.3.7
int WINAPI SsmStartPickupAnalyze(int ch);
int WINAPI SsmGetPickup(int ch);
//+++END+++ Added by xxb for 模拟电话线相对能量算法检测被叫摘机不适用于调用SsmTxDtmf()外拨及二次拨号,2003.3.7

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@ ADAPTIVE FILTER OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmQueryOpEchoCanceller(int ch);
int WINAPI SsmSetEchoCanceller(int ch, BOOL bRun);
int WINAPI SsmGetEchoCancellerState(int ch);
int WINAPI SsmSetEchoCancellerStudy(int ch, BOOL bRun);
int WINAPI SsmGetEchoCancellerStudyState(int ch);
int WINAPI SsmGetEchoCancellerRatio(int ch);
int WINAPI SsmSaveEchoCancellerPara(int ch);
int WINAPI SsmSetEchoCancelDelaySize(int ch,WORD wSize);
WORD WINAPI SsmGetEchoCancelDelaySize(int ch);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ CT-BUS OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmListenTo(int ch1,int ch2);
int WINAPI SsmListenToEx(int ch1, int nVolume1, int ch2);
int WINAPI SsmStopListenTo(int ch1,int ch2);
int WINAPI SsmTalkWith(int ch1,int ch2);
int WINAPI SsmTalkWithEx(int ch1, int nVlm1, int ch2, int nVlm2);
int WINAPI SsmStopTalkWith(int ch1,int ch2);

void WINAPI PlayListen(DWORD dwBId, DWORD ch);
void WINAPI PlayListenNew(DWORD dwSpeakerCh, DWORD dwMonitorCh);
void WINAPI StopListen(DWORD dwBId);
void WINAPI StopListenNew(DWORD dwSpeakerCh);

int	WINAPI SsmLinkFrom(int ch1,int ch2);	//add by wangjiang 2002.12.28 for open conference
int WINAPI SsmStopLinkFrom(int ch1,int ch2);	//add by wangjiang 2002.12.28 for open conference
int WINAPI SsmLinkFromEx(int ch1, int nVolume1, int ch2); //add by wangjiang 2002.12.28 for open conference
int	WINAPI SsmLinkFromAllCh(int ch, int nVolume, int*nListenerTable,int nListenerNum);	//add by wangjiang 2002.12.28 for open conference
int	WINAPI SsmUnLinkFromAllCh(int ch, int*nListenerTable,int nListenerNum);	//add by wangjiang 2002.12.28 for open conference

int WINAPI	SsmLinkToBus(int ch,int ts);
int	WINAPI  SsmUnLinkToBus(int ch,int ts);
int WINAPI	SsmLinkFromBus(int ts,int ch);
int WINAPI	SsmLinkFromBusEx(int ts, int ch, int vlm);
int WINAPI	SsmUnLinkFromBus(int ts,int ch);
int WINAPI	SsmListenToPlay(int ch1, int vlm1, int ch2);
int WINAPI	SsmUnListenToPlay(int ch1, int ch2);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@ CONFERENCE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmCreateConfGroup(int nMaxMember, int nMaxSpeaker, int nMaxSpeaking, int nMaxSilenceTime);
int WINAPI SsmFreeConfGroup(int nGrpId);
int WINAPI SsmJoinConfGroup(int nGrpId, int ch, WORD wJoinMode, int nMixerVolume, BOOL bCreateAlways, BOOL bExitGrpAlways);
int WINAPI SsmExitConfGroup(int ch, BOOL bFreeGrpAlways);
int WINAPI SsmGetConfCfgInfo(PWORD pwMaxMember, PWORD pwMaxSpeaker, PWORD pwMaxSpeaking, PWORD pwMaxSilenceTime);
int WINAPI SsmGetTotalConfGroup();
int WINAPI SsmGetConfGrpId(int* pnGrpId);
int WINAPI SsmGetConfGrpCfgInfo(int nGrpId, PWORD pwMaxMember, PWORD pwMaxSpeaker, PWORD pwMaxSpeaking, PWORD pwMaxSilenceTime);
int WINAPI SsmGetConfGrpInfo(int nGrpId, PWORD pwTotalMember, PWORD pwTotalSpeaker, PWORD pwTotalSpeaking);
int WINAPI SsmGetConfGrpMmbrId(int nGrpId, int* pnMmbrId);
int WINAPI SsmGetConfGrpMmbrInfo(int nGrpId, int nMmbrId, int* pnAppCh, PWORD pwJoinMode, PWORD pwIsSpeaking, PDWORD pdwSilenceTime);
int WINAPI SsmGetConfChInfo(int ch, int * pnGrpId, int * pnMmbrId, PWORD pwJoinMode, PWORD pwIsSpeaking, PDWORD pdwSilenceTime);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@ DRIVER  Ver. 1.x COMPATIBLE FUNCTIONS  @@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DWORD WINAPI InitCard(DWORD add1,DWORD add2,DWORD add3,DWORD add4,DWORD add5,
				DWORD add6,DWORD add7,DWORD add8,DWORD intno);
void WINAPI ShutCard(void);

DWORD WINAPI StartRecordFile(DWORD ch,char * fliename);
void WINAPI StopRecordFile(DWORD ch);
void WINAPI PauseRecord(DWORD ch);
void WINAPI RestartRecord(DWORD ch);
DWORD WINAPI GetRecordTime(DWORD ch);

DWORD WINAPI StartPlayFile(DWORD ch,char * filename);
void WINAPI StopPlayFile(DWORD ch);
DWORD WINAPI CheckPlayingEnd(DWORD ch);
void WINAPI PausePlay(DWORD ch);
void WINAPI RestartPlay(DWORD ch);
void WINAPI FastPlay(DWORD ch);
void WINAPI BackPlay(DWORD ch);
DWORD WINAPI GetPlayTime(DWORD ch);
DWORD WINAPI GetPlayPercent(DWORD ch);
void WINAPI SetPlayTime(DWORD ch,DWORD time);
void WINAPI SetPlayPercent(DWORD ch,DWORD percent);

DWORD WINAPI LoadIndexFile(DWORD segno,LPSTR filename,DWORD startadr,DWORD length);
void WINAPI FreeIndexMem(DWORD segno);
void WINAPI PlayIndex(DWORD ch,LPSTR segstring);
void WINAPI StopIndex(DWORD ch);
void WINAPI DTMFStop(DWORD ch,DWORD if_stop);

DWORD WINAPI GetDTMF(DWORD ch);
DWORD WINAPI GetDTMFStr(DWORD ch,char * buf);
void WINAPI ClearDTMFBuf(DWORD ch);
DWORD WINAPI DetectRing(DWORD ch);
void WINAPI ClearRing(DWORD ch);
void WINAPI HangUp(DWORD ch);
void WINAPI PickUp(DWORD ch);
DWORD WINAPI DetectInter(DWORD ch);
DWORD WINAPI GetFlash(DWORD ch);
void WINAPI SetFlashTime(int time);
DWORD WINAPI ToneCheck(DWORD ch);
DWORD WINAPI GetBusyLen(DWORD ch);
void WINAPI DTMFDial(DWORD ch,LPSTR dialstring);
DWORD WINAPI DTMFDialEnd(DWORD ch);
void WINAPI Flash(DWORD ch,DWORD time);
void WINAPI SetPlayVolume(DWORD ch,LONG volume);
void WINAPI SetRecVolume(DWORD ch,LONG volume);

DWORD WINAPI GetCallerId(DWORD ch,LPSTR buf);

void WINAPI SetPickSens(DWORD piont);
DWORD WINAPI GetPickUp(DWORD ch);
DWORD WINAPI GetNum(DWORD ch,LPSTR buf,DWORD time,DWORD len,int end_char);
void WINAPI SetWorkMode(int Mode);
void WINAPI SetUserCard(DWORD addr1,DWORD addr2,DWORD addr3,DWORD addr4,DWORD addr5,DWORD addr6,DWORD addr7,DWORD addr8);
void WINAPI SendBusyTone(int ch);
void WINAPI SendRingEchoTone(int ch);
void WINAPI SendDialTone(int ch);
void WINAPI StopSendTone(int ch);
void WINAPI StartSendRing(int ch);
void WINAPI StopSendRing(int ch);
int WINAPI Link2Ch(int ch1,int ch2);
void WINAPI UnLink2Ch(int ch1,int ch2);
int WINAPI Link3Ch(int ch1,int ch2,int ch3);
void WINAPI UnLink3Ch(int ch1,int ch2,int ch3);
int WINAPI ListenFromCh(int ch1,int ch2);
void WINAPI StopListenFromCh(int ch1,int ch2);
void WINAPI SetDelay(DWORD ch,DWORD delay);
void WINAPI SetLevel(DWORD ch,DWORD level);
DWORD WINAPI DetectSound(DWORD ch);
DWORD WINAPI GetFax11(DWORD ch);
DWORD WINAPI GetFax21(DWORD ch);
DWORD  WINAPI GetRing(DWORD ch);
void WINAPI SetDialSpeed (DWORD point );
void WINAPI GetErrorMsg(char *buf);
DWORD WINAPI SetMaxSeg(DWORD inmaxsegment);

void WINAPI PauseCard(void);
void WINAPI RestartCard(void);

BOOL WINAPI SetIRQPriority(int nPriorityClass);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@ RECORD MODULE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DWORD WINAPI GetLevel(DWORD ch);
void WINAPI SetJudge(DWORD ch, DWORD Judge);
int WINAPI SsmQueryOpADC(int ch);
int WINAPI SsmGetLineVoltage(int ch);
int WINAPI SsmSetDtrmLineVoltage(int ch, WORD wDtrmValtage);
int WINAPI SsmGetDtrmLineVoltage(int ch);
DWORD WINAPI DetectPickUp(DWORD ch);
DWORD WINAPI DetectEmpty(DWORD ch);
void WINAPI SetSoundJudgeLevel(DWORD ch, DWORD level);
DWORD WINAPI GetSoundJudgeLevel(DWORD ch);

int WINAPI SsmQueryOpMicGain(int ch);
int WINAPI SsmSetMicGain(int ch, int nGain);
int WINAPI SsmGetMicGain(int ch);

int WINAPI SsmSetIgnoreLineVoltage(int ch, BOOL bEnable);	// appended by cxg for 陶向东,2001.11.02
int WINAPI SsmGetIgnoreLineVoltage(int ch);					// appended by cxg for 陶向东,2001.11.02

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@ POWER-AMPLIFIER OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void WINAPI SetVolume(DWORD dwBoardId, DWORD dwVolume);
int WINAPI SsmQueryOpPowerAmp(int ch);
int WINAPI SsmSetPowerAmpVlm(int ch, int nVolume);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@ POLAR REVERSE OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DWORD WINAPI GetFZCount(DWORD ch);
int WINAPI SsmQueryOpPolarRvrs(int ch);
int WINAPI SsmGetPolarRvrsCount(int ch);
int WINAPI SsmGetPolarState(int ch);
int WINAPI SsmSetPolarState(int ch, int nPolar);
int WINAPI SsmSetUnimoduleState(int ch, int nLink);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ SS1 OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmQueryOpSS1(int ch);
int WINAPI SsmSendCAS(int ch, BYTE btCas);
int WINAPI SsmGetCAS(int ch);
int WINAPI SsmSetRxR2Mode(int ch, int nMode, BOOL bEnable);
int WINAPI SsmGetR2(int ch);
int WINAPI SsmSendR2(int ch, int nMode, BYTE btR2);
int WINAPI SsmStopSendR2(int ch);

int WINAPI SsmGetSendingCAS(int ch);
int WINAPI SsmGetSendingR2(int ch, int* pnMode, BYTE* pbtR2);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ PCM LINK OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmGetMaxPcm();
int WINAPI SsmGetPcmInfo(int nPcmNo, int* pnSSxMode, int* pnBoardId, int* pnBoardPcmNo, int* pnUsePcmTS16,
				 PDWORD pdwRcvrMode, PDWORD pdwEnableAutoCall, PDWORD pdwAutoCallDirection);
int WINAPI SsmGetPcmLinkStatus(int nPcmNo, PWORD pwPcmLinkStatus);
int WINAPI SsmPcmTsToCh(int nLocalPcmNo, int nTs);
int WINAPI SsmChToPcmTs(int ch, int* pnLocalPcmNo, int* pnTs);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ SEND FSK OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmSetFskPara(int nFreqBit0, int nFreqBit1, int nBaudrate, int nMdlAmp);
int WINAPI SsmGetFskPara(int* pnFreqBit0, int* pnFreqBit1, int* pnBaudrate, int* pnMdlAmp);
int WINAPI SsmTransFskData(unsigned char* pS, int	nSrcLen,int nSyncLen,int nSyncOffLen,unsigned char* pD);
int WINAPI SsmStartSendFSK(int ch, LPSTR pBuf, DWORD dwMaxBit);
int WINAPI SsmCheckSendFsk(int ch);
int WINAPI SsmStopSendFsk(int ch);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ RECEIVE FSK OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmStartRcvFSK_II(int ch, WORD wTimeOut, WORD wMaxLen, PUCHAR pucMarkCodeBuf, UCHAR ucMarkCodeCount);
int WINAPI SsmStartRcvFSK(int ch, WORD wTimeOut, WORD wMaxLen, UCHAR ucEndCode, WORD wEndCodeCount);
int WINAPI SsmClearRcvFSKBuf(int ch);
int WINAPI SsmCheckRcvFSK(int ch);
int WINAPI SsmGetRcvFSK(int ch, PUCHAR pucBuf);
int WINAPI SsmStopRcvFSK(int ch);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ SS7 OPERATION  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmSendSs7Msu(WORD wMsuLength, PUCHAR pucMsuBuf);
int WINAPI SsmGetSs7Msu(PUCHAR* ppucMsuBuf);
int WINAPI SsmGetSs7Mtp2Msu(PUCHAR pucPara, PUCHAR* ppucMsuBuf);
int WINAPI SsmGetMtp3State();
int WINAPI SsmGetMtp3StateEx(int nDpcNo);
int WINAPI SsmGetMtp2Status(int nLinkNum);
//added by mengjin for 动态设置主叫用户类别，2004.11.22
int WINAPI SsmSetISUPCAT(int nch,  UCHAR ucCallerCAT);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@ FAX OPERATION API @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmFaxGetChStateMsg(int ch ,char *buf);
int WINAPI SsmFaxGetPages(int ch);
int WINAPI SsmFaxStartReceive(int ch,char *filename);
int WINAPI SsmFaxStartSend(int ch,char *filename);
int WINAPI SsmFaxStop(int ch);
void WINAPI SsmFaxSetMaxSpeed(int speed);
int WINAPI SsmFaxCheckEnd(int ch);
int WINAPI SsmFaxSetID(int ch,char *myid);
int WINAPI SsmFaxGetID(int ch,char *myid);
int WINAPI SsmFaxSetSendMode(int ch, int mode );
int WINAPI SsmFaxGetRcvBytes(int ch);
int WINAPI SsmFaxGetSendBytes(int ch);
int WINAPI SsmFaxAppendSend(int ch,char *filename);
int WINAPI SsmFaxSetHangup(int ch, bool flag);
int WINAPI SsmFaxStartSendEx(int ch, char * filename, int nStartPage, int nEndPage);
int WINAPI SsmFaxSendMultiFile(int ch, char * szFilePath, char * szFileName);
int WINAPI SsmFaxSendMultiFileEx(int ch, FAX_FILE_SCT * pV, int nNum);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@ MODEM OPERATION API  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmEnableCh(int ch );
int WINAPI SsmDisableCh(int ch );
int WINAPI SsmResetCh(int ch );
int WINAPI SsmCheckResetCh(int ch );
int WINAPI SsmGetLSR(int ch,unsigned char *retu);
int WINAPI SsmGetMSR(int ch ,unsigned char *retu);
int WINAPI SsmGetRTS(int ch );
int WINAPI SsmGetCTS(int ch );
int WINAPI SsmGetOH(int ch );
int WINAPI SsmDetectCarry(int ch );

//soft-fax 2002.07.03
int WINAPI SsmFaxGetChState(int ch ,unsigned short *buf);


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ SERIAL PORT IO OPERATION API @@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmReadRxBuf(int ch , int nLen, char *lpcRxBuf);
int WINAPI SsmGetRxBufLen(int ch );
void WINAPI SsmClearRxBuf(int ch );
int WINAPI SsmWriteTxBuf(int ch, int nLen, char * lpcTxBuf);
int WINAPI SsmWriteTxBuf_S(int ch, char *s);
int WINAPI SsmWriteTxBuf_C(int ch , char buf);
int WINAPI SsmGetTxBufRemain(int ch);
int WINAPI SsmGetTxBufLen(int ch );
void WINAPI SsmClearTxBuf(int ch );

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ ISDN API @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmISDNSetDialSubAddr(int ch, LPSTR lpSubAddress);
int WINAPI SsmISDNSetTxSubAddr(int ch, LPSTR lpSubAddress);
int WINAPI SsmISDNGetTxCallerSubAddr(int ch, LPSTR lpSubAddress);
int WINAPI SsmISDNGetSubAddr(int ch, LPSTR lpSubAddress);
int WINAPI SsmISDNGetCallerSubAddr(int ch, LPSTR lpSubAddress);
int WINAPI SsmISDNGetDisplayMsg(int ch, LPSTR lpDispMsg);
int WINAPI SsmISDNSetHangupRzn(int ch, int nReason);
int WINAPI SsmISDNGetStatus(int nPcmNo, int *pL3Start, 
							int *pL2DStatus, int *pL2D_L3Atom, 
							int * pL3_L2DAtom, int *pRef_ind);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ ViaVoice recognize OPERATION API @@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmStartRecognize(int ch,int grammarid,int max_time);
int WINAPI SsmGetResultCount(int ch);
int WINAPI SsmGetCurSens(int ch);
int WINAPI SsmGetResult(LPSTR buf,LPSTR index,LPSTR score,int ch);
int WINAPI SsmGetNResult(int id,LPSTR buf, LPSTR index, LPSTR score, int ch);
void WINAPI	SsmSetSil(int nValue);
void WINAPI	SsmSetRecoSound(int nBeginLen,int nEndLen,int nSoundLen);
void WINAPI	SsmSetRecoTime(int nRecoTime,int nMaxWait);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ Set Hardware Flags OPERATION API @@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int WINAPI SsmSetFlag(int ch, int nType, long lValue);
int WINAPI SsmGetFlag(int ch, int nType, long* plValue);

int WINAPI SsmSetOvrlEnrgLevel(int ch,WORD wOvrlEnrgLevel);
WORD WINAPI SsmGetOvrlEnrgLevel(int ch);
int WINAPI SsmSetOvrlEnrgDtrmTime(int ch,WORD wMinTime,WORD wMaxTime);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ SPY  API @@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int  WINAPI SpyGetState(int nCic);
int  WINAPI SpyGetCallerId(int nCic,char *pcCid);
int  WINAPI SpyGetCalleeId(int nCic,char *pcCid);
int  WINAPI SpyGetCallInCh(int nCic);
int  WINAPI SpyGetCallOutCh(int nCic);
int  WINAPI SpyGetMaxCic();
int  WINAPI SpyStopRecToFile(int  nCic);
int  WINAPI SpyRecToFile(int nCic, WORD wDirection,
     						LPSTR pszFileName, int nCodecFormat,
	    					DWORD dwStartPos, DWORD dwBytes, 
							DWORD dwTime,  int nMask);
int  WINAPI SpyGetLinkStatus(int nSpyPcmNo,UCHAR ucFlag);

//add by JK Shi for 设置原主叫号码, begin
int WINAPI SsmSetTxOriginalCallerID(int ch, BYTE* pszTxCallerId);
//add by JK Shi for 设置原主叫号码, end

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@ EVENT  API @@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int	WINAPI SsmSetEvent (WORD wEvent, int nReference,BOOL bEnable, PEVENT_SET_INFO pEventSet);
int	WINAPI SsmWaitForEvent(DWORD dwTimeOut, PMESSAGE_INFO pEvent);
int	WINAPI SsmGetEvent(PMESSAGE_INFO pEvent);
int	WINAPI SsmStartTimer(WORD wDelay, WORD fuEvent);
int	WINAPI SsmStopTimer(int nTimer);

#ifdef __cplusplus
	}
#endif
