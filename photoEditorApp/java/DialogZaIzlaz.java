package poop2;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Dialog;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class DialogZaIzlaz extends Dialog{
	Button dugme1 , dugme2;
	public DialogZaIzlaz(KlasaGui arg0, String arg1, boolean arg2) {
		super(arg0, arg1, arg2);
		setSize(400, 100);
		dugme1 = new Button("Da");
		dugme2 = new Button("Ne");
		dugme2.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				DialogZaIzlaz.this.dispose();
			}
		});
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
			   	dispose();	
			}
		});
		dugme1.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				DialogZaCuvanje d =new DialogZaCuvanje(arg0, "Putanja fajla za cuvanje", true);
				DialogZaIzlaz.this.dispose();
			}
		});
		Panel p = new Panel();
		p.add(dugme1 , BorderLayout.WEST);
		p.add(dugme2 , BorderLayout.EAST);
		add(p);
		setVisible(true);
	}
}
