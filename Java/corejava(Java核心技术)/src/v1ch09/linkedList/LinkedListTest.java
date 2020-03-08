package v1ch09.linkedList;

import java.util.*;

/**
 * 创建a、b两个LinkedList
 * 1. 将b中的元素添加到a里面，a中的b元素相间排列。
 * 2. 将b中的元素每隔一个删除一个
 * 3. 将b含有的元素从a中删除。
 */
public class LinkedListTest {
	public static void main(String[] args) {
		// 创建a表
		LinkedList<String> a = new LinkedList<String>();
		a.add("apple");
		a.add("peach");
		a.add("banana");
		// 创建b表
		LinkedList<String> b = new LinkedList<String>();
		b.add("table");
		b.add("chair");
		b.add("TV");
		b.add("closet");
		// 将b中的元素添加到a里面，a中的b元素相间排列
		ListIterator<String> aIter = a.listIterator();
		ListIterator<String> bIter = b.listIterator();
		while(bIter.hasNext()) {
			if(aIter.hasNext())
				aIter.next();
			aIter.add(bIter.next());
		}
		System.out.println(a);
		// 将b中的元素每隔一个删除一个
		bIter = b.listIterator();
		while(bIter.hasNext()) {
			bIter.next();
			if(bIter.hasNext()) {
				bIter.next();
				bIter.remove();
			}
		}
		System.out.println(b);
		// 将b含有的元素从a中删除。
		a.removeAll(b);
		System.out.println(a);
	}
}
