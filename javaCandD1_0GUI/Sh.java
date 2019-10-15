//package synway;

import org.xvolks.jnative.JNative;
import org.xvolks.jnative.Type;
import org.xvolks.jnative.exceptions.NativeException;
import org.xvolks.jnative.pointers.Pointer;
import org.xvolks.jnative.pointers.memory.MemoryBlockFactory;
public class Sh 
{
	public static Pointer creatPointer()
		throws NativeException,IllegalAccessException
	{
		Pointer pointer = new Pointer(MemoryBlockFactory.createMemoryBlock(36)); 
		pointer.setIntAt(0, 36); 
		//System.out.println(pointer);
		return pointer; 
	}

	public static final int ssmGetLineVoltage(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetLineVoltage");
				n.setRetVal(Type.INT);
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
				//return n.getRetVal();
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}

	public static final int ssmStartCti(String shconfig,String shindex)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmStartCti");
				n.setRetVal(Type.INT);
				int i = 0;
				n.setParameter(i++,Type.STRING,shconfig);
				n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
				//return n.getRetVal();
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	
	public static final int ssmCloseCti()
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmCloseCti");
				n.setRetVal(Type.INT);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
		
	}
	public static final void ssmGetLastErrMsg(String errMsg)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetLastErrMsg");
				//n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.STRING,errMsg);
				n.invoke();
				//return n.getRetVal();
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		//return Integer.parseInt(n.getRetVal());
		
	}
	public static final int ssmGetMaxCh()
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetMaxCh");
				n.setRetVal(Type.INT);
				//int i = 0;
				//n.setParameter(i++,Type.STRING,shconfig);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
		
	}
	public static final int ssmGetChType(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetChType");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());		
	}
	public static final int ssmAutoDial(int ch,String phNum)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmAutoDial");
				n.setRetVal(Type.INT);
				int i = 0;
				n.setParameter(i++,Type.INT,""+ch);
				n.setParameter(i++,Type.STRING,phNum);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmAppendPhoNum(int ch,String appendPhnum)throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmAppendPhoNum");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,Type.STRING,appendPhnum);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmChkAutoDial(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmChkAutoDial");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmGetChState(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetChState");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmGetPendingReason(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetPendingReason");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmPickup(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmPickup");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmHangup(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmHangup");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmSendTone(int ch,int tonetype)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmSendTone");
				n.setRetVal(Type.INT);
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,Type.INT,""+tonetype);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
		
	}
	public static final int ssmStopSendTone(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetPendingReason");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmChkSendTone(int ch,int tonetype)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		//tonetype = new Pointer(MemoryBlockFactory.creatMemoryBlock(4));
		try
		{
			//tonetype = new Pointer(MemoryBlockFactory.creatMemoryBlock(4));
			n = new JNative("SHP_A3.dll","SsmChkSendTone");
			n.setRetVal(Type.INT);
				//int i = 0;
			n.setParameter(0,Type.INT,""+ch);
			n.setParameter(1,Type.INT,""+tonetype);
			n.invoke();
			//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmGetToneAnalyzeResult(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetToneAnalyzeResult");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmTxDtmf(int ch,String dtmf)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
			//dtmf = new Pointer(MemoryBlockFactory.creatMemoryBlock(50));
				n = new JNative("SHP_A3.dll","SsmTxDtmf");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,Type.STRING,dtmf);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmStopTxDtmf(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmStopTxDtmf");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmChkTxDtmf(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmChkTxDtmf");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				//n.setParameter(i++,Type.STRING,shindex);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmSetPlayDest(int ch,int selDest)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmSetPlayDest");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,Type.INT,""+selDest);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmSetPlayVolume(int ch,int gain)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmSetPlayVolume");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,Type.INT,""+gain);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmGet1stDtmfClr(int ch, Pointer pcDtmf)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGet1stDtmfClr");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,pcDtmf);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmTalkWith(int ch1,int ch2)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmTalkWith");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch1);
				n.setParameter(1,Type.INT,""+ch2);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmStopTalkWith(int ch1,int ch2)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmStopTalkWith");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch1);
				n.setParameter(1,Type.INT,""+ch2);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmGetCallerId(int ch,Pointer ptCID)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetCallerId");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,ptCID);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmStartRingWithCIDStr(int ch,String ptCID,long CIDlen,long delayTime)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmStartRingWithCIDStr");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.setParameter(1,Type.STRING,ptCID);
				n.setParameter(2,Type.LONG,""+CIDlen);
				n.setParameter(3,Type.LONG,""+delayTime);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmGetHookState(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmGetHookState");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmStopRing(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmStopRing");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
	public static final int ssmStartRing(int ch)
		throws NativeException,IllegalAccessException
	{
		JNative n = null;
		try
		{
				n = new JNative("SHP_A3.dll","SsmStartRing");
				n.setRetVal(Type.INT);
				//int i = 0;
				n.setParameter(0,Type.INT,""+ch);
				n.invoke();
				//return Integer.parseInt(n.getRetVal());
		}
		catch (NativeException e) 
		{
			e.printStackTrace();
		} 
		catch (IllegalAccessException e)
		{
			e.printStackTrace();
		}
		return Integer.parseInt(n.getRetVal());
	}
}
