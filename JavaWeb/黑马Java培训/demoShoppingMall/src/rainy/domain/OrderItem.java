package rainy.domain;

public class OrderItem {
	private String itemid;// 订单项id
	private int quantity = 0;// 商品数量
	private double total;// 价格小计
	
	private Product product;// 订单项对应的商品
	private Order order;// 订单项对应的订单
	
	// 构造函数
	public OrderItem(Product product, int quantity) {
		this.product = product;
		this.quantity = quantity;
		setTotal();
	}
	// 无参构造函数
	public OrderItem() {
	}

	// 计算价格小计
	public void setTotal(){
		// 取得商品价格 * 商品数量
		total = product.getShop_price() * quantity;
	}

	// setter&getter
	public String getItemid() {
		return itemid;
	}

	public void setItemid(String itemid) {
		this.itemid = itemid;
	}

	public int getQuantity() {
		return quantity;
	}

	public double getTotal() {
		return total;
	}

	public Product getProduct() {
		return product;
	}

	public Order getOrder() {
		return order;
	}

	public void setOrder(Order order) {
		this.order = order;
		// 注2。加入订单需要重新计算该订单的总金额
		order.setTotal();
	}

	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	
	public void setProduct(Product product) {
		this.product = product;
	}
	
	public void setTotal(double total) {
		this.total = total;
	}
	
	@Override
	public String toString() {
		// 注1
		return "OrderItem [itemid=" + itemid + ", quantity=" + quantity + ", total=" + total + ", product=" + product + "]";
	}
}
/*
 * 注1: 因为OrderItem里有Order的引用，自动生成的toString方法循环打印，引起栈溢出错误。
 * 注2: 解决，先在order中加入一个空的OrderItem列表，再往OrderItem列表加入OrderItem时，总金额为空的问题。
 * 		但，如果OrderItem设置Order时，并没有加入该Order的items中，仍会出现问题。配置时需要注意添加顺序。
 */
