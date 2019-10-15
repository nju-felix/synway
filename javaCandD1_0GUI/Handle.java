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
		{   //仅就座席通道进行操作座席通道就只有摘机和空闲两个状态
			if(i.getChType() ==2)
			{
					switch(i.getCurrentChState())
					{
						case 0:
							if(Sh.ssmGetHookState(i.chflag)==1)
							{
								i.setCurrentChState(1);
								i.setState(1);
								CHShow.UpdateChState(i.chflag,3,"准备外呼");
								CHShow.UpdateChState(i.chflag,4,"摘机");
							}
							break;
						case 1://摘机转入拨号流程
							if(i.getInUse()==0)
								if(!dialHandle(i.chflag))
								i.setCurrentChState(4);
							break;
						case 2://处理回铃
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
							//System.out.println("进入通话状态2");
							}
							break;
						case 3://处理通话
							//System.out.println("进入通话处理状态");
							if(Sh.ssmGetHookState(i.chflag)==0)
							{
								//System.out.println(""+Sh.ssmGetChState(i.chflag));
								Sh.ssmStopTalkWith(i.chflag,i.getLinkCh());
								Sh.ssmHangup(i.getLinkCh());
								temp = i.getLinkCh();
								cm[temp].setCurrentChState(0);
								cm[temp].setInUse(0);
								CHShow.UpdateChState(temp,2,""+(-1));
								CHShow.UpdateChState(temp,3,"目前空闲");
								CHShow.UpdateChState(temp,4,"等待呼入或者呼出");
								temp = -1;
								i.setInUse(0);
								i.setCurrentChState(0);
								Sh.ssmStopRing(i.chflag);
								CHShow.UpdateChState(i.chflag,2,""+(-1));
								CHShow.UpdateChState(i.chflag,3,"目前空闲");
								CHShow.UpdateChState(i.chflag,4,"等待呼入或者呼出");
								//System.out.println("你挂机了，通话结束");
								//System.out.println("可以摘机继续拨打");
							}
							else if (Sh.ssmGetToneAnalyzeResult(i.getLinkCh())==2)//被叫先挂机
							{
								Sh.ssmStopTalkWith(i.chflag,i.getLinkCh());
								Sh.ssmHangup(i.getLinkCh());
								temp = i.getLinkCh();
								cm[temp].setCurrentChState(0);
								cm[temp].setInUse(0);
								CHShow.UpdateChState(temp,2,""+(-1));
								CHShow.UpdateChState(temp,3,"目前空闲");
								CHShow.UpdateChState(temp,4,"等待呼入或者呼出");
								temp = -1;
								Sh.ssmSendTone(i.chflag,1);
								CHShow.UpdateChState(i.chflag,2,""+(-1));
								i.setCurrentChState(4);
								System.out.println("被叫挂机，请挂机");
							}
							break;
						case 4://等待座席挂机
							if(Sh.ssmGetHookState(i.chflag)==0)
							{
								Sh.ssmStopRing(i.chflag);
								Sh.ssmStopSendTone(i.chflag);
								i.setCurrentChState(0);
								i.setInUse(0);
								i.setLinkCh(-1);
								CHShow.UpdateChState(i.chflag,3,"目前空闲");
								CHShow.UpdateChState(i.chflag,4,"等待呼入或者呼出");
								//System.out.println("呼出结束");
								//System.out.println("可以摘机继续拨打");
							}
							break;

						default:break;
					}
			}
			//仅就模拟通道进行操作
			if (i.getChType() == 0)
			{
				switch(i.getCurrentChState())
				{
					case 0:
						if (Sh.ssmGetChState(i.chflag)==2&&i.getInUse()==0)
						{
							CHShow.UpdateChState(i.chflag,3,"电话呼入");
							CHShow.UpdateChState(i.chflag,4,"处理呼入。。。");
							i.setInUse(1);
							i.setCurrentChState(2);
							//System.out.println("jfklajdla");
						}
						break;
					case 1:break;//摘机
					case 2://振铃转入call流程
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
public boolean dialHandle(int ch)throws NativeException,IllegalAccessException//收号，寻找空闲模拟通道呼出。
{
		int linkch = findFreeCh(0);
		//System.out.println(""+linkch);
		if (linkch == -1)
		{
			Sh.ssmSendTone(ch,1);
			cm[ch].setCurrentChState(4);
			CHShow.UpdateChState(ch,4,"未找到空闲模拟通道，请挂机");
			return false;
		}
		else 
		{
			Sh.ssmSendTone(ch,0);
			cm[linkch].setCurrentChState(1);//设置外线通道当前状态为摘机状态。
			CHShow.UpdateChState(ch,2,""+linkch);
			CHShow.UpdateChState(linkch,2,""+ch);
		}
		//System.out.println("找到空闲的模拟通道"+linkch);
		cm[ch].setLinkCh(linkch);
		cm[linkch].setLinkCh(ch);
		cm[ch].setInUse(1);
		cm[linkch].setInUse(1);
		Pointer ptPhnum = Sh.creatPointer();
		ptPhnum.setStringAt(0,"a");
		String strPhnum = ptPhnum.getAsString();
		int temp = -1;
		Sh.ssmPickup(linkch);
		CHShow.UpdateChState(linkch,3,"准备外呼");
		CHShow.UpdateChState(linkch,4,"正在分析拨号音");
		//信号音分析正在进行
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
				CHShow.UpdateChState(linkch,4,"分析拨号音失败，主叫挂机");
				CHShow.UpdateChState(linkch,3,"目前空闲");
				CHShow.UpdateChState(ch,2,""+(-1));
				CHShow.UpdateChState(linkch,2,""+(-1));
				CHShow.UpdateChState(ch,3,"目前空闲");
				CHShow.UpdateChState(ch,4,"等待呼入或者呼出");
				return false;
			}
		}
		//有拨号音
		if (Sh.ssmGetToneAnalyzeResult(linkch)!=1)
		{	
			Sh.ssmSendTone(ch,1);
			Sh.ssmHangup(linkch);
			cm[ch].setCurrentChState(4);
			cm[linkch].setCurrentChState(0);
			cm[linkch].setInUse(0);
			cm[linkch].setLinkCh(-1);
			CHShow.UpdateChState(linkch,4,"分析拨号音失败，未知声音");
			CHShow.UpdateChState(ch,2,""+(-1));
			CHShow.UpdateChState(linkch,2,""+(-1));
			CHShow.UpdateChState(linkch,3,"目前空闲");
			return false;
		}
				
		else cm[linkch].setCurrentChState(5);//等待拨号状态
		CHShow.UpdateChState(ch,4,"请拨号。。。");
		CHShow.UpdateChState(linkch,4,"准备拨号");
		//System.out.println("请拨号");
		//收号操作(收取第一个号码)
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
				CHShow.UpdateChState(linkch,4,"拨号失败");
				CHShow.UpdateChState(linkch,3,"目前空闲");
				CHShow.UpdateChState(ch,2,""+(-1));
				CHShow.UpdateChState(linkch,2,""+(-1));
				ptPhnum.dispose();
				return false;
			}
		}
		while (temp!=1);
			//Sh.ssmGet1stDtmfClr(ch,ptPhnum);
			//strPhnum = ptPhnum.getAsString();
		CHShow.UpdateChState(ch,4,"你所拨打的号码是:"+strPhnum);
		CHShow.UpdateChState(linkch,4,"拨号中。。。等待追加号码");
		//System.out.print("你所拨打的号码是:"+strPhnum);
		Sh.ssmAutoDial(linkch,strPhnum);
			//收取剩余号码
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
				CHShow.UpdateChState(linkch,4,"拨号失败");
				CHShow.UpdateChState(linkch,3,"目前空闲");
				CHShow.UpdateChState(ch,2,""+(-1));
				CHShow.UpdateChState(linkch,2,""+(-1));
				return false;
			}
		}
			//System.out.println("\n");
		
		cm[ch].setCurrentChState(2);
		//System.out.println("进入通话状态");
		CHShow.UpdateChState(linkch,4,"进入通话状态");
		ptPhnum.dispose();
		return true;
		/*while(Sh.ssmChkAutoDial(linkch) != 2||Sh.ssmChkAutoDial(linkch) != 7)
		{
			if (Sh.ssmChkAutoDial(linkch) == 2)
			{
				cm[linkch].setCurrentChState(9);
				cm[ch].setCurrentChState(2);
				System.out.println("进入通话状态");
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
public boolean callHandle(int ch)throws NativeException,IllegalAccessException//传入模拟通道
{
	int linkch = findFreeCh(1);
	//System.out.println("找到空闲的座席通道"+linkch);
	if (linkch==-1)
	{
		CHShow.UpdateChState(ch,4,"未找到空闲座席通道");
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
		CHShow.UpdateChState(ch,3,"目前空闲");
		CHShow.UpdateChState(ch,4,"等待呼入或者呼出");
		return false;
	}
	CHShow.UpdateChState(ch,2,""+linkch);
	CHShow.UpdateChState(linkch,2,""+ch);
	cm[ch].setLinkCh(linkch);
	cm[linkch].setLinkCh(ch);
	cm[ch].setInUse(1);
	cm[linkch].setInUse(1);
	int CIDlen = -2;
	//System.out.println("找到空闲的座席通道"+linkch);
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
		CHShow.UpdateChState(linkch,4,"等待座席摘机");
		CHShow.UpdateChState(ch,4,"未知来电,正在提醒座席");
		//System.out.println("未知来电");
	}
	else
	{
		CHShow.UpdateChState(ch,4,"主叫号码"+strCID+"来电");
		CHShow.UpdateChState(linkch,4,"等待座席摘机");
		//System.out.println("主叫号码"+strCID+"来电");
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
			CHShow.UpdateChState(ch,3,"目前空闲");
			CHShow.UpdateChState(ch,4,"主叫挂机，呼入流程终止");
			CHShow.UpdateChState(linkch,2,""+(-1));
			CHShow.UpdateChState(linkch,3,"目前空闲");
			CHShow.UpdateChState(linkch,4,"主叫挂机，来电号码为"+strCID);
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
		CHShow.UpdateChState(ch,3,"目前空闲");
		CHShow.UpdateChState(ch,4,"总线连接失败，呼入流程终止");
		CHShow.UpdateChState(linkch,2,""+(-1));
		CHShow.UpdateChState(linkch,3,"目前空闲");
		CHShow.UpdateChState(linkch,4,"主叫挂机，来电号码为"+strCID);
		return false;
	}
	ptCID.dispose();
	cm[ch].setCurrentChState(3);
	cm[linkch].setCurrentChState(3);
	return true;
}
public int findFreeCh(int flag)throws NativeException,IllegalAccessException//flag标志位 0:寻找空闲模拟通道 1:寻找空闲座席通道。
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
