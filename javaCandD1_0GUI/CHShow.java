import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;

class CHShow extends JFrame
{
	public static ChManager []cm = null;
	int maxch = -1;
	public static JTable table=null;
	CHShow(ChManager []cm,int maxch)
	{
		setTitle("Java呼入呼出demo");
		this.cm = cm;
		this.maxch = maxch;
		Object[][]a;
		Object[]name = {"通道号","类型","对接通道","通话模式","通道状态"};
		a = new Object[maxch][5];
		DefaultTableModel model = new DefaultTableModel(a,name)
		{
			public boolean isCellEditable(int row,int column)
			{
				return false;
			}
		};
		table = new JTable(model);

		TableColumn firstColumn = table.getColumnModel().getColumn(0);
		firstColumn.setPreferredWidth(40);
		firstColumn.setMaxWidth(40);
		firstColumn.setMinWidth(40);

		TableColumn secondColumn = table.getColumnModel().getColumn(1);
		secondColumn.setPreferredWidth(40);
		secondColumn.setMaxWidth(40);
		secondColumn.setMinWidth(40);

		TableColumn thirdColumn = table.getColumnModel().getColumn(2);
		thirdColumn.setPreferredWidth(60);
		thirdColumn.setMaxWidth(60);
		thirdColumn.setMinWidth(60);

		TableColumn forthColumn = table.getColumnModel().getColumn(3);
		forthColumn.setPreferredWidth(60);
		forthColumn.setMaxWidth(60);
		forthColumn.setMinWidth(60);

		/*TableColumn fifthColumn = table.getColumnModel().getColumn(4);
		fifthColumn.setPreferredWidth(40);
		fifthColumn.setMaxWidth(40);
		fifthColumn.setMinWidth(40);*/
		//DefaultTableCellRenderer  renderer = (DefaultTableCellRenderer) table.getTableHeader().getDefaultRenderer();
		//renderer.setHorizontalAlignment(renderer.CENTER/*javax.swing.SwingConstants.CENTER*/);
		//table.setDefaultRenderer(Object.class,renderer);

		table.getTableHeader().setReorderingAllowed(false); 
		add(new JScrollPane(table));
		setSize(550,300);
		setVisible(true);
		validate();
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		for(int i=0;i<maxch;i++)
		{
			table.setValueAt(i,i,0);
			table.setValueAt(cm[i].getLinkCh(),i,2);
			table.setValueAt("目前空闲",i,3);
			table.setValueAt("等待呼入或者呼出",i,4);
			if(cm[i].getChType() == 0)
			{
				table.setValueAt("模拟",i,1);
			}
			else if (cm[i].getChType() == 2)
			{
				table.setValueAt("座席",i,1);
			}
		}
	}
	public static void UpdateChState(int row,int column,String str)
	{
		if (cm[row].getChType() == 0)//模拟通道动作
		{
			switch (column)
			{
				case 2:
					table.setValueAt(str,row,column);
					break;
				case 3:
					table.setValueAt(str,row,column);
					break;
				case 4:
					table.setValueAt(str,row,column);
					break;
				default:break;		
			}
		}
		else if (cm[row].getChType() == 2)//座席通道动作
		{
			switch (column)
			{
				case 2:
					table.setValueAt(str,row,column);
					break;
				case 3:
					table.setValueAt(str,row,column);
					break;
				case 4:
					table.setValueAt(str,row,column);
					break;
				default:break;		
			}
		}
		
	}
	public static String GetTableChState(int row,int column)
	{
		return (String)table.getValueAt(row,column);
	}
}
