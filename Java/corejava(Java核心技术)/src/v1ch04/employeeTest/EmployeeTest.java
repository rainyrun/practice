package v1ch04.employeeTest;

import java.time.*;

/**
 * 定义一个雇员类
 * 字段：name、salary、hireDay
 * 方法：getName、getSalary、getHireDay、raiseSalary
 * 
 * 在EmployeeTest的main方法中构造3个雇员，每人涨薪5%，然后打印出雇员信息
 */
public class EmployeeTest {
	public static void main(String[] args) {
		//构造3个雇员
		Employee[] employees = new Employee[3];
		employees[0] = new Employee("harry", 100, LocalDate.of(2019,8,11));
		employees[1] = new Employee("bob", 200, LocalDate.of(2019,8,11));
		employees[2] = new Employee("peter", 300, LocalDate.of(2019,8,11));
		
		//每人涨薪5%
		for(Employee e : employees) {
			e.raiseSalary(5);
		}
		
		//打印出雇员信息
		for(Employee e : employees) {
			System.out.println("name = " + e.getName() + ", salary = " + e.getSalary() + ", hireDay = " + e.getHireDay());
		}
	}

}

class Employee{
	//字段
	private String name;
	private double salary;
	private LocalDate hireDay;
	
	//构造器
	public Employee(String name, double salary, LocalDate hireDay) {
		this.name = name;
		this.salary = salary;
		this.hireDay = hireDay;
	}
	
	//方法
	public String getName() {
		return name;
	}
	public double getSalary() {
		return salary;
	}
	public LocalDate getHireDay() {
		return hireDay;
	}
	public void raiseSalary(double raise) {
		salary = salary * (1 + raise / 100);
	}
}