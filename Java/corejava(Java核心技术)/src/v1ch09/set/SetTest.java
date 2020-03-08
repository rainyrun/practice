package v1ch09.set;

import java.util.*;
import java.io.*;

/**
 * 读入文件，将单词加入hashset并统计共有多少个不同的单词，花费了多少时间
 */
public class SetTest {
	public static void main(String[] args) {
		Set<String> words = new HashSet<String>();
		// 统计时间
		long totalTime = 0;
		FileReader file = null;
		try {
			// 读入文件
			file = new FileReader("./vich09/set/test.txt");
			// 将单词加入hashset
			String word = readWord(file);
			while (word != null) {
				long callTime = System.currentTimeMillis();
				words.add(word);
				callTime = System.currentTimeMillis() - callTime;
				totalTime += callTime;
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		// 统计单词数和花费时间
		System.out.println("there are " + words.size() + "words and take " + (totalTime / 100) + "s");
	}

	public static String readWord(FileReader file) throws IOException {
		StringBuffer sb = new StringBuffer();
		String album = String.valueOf(file.read());
		while (!" ".equals(album)) {
			sb.append(album);
		}
		return sb.substring(0);
	}
}
