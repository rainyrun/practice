package v1ch05.reflection;

import java.util.*;
import java.lang.reflect.*;
import java.lang.reflect.Modifier;

/**
 * 输入类名，输出类中所有的方法和构造器的签名，以及全部字段名
 */
public class ReflectionTest {
	public static void main(String[] args) {
		System.out.println("请输入类名：");
		Scanner in = new Scanner(System.in);
		String className = in.nextLine();
		try {
			Class cl = Class.forName(className);
			Class supercl = cl.getSuperclass();
			//获取类修饰符
			String modifier = Modifier.toString(cl.getModifiers());
			System.out.print(modifier + " " + className);
			//获取父类
			if(supercl != null && supercl != Object.class) {
				System.out.println(" extends " + supercl.getName() + " {");
			}
			//打印字段
			printFields(cl);
			System.out.println();
			//打印构造器
			printConstructors(cl);
			System.out.println();
			//打印方法
			printMethods(cl);
			System.out.println("}");
			
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void printFields(Class cl) {
		Field[] fields = cl.getDeclaredFields();
		for(Field f : fields) {
			System.out.print("    ");
			//获取修饰符
			String modifier = Modifier.toString(f.getModifiers());
			if(modifier.length() > 0) {
				System.out.print(modifier + " ");
			}
			//获取字段名
			String name = f.getName();
			System.out.println(name +";");
		}
	}
	
	public static void printConstructors(Class cl) {
		Constructor[] cons = cl.getDeclaredConstructors();
		for(Constructor c : cons) {
			System.out.print("    ");
			//获取修饰符
			String modifier = Modifier.toString(c.getModifiers());
			if(modifier.length() > 0) {
				System.out.print(modifier + " ");
			}
			//获取构造器名
			String name = c.getName();
			System.out.print(name + "(");
			//获取构造器参数
			Class[] paramTypes = c.getParameterTypes();
			for(int i = 0; i < paramTypes.length; i++) {
				if(i > 0) {
					System.out.print(", ");
				}
				//获取参数类型
				String type = paramTypes[i].getName();
				System.out.print(type);
			}
			System.out.println(");");
		}
	}
	
	public static void printMethods(Class cl) {
		Method[] methods = cl.getDeclaredMethods();
		for(Method m : methods) {
			System.out.print("    ");
			//获取修饰符
			String modifier = Modifier.toString(m.getModifiers());
			if(modifier.length() > 0) {
				System.out.print(modifier + " ");
			}
			//获取返回值类型
			Class retType = m.getReturnType();
			System.out.print(retType + " ");
			//获取方法名
			String name = m.getName();
			System.out.print(name + "(");
			//获取方法参数类型
			Class[] methodTypes = m.getParameterTypes();
			for(int i = 0; i < methodTypes.length; i++) {
				if(i > 0) {
					System.out.print(", ");
				}
				String type = methodTypes[i].getName();
				System.out.print(type);
			}
			System.out.println(");");
		}
	}
}
