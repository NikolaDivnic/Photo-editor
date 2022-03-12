package poop2;

import java.awt.BasicStroke;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.Stroke;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Slika extends Canvas{
	private String fajl;
	private KlasaGui klasaGui;
	private int pomX  ,pomY;
	BufferedImage img = null;
	public Slika(String f , KlasaGui kg) {
		fajl = f;
		klasaGui  = kg;
		
		this.addMouseListener(new MouseAdapter() {
			@Override
			public synchronized void mousePressed(MouseEvent e) {
				if(Slika.this.klasaGui.dohvatiStanje()&& img!=null) {
				    double odnos = ((double)img.getWidth()) / img.getHeight();
					Slika.this.pomX = (int)(getMousePosition().getX() * (((double)img.getWidth()) /((double)getWidth())));
					Slika.this.pomY  = (int)(getMousePosition().getY() * (((double)img.getHeight()) /((int)( getWidth() / odnos))));
				}
				
			}
			@Override
			public synchronized void mouseReleased(MouseEvent e) {
				if(Slika.this.klasaGui.dohvatiStanje()) {
				    double odnos = ((double)img.getWidth()) / img.getHeight();

					Slika.this.klasaGui.napraviPravougaonik(Slika.this.pomX , Slika.this.pomY , 
							(int)(getMousePosition().getX() * (((double)img.getWidth()) /((double)getWidth())))
							,(int)(getMousePosition().getY() * (((double)img.getHeight()) /((int)( getWidth() / odnos)))));
				}
			}
		});
	}
	
	public void postaviSliku(String f) {
		fajl = f;
		repaint();
	}
	private void iscrtajIsprekidanu(Graphics  g ,double odnos) {
		int index =  klasaGui.sedmiList.getSelectedIndex();
		Selekcija s = klasaGui.selekcije.get(index);
		Graphics2D g2d = (Graphics2D) g.create();
		g2d.setColor(Color.RED);
		for (int i = 0 ; i  < s.brojPravougaonika() ; i++) {
			Pravougaonik p = s.dohvPravo(i);
		    Stroke dashed = new BasicStroke(3, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new float[]{9}, 0);
		    g2d.setStroke(dashed);
		    g2d.drawLine( (int) ((double)(((double)p.getX()) / ((double)img.getWidth())) * getWidth()),
		    		(int)( ((double)p.getY()*((double)getWidth()) / ((double) img.getWidth()))),
		    		(int) ((double)(((double)p.getXx()) / ((double)img.getWidth())) * getWidth()), 
		    		(int)( ((double)p.getY()*((double)getWidth()) / ((double) img.getWidth()))));
		    g2d.drawLine( (int) ((double)(((double)p.getX()) / ((double)img.getWidth())) * getWidth()),
		    		(int)( ((double)p.getYy()*((double)getWidth()) / ((double) img.getWidth()))),
		    		(int) ((double)(((double)p.getXx()) / ((double)img.getWidth())) * getWidth()), 
		    		(int)( ((double)p.getYy()*((double)getWidth()) / ((double) img.getWidth()))));
		    g2d.drawLine( (int) ((double)(((double)p.getX()) / ((double)img.getWidth())) * getWidth()),
		    		(int)( ((double)p.getY()*((double)getWidth()) / ((double) img.getWidth()))),
		    		(int) ((double)(((double)p.getX()) / ((double)img.getWidth())) * getWidth()), 
		    		(int)( ((double)p.getYy()*((double)getWidth()) / ((double) img.getWidth()))));
		    g2d.drawLine( (int) ((double)(((double)p.getXx()) / ((double)img.getWidth())) * getWidth()),
		    		(int)( ((double)p.getY()*((double)getWidth()) / ((double) img.getWidth()))),
		    		(int) ((double)(((double)p.getXx()) / ((double)img.getWidth())) * getWidth()), 
		    		(int)( ((double)p.getYy()*((double)getWidth()) / ((double) img.getWidth()))));
		}
        g2d.dispose();

	}
	@Override
	public void paint(Graphics g) {
	
		try {
				 img = ImageIO.read(new File(fajl));
				    double odnos = ((double)img.getWidth()) / img.getHeight();
				    g.drawImage(img,0,0,getWidth()-1, (int)( getWidth() / odnos) ,  0 ,  0 , img.getWidth()  ,img.getHeight() , null);
				   
				    if(klasaGui.sedmiList.getSelectedIndex()!=-1)iscrtajIsprekidanu(g,odnos);
		} catch (IOException e) {
		}
	}
}
