package itheima;

import java.io.*;
public class FileWriterDemo {
	public static void main(String[] args) throws IOException {
		FileWriter fw = new FileWriter("a.txt");
		fw.write("hello world!");
		fw.flush();
		
		fw.close();
	}
}
