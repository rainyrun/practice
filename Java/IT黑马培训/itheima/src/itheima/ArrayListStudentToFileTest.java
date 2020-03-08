package itheima;
import java.util.*;
import java.io.*;
/**
 * 需求
 * 键盘录入3个学生信息（学号、姓名、年龄、居住地）存入集合。
 * 然后遍历集合把每一个学生信息存入文本文件（每一个学生信息为一行数据，分割标记为"\t"）
 * 分析
 * 1. 依次输入3个学生的信息，并创建学生对象，加入到集合中
 * 2. 遍历集合，依次取出学生的信息，写入文件中。每写入一个属性，写入一个"\t"，每写入一个学生，写入一个换行
 */
public class ArrayListStudentToFileTest {
	public static void main(String[] args) throws IOException {
		ArrayList<Student> array = new ArrayList<>();
		Scanner in = new Scanner(System.in);
		//输入学生信息，并加入集合
		for(int i = 0; i < 3; i++) {
			System.out.println("please input the " + (i+1) + " student's information:");
			Student s = new Student();
			System.out.println("student id:");
			s.setId(in.nextInt());
			System.out.println("student name:");
			s.setName(in.next());
			System.out.println("student age:");
			s.setAge(in.nextInt());
			System.out.println("student addr:");
			s.setAddr(in.next());
			
			array.add(s);
		}
		//遍历集合，并写入文件
		BufferedWriter writer = new BufferedWriter(new FileWriter("students.txt"));
		for(int i = 0; i < array.size(); i++) {
			Student s = array.get(i);
			writer.write(String.valueOf(s.getId()));
			writer.write("\t");
			writer.write(s.getName());
			writer.write("\t");
			writer.write(String.valueOf(s.getAge()));
			writer.write("\t");
			writer.write(s.getAddr());
			writer.newLine();
		}
		writer.close();
	}
}
/*备注：
 * 1. BufferedWriter中，void write​(int c)并不是写入整型数字，而是写入单个字符
 * 2. 在文件中添加内容，也可以使用writer.append("aaa").append("bbb");
 */
