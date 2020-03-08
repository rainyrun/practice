package v1ch04.staticTest;

/**
 * 在Employee类的基础上，增加静态字段 nextId（员工编号）和一个静态方法 getNextId。 在StaticTest类中打印出下一个可用ID
 */
public class StaticTest {
	public static void main(String[] args) {
		// 构造3个雇员
		Employee[] employees = new Employee[3];
		employees[0] = new Employee("harry", 100);
		employees[1] = new Employee("bob", 200);
		employees[2] = new Employee("peter", 300);

		// 打印出雇员信息
		for (Employee e : employees) {
			System.out.println("name=" + e.getName() + ", salary=" + e.getSalary() + 
					", id=" + e.getId());
		}
		
		//下一个可用id
		System.out.println("next avalible id is " + Employee.getNextId());
	}
}

class Employee {
	// 静态域
	private static int nextId = 1;
	
	// 域
	private String name;
	private double salary;
	private int id;
	
	// 构造器
	public Employee(String name, double salary) {
		this.name = name;
		this.salary = salary;
		id = nextId++;
	}

	// 方法
	public String getName() {
		return name;
	}

	public double getSalary() {
		return salary;
	}

	public void raiseSalary(double raise) {
		salary = salary * (1 + raise / 100);
	}
	//静态方法只能访问静态字段（静态域）
	public static int getNextId() {
		return nextId;
	}
	
	public int getId() {
		return id;
	}
	
	public static void main(String[] args) {
		Employee e = new Employee("cate", 50);
		System.out.println("name=" + e.getName() + ", salary=" + e.getSalary() + 
				", id=" + e.getId());
	}
}
/* 注意对Employee类做单元测试（在main方法里）
 */