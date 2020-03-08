package v1ch09.blockingQueue;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

/**
 * 在一个目录及其子目录下的文件里，查询某个关键字，并将含有关键字的文件信息（文件路径、行号、行）打印出来。 备注：需要使用100个子线程完成查找打印的任务。
 */
public class BlockingQueueTest {
	private static final int SEARCH_THREAD_NUM = 100;
	private static final int QUEUE_SIZE = 10;
	private static final File DUMMY = new File("");
	private static BlockingQueue<File> queue = new ArrayBlockingQueue<File>(QUEUE_SIZE);

	public static void main(String[] args) throws InterruptedException {
		Scanner in = new Scanner(System.in);
		System.out.println("请输入查找目录，如/Users/runlei/Documents/synch");
		String dir = in.nextLine();
		System.out.println("请输入查找的关键字");
		String word = in.nextLine();
		Runnable listFiles = () -> {
			try {
				findFiles(new File(dir));
				queue.put(DUMMY); // 队列中没有文件的标志
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		};
		new Thread(listFiles).start();
		searchWord(word);
	}

	/**
	 * 将目录及其子目录下的文件放入队列
	 * 
	 * @param dir 查找目录
	 * @throws InterruptedException
	 */
	public static void findFiles(File dir) throws InterruptedException {
		File[] files = dir.listFiles();
		for (File file : files) {
			if (file.isDirectory())
				findFiles(file);
			else {
				queue.put(file);
			}
		}
	}

	/**
	 * 创建 SEARCH_THREAD_NUM 个线程，从队列中取出文件，并查找word是否在文件中。在则输出文件信息
	 * 
	 * @param word 要查找的单词
	 */
	public static void searchWord(String word) {
		for (int i = 0; i < SEARCH_THREAD_NUM; i++) {
			Runnable searcher = () -> {
				try {
					boolean done = false;
					while (!done) {
						File file = queue.take();
						if (file == DUMMY) {
							queue.put(file);
							done = true;
						}
						else {
							search(file, word);
						}
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
			};
			Thread r = new Thread(searcher);
			r.start();
		}
	}

	/**
	 * 查找文件file中是否有word。有，则打印文件信息
	 * 
	 * @param file
	 * @param word
	 * @throws FileNotFoundException
	 */
	public static void search(File file, String word) throws FileNotFoundException {
		assert (file.isDirectory() == false); // file不是目录
		int lineNumber = 0;
		Scanner in = new Scanner(file, "UTF-8");
		while(in.hasNextLine()) {
			lineNumber++;
			String line = in.nextLine();
			if(line.contains(word))
				System.out.printf("%s:%d:%s\n", file.getPath(), lineNumber, line);
		}
	}
}

/*
 * 常量不要写死在类中，不希望被改变的类常量记得设置成final
 * 遍历目录中的文件可以和查找并行
 */