package test;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

import rainy.MyHashMap;

public class MyHashMapTest {
	@Test
	public void testMyHashMap() {
//		1. 创建一个HashMap，不设置容量
		MyHashMap<String, String> map = new MyHashMap<>();		
//	    1. 在 HashMap 中存入一组 key-value，看是否能取出
		map.put("1", "first");
		String value1 = map.get("1");
		assertEquals("first", value1);
//	    2. 再存入一组key相同，value不同的数据，看是否能取出最新值
		map.put("1", "new first");
		String newvalue1 = map.get("1");
		assertEquals("new first", newvalue1);
//	    3. 存入(null, null)，看是否能取到；再存入 (null, 1)，看是否更新
		map.put(null, "It's null");
		assertEquals("It's null", map.get(null));
		map.put(null, "It's new null");
		assertEquals("It's new null", map.get(null));
//	    4. 存入key不同的数据，看能否取到
		map.put("2", "second");
		assertEquals("second", map.get("2"));
//	    2. 创建一个HashMap，设置容量为2
		MyHashMap<String, String> map2 = new MyHashMap<String, String>(2);
//	    1. 存入数据后，看是否会扩容，扩容后，是否能取出数据
		map2.put("1", "first");
		map2.put("2", "second");
		assertEquals("first", map2.get("1"));
		assertEquals("second", map2.get("2"));
//	    2. 设置最大容量为4，存入4个数据后，再存入数据，看是否会扩容
		map2.put("3", "third");
		map2.put("4", "forth");
		map2.put("5", "fifth");
	}

}
