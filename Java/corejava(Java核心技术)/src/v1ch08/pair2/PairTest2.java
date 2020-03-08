package v1ch08.pair2;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Random;

/**
 * 编写了一个泛型方法 minmax。这个方法计算泛型数组的最大值和最小值，并返回 Pair<T>。
 */
public class PairTest2 {
	
	public static <T extends Comparable> Pair<T> minmax(T[] a) {
		T min = a[0];
		T max = a[0];
		for(int i = 0; i < a.length; i++) {
			if(a[i].compareTo(max) > 0)
				max = a[i];
			if(a[i].compareTo(min) < 0)
				min = a[i];
		}
		System.out.println("min: " + min + " ;max: " + max);
		return new Pair<T>(min, max);
	}
	
	public static void main(String[] args) {
		Integer[] a = new Integer[10];
		for(int i = 0; i < 10; i++) {
			a[i] = new Random().nextInt(100);
			System.out.println(a[i]);
		}
		
//		LocalDate[] birthdays = { 
//				LocalDate.of(1906, 12, 9), // C.Hopper 
//				LocalDate.of(1815, 12, 10), // A. Lovelace 
//				LocalDate.of(1903, 12, 3), // 3. von Neumann 
//				LocalDate.of(1910, 6, 22), // K. Zuse };
//		};
		Pair p = minmax(a);
		System.out.println("min: " +  p.getFirst());
		System.out.println("max: " + p.getSecond());
		System.out.println(p);
		
	}

}

class Pair<T> {
	private T first;
	private T second;
	
	public Pair () {
		first = null;
		second = null;
	}
	
	public Pair (T first, T second){
		this.first = first;
		this.second = second;
	}
	
	public T getFirst() {
		return first;
	}
	
	public T getSecond() {
		return second;
	}

	@Override
	public String toString() {
		return "Pair [first=" + first + ", second=" + second + "]";
	}
}