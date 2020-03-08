package rainy.service;

import rainy.domain.Cart;

public interface CartService {
	// 将商品添加到购物车
	void addToCart(Cart cart, String pid, int num);
	// 从购物车中删除商品
	void deleteFromCart(Cart cart, String pid);
	// 修改商品数量
	void modifyProduct(Cart cart, String pid, int num);
	// 清空购物车
	void clear(Cart cart);
}
