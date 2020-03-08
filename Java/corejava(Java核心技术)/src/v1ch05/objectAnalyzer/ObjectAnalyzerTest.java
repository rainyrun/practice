package v1ch05.objectAnalyzer;

import java.util.*;
import java.lang.reflect.*;

/**
 * 分析输入对象的域，并给出字符串。 如果输入的是数组对象，则输出字符串为：数组类型[数组对象类型[对象的值]，...]
 * 如果输入的是普通对象，则输入为：对象类型[field1=field1Value, ...]
 */

public class ObjectAnalyzerTest {
	public static void main(String[] args) {
		ArrayList<Integer> array = new ArrayList<Integer>();
		for (int i = 1; i <= 5; i++) {
			array.add(i * i);
		}

//		int[] array = new int[5];
//		for(int i = 1; i <= 5; i++) {
//			array[i - 1] = i;
//		}
		
		String s = new ObjectAnalyzer().toString(array);
		System.out.println(s);
	}
}

class ObjectAnalyzer {
	// 注2
	private ArrayList<Object> visited = new ArrayList<Object>();

	public String toString(Object obj) {
		if (obj == null) return "null";
		if (visited.contains(obj)) return "...";
		visited.add(obj);
		Class cl = obj.getClass();
		// 如果对象是字符串
		if(obj.getClass() == String.class) return (String) obj;
		// 如果对象是数组
		// 注1
		if (cl.isArray()) {
			// 获得数组类型
			String r = cl.getComponentType() + "[]{";
			// 依次取出数组中的元素
			for (int i = 0; i < Array.getLength(obj); i++) {
				if (i > 0)
					r += ", ";
				// 获得数组中的元素类型
				Class type = cl.getComponentType();
				// 获得数组元素的值
				Object val = Array.get(obj, i);
				if (type.isPrimitive()) {
					r += val;
				} else {
					// 数组元素非原始类型，则递归调用toString方法
					r += toString(val);
				}
			}
			return r + "}";
		}
		// 如果对象不是数组
		String r = cl.getName();
		do {
			r += "[";
			Field[] fields = cl.getDeclaredFields();
			AccessibleObject.setAccessible(fields, true);
			for (int j = 0; j < fields.length; j++) {
				Field f = fields[j];
				// 只展示非静态字段
				if (!Modifier.isStatic(f.getModifiers())) {
					if (!r.endsWith("["))
						r += ", ";
					// 获取字段类型
					String className = f.getName();
					r += className + "=";
					// 获取字段值
					try {
						Class t = f.getType();
						Object val = f.get(obj);
						if (t.isPrimitive()) {
							r += val;
						}
						else {
							// 递归调用toString方法
							r += toString(val);
						}
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}
			r += "]";
			cl = cl.getSuperclass();
		}
		while(cl != null);
		
		return r;
	}
}

/*
 * 注1：如果cl = java.util.ArrayList，则cl.isArray()=false
 * 注2: 但分析的对象出现重复引用的情况（如一个对象引用它自身）时，会无限递归。记录已访问的元素，避免重复访问。
 * 注3: 结果中java.lang.Integer[value=1][][]中多的方括号，是打印它的父类导致的。因为父类中没有非静态域。
 */