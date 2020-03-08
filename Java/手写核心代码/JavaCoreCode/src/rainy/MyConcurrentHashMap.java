package rainy;

import java.util.concurrent.ConcurrentHashMap;
import java.util.function.BiConsumer;
import java.util.function.BiFunction;
import java.util.function.Function;

public class MyConcurrentHashMap {
	public static void main(String[] args) {
		ConcurrentHashMap<String, Integer> map = new ConcurrentHashMap<>();
		for (int i = 0; i < 20; i++) {
			map.put(Integer.valueOf(i).toString(), i);
		}
		map.put(null, null);
	}
}
