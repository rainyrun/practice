package itheima;
import java.util.*;
import java.io.*;
/**
 * 需求
 * 从文本文件中读取数据到ArrayList集合中，并遍历集合，每一行数据作为一个字符串元素。
 * 分析
 * 1. 依次从文本文件读取一行
 * 2. 将该行作为一个字符串添加到ArrayList集合中
 */
public class FileToArrayListTest {
	public static void main(String[] args) throws IOException {
		ArrayList<String> array = new ArrayList<>();
		BufferedReader reader = new BufferedReader(new FileReader("a.txt"));
		String str;
		while((str = reader.readLine()) != null) {
			array.add(str);
		}
		reader.close();
		
		for(int i = 0; i < array.size(); i++) {
			System.out.println(array.get(i));
		}
	}
}
