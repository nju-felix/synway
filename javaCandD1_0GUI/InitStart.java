import org.xvolks.jnative.exceptions.NativeException;

public class  InitStart
{
	//初始化开始，启动板卡
	public int StartCard()throws NativeException,IllegalAccessException
	{
		int isStartok = -6;
		isStartok = Sh.ssmStartCti("c:\\ShCti\\ShConfig.ini","c:\\ShCti\\ShIndex.ini");

		return isStartok;
	}
	//关闭板卡
	public void CloseCard()throws NativeException,IllegalAccessException
	{
		Sh.ssmCloseCti();
	}
	//启动成功后对通道进行处理
	public int GetMaxCh()throws NativeException,IllegalAccessException
	{
		int maxch = -1;
		maxch = Sh.ssmGetMaxCh();
		return maxch;
	}
	public void GetChType(ChManager [] cm,int maxch)throws NativeException,IllegalAccessException
	{
		for (int i = 0;i<maxch;i++)
		{
			cm[i].setChType(Sh.ssmGetChType(i));
			cm[i].setCurrentChState(Sh.ssmGetChState(i));
			cm[i].setState(Sh.ssmGetChState(i));
			cm[i].chflag = i;
			cm[i].chnowuse = false;
			cm[i].setInUse(0);
		}
	}
}
