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
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class DialogZaUcitavanje  extends Dialog {
	Button dugme;
	TextField adresa;
	public DialogZaUcitavanje(KlasaGui arg0, String arg1, boolean arg2) {
		super(arg0, arg1, arg2);
		setSize(400, 100);
		dugme = new Button("Ucitaj");
		adresa = new TextField(20);
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
							s, "1"});
					int pom = p2.waitFor();
					for ( int i = 0 ; i < pom ; i++)
						arg0.dodajUPrvuListu();
					arg0.citajSelekcije();
					arg0.slika.postaviSliku("kopija.bmp");
					arg0.ucitajSelekcije();
				  	dispose();	
				  	
				} catch (IOException | InterruptedException e2) {}
				try {
					BufferedReader br = new BufferedReader(new FileReader("brojOperacija.txt"));
				    String line = br.readLine();
				    int bro = Integer.parseInt(line);
				    arg0.desniList1.clear();
				    for (int i = 0 ; i< bro ; i++) {
				    	arg0.desniList1.add(String.valueOf(i));
				    }
				    br.close();
				}catch (Exception es) {}
			}
		});
		Panel p = new Panel();
		p.add(dugme , BorderLayout.WEST);
		p.add(adresa , BorderLayout.EAST);
		add(p);
		setVisible(true);
	}
}
