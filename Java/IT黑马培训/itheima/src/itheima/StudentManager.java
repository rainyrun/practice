package itheima;
/**
需求
输入序号进行对应的操作。操作完成后，自动回到初始选择界面。
学生的属性包括学号、姓名、年龄、地址。
1. 查看学生
	1. 学生为空时，提示没有学生。
	2. 学生不为空时，按学号、姓名、年龄、地址展示学生信息。
2. 添加学生
	1. 按照提示，依次添加学生的属性信息
	2. 不能添加学号相同的学生，并回到初始选择界面
3. 删除学生
	1. 输入学号删除对应的学生
	2. 学生学号不存在时，提示无法删除成功，并回到初始选择界面
4. 修改学生
	1. 输入学号修改学生，修改内容包括：姓名、年龄、地址
	2. 输入学号不存在时，提示失败，并回到初始选择界面
5. 退出
	退出学生管理系统
 
 分析
 1. 创建学生类，属性包括：学号、姓名、年龄、地址。方法包括：获得和修改各个属性
 2. 创建学生管理类，属性包括：学生数组。方法包括以上5个方法。
 3. 在main方法里进行操作
 
 测试
 1. 学生数组为空时，查看学生
 2. 添加已存在学号的学生
 3. 删除不在学生数组中的学生
 4. 修改不在学生数组中的学生
 5. 退出
 */
import java.util.*;
public class StudentManager {
	ArrayList<Student> studentList = new ArrayList<>();
	//查看学生
	public void check() {
		if(studentList.isEmpty()) {
			System.out.println("student list is empty.");
		}
		else {
			System.out.format("id\tname\tage\taddr\n");
			for(Student s : studentList) {
				System.out.format("%d\t%s\t%d\t%s\n",s.getId(), s.getName(), s.getAge(), s.getAddr());
			}
		}
	}
	//添加学生
	public void add() {
		//输入学生id
		System.out.println("please input student id:");
		Scanner in = new Scanner(System.in);
		int newId = in.nextInt();
		//检查id是否存在
		if(find(newId) == null) {
			//id不存在，添加学生
			Student newStudent = new Student();
			newStudent.setId(newId);
			System.out.println("please input student name:");
			newStudent.setName(in.next());
			System.out.println("please input student age:");
			newStudent.setAge(in.nextInt());
			System.out.println("please input student addr:");
			newStudent.setAddr(in.next());
			
			studentList.add(newStudent);
			System.out.println("add student success!");
		}
		else
			System.out.println("the student is already exist.");
		
	}
	//删除学生
	public void delete() {
		// 输入学生id
		System.out.println("please input student id:");
		Scanner in = new Scanner(System.in);
		int newId = in.nextInt();
		// 检查id是否存在
		Student temp = find(newId);
		if(temp == null)
			System.out.println("student is not existed.");
		else {
			studentList.remove(temp);
			System.out.println("the student is removed.");
		}
	}
	//修改学生
	public void change() {
		// 输入学生id
		System.out.println("please input student id:");
		Scanner in = new Scanner(System.in);
		int newId = in.nextInt();
		// 检查id是否存在
		Student changeS = find(newId);
		if(changeS == null)
			System.out.println("student is not existed.");
		else {
			System.out.println("please input student name:");
			changeS.setName(in.next());
			System.out.println("please input student age:");
			changeS.setAge(in.nextInt());
			System.out.println("please input student addr:");
			changeS.setAddr(in.next());
			System.out.println("student modify success!");	
		}
	}
	
	public Student find(int id) {
		Student exist = null;
		if (!studentList.isEmpty()) {
			for (Student s : studentList) {
				if (s.getId() == id) {
					exist = s;
					break;
				}
			}
		}
		return exist;
	}
	
	public static void main(String[] args) {
		boolean quit = false;
		StudentManager sm = new StudentManager();
		while(!quit) {
			System.out.println("-------welcome to student management system!-------");
			System.out.println("1. check students");
			System.out.println("2. add students");
			System.out.println("3. delete students");
			System.out.println("4. modify students");
			System.out.println("5. quit");
			System.out.println("please input your choice");
			Scanner in = new Scanner(System.in);
			int choice = in.nextInt();
			switch(choice) {
			case 1:
				sm.check();
				break;
			case 2:
				sm.add();
				break;
			case 3:
				sm.delete();
				break;
			case 4:
				sm.change();
				break;
			case 5:
				quit = true;
				System.out.println("quiting...");
				break;
			default:
				System.out.println("please input between 1 - 5");
				break;
			}
		}
	}
}

/* 备注
 * 1. 成员变量不要忘记private关键词
 * 2. 不要全部写完再测试，将代码分成模块，一块一块测试
 */
