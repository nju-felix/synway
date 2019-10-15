import javax.swing.table.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Vector;
import javax.swing.*;
import javax.swing.event.*;

public class  MyThread extends Thread{
	MESSAGE_INFO  msg= new MESSAGE_INFO();
	Dump    dump=  new  Dump();
	JTable table =null;
	public  MyThread(JTable table)
	{
        this.table=table;

	}
		
	public void run(){
		
		while(true){
			
			if(shcti.SsmGetEvent(msg)==-1)//
			{
				
				/*
				try{
					Thread.sleep(10);
				}catch(InterruptedException e) {
					System.out.println(e);
				}
				*/

				
			}else{
			
			dump.out(msg,table);
			}

		
		}

	}
	
}

class  Dump{
	public void out(MESSAGE_INFO msg,JTable table){
		
		//table.setValueAt("11",0,0);
		//fireTableCellUpdated(0,0);
		int param=(int)msg.getDwParam();
		short old,now;
		System.out.print("Ch=");
		System.out.print(msg.getNReference());
		System.out.print("  EventCode=");
		System.out.print(msg.getWEventCode());
		old=(short)(param >>16);
		now=(short)param ;
		System.out.println("old state=" + old +"new state=" + now);


	}
}

