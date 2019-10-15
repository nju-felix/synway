%module  shcti
%{
#include <shpa3api.h>
%}
/////////////////////////////////////
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
//++++start++++ fax error code      
	C_ERROR_FAX_NOFILE	  = 16
//++++end++++ fax error code
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
	S_TUP_WaitSetCallerID = 77,

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
	S_ISUP_WaitSetCallerID         = 127,

};

enum { 
	//����ʶ��
	E_PROC_Recognize,		//0x0000        //����ʶ������¼�

	//ISDN����
	E_CHG_ISDNStatus,		//0x0001        //ISDN�ײ�״̬�ı��¼�

	//ss7
	E_RCV_Ss7Msu,		//0x0002        //SS7 MSU����֪ͨ�¼�
	E_CHG_Mtp3State,		//0x0003        //Mtp3״̬�ı��¼�

	//����
	E_CHG_FaxChState,		//0x0004        //����ͨ������״̬�ı��¼�
	E_CHG_FaxPages,		//0x0005        //�������/����ҳ�����¼�
	E_PROC_FaxEnd,		//0x0006        //��������¼�

	//PCM��·ͬ��״̬
	E_CHG_PcmLinkStatus,	//0x0007    //PCM��·ͬ��״̬�ı��¼�

	//¼��ͨ��
	E_CHG_LineVoltage,	//0x0008        //¼��ͨ����·��ѹ�仯�¼�

	//ss1
	E_RCV_CAS,		//0x0009        //���յ���CASֵ�б仯
	E_RCV_R2,			//0x000A        //�յ��µ�R2 ֵ

	//DTMF����
	E_PROC_WaitDTMF,		//0x000B        //WaitDTMF��������¼�
	E_CHG_RcvDTMF,		//0x000C

	//DTMF����
	E_PROC_SendDTMF,		//0x000D        //����DTMF��������¼�

	//��������
	E_PROC_SendFlash,		//0x000E        //����������������¼�

	//����
	E_PROC_PlayEnd,		//0x000F        //�����������
	E_PROC_PlayFile,		//0x0010        //�ļ���������ָʾ
	E_PROC_PlayFileList,	//0x0011    //�ļ��б��������ָʾ
	E_PROC_PlayMem,		//0x0012        //�ڴ��������ָʾ

	//¼��
	E_PROC_RecordEnd,		//0x0013        //¼���������
	E_PROC_RecordFile,		//0x0014        //�ļ�¼�������չָʾ
	E_PROC_RecordMem,		//0x0015        //�ڴ�¼�������չָʾ

	//FSK����
	E_PROC_SendFSK,		//0x0016        //����FSK��������¼�

	//FSK����
	E_PROC_RcvFSK,		//0x0017        //RcvFSK�������

	//���п���
	E_CHG_ChState,		//0x0018        //ͨ��״̬�����仯
	E_PROC_AutoDial,		//0x0019        //AutoDial�����н�չ
	E_CHG_RemoteChBlock,	//0x001A
	E_CHG_RemotePCMBlock,	//0x001B
	E_SYS_ActualPickup,		//0x001C        //����ͨ��ʵ��ժ��
	E_CHG_RingFlag,		//0x001D        //������ƽ�仯
	E_CHG_RingCount,		//0x001E        //��������仯
	E_CHG_CIDExBuf,		//0x001F        //CID��չ���ջ������仯
	E_CHG_RxPhoNumBuf,		//0x0020        //���к�����ջ������仯
	E_CHG_PolarRvrsCount,	//0x0021   //����ͨ�����Է�ת
	E_SYS_RemotePickup,		//0x0022        //ģ��绰����������㷨��ⱻ��ժ��

	//��ϯ
	E_CHG_FlashCount,		//0x0023        //flash���������仯
	E_CHG_HookState,		//0x0024        //Hook״̬�����仯

	//�ź������
	E_CHG_ToneAnalyze,	//0x0025        //�ź�����������仯�¼�
	E_OverallEnergy,		//0x0026
	E_CHG_OvrlEnrgLevel,	//0x0027    //ȫƵ������ʶ����¼�
	E_CHG_BusyTone,		//0x0028        //æ�������仯�¼�
	E_CHG_BusyToneEx,		//0x0029        //��ɢæ���仯
	E_CHG_VocFxFlag,		//0x002A        //����Ƶ�ź�����ƽ�仯
	E_CHG_ToneValue,		//0x002B        //�ź�����ƽ�仯
	E_CHG_RingEchoToneTime,	//0x002C
	E_CHG_PeakFrq,		//0x002D        //PeakFrq�б仯
	E_SYS_BargeIn,		//0x003E        //��⵽BargeIn
	E_SYS_NoSound,		//0x002F        //��⵽NoSound

	//��ʱ��
	E_SYS_TIMEOUT,		//0x0030        //��ʱ���¼�

	//������
	E_CHG_SpyState,		//0x0031        //����ص�·�Ľ���״̬֪ͨ�¼�
	E_CHG_SpyLinkStatus,	//0x0032    //����ص�PCM��·״̬֪ͨ�¼�
};

enum { 
	TIMER_ONE, 
	TIMER_PERIODIC 
};

enum { 	
	NO_EVENT,			// ���¼���ʽ
	EVENT_POLLING,		//�¼���ѯ
	EVENT_CALLBACK,		//�¼��ص�
	EVENT_MESSAGE		//windows��Ϣ
};

//�ļ���������ָʾ�����������.
enum {  
	PLAYPERCENT, 
	PLAYTIME, 
	DATABYTESPLAYED, 
	DATABYTESTOPLAY 
};

//�ڴ�¼��������ָʾ�����������.
enum { 	
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
	DWORD dwParam;		//�������
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
//added by mengjin for ��̬���������û����2004.11.22
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
