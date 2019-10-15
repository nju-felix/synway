import org.xvolks.jnative.JNative;
import org.xvolks.jnative.pointers.Pointer;
import org.xvolks.jnative.pointers.memory.MemoryBlockFactory;
import org.xvolks.jnative.pointers.memory.HeapMemoryBlock;
import org.xvolks.jnative.Type;
import org.xvolks.jnative.exceptions.NativeException;
import java.lang.Thread.*;
public class Handle 
{
	private ChManager []cm=null;
	private int maxch = 0;
	private int temp=-1;
	Thread current = Thread.currentThread();
	Handle(ChManager []cm,int maxch)
	{
		this.cm = cm;
		this.maxch = maxch;
	}
	public void chHandle()throws NativeException,IllegalAccessException
	{
		for(ChManager i:cm)
		{   //������ϯͨ�����в�����ϯͨ����ֻ��ժ���Ϳ�������״̬
			if(i.getChType() ==2)
			{
					switch(i.getCurrentChState())
					{
						case 0:
							if(Sh.ssmGetHookState(i.chflag)==1)
							{
								i.setCurrentChState(1);
								i.setState(1);
								CHShow.UpdateChState(i.chflag,3,"׼�����");
								CHShow.UpdateChState(i.chflag,4,"ժ��");
							}
							break;
						case 1://ժ��ת�벦������
							if(i.getInUse()==0)
								if(!dialHandle(i.chflag))
								i.setCurrentChState(4);
							break;
						case 2://�������
							if (Sh.ssmChkAutoDial(i.getLinkCh()) == 7)
							{
								//System.out.println(Sh.ssmChkAutoDial(i.getLinkCh()));
								if (Sh.ssmTalkWith(i.chflag,i.getLinkCh())==-1)
								{
									Sh.ssmHangup(i.getLinkCh());
									temp = i.getLinkCh();
									cm[temp].setCurrentChState(0);
									cm[temp].setInUse(0);
									temp = -1;
									i.setCurrentChState(4);
									break;
								}
							i.setCurrentChState(3);
							//System.out.println("����ͨ��״̬2");
							}
							break;
						case 3://����ͨ��
							//System.out.println("����ͨ������״̬");
							if(Sh.ssmGetHookState(i.chflag)==0)
							{
								//System.out.println(""+Sh.ssmGetChState(i.chflag));
								Sh.ssmStopTalkWith(i.chflag,i.getLinkCh());
								Sh.ssmHangup(i.getLinkCh());
								temp = i.getLinkCh();
								cm[temp].setCurrentChState(0);
								cm[temp].setInUse(0);
								CHShow.UpdateChState(temp,2,""+(-1));
								CHShow.UpdateChState(temp,3,"Ŀǰ����");
								CHShow.UpdateChState(temp,4,"�ȴ�������ߺ���");
								temp = -1;
								i.setInUse(0);
								i.setCurrentChState(0);
								Sh.ssmStopRing(i.chflag);
								CHShow.UpdateChState(i.chflag,2,""+(-1));
								CHShow.UpdateChState(i.chflag,3,"Ŀǰ����");
								CHShow.UpdateChState(i.chflag,4,"�ȴ�������ߺ���");
								//System.out.println("��һ��ˣ�ͨ������");
								//System.out.println("����ժ����������");
							}
							else if (Sh.ssmGetToneAnalyzeResult(i.getLinkCh())==2)//�����ȹһ�
							{
								Sh.ssmStopTalkWith(i.chflag,i.getLinkCh());
								Sh.ssmHangup(i.getLinkCh());
								temp = i.getLinkCh();
								cm[temp].setCurrentChState(0);
								cm[temp].setInUse(0);
								CHShow.UpdateChState(temp,2,""+(-1));
								CHShow.UpdateChState(temp,3,"Ŀǰ����");
								CHShow.UpdateChState(temp,4,"�ȴ�������ߺ���");
								temp = -1;
								Sh.ssmSendTone(i.chflag,1);
								CHShow.UpdateChState(i.chflag,2,""+(-1));
								i.setCurrentChState(4);
								System.out.println("���йһ�����һ�");
							}
							break;
						case 4://�ȴ���ϯ�һ�
							if(Sh.ssmGetHookState(i.chflag)==0)
							{
								Sh.ssmStopRing(i.chflag);
								Sh.ssmStopSendTone(i.chflag);
								i.setCurrentChState(0);
								i.setInUse(0);
								i.setLinkCh(-1);
								CHShow.UpdateChState(i.chflag,3,"Ŀǰ����");
								CHShow.UpdateChState(i.chflag,4,"�ȴ�������ߺ���");
								//System.out.println("��������");
								//System.out.println("����ժ����������");
							}
							break;

						default:break;
					}
			}
			//����ģ��ͨ�����в���
			if (i.getChType() == 0)
			{
				switch(i.getCurrentChState())
				{
					case 0:
						if (Sh.ssmGetChState(i.chflag)==2&&i.getInUse()==0)
						{
							CHShow.UpdateChState(i.chflag,3,"�绰����");
							CHShow.UpdateChState(i.chflag,4,"������롣����");
							i.setInUse(1);
							i.setCurrentChState(2);
							//System.out.println("jfklajdla");
						}
						break;
					case 1:break;//ժ��
					case 2://����ת��call����
						if (i.getInUse()==1)
						{
							callHandle(i.chflag);
						}
						break;
					case 3:
							break;
					default:break;
				}
			}
		}
	}
public boolean dialHandle(int ch)throws NativeException,IllegalAccessException//�պţ�Ѱ�ҿ���ģ��ͨ��������
{
		int linkch = findFreeCh(0);
		//System.out.println(""+linkch);
		if (linkch == -1)
		{
			Sh.ssmSendTone(ch,1);
			cm[ch].setCurrentChState(4);
			CHShow.UpdateChState(ch,4,"δ�ҵ�����ģ��ͨ������һ�");
			return false;
		}
		else 
		{
			Sh.ssmSendTone(ch,0);
			cm[linkch].setCurrentChState(1);//��������ͨ����ǰ״̬Ϊժ��״̬��
			CHShow.UpdateChState(ch,2,""+linkch);
			CHShow.UpdateChState(linkch,2,""+ch);
		}
		//System.out.println("�ҵ����е�ģ��ͨ��"+linkch);
		cm[ch].setLinkCh(linkch);
		cm[linkch].setLinkCh(ch);
		cm[ch].setInUse(1);
		cm[linkch].setInUse(1);
		Pointer ptPhnum = Sh.creatPointer();
		ptPhnum.setStringAt(0,"a");
		String strPhnum = ptPhnum.getAsString();
		int temp = -1;
		Sh.ssmPickup(linkch);
		CHShow.UpdateChState(linkch,3,"׼�����");
		CHShow.UpdateChState(linkch,4,"���ڷ���������");
		//�ź����������ڽ���
		while(Sh.ssmGetToneAnalyzeResult(linkch)==0)
		{
			if(Sh.ssmGetHookState(ch)==0)
			{
				Sh.ssmHangup(linkch);
				cm[ch].setCurrentChState(0);
				cm[ch].setInUse(0);
				cm[ch].setLinkCh(-1);
				cm[linkch].setCurrentChState(0);
				cm[linkch].setInUse(0);
				cm[linkch].setLinkCh(-1);
				CHShow.UpdateChState(linkch,4,"����������ʧ�ܣ����йһ�");
				CHShow.UpdateChState(linkch,3,"Ŀǰ����");
				CHShow.UpdateChState(ch,2,""+(-1));
				CHShow.UpdateChState(linkch,2,""+(-1));
				CHShow.UpdateChState(ch,3,"Ŀǰ����");
				CHShow.UpdateChState(ch,4,"�ȴ�������ߺ���");
				return false;
			}
		}
		//�в�����
		if (Sh.ssmGetToneAnalyzeResult(linkch)!=1)
		{	
			Sh.ssmSendTone(ch,1);
			Sh.ssmHangup(linkch);
			cm[ch].setCurrentChState(4);
			cm[linkch].setCurrentChState(0);
			cm[linkch].setInUse(0);
			cm[linkch].setLinkCh(-1);
			CHShow.UpdateChState(linkch,4,"����������ʧ�ܣ�δ֪����");
			CHShow.UpdateChState(ch,2,""+(-1));
			CHShow.UpdateChState(linkch,2,""+(-1));
			CHShow.UpdateChState(linkch,3,"Ŀǰ����");
			return false;
		}
				
		else cm[linkch].setCurrentChState(5);//�ȴ�����״̬
		CHShow.UpdateChState(ch,4,"�벦�š�����");
		CHShow.UpdateChState(linkch,4,"׼������");
		//System.out.println("�벦��");
		//�պŲ���(��ȡ��һ������)
		do
		{
			temp = Sh.ssmGet1stDtmfClr(ch,ptPhnum);
			strPhnum = ptPhnum.getAsString();
			if(Sh.ssmGetHookState(ch)==0||Sh.ssmGetToneAnalyzeResult(linkch)==2)
			{
				Sh.ssmHangup(linkch);
				cm[ch].setCurrentChState(0);
				cm[ch].setInUse(0);
				cm[ch].setLinkCh(-1);
				cm[linkch].setLinkCh(-1);
				cm[linkch].setCurrentChState(0);
				cm[linkch].setInUse(0);
				CHShow.UpdateChState(linkch,4,"����ʧ��");
				CHShow.UpdateChState(linkch,3,"Ŀǰ����");
				CHShow.UpdateChState(ch,2,""+(-1));
				CHShow.UpdateChState(linkch,2,""+(-1));
				ptPhnum.dispose();
				return false;
			}
		}
		while (temp!=1);
			//Sh.ssmGet1stDtmfClr(ch,ptPhnum);
			//strPhnum = ptPhnum.getAsString();
		CHShow.UpdateChState(ch,4,"��������ĺ�����:"+strPhnum);
		CHShow.UpdateChState(linkch,4,"�����С������ȴ�׷�Ӻ���");
		//System.out.print("��������ĺ�����:"+strPhnum);
		Sh.ssmAutoDial(linkch,strPhnum);
			//��ȡʣ�����
		while(Sh.ssmChkAutoDial(linkch) != 2&&Sh.ssmChkAutoDial(linkch) != 7)
		{
			temp = Sh.ssmGet1stDtmfClr(ch,ptPhnum);
			if (temp==1)
			{
				strPhnum = ptPhnum.getAsString();
				CHShow.UpdateChState(ch,4,CHShow.GetTableChState(ch,4)+strPhnum);
				//System.out.print(strPhnum);
				   Sh.ssmAppendPhoNum(linkch,strPhnum);
			}
			if(Sh.ssmGetHookState(ch)==0||Sh.ssmGetToneAnalyzeResult(linkch)==2||Sh.ssmGetChState(linkch)==7)
			{
				Sh.ssmHangup(linkch);
				Sh.ssmSendTone(ch,1);
				cm[ch].setCurrentChState(4);
				cm[ch].setInUse(0);
				cm[ch].setLinkCh(-1);
				cm[linkch].setLinkCh(-1);
				cm[linkch].setCurrentChState(0);
				cm[linkch].setInUse(0);
				ptPhnum.dispose();
				CHShow.UpdateChState(linkch,4,"����ʧ��");
				CHShow.UpdateChState(linkch,3,"Ŀǰ����");
				CHShow.UpdateChState(ch,2,""+(-1));
				CHShow.UpdateChState(linkch,2,""+(-1));
				return false;
			}
		}
			//System.out.println("\n");
		
		cm[ch].setCurrentChState(2);
		//System.out.println("����ͨ��״̬");
		CHShow.UpdateChState(linkch,4,"����ͨ��״̬");
		ptPhnum.dispose();
		return true;
		/*while(Sh.ssmChkAutoDial(linkch) != 2||Sh.ssmChkAutoDial(linkch) != 7)
		{
			if (Sh.ssmChkAutoDial(linkch) == 2)
			{
				cm[linkch].setCurrentChState(9);
				cm[ch].setCurrentChState(2);
				System.out.println("����ͨ��״̬");
				break;
			}
			else if (Sh.ssmChkAutoDial(linkch) == 7)
			{
				cm[linkch].setCurrentChState(3);
				
				break;
			}
			if(Sh.ssmGetChState(ch)==0)
			{
				Sh.ssmHangup(linkch);
				cm[ch].setCurrentChState(0);
				cm[ch].setInUse(0);
				cm[linkch].setCurrentChState(0);
				cm[linkch].setInUse(0);
				ptPhnum.dispose();
				return false;
			}
		}*/
				
}
public boolean callHandle(int ch)throws NativeException,IllegalAccessException//����ģ��ͨ��
{
	int linkch = findFreeCh(1);
	//System.out.println("�ҵ����е���ϯͨ��"+linkch);
	if (linkch==-1)
	{
		CHShow.UpdateChState(ch,4,"δ�ҵ�������ϯͨ��");
		Sh.ssmPickup(ch);
		Sh.ssmSendTone(ch,1);
		try
		{
			current.sleep(1000);
		}
		catch (Exception e)
		{
		}
		Sh.ssmStopSendTone(ch);
		Sh.ssmHangup(ch);
		cm[ch].setCurrentChState(0);
		cm[ch].setInUse(0);
		CHShow.UpdateChState(ch,3,"Ŀǰ����");
		CHShow.UpdateChState(ch,4,"�ȴ�������ߺ���");
		return false;
	}
	CHShow.UpdateChState(ch,2,""+linkch);
	CHShow.UpdateChState(linkch,2,""+ch);
	cm[ch].setLinkCh(linkch);
	cm[linkch].setLinkCh(ch);
	cm[ch].setInUse(1);
	cm[linkch].setInUse(1);
	int CIDlen = -2;
	//System.out.println("�ҵ����е���ϯͨ��"+linkch);
	Pointer ptCID = Sh.creatPointer();
	ptCID.setStringAt(0,"a");
	String strCID = ptCID.getAsString();
	try
		{
			current.sleep(1000);
		}
		catch (Exception e)
		{
		}
	Sh.ssmGetCallerId(ch,ptCID);
	strCID = ptCID.getAsString();
	CIDlen = strCID.length();
	if (CIDlen==-1||CIDlen==0)
	{
		Sh.ssmStartRing(linkch);
		CHShow.UpdateChState(linkch,4,"�ȴ���ϯժ��");
		CHShow.UpdateChState(ch,4,"δ֪����,����������ϯ");
		//System.out.println("δ֪����");
	}
	else
	{
		CHShow.UpdateChState(ch,4,"���к���"+strCID+"����");
		CHShow.UpdateChState(linkch,4,"�ȴ���ϯժ��");
		//System.out.println("���к���"+strCID+"����");
		Sh.ssmStartRingWithCIDStr(linkch,strCID,strCID.length(),500);
	}
	while(Sh.ssmGetHookState(linkch)!=1)
	{
		if(Sh.ssmGetChState(ch)==0)
		{
			//System.out.println("fjkdlsa");
			//Sh.ssmPickup(ch);
			//Sh.ssmSendTone(ch,1);
			cm[ch].setCurrentChState(0);
			cm[ch].setInUse(0);
			cm[ch].setLinkCh(-1);
			cm[linkch].setCurrentChState(0);
			cm[linkch].setInUse(0);
			cm[linkch].setLinkCh(-1);
			ptCID.dispose();
			Sh.ssmStopRing(linkch);
			CHShow.UpdateChState(ch,2,""+(-1));
			CHShow.UpdateChState(ch,3,"Ŀǰ����");
			CHShow.UpdateChState(ch,4,"���йһ�������������ֹ");
			CHShow.UpdateChState(linkch,2,""+(-1));
			CHShow.UpdateChState(linkch,3,"Ŀǰ����");
			CHShow.UpdateChState(linkch,4,"���йһ����������Ϊ"+strCID);
			return false;
		}
	}
	Sh.ssmStopRing(linkch);

	Sh.ssmPickup(ch);
	
	if (Sh.ssmTalkWith(ch,linkch)==-1)
	{
		Sh.ssmHangup(ch);
		cm[ch].setCurrentChState(0);
		cm[ch].setInUse(0);
		cm[ch].setLinkCh(-1);
		cm[linkch].setCurrentChState(4);
		cm[linkch].setInUse(0);
		cm[linkch].setLinkCh(-1);
		ptCID.dispose();
		CHShow.UpdateChState(ch,2,""+(-1));
		CHShow.UpdateChState(ch,3,"Ŀǰ����");
		CHShow.UpdateChState(ch,4,"��������ʧ�ܣ�����������ֹ");
		CHShow.UpdateChState(linkch,2,""+(-1));
		CHShow.UpdateChState(linkch,3,"Ŀǰ����");
		CHShow.UpdateChState(linkch,4,"���йһ����������Ϊ"+strCID);
		return false;
	}
	ptCID.dispose();
	cm[ch].setCurrentChState(3);
	cm[linkch].setCurrentChState(3);
	return true;
}
public int findFreeCh(int flag)throws NativeException,IllegalAccessException//flag��־λ 0:Ѱ�ҿ���ģ��ͨ�� 1:Ѱ�ҿ�����ϯͨ����
{
	if(flag==0)
	{
		for (int i = 0;i<maxch;i++)
		{
			if (cm[i].getChType()==0&&Sh.ssmGetLineVoltage(i)>26)
			{
				cm[i].setInUse(1);
					//cm[i].setLinkCh(i);
				return i;
			}
		}
	}
		else if (flag == 1)
		{
			for (int i = 0;i<cm.length;i++)
			{
				//System.out.println(""+i);
				if (cm[i].getChType()==2&&Sh.ssmGetHookState(i)==0)
				{
					cm[i].setInUse(1);
					//cm[i].setLinkCh(i);
					return i;
				}
			}
		}
		return -1;
	}
	
}
