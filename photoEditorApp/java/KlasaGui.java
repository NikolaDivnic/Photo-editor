package poop2;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.LinkedList;
import java.util.Stack;
import java.awt.*;

public class KlasaGui	extends Frame {
	Slika slika ;
	int brojSlojeva;
	boolean flegZaIzlaz;
	List listaSlojeva;
	List l2;
	List sedmiList , sedmiList2;
	TextField tfp72;
	TextField desniTf17;
	boolean stanje;
	int brojOperacija = -1;
	Stack<Integer> stek;
	TextField desniTfBoja;
	TextField desniTfKonstanta;
	List desniList1;
	int brojUkupnoOperacija = 0;
	TextField desniTf18 ;
	private ArrayList<Pravougaonik>pravougaonici;
	
	LinkedList<Selekcija>selekcije;
	public void ucitajSelekcije() {
		try {
			BufferedReader br = new BufferedReader(new FileReader("selekcijeZaJavu.txt"));
			String line = br.readLine();
			if (!(line.equals("nema"))) {
				int brojSelekcija = Integer.parseInt(line);
				for (int i = 0  ; i  <brojSelekcija ; i++)
				{
					String ime =  br.readLine();
					String a = br.readLine();
					int akt = Integer.parseInt(a);
					boolean fl ;
					if (akt == 1) {
						fl = true;
					}
					else 
					{
						fl = false;
					}
					ArrayList<Pravougaonik> pom = new ArrayList<Pravougaonik>();
					line = br.readLine();
					int brojPravougaonika = Integer.parseInt(line);
					for (int j = 0 ;j< brojPravougaonika ;j++) {
						line = br.readLine();
						int visina = Integer.parseInt(line);
						line = br.readLine();
						int sirina = Integer.parseInt(line);
						line = br.readLine();
						int gore = Integer.parseInt(line);
						line = br.readLine();
						int levo = Integer.parseInt(line);
						pom.add(new Pravougaonik(levo, gore, levo + sirina, gore+visina));
					}
					selekcije.add(new Selekcija(pom, ime, fl));
				}
				
			}
			br.close();
		} catch (NumberFormatException e) {
		} catch (FileNotFoundException e) {
		} catch (IOException e) {
		}
	}
	public void citajSelekcije() {
		sedmiList.removeAll();
		sedmiList2.removeAll();
		try {
			BufferedReader br = new BufferedReader(new FileReader("selekcijeSve.txt"));
		    String line = br.readLine();
		   while (line != null) {
			   sedmiList.add(line);
		        line = br.readLine();
		    }
		   br.close();
		}catch (Exception e) {}
		try {
			BufferedReader br = new BufferedReader(new FileReader("selekcijeAktivne.txt"));
		    String line = br.readLine();
		   while (line != null) {
			   sedmiList2.add(line);
		        line = br.readLine();
		    }
		   br.close();
		}catch (Exception e) {}
		flegZaIzlaz = true;
	}
	
	private void naprvaviSlozenuOperaciju() {
		try {
			if (!(desniTf17.getText().contentEquals("")) ){
			PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("operacija.txt", true)));
			writer.write("<slozenaOperacija>\n");
			writer.write("<brojOperacija>" + desniTf17.getText() + "</brojOperacija>1\n");  
			if (--brojOperacija>=0) {
				if (brojOperacija == 0)stek.push(-2);
				else stek.push(brojOperacija);
			}

			brojOperacija = Integer.parseInt(desniTf17.getText());

			desniTf17.setText("");
			writer.close();
			}
		} catch (IOException e) {}
		flegZaIzlaz = true;
	}
	private void napraviOsnovnuOperaciju() {
		try {

			if (brojOperacija>0 ) {
				PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("operacija.txt", true)));
				writer.write("<osnovnaOperacija>\n");
				writer.write("\t<operacija>" + desniTf18.getText() + "</operacija>1\n"+  "\t<boja>" 
				+ desniTfBoja.getText()+"</boja>1\n"+
						 "\t<konstanta>"+ desniTfKonstanta.getText()+"</konstanta>1\n");  
				writer.write("</osnovnaOperacija>\n");
				desniTf18.setText("");
				desniTfBoja.setText("");
				desniTfKonstanta.setText("");
				brojOperacija--;

				if (brojOperacija == 0) {
					Object o = null;
					try {

						int pom;
						do {
							writer.write("</slozenaOperacija>\n");
							brojOperacija = stek.pop();
						}while(brojOperacija == -2);

						writer.close();
					} catch (EmptyStackException e) {
							writer.close();
							try {
								Process p2 = Runtime.getRuntime().exec(new String[] {
										"Project84.exe",
										"aaaa" , "19" ,"operacija.txt"});
								p2.waitFor();
							} catch (InterruptedException e1) {}
						
							try {
								BufferedReader br = new BufferedReader(new FileReader("brojOperacija.txt"));
							    String line = br.readLine();
							    int bro = Integer.parseInt(line);
							    desniList1.clear();
							    for (int i = 0 ; i< bro ; i++) {
							    	desniList1.add(String.valueOf(i));
							    }
							    br.close();
							}catch (Exception es) {}
							Writer wr = new BufferedWriter(new OutputStreamWriter
									(new FileOutputStream("operacija.txt"), "utf-8")) ;
							wr.close();	
					}		
				}	else {
					writer.close();
				}	
			}
		} catch (IOException e) {}
		flegZaIzlaz = true;
	}
	private void napraviSelekciju() {
		try {
			selekcije.add(new Selekcija(pravougaonici , tfp72.getText() , true));
			
			Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("selekcija.txt"), "utf-8")) ;
			writer.write("<selekcija>\n");
			writer.write("\t<ime>" + tfp72.getText() + "</ime>1"+"\n"  
			+"\t" + "<aktivnost>"  + 1 + "</aktivnost>1" + "\n" +
			"\t<brojPravougaonika>" + pravougaonici.size() + "</brojPravougaonik>1\n");
			for ( int i = 0 ; i < pravougaonici.size() ; i++) {
				writer.write( "\t<pravougaonik>\n" + "\t\t<visina>" + 
			(pravougaonici.get(i).getYy() - pravougaonici.get(i).getY()) +"</visina>1\n"
				+"\t\t<sirina>" + (pravougaonici.get(i).getXx() - pravougaonici.get(i).getX()) + "</sirina>1\n"
				+"\t\t<gore>" + pravougaonici.get(i).getY() + "</gore>1\n"
				+"\t\t<levo>" +pravougaonici.get(i).getX() + "</levo>1\n" + "\t</pravougaonik>\n") ;
			}
			writer.write("</selekcija>\n");
			writer.close();
			pravougaonici.clear();
			
			tfp72.setText("");
			Process p2 = Runtime.getRuntime().exec(new String[] {
					"Project84.exe",
					"aaaa" , "14" });
			int pom = p2.waitFor();
			citajSelekcije();
		} catch (IOException | InterruptedException e) {}
		flegZaIzlaz = true;
	}
	public void  dodajUPrvuListu() {
		listaSlojeva.add(String.valueOf(brojSlojeva));
		l2.add(String.valueOf(brojSlojeva));
		brojSlojeva++;
		flegZaIzlaz = true;
	}
	public boolean dohvatiStanje() {
		return stanje;
	}
	public void napraviPravougaonik(int x , int y , int xx, int yy) {
		if(x>xx) {
			int pom = x;
			x = xx;
			xx = pom;
		}
		if (y>yy) {
			int pom = y;
			y = yy;
			yy = y;
		}
		Pravougaonik p = new Pravougaonik(x, y, xx, yy);
		pravougaonici.add(p);
		flegZaIzlaz = true;
	}
	
	public KlasaGui() {
		super("Paint");
		setSize(900,500);
		brojSlojeva = 0;
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				if (flegZaIzlaz) {
					DialogZaIzlaz d =new DialogZaIzlaz(KlasaGui.this, "Da li zelite da sacuvate promene?", true);
				}
			   	dispose();	
			}
		});
		Writer wr;
		try {
			wr = new BufferedWriter(new OutputStreamWriter
					(new FileOutputStream("operacija.txt"), "utf-8"));
			try {
				wr.close();
			} catch (IOException e1) {}
		} catch (UnsupportedEncodingException e1) {
		} catch (FileNotFoundException e1) {}
		stek = new Stack<Integer>();
		pravougaonici = new ArrayList<Pravougaonik>();
		selekcije = new LinkedList<Selekcija>();
		stanje = false;
		Panel pan = new Panel(new BorderLayout());	
		Panel levi = new Panel(new GridLayout(0,1));
		Label l1 = new Label("Slojevi");
		Panel prviRed = new Panel(new GridLayout(1,2));
		prviRed.add(l1);
		listaSlojeva = new List();
		prviRed.add(listaSlojeva);
		Panel prviDrugi = new Panel(new GridLayout(1,2));
		Label prviRedL2 = new Label("Aktivan");
		prviDrugi.add(prviRedL2);
		l2= new List();
		prviDrugi.add(l2);
	
		Panel drugiRed = new Panel(new GridLayout(1,3));
		Button dodajSloj = new Button("Dodaj");
		Label drugiRedLabela  = new Label("Adresa");
		TextField drugiTf = new TextField();
		drugiRed.add(dodajSloj);
		drugiRed.add(drugiRedLabela);
		drugiRed.add(drugiTf);
		Panel treciRed = new Panel(new GridLayout(1,2));
		Label treciRedLabela1  = new Label("X");
		Label treciRedLabela2  = new Label("Y");
		TextField treciTf1 = new TextField();
		TextField treciTf2 = new TextField();
		treciRed.add(treciRedLabela1);
		treciRed.add(treciTf1);
		Panel treciCetvrti = new Panel(new GridLayout(1,2));
		treciCetvrti.add(treciRedLabela2);
		treciCetvrti.add(treciTf2);	
		
		dodajSloj.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String s = drugiTf.getText();
				Process p2;
				if (s != "") {
				try {
						p2 = Runtime.getRuntime().exec(new String[] {
								"Project84.exe",
								s, "3" , treciTf1.getText() , treciTf2.getText() , "100"});
						int pom = p2.waitFor();
						treciTf1.setText("");
						treciTf2.setText("");
						drugiTf.setText("");
						citajSelekcije();
						for ( int i = 0 ; i < pom ; i++)
							KlasaGui.this.dodajUPrvuListu();
						KlasaGui.this.slika.postaviSliku("Kopija.bmp");
						KlasaGui.this.slika.repaint();
				} catch (IOException | InterruptedException e2) {}
				KlasaGui.this.flegZaIzlaz = true;
				}
			}
		});

		Panel cetvrtiRed = new Panel(new GridLayout(1,6));
		Button cetvrtiDugme = new Button("Aktivnost");
		TextField cetvrtiTf = new TextField();
		cetvrtiRed.add(cetvrtiDugme);
		cetvrtiRed.add(cetvrtiTf);
		
		cetvrtiDugme.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				Process p2;
				if (listaSlojeva.getSelectedItem()!= "" && listaSlojeva.getSelectedItem()!=null){
					try {
							p2 = Runtime.getRuntime().exec(new String[] {
									"Project84.exe",
									"aaa", "7" ,"1", listaSlojeva.getSelectedItem() , cetvrtiTf.getText()});
							p2.waitFor();
							l2.clear();
							BufferedReader br = new BufferedReader(new FileReader("aktivna.txt"));
							try {
								int i = 0;
							    String line = br.readLine();
							    int pom = Integer.parseInt(line);
							    if(pom == 1) {
							    	l2.add(String.valueOf(i));
							    }
							   while (line != null) {
							    	i++;
							        line = br.readLine();
							        if (line == null) {
							        	break ;
							        }
							        pom = Integer.parseInt(line);
							        if(pom == 1) {
								    	l2.add(String.valueOf(i));
							        }  
							    }
							 
							} finally { br.close();}
							cetvrtiTf.setText("");
							KlasaGui.this.slika.repaint();
					} catch (IOException | InterruptedException e2) {}
				}
				KlasaGui.this.flegZaIzlaz = true;
			}
		});

		
		Panel petiRed = new Panel(new GridLayout(1,2));
		Button petiDugme = new Button("Vidljivost");
		TextField petiTf = new TextField();
		petiRed.add(petiDugme);
		petiRed.add(petiTf);

		petiDugme.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				Process p2;
				if (listaSlojeva.getSelectedItem()!= "" && listaSlojeva.getSelectedItem()!=null){
					try {
							p2 = Runtime.getRuntime().exec(new String[] {
									"Project84.exe",
									"aa", "7" ,"2", listaSlojeva.getSelectedItem() , petiTf.getText()});
							p2.waitFor();			
							petiTf.setText("");
							KlasaGui.this.slika.repaint();
					} catch (IOException | InterruptedException e2) {}
				}
				KlasaGui.this.flegZaIzlaz = true;
			}
		});

		Panel sestiRed = new Panel(new GridLayout(1,2));
		Button sestiDugme = new Button("Prozirnost");
		TextField sestiTf = new TextField();
		sestiRed.add(sestiDugme);
		sestiRed.add(sestiTf);
		
		sestiDugme.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				Process p2;
				
				if (listaSlojeva.getSelectedItem()!= "" && listaSlojeva.getSelectedItem()!=null){
					try {
							p2 = Runtime.getRuntime().exec(new String[] {
									"Project84.exe",
									"aaaaa", "7" ,"0", listaSlojeva.getSelectedItem() , sestiTf.getText()});
							p2.waitFor();			
							sestiTf.setText("");
							KlasaGui.this.slika.repaint();
					} catch (IOException | InterruptedException e2) {}
				}
				else {
				}
				KlasaGui.this.flegZaIzlaz = true;
			}
		});
		Panel sedmiRed = new Panel(new GridLayout(1,2));
		Label sedmiL1 = new Label("Selekcije");
		Label sedmiL2 = new Label("Aktivne");
		sedmiList = new List();
		sedmiList2 = new List();
		sedmiList.addItemListener(new ItemListener() {	
			@Override
			public void itemStateChanged(ItemEvent e) {
				KlasaGui.this.slika.repaint();
			}
		});

		sedmiRed.add(sedmiL1);
		sedmiRed.add(sedmiList);
		Panel sedmiOsmi = new Panel(new GridLayout(1,2));
		sedmiOsmi.add(sedmiL2);
		sedmiOsmi.add(sedmiList2);
			
		Panel posleSedmog = new Panel(new GridLayout(1,2));
		Checkbox rb = new Checkbox("Stanje");
		rb.addItemListener(new ItemListener() {	
			@Override
			public void itemStateChanged(ItemEvent e) {
				if (stanje == true && pravougaonici.size()>0) {
					napraviSelekciju();
				}
				else {
					tfp72.setText("");
				}
				KlasaGui.this.stanje=!KlasaGui.this.stanje;
				
			}
		});

		posleSedmog.add(rb);
		Panel posleSedmog2 = new Panel(new GridLayout(1,2));
		Label lp72= new Label("Ime");
		tfp72 = new TextField();
		posleSedmog2.add(lp72);
		posleSedmog2.add(tfp72);
		
		Panel dvanestiRed = new Panel(new GridLayout(1,2));
		Button dvanestiDugme = new Button("Aktivnost");
		TextField dvanestiTf = new TextField();
		dvanestiRed.add(dvanestiDugme);
		dvanestiRed.add(dvanestiTf);
		
		Button trinestiDugme = new Button("Obrisi");
		posleSedmog.add(trinestiDugme);
		trinestiDugme.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				Process p2;
					try {
							for (int i = 0 ; i < selekcije.size() ; i++) {
								if (!(selekcije.get(i).dohvIme() == tfp72.getText())) {
									selekcije.remove(i);
									break;
								}
							}
							
							p2 = Runtime.getRuntime().exec(new String[] {
									"Project84.exe",
									"aaa", "13" ,tfp72.getText()});
							p2.waitFor();
							citajSelekcije();
							tfp72.setText("");
					} catch (IOException | InterruptedException e2) {}
					KlasaGui.this.flegZaIzlaz = true;
			}
		});
		dvanestiDugme.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				if (dvanestiTf.getText() != "") {
					Process p2;
					try {
							p2 = Runtime.getRuntime().exec(new String[] {
									"Project84.exe",
									"aaa", "10" ,tfp72.getText(), dvanestiTf.getText()});
							p2.waitFor();
							citajSelekcije();
							tfp72.setText("");
							dvanestiTf.setText("");
					} catch (IOException | InterruptedException e2) {}
				}
				KlasaGui.this.flegZaIzlaz = true;
			}
		});
		Panel trinestiRed = new Panel();
		Button trinestiL = new Button("Oboji selekciju");
		
		trinestiRed.add(trinestiL);
		Panel cetrnestiRed = new Panel(new GridLayout(1,6));
		Label cetrnestiL1 = new Label("R");
		Label cetrnestiL2 = new Label("G");
		Label cetrnestiL3 = new Label("B");
		TextField cetrnestiTf1 = new TextField();
		TextField cetrnestiTf2 = new TextField();
		TextField cetrnestiTf3 = new TextField();
		cetrnestiRed.add(cetrnestiL1);
		cetrnestiRed.add(cetrnestiL2);
		cetrnestiRed.add(cetrnestiL3);
		Panel red1415 = new Panel(new GridLayout(1,3));
		red1415.add(cetrnestiTf1);
		red1415.add(cetrnestiTf2);
		red1415.add(cetrnestiTf3);	
		
		trinestiL.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if (dvanestiTf.getText() != "" && cetrnestiTf1.getText() != "" && 
						cetrnestiTf2.getText() != "" && cetrnestiTf3.getText() != "") {
					Process p2;
					try {
							p2 = Runtime.getRuntime().exec(new String[] {
									"Project84.exe",
									"aaa", "12" ,tfp72.getText(),cetrnestiTf1.getText(),cetrnestiTf2.getText(),cetrnestiTf3.getText() });
							p2.waitFor();
							citajSelekcije();
							tfp72.setText("");
							cetrnestiTf1.setText("");
							cetrnestiTf2.setText("");
							cetrnestiTf3.setText("");
							KlasaGui.this.slika.repaint();

					} catch (IOException | InterruptedException e2) {}
				}
				KlasaGui.this.flegZaIzlaz = true;
			}
		});
		Panel desni = new  Panel(new GridLayout(0,1));
		
		Panel desniPrviRed = new Panel(new GridLayout(1,2));
		Label desniL1 = new Label("Operacije");
		desniList1 = new List();
		desniPrviRed.add(desniL1);
		desniPrviRed.add(desniList1);
		
		Label desniL2 = new Label("0 sabiranje sa konstantom");
		Label desniL3 = new Label("1 oduzimanje sa konstantom");
		Label desniL4 = new Label("2 inverzno oduzimanje");
		Label desniL5 = new Label("3 mnozenje konstantom");
		Label desniL6 = new Label("4 deljnje konstantom");
		Label desniL7 = new Label("5 inverzno deljenje");
		Label desniL8 = new Label("6 stepenovanje(power)");
		Label desniL9 = new Label("7 logaritmovanje");
		Label desniL10 = new Label("8 apsolutna vrednostn");
		Label desniL11 = new Label("9 minimum");
		Label desniL12 = new Label("10 maksimum");
		Label desniL13 = new Label("11 negacija boje");
		Label desniL14 = new Label("12 pretvaranje u sivu");
		Label desniL15 = new Label("13 pretvaranje u crno-belu");
		Label desniL16 = new Label("14 medijana");
		Panel desniSedamnestiRed = new Panel(new GridLayout(1,3));
		Label desniL17=  new Label ("Kompozitna");
		Button desniDugme17 = new Button("Dodaj");
		Label desniL18 = new Label("Broj");
		desniTf17 = new TextField();
		desniSedamnestiRed.add(desniL17);
		desniSedamnestiRed.add(desniDugme17);
		Panel desni1718 = new Panel(new GridLayout(1,2));
		desni1718.add(desniL18);
		desni1718.add(desniTf17);
		
		Panel desni18  = new Panel(new GridLayout(1,2));
		Label desniL19 = new Label("Osnovna");
		Button desniDugme19 = new Button("Dodaj");
		Label desniL20 = new Label("Redni broj");
		desniTf18 = new TextField();
		
		desni18.add(desniL19);
		desni18.add(desniDugme19);
		Panel desni1819 = new Panel(new GridLayout(1,2));
		desni1819.add(desniL20);
		desni1819.add(desniTf18);
		
		Panel desni20  = new Panel(new GridLayout(1,2));
		Label desniBoja = new Label("Boja");
		desniTfBoja = new TextField();
		desni20.add(desniBoja);
		desni20.add(desniTfBoja);
		Panel desni21  = new Panel(new GridLayout(1,2));
		Label desniKonstanta = new Label("Konstanta");
		desniTfKonstanta = new TextField();
		desni21.add(desniKonstanta);
		desni21.add(desniTfKonstanta);
		
		desniDugme17.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
					naprvaviSlozenuOperaciju();
					KlasaGui.this.flegZaIzlaz = true;
				}
		});
		desniDugme19.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
					napraviOsnovnuOperaciju();
					KlasaGui.this.flegZaIzlaz = true;
				}
			
		});
		Button dugmeOperacije = new Button("Pokreni");
		Panel desniOperSac  = new Panel(new GridLayout(1,2));
		Button dugmeSacuvaj = new Button("Sacuvaj");
		desniOperSac.add(dugmeOperacije);
		desniOperSac.add(dugmeSacuvaj);
		dugmeOperacije.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
					int i = KlasaGui.this.desniList1.getSelectedIndex();
					Process p2;
					try {
						p2 = Runtime.getRuntime().exec(new String[] {
								"Project84.exe",
								"aaa", "20" ,String.valueOf(i) });
						p2.waitFor();
						KlasaGui.this.slika.repaint();
					} catch (IOException e1) {
					} catch (InterruptedException e1) {}
					KlasaGui.this.flegZaIzlaz = true;
				}
		});
		
		dugmeSacuvaj.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
					DialogZaCuvanjeKompozitne d =new DialogZaCuvanjeKompozitne(KlasaGui.this, "Putanja fajla za cuvanje", true);

					int i = KlasaGui.this.desniList1.getSelectedIndex();
					Process p2;
					try {
						p2 = Runtime.getRuntime().exec(new String[] {
								"Project84.exe",
								"aaa", "20" ,String.valueOf(i) });
						p2.waitFor();
						KlasaGui.this.slika.repaint();
					} catch (IOException e1) {
					} catch (InterruptedException e1) {}
				}
		});
		desni.add(desniOperSac);
		desni.add(desniPrviRed);
		desni.add(desniL2);
		desni.add(desniL3);
		desni.add(desniL4);
		desni.add(desniL5);
		desni.add(desniL6);
		desni.add(desniL7);
		desni.add(desniL8);
		desni.add(desniL9);
		desni.add(desniL10);
		desni.add(desniL11);
		desni.add(desniL12);
		desni.add(desniL13);
		desni.add(desniL14);
		desni.add(desniL15);
		desni.add(desniL16);
		desni.add(desniSedamnestiRed);
		desni.add(desni1718);
		desni.add(desni18);
		desni.add(desni1819);
		desni.add(desni20);
		desni.add(desni21);
		
		Button obrisiSloj = new Button("Obrisi sloj");
		obrisiSloj.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
					//int i = KlasaGui.this.desniList1.getSelectedIndex();
					if (KlasaGui.this.listaSlojeva.getSelectedItem()!=null) {
						Process p2;
						try {
							String sloj = listaSlojeva.getSelectedItem();
							
							p2 = Runtime.getRuntime().exec(new String[] {
									"Project84.exe",
									"aaa", "6" ,listaSlojeva.getSelectedItem()});
							p2.waitFor();
							brojSlojeva--;
							listaSlojeva.clear();
							for (int ii  = 0 ; ii< brojSlojeva ;ii++)
								listaSlojeva.add(String.valueOf(ii));
							
							l2.clear();
							BufferedReader br = new BufferedReader(new FileReader("aktivna.txt"));
							try {
								int iii = 0;
							    String line = br.readLine();
							    int pom = Integer.parseInt(line);
							    if(pom == 1) {
							    	l2.add(String.valueOf(iii));
							    }
							   while (line != null) {
							    	iii++;
							        line = br.readLine();
							        if (line == null) {
							        	break ;
							        }
							        pom = Integer.parseInt(line);
							        if(pom == 1) {
								    	l2.add(String.valueOf(iii));
							        }  
							    }
							 
							} finally { br.close();}		
							KlasaGui.this.slika.repaint();
						} catch (IOException e1) {
						} catch (InterruptedException e1) {}
						KlasaGui.this.flegZaIzlaz = true;
					}
					else {
					}
				}
		});
		levi.add(prviRed);
		levi.add(obrisiSloj);
		levi.add(prviDrugi);
		levi.add(drugiRed);
		levi.add(treciRed);
		levi.add(treciCetvrti);
		levi.add(cetvrtiRed);
		levi.add(petiRed);
		levi.add(sestiRed);
		levi.add(sedmiRed);
		levi.add(sedmiOsmi);
		levi.add(posleSedmog);
		levi.add(posleSedmog2);
		levi.add(dvanestiRed);
		levi.add(trinestiRed);
		levi.add(cetrnestiRed);
		levi.add(red1415);
		MenuBar meniBar = new MenuBar();

		Menu m = new Menu("Opcije");
		m.setFont(new Font("Courier", Font.BOLD, 14));
		MenuItem sacuvaj = new MenuItem("Sacuvaj");
		MenuItem ucitaj = new MenuItem("Ucitaj Pocetnu");
		m.add(sacuvaj);
		m.add(ucitaj);
		meniBar.add(m);
		setMenuBar(meniBar);

		slika = new Slika("", this);
		Panel panLevi = new Panel(new BorderLayout());
		panLevi.add(levi , BorderLayout.WEST);
		panLevi.add(slika , BorderLayout.CENTER);
		Panel ceo = new Panel(new BorderLayout());
		ceo.add(panLevi, BorderLayout.CENTER);
		ceo.add(desni, BorderLayout.EAST);
			
		sacuvaj.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				DialogZaCuvanje d =new DialogZaCuvanje(KlasaGui.this, "Putanja fajla za cuvanje", true);
				KlasaGui.this.flegZaIzlaz = false;
			}
		});
		ucitaj.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				DialogZaUcitavanje d =new DialogZaUcitavanje(KlasaGui.this, "Putanja fajla za ucitavanje", true);
				
				KlasaGui.this.flegZaIzlaz = true;
				KlasaGui.this.slika.repaint();
			}
		});
		add(ceo);
		setVisible(true);
	}
	public static void main(String[] s) {
		try {
			new KlasaGui();
		} catch (Exception e) {
			// TODO Auto-generated catch block
		}
	}
}
