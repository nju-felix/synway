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
			init.CloseCard();//�����忨
			System.out.println("����ʧ��");
		}
		else System.out.println("�忨�����ɹ�");
		maxch = init.GetMaxCh();
		System.out.println("�忨��ͨ����Ϊ��"+maxch);
		if (maxch<0)
		{
			init.CloseCard();
		}
		//�ж�ͨ������
		ChManager [] cm = new ChManager[maxch];
		for (int i = 0;i<cm.length ;i++ )
		{
			cm[i] = new ChManager();
		}
		init.GetChType(cm,maxch);
		//�����̿�ʼͨ����ѯ
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
