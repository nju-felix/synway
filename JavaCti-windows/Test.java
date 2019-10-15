import  java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Vector;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
import javax.swing.JOptionPane;


public class Test implements ActionListener{
private volatile Thread timer; 
static		
{
	System.loadLibrary("shcti");
}


  JTable table =null;
  DefaultTableModel defaultModel = null;  
	shctiConstants cti ;

public  Test(){
	cti=new  shcti();
	///////////////////////////////////
	int i,j;
	SWIGTYPE_p_int nDierction = shcti.new_intp();
	JFrame f=new JFrame();
	String name[]={"����","״̬","���Ž��"};
	String [][]data=new String [1000][4];
	int value=1;
	int nResult=shcti.SsmStartCti("C:\\ShCti\\ShConfig.ini","C:\\ShCti\\ShIndex.ini");
	//System.out.println(cti.EVENT_POLLING);
	System.out.println(nResult);	
	 int nCol=shcti.SsmGetMaxCh();
	 System.out.println(nCol);
	 for ( i=0;i<nCol ; i++)
	 {
		 switch (shcti.SsmGetChType(i))
			{
			case 0 :
				data[i][0]="ģ��";
				break;
			case 2:
					data[i][0]="��ϯ";
					break;
			case 3:
					data[i][0]="¼��";
					break;
			case 4:
				if(shcti.SsmGetAutoCallDirection(i,nDierction) == 0) data[i][0]="SS1"; 
				else if(shcti.intp_value(nDierction)==0)             data[i][0]="SS1i";  
				else if(shcti.intp_value(nDierction)==1)             data[i][0]="SS1o";  
				else	                                             data[i][0]="SS1io"; 
				break;
			case 6:
				if(shcti.SsmGetAutoCallDirection(i,nDierction) == 0) data[i][0]="SS7"; 
				else if(shcti.intp_value(nDierction)==0)            data[i][0]="TUPi"; 
				else if(shcti.intp_value(nDierction)==1)            data[i][0]="TUPo";
				else if(shcti.intp_value(nDierction)==2)             data[i][0]="TUPio";
				else                                                 data[i][0]="TUP-x";
				break;
			case 7:
					
				if(shcti.SsmGetAutoCallDirection(i,nDierction) == 0) data[i][0]="ISDN";  
				else if(shcti.intp_value(nDierction)==0)             data[i][0]="ISDNi";
				else if(shcti.intp_value(nDierction)==1)             data[i][0]="ISDNo"; 
				else if(shcti.intp_value(nDierction)==2)             data[i][0]="ISDNio";				
				break;

				case 8: 
				if(shcti.SsmGetAutoCallDirection(i,nDierction) == 0) data[i][0]="ISDNNet"; 
				else if(shcti.intp_value(nDierction)==0)             data[i][0]="ISDNNeti"; 
				else if(shcti.intp_value(nDierction)==1)             data[i][0]="ISDNNeto"; 
				else if(shcti.intp_value(nDierction)==2)             data[i][0]="ISDNNetio"; 
				break;
			case 9: break;
			default:
				data[i][0]="-1";  			
				break;
			}

	 }
      for(i=0;i<nCol;i++)
		{
			switch(shcti.SsmGetChState(i))
			{
				case 0:
					data[i][1]="����";
					break;
				case 1:
					data[i][1]="ժ��";
					break;
				case 2:
                    data[i][1]="����";
					break;
				case 3:
					data[i][1]="ͨ��";
				  break;
				case 4:
					data[i][1]="�ȴ�������";
					break;
				case 5:
					data[i][1]="����";
					break;
				case 6:
					data[i][1]="�ȴ����Ž��";
					break;
				case 7:
					data[i][1]="����";
					break;
				case 8:
					data[i][1]="����";
						break;
				case 9:
					data[i][1]="�Ⱥ򱻽�ժ��";
					break;
				default:
					data[i][1]="-1";
				break;




			}
		}

       for(  i=0; i<nCol; i++)
       	{
       	    for( j=2; j<4 ; j++)
       	        data[i][j] = "����";//String.valueOf(value++);
       }
	   	defaultModel = new DefaultTableModel(data,name);
       	table=new JTable(defaultModel);
       	table.setPreferredScrollableViewportSize(new Dimension(400, 80));

		JScrollPane s = new JScrollPane(table);
        
        JPanel panel = new JPanel();
        JButton b = new JButton("SsmPickup");
        panel.add(b);
        b.addActionListener(this);
        b = new JButton("SsmAutoDial");
        panel.add(b);
        b.addActionListener(this);
        b = new JButton("SsmHuangup");
        panel.add(b);
        b.addActionListener(this);
        b = new JButton("Exit");
        panel.add(b);
        b.addActionListener(this);
        
        Container contentPane = f.getContentPane();
        contentPane.add(panel, BorderLayout.NORTH);
        contentPane.add(s, BorderLayout.CENTER);
        
	    f.setTitle("HelloApplet");
        f.pack();
        f.setVisible(true);
        
        f.addWindowListener(new WindowAdapter() 
		{
            public void windowClosing(WindowEvent e)
			{
                System.exit(0);
            }
        });

		

	}

////////////////////////////////////////////////////////////////////

public void actionPerformed(ActionEvent e)
    {
        if(e.getActionCommand().equals("SsmPickup"))
      	shcti.SsmPickup(0);
        if(e.getActionCommand().equals("������"))
            defaultModel.addRow(new Vector());
        if(e.getActionCommand().equals("ɾ����"))
        {
            int columncount = defaultModel.getColumnCount()-1;
            if(columncount >= 0)//��columncount<0�����Ѿ�û���κ����ˡ�
            {
                TableColumnModel columnModel = table.getColumnModel();
                TableColumn tableColumn = columnModel.getColumn(columncount);
                columnModel.removeColumn(tableColumn);
                defaultModel.setColumnCount(columncount);
            }
        }
        if(e.getActionCommand().equals("ɾ����"))
        {
            int rowcount = defaultModel.getRowCount()-1;//getRowCount����������rowcount<0�����Ѿ�û���κ����ˡ�
            if(rowcount >= 0)
            {
                defaultModel.removeRow(rowcount);
                defaultModel.setRowCount(rowcount);//ɾ���бȽϼ򵥣�ֻҪ��DefaultTableModel��removeRow()�������ɡ�ɾ��
                 //����Ϻ������������������Ҳ����ʹ��DefaultTableModel��setRowCount()���������á�
            }
        }
        table.revalidate();
    }


	public static void main(String arg[]){
		//new Test();
		Test test = new Test();
		test.TestUnit();


	}
	public void TestUnit(){
		
		EVENT_SET_INFO  MyEvent= new  EVENT_SET_INFO();
		MyEvent.setDwWorkMode(1);  //1 is Polling  cti.EVENT_POLLING
		MyEvent.setDwUser(0);
		System.out.println("cti.EVENT_POLLING");
		
		if(shcti.SsmSetEvent(-1,-1,1,MyEvent)!=0)
		{
			shcti.SsmCloseCti();
			System.out.println("SsmSetEvent Error");
			return ;
		}

		MyThread mythread=new MyThread(this.table);
		mythread.start();
		InputStreamReader inR = new InputStreamReader(System.in);
		BufferedReader inBuffer = new BufferedReader(inR);
		try{
		String data=inBuffer.readLine();
		System.out.println(data);
		}catch(IOException e){
		}
		shcti.SsmCloseCti();
		System.out.println("Start Cti OK Event Polling Mode");/**/
	}
}

