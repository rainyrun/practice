package rainy;

public class MyHashMap<K, V> {
    private final static int MAX_CAPACITY = 1 << 2;
    private final static int DEFAULT_INITIAL_CAPACITY = 16;
    private final static double DEFAULT_LOAD_FACTOR = 0.75f;

    private Node<K, V>[] table;
    private int threshold;
    private double loadFactor;
    private int size;
    
    class Node<K, V> {
    	// 属性
        int hash;
        K key;
        V value;
        Node<K, V> next;
        // 构造方法
        Node(int hash, K key, V value, Node<K, V> next) {
        	this.hash = hash;
        	this.key = key;
        	this.value = value;
        	this.next = next;
        }
    }
    
	// 构造函数
    public MyHashMap() {
    }

    public MyHashMap(int initialCapacity, double loadFactor) {
        // 参数有效性检验
    	if (initialCapacity < 0) {
    		throw new IllegalArgumentException("容量不能为负数");
    	}
    	if (initialCapacity > MAX_CAPACITY) {
    		this.threshold = Integer.MAX_VALUE;
    		initialCapacity = MAX_CAPACITY;
    	}
    	if (loadFactor <= 0 || loadFactor > 1)
    		throw new IllegalArgumentException("loadFactor的范围是(0,1]");
        // 初始化
        this.loadFactor = loadFactor;
        this.threshold = tableSizeFor(initialCapacity);
    }

    public MyHashMap(int initialCapacity) {
        this(initialCapacity, DEFAULT_LOAD_FACTOR);
    }
    
    public V put(K key, V value) {
    	// 检查tab是否存在，不存在则初始化
    	if (table == null || table.length == 0) {
    		resize();
    	}
    	int n = table.length;
        // 找出table中对应的位置
    	Node<K, V> p = table[hash(key) & (n - 1)];
    	if(p == null) { // 位置为空，则创建新节点并把节点放进去。
    		table[hash(key) & (n - 1)] = new Node<K, V>(hash(key), key, value, null);
    	} else { // 位置不为空，遍历找出key相同的节点，将value更新；或者将节点加到链表末尾
    		Node<K, V> e = null; // 指向p的前一个节点
    		while(p != null) {
    			if(p.key == key || (p.key != null && p.key.equals(key))) {
    				V oldValue = p.value;
    				p.value = value;
    				return oldValue;
    			}
    			e = p;
    			p = p.next;
    		}
    		e.next = new Node<K, V>(hash(key), key, value, null);
    	}
    	// 更新数组的元素数量
    	++size;
    	if(size > threshold)
    		resize();
    	return null;
    }
    
    public V get(K key) {
    	// 获得 key 所在的桶
    	Node<K, V> p = table[hash(key) & (table.length - 1)];
    	// 遍历该桶
    	while(p != null) {
    		if(p.key == key || (p.key != null && p.key.equals(key))) {
    			return p.value;
    		}
    		p = p.next;
    	}
    	return null;
    }
    
    // ------------------- 工具方法 -------------------
    
    private static int tableSizeFor(int cap) {
    	int n = (-1 >>> Integer.numberOfLeadingZeros(cap - 1));
    	if (n == 0)
    		return 1;
    	if ((n + 1) > MAX_CAPACITY)
    		return MAX_CAPACITY;
    	return n + 1;
    	// n == 0 ? 1 : ((n + 1) > MAX_CAPACITY ? MAX_CAPACITY : n + 1);
    }
    
    private int hash(K key) {
    	if (key == null)
    		return 0;
    	return key.hashCode() ^ (key.hashCode() >>> 16);
    }
    
    private void resize() {
    	// 获取新的capacity和threshold
    	int oldCap = (table == null) ? 0 : table.length;
    	int oldThr = this.threshold;
    	int newThr = 0;
    	int newCap;
    	Node<K, V>[] tab = table;
    	if (oldCap > 0) {
    		if(oldCap >= MAX_CAPACITY) { // 检查上限
    			newThr = Integer.MAX_VALUE;
    			newCap = MAX_CAPACITY;
    		} else {
    			newCap = oldCap << 1;
    			if (newCap > MAX_CAPACITY) {
    				newCap = MAX_CAPACITY;
    				newThr = Integer.MAX_VALUE;
    			} else {
    				newThr = oldThr << 1;
    			}
    		}
    	} else if (oldThr > 0) { // 初始化table
    		newCap = oldThr;
    	} else {
    		newCap = DEFAULT_INITIAL_CAPACITY;
    	}
    	if(newThr == 0) {
    		newThr = (int)(newCap * DEFAULT_LOAD_FACTOR);
    	}
    	// 设置新table，将tab中的node转移到table中
    	table = (Node<K, V>[])new Node[newCap];
    	this.threshold = newThr;
    	System.out.println("expands, newCap: " + newCap + ", newThr: " + newThr);
    	if(tab != null) { // tab中有数据
        	for(int i = 0; i < tab.length; ++i) {
        		Node<K, V> p = tab[i];
        		tab[i] = null; // 释放空间
        		if(p != null) {
        			Node<K, V> loHead = null;
            		Node<K, V> loTail = null;
            		Node<K, V> hiHead = null;
            		Node<K, V> hiTail = null;
            		while(p != null) {
            			if((hash(p.key) & (table.length - 1)) == i) {
            				if(loTail == null) {
            					loHead = p;
            				} else {
            					loTail.next = p;
            				}
            				loTail = p;
            			} else {
            				if(hiTail == null) {
            					hiHead = p;
            				} else {
            					hiTail.next = p;
            				}
            				hiTail = p;
            			}
            			p = p.next;
            		}
            		if(loHead != null) {
            			loTail.next = null;
            			table[i] = loHead;
            		}
            		if(hiHead != null) {
            			hiTail.next = null;
            			table[i + tab.length] = hiHead;
            		}
        		}
        	}
    	}
    }
    
}
