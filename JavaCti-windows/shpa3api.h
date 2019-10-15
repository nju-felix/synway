
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
	F_RCVDTMFSENS=1,		//����DTMF���ж�
	F_TXDTMFAMP=2,			//����DTMF�ź�ǿ��
	F_RCVPHONUMHOLDUP=3,	//���к������ر��
	
	// Added by xxb for ģ��绰�߱���ժ��������㷨,2003.2.27	
	F_RELATIVEENGYHOOKDETECT=4, //�Ƿ�����ģ��绰�߱���ժ��������㷨
	
	//Added by xxb,for һ������R2�˲��������ɵ�,2003.3.7
	F_RXR2FILTERTIME=5, //R2�����˲�ʱ��
	F_RECTOFILEA_CALLBACKTIME = 6, //Appended by xxb, for SsmRecToFileA�ص�ʱ��ɵ�, 2003.06.24
	F_CALLERIDSTYLE=7,
	F_InVoiceToBus=8, //Added by xxb,for ���������� DTMF����,2004.04.19
	F_ClearInVoiceOnRcvDtmf=9, //Added by xxb,for ���������� DTMF����,2004.04.19
	F_MixerResToBus=10, //added by xxb,for ����Դ������,2004.06.02
	F_HighAndLowFreqEnScale=11, //appended by cqb for �������������е�DTMF , 2004.11.01
	F_DualAndAllFreqEnScale=12 //appended by cqb for �������������е�DTMF , 2004.11.01
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
// ��������ʧ��ԭ��ĳ������壬���ں���SsmGetLastErrCode()����ֵ
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
	C_ERROR_OP_FAILURE		  =14,		//appended by xxb, for ͣ¼��������־����Ч,2003.7.18
	C_ERROR_INVALID_APPSPYCIC =15,

	//+++start+++	fax error code
	C_ERROR_FAX_NOFILE		  =16,
	//+++end+++		fax error code
	
};

//-----------------------------------------------------------------------
// �Զ���������ʧ�ܵĳ������壬���ں���SsmGetAutoDialFailureReason()����ֵ
//-----------------------------------------------------------------------
enum{
	ATDL_NULL=0,								// û�к�������
	ATDL_Cancel=1,								// Ӧ�ó�������ȡ��
	ATDL_WaitDialAnsTimeout=2,					// �ȴ�����Ӧ��ʱ
	ATDL_WaitRemotePickupTimeout=3,				// �ȴ�����ժ����ʱ
	ATDL_PcmSyncLos=4,							// PCM��·������ʧ������100ms

	ATDL_Mtp3Unusable=10,						// No.7����������
	ATDL_RcvSSB=11,								// No.7����յ�SSB
	ATDL_RcvSLB=12,								// No.7����յ�SLB
	ATDL_RcvSTB=13,								// No.7����յ�STB
	ATDL_RcvUNN=14,								// No.7����յ�UNN
	ATDL_RcvSEC=15,								// No.7����յ�SEC
	ATDL_RcvCGC=16,								// No.7����յ�CGC
	ATDL_RcvNNC=17,								// No.7����յ�NNC
	ATDL_RcvCFL=18,								// No.7����յ�CFL
	ATDL_RcvLOS=19,								// No.7����յ�LOS
	ATDL_RcvSST=20,								// No.7����յ�SST
	ATDL_RcvACB=21,								// No.7����յ�ACB
	ATDL_RcvDPN=22,								// No.7����յ�DPN
	ATDL_RcvEUM=23,								// No.7����յ�EUM
	ATDL_RcvADI=24,								// No.7����յ�ADI
	ATDL_RcvBLO=25,								// No.7����յ�BLO
	ATDL_DoubleOccupy=26,						// No.7������ͬ��
	ATDL_CircuitReset=27,						// No.7����յ���·/Ⱥ��ԭ�ź�
	ATDL_BlockedByRemote=28,					// No.7�����·���Զ˽���������

	ATDL_SS1WaitOccupyAckTimeout=40,			// No.1����ȴ�ռ��Ӧ���źų�ʱ
	ATDL_SS1RcvCAS_HANGUP=41,					// No.1����յ���������ź�
	ATDL_SS1RcvA4=42,							// No.1����յ�A4�źţ�����ӵ����
	ATDL_SS1RcvA5=43,							// No.1����յ�A5�źţ��պţ�
	ATDL_SS1RcvUndefinedAx=44,					// No.1����յ�δ����ĺ���A���ź�
	ATDL_SS1RcvUndefinedAxOnTxCallerId=45,		// No.1���������ʱ�յ�δ����ĺ���A���ź�
	ATDL_SS1WaitAxTimeout=46,					// No.1����Ⱥ���պ���A���źų�ʱ
	ATDL_SS1WaitAxStopTimeout=47,				// No.1����Ⱥ����A���ź�ͣ����ʱ
	ATDL_SS1WaitAxTimeoutOnTxCallerId=48,		// No.1���������ʱ�Ⱥ����A���źų�ʱ
	ATDL_SS1WaitAxStopTimeoutOnTxCallerId=49,	// No.1���������ʱ�Ⱥ����A���ź�ͣ����ʱ
	ATDL_SS1RcvKB2=50,							// No.1����յ�KB2�ź�(�û�����æ��)
	ATDL_SS1RcvKB3=51,							// No.1����յ�KB3�ź�(�û�����æ��)
	ATDL_SS1RcvKB4=52,							// No.1����յ�KB4�źţ�����ӵ����
	ATDL_SS1RcvKB5=53,							// No.1����յ�KB5�źţ��պţ�
	ATDL_SS1RcvUndefinedKB=54,					// No.1����յ�δ�����KB�ź�
	ATDL_SS1WaitKBTimeout=55,					// No.1������պ���KB�źų�ʱ
	ATDL_SS1WaitKBStopTimeout=56,				// No.1����Ⱥ򱻽з�ͣ������KB�źų�ʱ

	ATDL_ISDNNETISBUS	= 60,					//ISDN������æ
	ATDL_ISDNEMPTYNO	= 61,					//ISDN:�������ǿպ�.

	ATDL_IllegalMessage = 65,                   //SS7:�Ƿ���Ϣ
	ATDL_RcvREL         = 66,                   //ISUP:�յ��ͷ���Ϣ
};



//-----------------------------------------------------------------------
// �Զ���������ִ������ĳ������壬����SsmChkAutoDial()�ķ���ֵ
//-----------------------------------------------------------------------
enum{
	DIAL_STANDBY        = 0,	// û���Զ���������
	DIAL_DIALING        = 1,	// �����Զ�����
	DIAL_ECHOTONE       = 2,	// �����걻�к�����⵽�˻�����
	DIAL_NO_DIALTONE    = 3,	// û�в��������Զ�����ʧ�ܡ�
	DIAL_BUSYTONE       = 4,	// �����û�æ���Զ����Ž���
	DIAL_ECHO_NOVOICE   = 5,	// ģ������ͨ�����Ž������յ�������������������Զ����Ž���
	DIAL_NOVOICE        = 6,	// ģ������ͨ�����Ž�������ָ��ʱ����û�м�⵽�κ��������Զ����Ž���
	DIAL_VOICE          = 7,	// �����û�ժ�����Զ����Ž���
	DIAL_VOICEF1        = 8,	// �����û�ժ�����յ�Ƶ��F1��������ģ������ͨ�������Զ����Ž���
	DIAL_VOICEF2        = 9,	// �����û�ժ�����յ�Ƶ��F2��������ģ������ͨ�������Զ����Ž���
	DIAL_NOANSWER       = 10,	// ���˽������Զ�����ʧ��
	DIAL_FAILURE        = 11,	// �Զ�����ʧ��
	DIAL_INVALID_PHONUM = 12,	// �պţ��Զ����Ž���
};

//-----------------------------------------------------------------------
// ͨ������ԭ�������壬����SsmGetPendingReason()�ķ���ֵ
//-----------------------------------------------------------------------
enum{
	ANALOGOUT_NO_DIALTONE=0,				// ģ��ͨ�����Զ�����ʱû�м�⵽���������Զ�����ʧ�ܡ�
	ANALOGOUT_BUSYTONE=1,					// ģ��ͨ�����Զ����Ž������⵽���������Զ�����ʧ�ܡ�
	ANALOGOUT_ECHO_NOVOICE=2,				// ģ��ͨ�����Զ����Ž����󲢼�⵽���������ޡ�
	ANALOGOUT_NOANSWER=3,					// ģ��ͨ�����Զ����Ž������⵽�����źŵ���ָ����ʱ����û��Ӧ��
	ANALOGOUT_TALKING_REMOTE_HANGUPED=4,	// ģ��ͨ������"ͨ��"״̬ʱ���Է��һ�
	ANALOGOUT_NOVOICE=5,					// ģ��ͨ�����Զ����Ž������⵽��·�ϳ�������

	PEND_WaitBckStpMsg=10,					// �����м�ͨ�����ȴ�Ӧ�ó������ñ����û�״̬

	SS1IN_BWD_KB5=11,						// No.1����ͨ�����ȴ����в���
	PEND_RemoteHangupOnTalking=12,			// �����м�ͨ�����Զ��������ͨ�����⵽�����û��ȹһ�

	PEND_AutoDialFailed=13,					// �����м�ͨ�����Զ�����ʧ��
	PEND_SsxUnusable=14,					// �����м�ͨ�����������
	PEND_CircuitReset=15,					// �����м�ͨ������·��ԭ
	PEND_PcmSyncLos=16,						// �����м�ͨ����������ͬ����ʧʱ�䳬��100ms

	SS1OUT_TALKING_REMOTE_HANGUPED=20,		// �����м�ͨ�����Զ���������ͨ�����⵽�����û��ȹһ�
	PEND_CalleeHangupOnTalking=20,			// �����м�ͨ�����Զ���������ͨ�����⵽�����û��ȹһ�

	SS1OUT_NOANSWER=21,						// No.1����ͨ�����ȴ������û�ժ����ʱ
	SS1OUT_NOBWDACK=22,						// No.1����ͨ�����ȴ�ռ��Ӧ���źų�ʱ
	SS1OUT_DIALING_BWD_HANGUP=23,			// No.1����ͨ�����յ���������ź�
	SS1OUT_BWD_A5=24,						// No.1����ͨ�����յ�A=5���պţ��ź�
	SS1OUT_BWD_KB5=25,						// No.1����ͨ�����յ�KB=5���պţ��ź�
	SS1OUT_BWD_KB2=26,						// No.1����ͨ�����û�����æ��
	SS1OUT_BWD_KB3=27,						// No.1����ͨ�����û�����æ��
	SS1OUT_BWD_A4=28,						// No.1����ͨ��������ӵ��
	SS1OUT_BWD_KB4=29,						// No.1����ͨ�����յ�KB=4������ӵ�����ź�
	SS1OUT_TIMEOUT_BWD_A=30,				// No.1����ͨ�����Ⱥ���պ���A���źų�ʱ
	SS1OUT_TIMEOUT_BWD_A_STOP=31,			// No.1����ͨ�����Ⱥ����A���ź�ͣ����ʱ
	SS1OUT_TIMEOUT_BWD_KB=32,				// No.1����ͨ�������պ���KB�źų�ʱ
	SS1OUT_TIMEOUT_BWD_KB_STOP=33,			// No.1����ͨ�����Ⱥ򱻽з�ͣ������KB�źų�ʱ
	SS1OUT_TIMEOUT_CALLERID_BWD_A1=34,		// No.1����ͨ�����յ�δ����ĺ���A���ź�
	SS1OUT_TIMEOUT_CALLERID_BWD_A1_STOP=35,	// No.1����ͨ��������CALLERIDʱ�Ⱥ����A���ź�ͣ����ʱ
	SS1OUT_UNDEFINED_CALLERID_BWD_A=36,		// No.1����ͨ�����������к���ʱ�յ�δ����ĺ���A���ź�
	SS1OUT_UNDEFINED_BWD_A=37,				// No.1����ͨ�����յ�δ����ĺ���A���ź�
	SS1OUT_UNDEFINED_BWD_KB=38,				// No.1����ͨ�����յ�δ�����KB�ź�
	
	ISDN_CALLOVER		= 41,			//���н���,�Է��ȹһ�.
	ISDN_WAIT_RELEASE	= 42,			//�ȴ��ͷ�
	ISDN_HANGING		= 43,			//������
	ISDN_RELEASING		= 44,			//�����ͷ�

	ISDN_UNALLOCATED_NUMBER = 45,		//ISDN��δ����ĺ���
	ISDN_NETWORK_BUSY		= 46,		//ISDN, ����æ��
	ISDN_CIRCUIT_NOT_AVAILABLE= 47,		//ISDN, ָ���ĵ�·�����á�
	PEND_CalleeHangupOnWaitRemotePickUp=48,		// added by cqb for SHCTI030902 �����м�ͨ�����Զ�������ȴ����йһ�ʱ��⵽�����û��ȹһ�

	ISUP_HardCircuitBlock    = 49,
	ISUP_RemoteSuspend       = 50,

	PEND_RcvHGBOrSGB		 = 51,//Appended by xxb,for ���յ��Զ˽�����SGB/HGB������������,2003.11.27

	ISDN_NO_ANSWER			=52,		//ISDN, ��Ӧ��
	ISDN_CALL_REJ			=53,		//ISDN, ���оܾ�
};

//-----------------------------------------------------------------------
// ͨ��״̬�������壬����SsmGetChState()�ķ���ֵ
//-----------------------------------------------------------------------
enum{
	S_CALL_STANDBY =0,					//�����С�״̬
	S_CALL_PICKUPED=1,					//��ժ����״̬
	S_CALL_RINGING =2,					//�����塱״̬
	S_CALL_TALKING =3,					//��ͨ����״̬

	S_CALL_ANALOG_WAITDIALTONE  =4,		// ���ȴ���������״̬  ��ģ��ͨ����
	S_CALL_ANALOG_TXPHONUM      =5,		// �����š�״̬        ��ģ��ͨ����
	S_CALL_ANALOG_WAITDIALRESULT=6,		// ���ȴ����Ž����״̬��ģ��ͨ����

	S_CALL_PENDING            =7,		// ������״̬
	S_CALL_OFFLINE            =8,		// �����ߡ�״̬        ��¼��ͨ����
	S_CALL_WAIT_REMOTE_PICKUP =9,		// ���ȴ�����ժ����״̬
	S_CALL_ANALOG_CLEAR      =10,		//  **�ڲ�״̬**       ��ģ��ͨ����
	S_CALL_UNAVAILABLE       =11,		// ��ͨ�������á�״̬
	S_CALL_LOCKED            =12,		// ������������״̬

	S_CALL_RemoteBlock	     =19,		// ���Զ˱�����״̬
	S_CALL_LocalBlock        =20,		// �����˱�����״̬

	S_CALL_Ss1InWaitPhoNum  =30,		// ���ȴ����ձ��к��롱״̬			��No.1������룩
	S_CALL_Ss1InWaitFwdStop =31,		// ���ȴ�ǰ��ͣ����״̬				��No.1������룩
	S_CALL_Ss1InWaitCallerID=32,		// ���ȴ�����CALLERID���롱״̬		��No.1������룩
	S_CALL_Ss1InWaitKD      =33,		// ���ȴ�����KD�źš�״̬			��No.1������룩
	S_CALL_Ss1InWaitKDStop  =34,		// ���ȴ�KD�ź�ͣ����״̬			��No.1������룩
	S_CALL_SS1_SAYIDLE      =35,		// ������ʾ�����״̬				��No.1���
	S_CALL_SS1WaitIdleCAS   =36,		// ���ȴ��Զ�ʾ�С�״̬				��No.1���
	S_CALL_SS1PhoNumHoldup  =37,		// ������������ء�״̬				��No.1���
	S_CALL_Ss1InWaitStopSendA3p=38,		// ���ȴ�ͣ��A3p�źš�״̬			��No.1���


	S_CALL_Ss1OutWaitBwdAck       =40,	// ���ȴ�����ռ��֤ʵ���״̬		��No.1���������
	S_CALL_Ss1OutTxPhoNum         =41,	// �����ͱ��к��롱״̬				��No.1���������
	S_CALL_Ss1OutWaitAppendPhoNum =42,	// ���ȴ�Ӧ�ó���׷�ӵ绰���롱״̬	��No.1���������
	S_CALL_Ss1OutTxCallerID       =43,	// ���������к��롱״̬				��No.1���������
	S_CALL_Ss1OutWaitKB           =44,	// ���ȴ�����KB�źš�״̬			��No.1���������
	S_CALL_Ss1OutDetectA3p        =45,	// �����A3p�ź�(����)��״̬		��No.1���������


	S_FAX_Wait    = S_CALL_STANDBY,		// �����С�״̬								������ͨ����
	S_FAX_ROUND   = 50,					// ��״̬ת�ƹ����С�״̬					������ͨ����
	S_FAX_PhaseA  = 51,					// ��������н�����״̬						������ͨ����
	S_FAX_PhaseB  = 52,					// �����汨��ǰ����״̬					������ͨ����
	S_FAX_SendDCS = 53,					// �����淢��������շ�����DCS�źš�״̬    ������ͨ����
	S_FAX_Train   = 54,					// �����汨�Ĵ���ǰ����ѵ����״̬			������ͨ����
	S_FAX_PhaseC  = 55,					// �����汨�Ĵ����С�״̬					������ͨ����
	S_FAX_PhaseD  = 56,					// �����汨�ĺ���״̬					������ͨ����
	S_FAX_NextPage= 57,					// �����汨�Ĵ�����һҳ��״̬				������ͨ����
	S_FAX_AllSent = 58,					// �����淢���б��Ĵ��������״̬			������ͨ����
	S_FAX_PhaseE  = 59,					// ����������ͷš�״̬						������ͨ����
	S_FAX_Reset   = 60,					// ����λMODEM��״̬						������ͨ����
	S_FAX_Init    = 61,					// ����ʼ��MODEM��״̬						������ͨ����
	S_FAX_RcvDCS  = 62,					// ����������н��շ�����DCS�źš�״̬		������ͨ����
	S_FAX_SendFTT = 63,					// ������������򷢷�����ѵ��ʧ���ź�FTT��״̬		������ͨ����
	S_FAX_SendCFR = 64,					// ������������򷢷����Ϳɽ��ܵ�֤ʵ�ź�CFR��״̬  ������ͨ����

	S_TUP_WaitPcmReset    = 70,			// ���ȴ���·Ⱥ��ԭ��״̬		��No.7����TUPЭ�飩
	S_TUP_WaitSAM         = 71,			// ���ȴ�������ַ��Ϣ��״̬		��No.7����TUPЭ�飩
	S_TUP_WaitGSM         = 72,			// ���ȴ�GSM��Ϣ��״̬			��No.7����TUPЭ�飩
	S_TUP_WaitCLF         = 73,			// ���ȴ����в����źš�״̬		��No.7����TUPЭ�飩
	S_TUP_WaitPrefix      = 74,			// ���ȴ���������ֹڡ�״̬		��No.7����TUPЭ�飩
	S_TUP_WaitDialAnswer  = 75,			// ���ȴ����Ž����״̬			��No.7����TUPЭ�飩
	S_TUP_WaitRLG         = 76,			// ���ȴ��ͷż໤�źš�״̬		��No.7����TUPЭ�飩
	S_TUP_WaitSetCallerID = 77,         //  "�ȴ���������"״̬          ��No.7����TUPЭ�飩

	S_ISDN_OUT_WAIT_NET_RESPONSE	= 81,	//ISDN���ȴ�������Ӧ
	S_ISDN_OUT_PLS_APPEND_NO		= 82,	//ISDN����׷�Ӻ���
	S_ISDN_IN_CHK_CALL_IN			= 83,	//ISDN����⵽����
	S_ISDN_IN_RCVING_NO				= 84,	//ISDN�����ڽ��պ���
	S_ISDN_IN_WAIT_TALK				= 85,	//ISDN��׼������ͨ��
	S_ISDN_OUT_WAIT_ALERT			= 86,	//ISDN: �ȴ��Է��������ź�

	S_ISDN_CALL_BEGIN				= 87,	//ISDN������ʱΪ�շ�����У�����ʱΪ�ռ�⵽����
	S_ISDN_WAIT_HUANGUP				= 88,	//ISDN:�ȴ��ͷ����

	S_CALL_SENDRING                 = 100,  //��ʯģ�����ڷ�������

	S_SPY_STANDBY					= S_CALL_STANDBY,	//��أ�����
	S_SPY_RCVPHONUM                 = 105,  //��أ����պ���
	S_SPY_RINGING					= S_CALL_RINGING,	//��أ�����
	S_SPY_TALKING					= S_CALL_TALKING,	//��أ�ͨ��

	S_SPY_SS1RESET					= 110,	//SS1��أ���ԭ
	S_SPY_SS1WAITBWDACK				= 111,	//SS1��أ��ȴ�����֤ʵ
	S_SPY_SS1WAITKB					= 112,	//SS1��أ��ȴ�KB

	S_ISUP_WaitSAM                 = 120,// ISUP:�ȴ���̺���
	S_ISUP_WaitRLC                 = 121,// ISUP:�ȴ��ͷ������Ϣ
	S_ISUP_WaitReset               = 122,// ISUP:��·��ԭ
	S_ISUP_LocallyBlocked          = 123,// ISUP:���ر����������ر���Զ�˺���
	S_ISUP_RemotelyBlocked         = 124,// ISUP:Զ�˱�������Զ�˱������˺���
	S_ISUP_WaitDialAnswer          = 125,// ISUP:�ȴ��������
	S_ISUP_WaitINF                 = 126,// ISUP:�ȴ����к���
	S_ISUP_WaitSetCallerID         = 127,// ISUP:�ȴ���������

};

// �¼���ռ��16bytes������˳����루��0��ʼ���룩��
// ������windows��Ϣ���ƣ�windows��Ϣ���룺�¼���+0x7000(WM_USER)
enum{
	//����ʶ��
	E_PROC_Recognize,	//0x0000	//����ʶ������¼�

	//ISDN����
	E_CHG_ISDNStatus,	//0x0001	//ISDN�ײ�״̬�ı��¼�

	//ss7
	E_RCV_Ss7Msu,		//0x0002	//SS7 MSU����֪ͨ�¼�
	E_CHG_Mtp3State,	//0x0003	//Mtp3״̬�ı��¼�

	//����
	E_CHG_FaxChState,	//0x0004	//����ͨ������״̬�ı��¼�
	E_CHG_FaxPages,		//0x0005	//�������/����ҳ�����¼�
	E_PROC_FaxEnd,		//0x0006	//��������¼�

	//PCM��·ͬ��״̬
	E_CHG_PcmLinkStatus,//0x0007	//PCM��·ͬ��״̬�ı��¼�


	//¼��ͨ��
	E_CHG_LineVoltage,	//0x0008	//¼��ͨ����·��ѹ�仯�¼�


	//ss1
	E_RCV_CAS,		//0x0009	//���յ���CASֵ�б仯
	E_RCV_R2,		//0x000A	//�յ��µ�R2 ֵ


	//DTMF����
	E_PROC_WaitDTMF,	//0x000B	//WaitDTMF��������¼�
	E_CHG_RcvDTMF,		//0x000C

	//DTMF����
	E_PROC_SendDTMF,	//0x000D	//����DTMF��������¼�


	//��������
	E_PROC_SendFlash,	//0x000E	//����������������¼�


	//����
	E_PROC_PlayEnd,		//0x000F	//�����������
	E_PROC_PlayFile,	//0x0010	//�ļ���������ָʾ
	E_PROC_PlayFileList,//0x0011	//�ļ��б��������ָʾ


	E_PROC_PlayMem,		//0x0012	//�ڴ��������ָʾ

	//¼��
	E_PROC_RecordEnd,	//0x0013	//¼���������
	E_PROC_RecordFile,	//0x0014	//�ļ�¼�������չָʾ
	E_PROC_RecordMem,	//0x0015	//�ڴ�¼�������չָʾ


	//FSK����
	E_PROC_SendFSK,		//0x0016	//����FSK��������¼�

	//FSK����
	E_PROC_RcvFSK,		//0x0017	//RcvFSK�������


	//���п���
	E_CHG_ChState,		//0x0018	//ͨ��״̬�����仯
	E_PROC_AutoDial,	//0x0019	//AutoDial�����н�չ
	E_CHG_RemoteChBlock,//0x001A
	E_CHG_RemotePCMBlock,//0x001B
	E_SYS_ActualPickup,	//0x001C	//����ͨ��ʵ��ժ��
	E_CHG_RingFlag,		//0x001D	//������ƽ�仯
	E_CHG_RingCount,	//0x001E	//��������仯
	E_CHG_CIDExBuf,		//0x001F	//CID��չ���ջ������仯
	E_CHG_RxPhoNumBuf,	//0x0020	//���к�����ջ������仯
	E_CHG_PolarRvrsCount,//0x0021	//����ͨ�����Է�ת
	E_SYS_RemotePickup,	//0x0022	//ģ��绰����������㷨��ⱻ��ժ��

	//��ϯ
	E_CHG_FlashCount,	//0x0023	//flash���������仯
	E_CHG_HookState,	//0x0024	//Hook״̬�����仯

	//�ź������
	E_CHG_ToneAnalyze,	//0x0025	//�ź�����������仯�¼�
	E_OverallEnergy,	//0x0026
	E_CHG_OvrlEnrgLevel,//0x0027	//ȫƵ������ʶ����¼�
	E_CHG_BusyTone,		//0x0028	//æ�������仯�¼�
	E_CHG_BusyToneEx,	//0x0029	//��ɢæ���仯
	E_CHG_VocFxFlag,	//0x002A	//����Ƶ�ź�����ƽ�仯
	E_CHG_ToneValue,	//0x002B	//�ź�����ƽ�仯
	E_CHG_RingEchoToneTime,	//0x002C
	E_CHG_PeakFrq,		//0x002D	//PeakFrq�б仯
	E_SYS_BargeIn,		//0x003E	//��⵽BargeIn
	E_SYS_NoSound,		//0x002F	//��⵽NoSound

	//��ʱ��
	E_SYS_TIMEOUT,		//0x0030	//��ʱ���¼�

	//������
	E_CHG_SpyState,		//0x0031	//����ص�·�Ľ���״̬֪ͨ�¼�
	E_CHG_SpyLinkStatus,//0x0032	//����ص�PCM��·״̬֪ͨ�¼�
};

typedef struct  _MESSAGE_INFO
{
	WORD	wEventCode;
	int		nReference;
	DWORD	dwParam; //�������
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
	NO_EVENT, // ���¼���ʽ
	EVENT_POLLING, //�¼���ѯ
	EVENT_CALLBACK, //�¼��ص�
	EVENT_MESSAGE //windows��Ϣ
};

//�ļ���������ָʾ�����������.
enum
{
	PLAYPERCENT,
	PLAYTIME,
	DATABYTESPLAYED,
	DATABYTESTOPLAY
};

//�ڴ�¼��������ָʾ�����������.
enum
{
	END_HALF_BUFFER,
	END_BUFFER,	
	MEM_OFFSET
};

//�ļ�¼������ָʾ�����������.
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

//appended by xxb for ����,01.09,2002 +++++
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
//appended by xxb for ����,01.09,2002 -----
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
//appended by xxb for ����,01.09,2002 +++++
int WINAPI SsmSetDTMFStopRecCharSet(int ch, LPSTR lpstrDtmfCharSet);
int WINAPI SsmGetDTMFStopRecCharSet(int ch, LPSTR lpstrDtmfCharSet);
int WINAPI SsmSetHangupStopRecFlag(int ch, BOOL bHangupStopRecFlag );
int WINAPI SsmCheckRecord(int ch);
int WINAPI SsmRecordMemBlock(int ch, int nFormat, LPBYTE pBuf,
					 DWORD dwBufSize, RECORDMEMBLOCKHANDLER OnRecMemBlockDone, PVOID pV);
int WINAPI SsmStopRecordMemBlock(int ch);
//appended by xxb for ����,01.09,2002 -----

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

//appended by xxb for ����,01.09,2002 +++++
// ���ý���DTMF�ַ��ص�������
int WINAPI SsmSetRxDtmfHandler(int ch, RXDTMFHANDLER OnRcvDtmf, PVOID pV);
//appended by xxb for ����,01.09,2002 -----
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
int WINAPI SsmSetTxFlashCharTime(int ch, WORD time);	//appended by LM for �Ϻ�������,2001.11.02
int WINAPI SsmGetTxFlashCharTime(int ch);				//appended by LM for �Ϻ�������,2001.11.02


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

//++++START++++ appended by CXG for �ſ�����æ���������,2001.11.22
int WINAPI SsmGetBusyToneEx(int ch);
//++++END++++ appended by LM for �ſ�����æ���������,2001.11.22

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
int WINAPI SsmSetBusyTonePeriodEx(int ch, int nType, WORD wMax, PWORD pwPeriod);	//appended by LM for �Ϻ�������,2001.11.02
int WINAPI SsmGetBusyTonePeriodEx(int ch, int nType, PWORD pwPeriod);				//appended by LM for �Ϻ�������,2001.11.02
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

//����ģ��绰�������������ժ��������
//����ֵ 0:�����ɹ�, -1:����ʧ��
int WINAPI SsmSetCalleeHookDetectP(int ch, // ͨ����
							 WORD wMulti, //Ԥ������
							 WORD wValidTime); //��Чʱ��
//��ȡģ��绰�������������ժ��������
//����ֵ 0:�����ɹ�, -1:����ʧ��
int WINAPI SsmGetCalleeHookDetectP(int ch, // ͨ����
							 PWORD pwMulti, //Ԥ������
							 PWORD pwValidTime); //��Чʱ��


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
//+++BEGIN+++ Added by xxb for ģ��绰����������㷨��ⱻ��ժ���������ڵ���SsmTxDtmf()�Ⲧ�����β���,2003.3.7
int WINAPI SsmStartPickupAnalyze(int ch);
int WINAPI SsmGetPickup(int ch);
//+++END+++ Added by xxb for ģ��绰����������㷨��ⱻ��ժ���������ڵ���SsmTxDtmf()�Ⲧ�����β���,2003.3.7

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

int WINAPI SsmSetIgnoreLineVoltage(int ch, BOOL bEnable);	// appended by cxg for ����,2001.11.02
int WINAPI SsmGetIgnoreLineVoltage(int ch);					// appended by cxg for ����,2001.11.02

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
//added by mengjin for ��̬���������û����2004.11.22
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

//add by JK Shi for ����ԭ���к���, begin
int WINAPI SsmSetTxOriginalCallerID(int ch, BYTE* pszTxCallerId);
//add by JK Shi for ����ԭ���к���, end

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
