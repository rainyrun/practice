package test;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

import rainy.MyString;

public class MyStringTest {
	@Test
	public void testMyString() {
		MyString str1 = new MyString("a");
		MyString str2 = new MyString(str1);
		assertTrue(str1.equals(str2));
	}
}
