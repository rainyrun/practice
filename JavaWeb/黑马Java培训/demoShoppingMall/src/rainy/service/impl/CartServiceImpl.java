package rainy.service.impl;

import rainy.domain.Cart;
import rainy.domain.CartItem;
import rainy.domain.Product;
import rainy.service.CartService;
import rainy.service.ProductService;

public class CartServiceImpl implements CartService {

	@Override
	public void addToCart(Cart cart, String pid, int num) {
		int newNum = num;
		// 查询pid对应的商品项
		CartItem oldCartItem = cart.getCartItems().get(pid);
		if(oldCartItem != null) {// 购物车里已有商品，将商品数量相加
			int oldNum = oldCartItem.getNum();
			oldCartItem.setNum(num + oldNum);
		}
		else {// 购物车内没有该商品
			// 创建新的CartItem对象
			CartItem newCartItem = new CartItem();
			// 查询pid对应的商品
			ProductService prodService = new ProductServiceImpl();
			Product prod = prodService.getProductByPid(pid);
			// 配置CartItem对象
			newCartItem.setProd(prod);
			newCartItem.setNum(newNum);
			// 更新cart中的商品
			cart.putProduct(newCartItem);
		}
	}

	@Override
	public void deleteFromCart(Cart cart, String pid) {
		cart.deleteProduct(pid);
	}

	@Override
	public void modifyProduct(Cart cart, String pid, int num) {
		CartItem cartItem = cart.getCartItems().get(pid);
		cartItem.setNum(num);
		cart.putProduct(cartItem);
	}

	@Override
	public void clear(Cart cart) {
		cart.clear();
	}

}
