package poop2;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Dialog;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;

public class DialogZaCuvanje extends Dialog{
	Button dugme;
	TextField adresa;
	public DialogZaCuvanje(KlasaGui arg0, String arg1, boolean arg2) {
		super(arg0, arg1, arg2);
		setSize(400, 100);
		dugme = new Button("Sacuvaj");
		adresa = new TextField(20);
		
		// TODO Auto-generated constructor stub
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
			   	dispose();	
			}
		});
		dugme.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String s = adresa.getText();
				Process p2;
				try {
					p2 = Runtime.getRuntime().exec(new String[] {
							"Project84.exe",
							s, "2"});
					p2.waitFor();
				  	dispose();	
				} catch (IOException | InterruptedException e2) {
					// TODO Auto-generated catch block
					e2.printStackTrace();
				}
				
			}
		});
		Panel p = new Panel();
		p.add(dugme , BorderLayout.WEST);
		p.add(adresa , BorderLayout.EAST);
		add(p);
		setVisible(true);
	}
	
}
