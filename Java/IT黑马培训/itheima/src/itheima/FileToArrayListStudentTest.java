package itheima;
import java.util.*;
import java.io.*;
/**
 * 需求：
 * 把文本中的学生信息读取出来存储到集合中，然后遍历集合，在控制台输出
 * 分析
 * 1. 按行读出学生信息，按"\t"划分学生属性
 * 2. 将学生对象加入到集合中
 * 3. 遍历集合，并展示
 */
public class FileToArrayListStudentTest {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("students.txt"));
		ArrayList<Student> array = new ArrayList<>();
		String line;
		while((line = reader.readLine()) != null) {
			String[] temp = line.split("\t");
			Student s = new Student();
			s.setId(Integer.parseInt(temp[0]));
			s.setName(temp[1]);
			s.setAge(Integer.parseInt(temp[2]));
			s.setAddr(temp[3]);
			array.add(s);
		}
		reader.close();
		System.out.println("id\tname\tage\taddr");
		for(int i = 0; i < array.size(); i++) {
			Student s = array.get(i);
			System.out.println(s.getId() + "\t" + s.getName() + "\t" + s.getAddr() + "\t" +s.getAddr());
		}
	}
}
