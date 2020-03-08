package rainy.domain;

public class CartItem {
	private Product prod;// 购物车中的商品，需要的信息为：商品缩略图、商品名、价格
	private int num;// 商品数量
	private double subTotal;// 小计

	// 修改商品数量
	public void setNum(int num){
		this.num = num;
		setSubTotal();
	}

	// 计算小计
	private void setSubTotal(){
		this.subTotal = this.num * prod.getShop_price();
	}

	// 其他getter&setter
	public Product getProd() {
		return prod;
	}

	public void setProd(Product prod) {
		this.prod = prod;
	}

	public double getSubTotal() {
		return subTotal;
	}

	public int getNum() {
		return num;
	}

	@Override
	public String toString() {
		return "CartItem [prod=" + prod + ", num=" + num + ", subTotal=" + subTotal + "]";
	}
}
