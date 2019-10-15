import org.xvolks.jnative.exceptions.NativeException;

public class CandD 
{
	public static void main(String[] args) throws NativeException,IllegalAccessException
	{
		int maxch = -1;
		Thread current = Thread.currentThread();
		InitStart init = new InitStart();
		if(init.StartCard()!=0)
		{
			init.CloseCard();//启动板卡
			System.out.println("启动失败");
		}
		else System.out.println("板卡启动成功");
		maxch = init.GetMaxCh();
		System.out.println("板卡总通道数为："+maxch);
		if (maxch<0)
		{
			init.CloseCard();
		}
		//判断通道类型
		ChManager [] cm = new ChManager[maxch];
		for (int i = 0;i<cm.length ;i++ )
		{
			cm[i] = new ChManager();
		}
		init.GetChType(cm,maxch);
		//主流程开始通道轮询
		Handle hand = new Handle(cm,maxch);
		new CHShow(cm,maxch);
		while(true)
		{
			hand.chHandle();
			try
			{
				current.sleep(100);
			}
			catch (Exception e)
			{
			}
		}
	}
}
