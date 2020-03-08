package itheima;
import java.util.*;
import java.io.*;
/**
 * 需求
 * 把ArrayList集合中的字符串数据存储到文本文件，每一个字符串元素作为文件中的一行数据
 * 分析
 * 1. 遍历ArrayList中的字符串，每个字符串作为bufferedWriter的参数，写入到文件中
 */
public class ArrayListToFileTest {
	public static void main(String[] args) throws IOException {
		BufferedWriter buffer = new BufferedWriter(new FileWriter("a.txt"));
		ArrayList<String> array = new ArrayList<>();
		array.add("aaa");
		array.add("hello, rainy");
		array.add("see you latter.");
		for(int i = 0; i < array.size(); i++) {
			buffer.write(array.get(i));
			buffer.newLine();
		}
		buffer.close();
	}
}
