package rainy;

public class MyString {
    private final byte[] value;
    public MyString() {
        value = "".getBytes();
    }
    public MyString(MyString s) {
        value = s.value;
    }
    public MyString(String s) {
        value = s.getBytes();
    }
    public boolean equals(MyString s) {
        if(value == s.value)
            return true;
        if(s instanceof MyString) {
        	return MyStringUtil.equals(value, s.value);
        }
        return false;
    }
       
}

// 参考StringUTF16
final class MyStringUtil {
	private static native boolean isBigEndian();

    static final int HI_BYTE_SHIFT;
    static final int LO_BYTE_SHIFT;
    static {
        if (isBigEndian()) {
            HI_BYTE_SHIFT = 8;
            LO_BYTE_SHIFT = 0;
        } else {
            HI_BYTE_SHIFT = 0;
            LO_BYTE_SHIFT = 8;
        }
    }
    
    private static char getChar(byte[] value, int index) {
    	index <<= 1;
    	return (char)(((value[index++] & 0xff) << HI_BYTE_SHIFT) |
    			((value[index] & 0xff) << LO_BYTE_SHIFT));
    }
    
    public static boolean equals(byte[] value, byte[] others) {
    	if(value.length == others.length) {
    		int len = value.length >> 1;
    		for(int i = 0; i < len; i++) {
    			if(getChar(value, i) != getChar(others, i))
    				return false;
    		}
    		return true;
    	}
    	return false;
    }
}