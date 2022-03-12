package poop2;

import java.util.ArrayList;

public class Selekcija {
	private ArrayList<Pravougaonik>pravougaonici;
	private boolean aktivna;
	private String ime;
	public Selekcija(ArrayList<Pravougaonik>p , String s , boolean b) {
		pravougaonici = new ArrayList<Pravougaonik>();
		for (Pravougaonik pp:p) {
			pravougaonici.add(pp);
		}
		ime = s;
		aktivna = b;
	}
	public boolean dohvAktivna() {
		return aktivna;
	}
	public String dohvIme() {
		return ime;
	}
	public ArrayList<Pravougaonik> dohvatiPravougaonike(){
		return pravougaonici;
	}
	public int brojPravougaonika() {
		return pravougaonici.size();
	}
	public Pravougaonik dohvPravo(int i) {
		return pravougaonici.get(i);
	}
}
