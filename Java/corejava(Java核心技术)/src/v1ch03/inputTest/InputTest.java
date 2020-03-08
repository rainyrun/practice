package v1ch03.inputTest;

import java.util.*;

/**
 * 功能：询问用户姓名和年龄，然后打印一条如下格式的消息：Hello, Cay. Next year, you'll be 57.
 */
public class InputTest {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		System.out.println("What's your name?");
		String name = in.nextLine();
		
		System.out.println("How old are you?");
		int age = in.nextInt();
		
		System.out.println("Hello, " + name + ". Next year, you'll be " + (age + 1) + ".");
	}
}
