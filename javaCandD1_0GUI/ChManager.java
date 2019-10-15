public class  ChManager
{
	private int state = -1;
	private int currentChState = -1;
	private int chtype = -1;
	private int linkCh = -1;
	private int inuse = -1;//是否空闲可用的通道 0:可用 1:不可用
	public int chflag = -1;
	public boolean chnowuse = false;
	ChManager()
	{}
	int getState()
	{
		return state;
	}
	void setState(int state)
	{
		this.state = state;
	}
	void setCurrentChState(int currentChState)
	{
		this.currentChState = currentChState;
	}
	int getCurrentChState()
	{
		return currentChState;
	}
	void setChType(int chtype)
	{
		this.chtype = chtype;
	}
	int getChType()
	{
		return chtype;
	}
	void setLinkCh(int ch)
	{
		linkCh = ch;
	}
	int getLinkCh()
	{
		return linkCh;
	}
	void setInUse(int inuse)
	{
		this.inuse = inuse;
	}
	int getInUse()
	{
		return inuse;
	}
}
/*class  MNCH extends ChManager
{
	public int linkZXch = -1;
	MNCH(int state)
	{
		this.state = state;
	}
	void setLinkCh(int ch)
	{
		linkZXch = ch;
	}
	int getLinkCh()
	{
		return linkZXch;
	}
}
class  ZXCH extends ChManager
{
	public int linkMNch = -1;
	ZXCH(int state)
	{
		this.state = state;
	}
	void setLinkCh(int ch)
	{
		linkMNch = ch;
	}
	int getLinkCh()
	{
		return linkMNch;
	}
}*/