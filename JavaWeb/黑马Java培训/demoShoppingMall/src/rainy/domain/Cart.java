package rainy.domain;

import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Cart {
	private double total = 0;// 商品总价
	Map<String, CartItem> cartItems;// 购物车商品项们
	
	// 注1
	public Cart() {
		total = 0;
		this.cartItems = new HashMap<String, CartItem>();
	}

	// 添加商品项到购物车，如果商品项已存在，则替换为新的商品项。
	public void putProduct(CartItem cartItem) {
		// key为商品id
		String key = cartItem.getProd().getPid();
		cartItems.put(key, cartItem);
		// 计算商品总价
		setTotal();
	}
	// 删除购物项
	public void deleteProduct(String pid){
		cartItems.remove(pid);
		setTotal();
	}
	// 清空购物车
	public void clear() {
		cartItems.clear();
		total = 0;
	}
	// 购物车商品总价
	private void setTotal() {
		// 总价清零
		total = 0;
		// 遍历商品，将subTotal累加
		for(CartItem cartItem : cartItems.values()) {
			total += cartItem.getSubTotal();
		}
	}
	// 其他setter&getter
	public double getTotal() {
		return total;
	}
	public Map<String, CartItem> getCartItems() {
		return cartItems;
	}
	public void setCartItems(Map<String, CartItem> cartItems) {
		this.cartItems = cartItems;
	}
	public Collection<CartItem> getValues(){
		return cartItems.values();
	}
}

/*
 * 注1: 一开始没有写构造函数，没有为cartItems分配空间，导致总是出现空指针错误。
 */
