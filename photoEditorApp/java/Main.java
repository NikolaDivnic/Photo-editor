package poop2;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[]s) throws InterruptedException {
		try {
			//  String[] commands = {"cmd", "/c", "tesseract", imageFilePath, outputFilePath };

			
			Process p = Runtime.getRuntime().exec(new String[] {
					"C:\\Users\\Nikola\\source\\repos\\Project84\\Release\\Project84.exe",
					"C:\\Users\\Nikola\\Desktop\\kopija3.bmp", "1"});
			p.waitFor();

			Process p2 = Runtime.getRuntime().exec(new String[] {
					"C:\\Users\\Nikola\\source\\repos\\Project84\\Release\\Project84.exe",
					"C:\\Users\\Nikola\\Desktop\\kopija3.bmp", "3" ,"50", "50" , "50"});
			p2.waitFor();
			p2 = Runtime.getRuntime().exec(new String[] {
					"C:\\Users\\Nikola\\source\\repos\\Project84\\Release\\Project84.exe",
					"C:\\Users\\Nikola\\Desktop\\images32.pam", "3" ,"150", "100" , "70"});
			p2.waitFor();
			
			Process p3 = Runtime.getRuntime().exec(new String[] {
					"C:\\Users\\Nikola\\source\\repos\\Project84\\Release\\Project84.exe",
					"C:\\Users\\Nikola\\Desktop\\slika.bmp", "6" , "1"});
			p3.waitFor();

			 p2 = Runtime.getRuntime().exec(new String[] {
					"C:\\Users\\Nikola\\source\\repos\\Project84\\Release\\Project84.exe",
					"C:\\Users\\Nikola\\Desktop\\images32.pam", "7" , "2" ,"0", "0"});
			p2.waitFor();
			p2 = Runtime.getRuntime().exec(new String[] {
					"C:\\Users\\Nikola\\source\\repos\\Project84\\Release\\Project84.exe",
					"C:\\Users\\Nikola\\Desktop\\slika.bmp", "2"});
			p2.waitFor();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	}
}
