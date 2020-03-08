package v1ch06.staticInnerClass;

/**
 * ArrayAlg的minmax方法：返回一个Pair对象，功能是从数组中找出最大和最小的两个数。
 * Pair是内部类。对象有2个属性。
 */
public class StaticInnerClassTest {
	public static void main(String[] args) {
		// 生成一个数组
		double[] array = new double[20];
		for(int i = 0; i < array.length; i++) {
			array[i] = Math.random() * 10;
		}
		// 调用ArrayAlg的静态方法minmax返回Pair对象
		ArrayAlg.Pair p = ArrayAlg.minmax(array);
		// 输出Pair对象的值
		System.out.println("min = " + p.first + "; max = " + p.second);
	}

}

class ArrayAlg{
	//从数组中选出最小值和最大值
	public static Pair minmax(double[] d) {
		double max = Double.NEGATIVE_INFINITY;
		double min = Double.POSITIVE_INFINITY;
		for(int i = 0; i < d.length; i++) {
			if (d[i] > max)
				max = d[i];
			if(d[i] < min)
				min = d[i];
		}
		return new Pair(min, max);
	}
	
	static class Pair{
		double first;
		double second;
		//构造器
		public Pair(double first, double second) {
			this.first = first;
			this.second = second;
		}
		
		//getter
		public double getFirst() {
			return first;
		}
		
		public double getSecond() {
			return second;
		}
	}
}
